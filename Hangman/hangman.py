import linecache
import random
import string
import turtle

import letter_draw as ld
from hangman_draw import *
from letter_grid import letter_grid


class Board:
    def __init__(self):
        self.window = turtle.Screen()
        self.window.title('Hangman 1.0')
        self.max_x, self.max_y = self.window.screensize()

        self.turtle = turtle.Turtle()
        self.turtle.speed(speed=100)
        self.turtle.ht()
        self.sc = turtle.Screen()
        self.sc.onclick(self.click)

        self.grid_pos = [(x, y) for y in (155, 105) for x in range(-320, 330, 50)]
        self.alphabet = list(string.ascii_uppercase)

        self.playing = False
        self.drawing = False

        self.word = None
        self.word_checker = None
        self.dict_len = 0
        for _ in open('20k.txt'):
            self.dict_len += 1
        self.used_letters = []
        self.letter_positions = []

        self.mistake = -1

        self.body_parts = [draw_noose, draw_head, draw_body, draw_lhand, draw_rhand, draw_lleg, draw_rleg]

        self.draw_board()

        self.start = True

        self.new_game()

    def new_game(self):
        self.playing = False
        self.reset_board()

        self.word = None
        self.word_checker = None

        self.used_letters = []
        self.letter_positions = []

        self.mistake = -1

        self.generate_word()
        self.draw_lines()

        self.playing = True
        self.start = False

    def reset_board(self):
        self.drawing = True
        tur = self.turtle
        tur.pencolor('white')

        if not self.start:
            tur.up()
            tur.setpos(-450, -350)
            tur.down()
            tur.setheading(0)
            tur.fd(900)

        for x in range(min((self.mistake + 1, len(self.body_parts)))):
            if x == 0:

                self.body_parts[x](self, erase=True)
            else:
                self.body_parts[x](self)

        if self.word:
            for letter, cords in zip(self.word, self.letter_positions):
                ld.letter_dict[letter.upper()](self, cords[0] + 5, cords[1] + 5)

        tur.pencolor('black')
        self.fill_letter_grid()
        self.drawing = False

    def generate_word(self):
        self.word = 'a' * 16
        while len(self.word) > 15 or len(self.word) < 3:
            line = random.randint(10000, self.dict_len)
            self.word = linecache.getline('20k.txt', line)[:-1]

        self.word_checker = self.word
        print('word: ', self.word)

    def click(self, x, y):
        if not self.playing:
            return

        if -325 < x < 325 and 100 < y < 200:
            self.click_grid(x, y)

        elif -210 < x < -50 and 295 < y < 320:
            self.new_game()
        else:
            pass

    def click_grid(self, x, y):
        if self.drawing:
            return

        i = 0
        if y < 150:
            i += 13

        for compare_x in range(-275, 330, 50):
            if compare_x >= x:
                break
            i += 1

        self.check_letter(self.alphabet[i])

    def check_letter(self, letter):
        if letter in self.used_letters:
            return

        for character, pos in zip(self.alphabet, self.grid_pos):
            if character == letter:
                self.turtle.pencolor('white')
                ld.letter_dict[letter](self, pos[0], pos[1])
                self.turtle.pencolor('black')

        self.used_letters.append(letter)

        if letter.lower() in self.word:
            self.update_letter(letter)
        else:
            self.wrong_answer()

    def update_letter(self, letter):
        self.word_checker = self.word_checker.replace(letter.lower(), '')
        for i, letters in enumerate(self.word):
            if letter.lower() == letters:
                x, y = self.letter_positions[i]
                ld.letter_dict[letter](self, x + 5, y + 5)
        if self.word_checker == '':
            self.game_over(True)

    def wrong_answer(self):
        if self.drawing:
            return
        self.drawing = True

        self.mistake += 1
        m = self.mistake

        if m < 7:
            self.body_parts[m](self)
        else:
            draw_eyes(self)
            self.game_over(False)

        self.drawing = False

    def game_over(self, victory):
        self.playing = False
        if victory:
            print('You Won !!')
        else:
            print('You are a LOSER')
        self.new_game()

    def draw_board(self):
        self.button_new_game()
        self.draw_letter_grid()

        self.draw_stand()
        self.drawing = False

    def button_new_game(self):
        tur = self.turtle
        tur.setheading(0)
        tur.up()
        tur.setpos(-210, 295)
        tur.down()

        tur.fd(160)
        tur.lt(90)
        tur.fd(25)
        tur.lt(90)
        tur.fd(160)
        tur.lt(90)
        tur.fd(25)

        self.write('NEW GAME', -200, 300, 16)

    def draw_letter_grid(self):
        tur = self.turtle

        tur.lt(90)

        letter_grid(tur, -325, 200)
        tur.rt(90)

    def fill_letter_grid(self):
        self.turtle.setheading(90)

        for letter, pos in zip(self.alphabet, self.grid_pos):
            if letter in self.used_letters or self.start:
                ld.letter_dict[letter](self, pos[0], pos[1])
        self.turtle.setheading(0)

    def draw_stand(self):
        tur = self.turtle

        tur.up()
        tur.setpos(-340, -270)
        tur.down()
        tur.setheading(0)
        tur.fd(150)
        tur.back(75)
        tur.left(90)
        tur.fd(300)
        tur.rt(90)
        tur.fd(100)
        tur.rt(90)
        tur.fd(10)
        tur.lt(180)

    def draw_lines(self):
        tur = self.turtle
        tur.up()

        if not self.word:
            return

        length = len(self.word)
        if length <= 15:
            half = (910 - length * 60) // 2
            tur.setheading(0)
            tur.setpos(-450 + half, -350)
            tur.down()

            for x in range(-450 + half, 450 - half, 60):
                self.letter_positions.append((x, -350))
                tur.fd(50)
                tur.up()
                tur.fd(10)
                tur.down()
            tur.setheading(90)

    def write(self, word, x, y, size):
        for letter in word:
            if letter != ' ':
                ld.letter_dict[letter](self, x, y, size=size)
            x += size + size // 8


Board()

turtle.mainloop()
