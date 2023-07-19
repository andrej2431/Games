import math


def draw_A(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    tur.up()
    tur.setpos(x, y)
    tur.down()
    tur.setheading(90)
    tur.rt(26.565)
    tur.fd(size * 1.11)
    tur.rt(180 - 26.565 * 2)
    tur.fd(size * 1.11)
    tur.back(size * 1.11 * 0.5)
    tur.rt(116.565)
    tur.fd(size // 2)
    tur.rt(90)

    self.drawing = False


def draw_B(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m, y)
    tur.down()
    tur.setheading(90)

    tur.fd(size)
    tur.rt(90)
    tur.fd(size // 3)
    tur.lt(180)
    tur.circle(size // 5, -180)
    tur.lt(180)
    tur.fd(size // 3)
    tur.lt(90)
    tur.fd(size // 5 * 3)
    tur.lt(90)
    tur.fd(size // 3)

    tur.circle(size // 10 * 3, 180)
    tur.rt(90)

    self.drawing = False


def draw_C(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m * 3, y)
    tur.down()
    tur.setheading(90)
    tur.rt(90)
    tur.circle(size // 2, -180)
    tur.rt(90)

    self.drawing = False


def draw_D(self, x, y, size=40):
    self.drawing = True

    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m, y)
    tur.down()
    tur.setheading(90)

    tur.fd(size)
    tur.lt(90)
    tur.circle(size // 2, -180)
    tur.lt(90)

    self.drawing = False


def draw_E(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m / 2, y)
    tur.down()
    tur.setheading(90)

    tur.fd(size)
    tur.rt(90)
    tur.fd(size // 3 * 2)
    tur.bk(size // 3 * 2)
    tur.rt(90)
    tur.fd(size // 2)
    tur.lt(90)
    tur.fd(size // 3 * 2 - size // 10)
    tur.bk(size // 3 * 2 - size // 10)
    tur.rt(90)
    tur.fd(size // 2)
    tur.lt(90)
    tur.fd(size // 3 * 2)
    tur.lt(90)

    self.drawing = False


def draw_F(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m / 2, y)
    tur.down()
    tur.setheading(90)

    tur.fd(size)
    tur.rt(90)
    tur.fd(size // 3 * 2)
    tur.bk(size // 3 * 2)
    tur.rt(90)
    tur.fd(size // 2)
    tur.lt(90)
    tur.fd(size // 3 * 2 - size // 10)
    tur.bk(size // 3 * 2 - size // 10)
    tur.lt(90)

    self.drawing = False


def draw_G(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m * 2, y + m * 2)
    tur.down()
    tur.setheading(90)
    tur.rt(90)
    tur.fd(size // 2)
    tur.lt(90)
    tur.circle(size // 2, -315)
    tur.rt(45)

    self.drawing = False


def draw_H(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m, y)
    tur.down()
    tur.setheading(90)

    tur.fd(size)
    tur.bk(size // 2)
    tur.rt(90)
    tur.fd(size // 2)
    tur.lt(90)
    tur.fd(size // 2)
    tur.bk(size)

    self.drawing = False


def draw_I(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + 2 * m, y)
    tur.down()
    tur.setheading(90)

    tur.fd(size)

    self.drawing = False


def draw_J(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m, y + m)
    tur.down()
    tur.setheading(90)
    tur.lt(180)
    tur.circle(size // 4, 180)
    tur.fd(size // 4 * 3)

    self.drawing = False


def draw_K(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m, y)
    tur.down()
    tur.setheading(90)

    tur.fd(size)
    tur.bk(size // 2)
    tur.rt(45)
    tur.fd(size // math.sqrt(2))
    tur.bk(size // math.sqrt(2))
    tur.rt(90)
    tur.fd(size // math.sqrt(2))
    tur.lt(135)

    self.drawing = False


def draw_L(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m, y)
    tur.down()
    tur.setheading(90)

    tur.fd(size)
    tur.bk(size)
    tur.rt(90)
    tur.fd(size // 2)
    tur.lt(90)

    self.drawing = False


def draw_M(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    tur.up()
    tur.setpos(x, y)
    tur.down()
    tur.setheading(90)

    tur.fd(size)
    tur.rt(135)
    tur.fd(size // math.sqrt(2))
    tur.lt(90)
    tur.fd(size // math.sqrt(2))
    tur.lt(45)
    tur.bk(size)

    self.drawing = False


def draw_N(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m / 2, y)
    tur.down()
    tur.setheading(90)

    tur.fd(size)
    tur.rt(180 - 36.87)
    tur.fd(size / 4 * 5)
    tur.lt(90 + 53.13)
    tur.fd(size)

    self.drawing = False


def draw_O(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m * 2, y)
    tur.down()
    tur.setheading(90)

    tur.rt(90)
    tur.circle(size // 2, 360)
    tur.lt(90)

    self.drawing = False


def draw_P(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m, y)
    tur.down()
    tur.setheading(90)

    tur.fd(size)
    tur.rt(90)
    tur.fd(size // 3)
    tur.bk(size // 3)
    tur.rt(90)
    tur.fd(size // 2)
    tur.lt(90)
    tur.fd(size // 3)
    tur.circle(size // 4, 180)
    tur.rt(90)

    self.drawing = False


def draw_Q(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + 2 * m, y)
    tur.down()
    tur.setheading(90)

    tur.rt(90)
    tur.circle(size // 2, 360)
    tur.lt(90)

    m = size / 4
    tur.up()
    tur.setpos(x + m * 4, y)
    tur.down()
    tur.setheading(90)

    tur.lt(60)
    tur.fd(size // 2)
    tur.rt(60)

    self.drawing = False


def draw_R(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m, y)
    tur.down()
    tur.setheading(90)

    tur.fd(size)
    tur.rt(90)
    tur.fd(size // 3)
    tur.bk(size // 3)
    tur.rt(90)
    tur.fd(size // 2)
    tur.lt(90)
    tur.fd(size // 3)
    tur.circle(size // 4, 180)

    tur.fd(size // 3)
    tur.lt(90)
    tur.fd(size // 2)
    tur.lt(45)
    tur.fd(size // math.sqrt(2))
    tur.lt(135)

    self.drawing = False


def draw_S(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m, y + m)
    tur.down()
    tur.setheading(90)

    tur.rt(180)
    tur.circle(size // 4, 270)
    tur.lt(180)
    tur.circle(size // 4, -270)

    self.drawing = False


def draw_T(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + 2 * m, y)
    tur.down()
    tur.setheading(90)

    tur.fd(size)
    tur.rt(90)
    tur.fd(size // 2)
    tur.bk(size)
    tur.lt(90)

    self.drawing = False


def draw_U(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x, y + m * 4)
    tur.down()
    tur.setheading(90)

    tur.rt(180)
    tur.fd(size // 2)
    tur.circle(size // 2, 180)
    tur.fd(size // 2)

    self.drawing = False


def draw_V(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x, y + m * 4)
    tur.down()
    tur.setheading(90)

    tur.rt(180 - 26.565)
    tur.fd(math.sqrt(5) * size // 2)
    tur.lt(63.435 * 2)
    tur.fd(math.sqrt(5) * size // 2)
    tur.lt(26.565)

    self.drawing = False


def draw_W(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x, y + m * 4)
    tur.down()
    tur.setheading(90)

    tur.rt(180 - 14.036)
    tur.fd(math.sqrt(17) * size // 4)
    tur.lt(75.964 * 2)
    tur.fd(math.sqrt(17) * size // 4)
    tur.lt(14.036)

    tur.rt(180 - 14.036)
    tur.fd(math.sqrt(17) * size // 4)
    tur.lt(75.964 * 2)
    tur.fd(math.sqrt(17) * size // 4)
    tur.lt(14.036)

    self.drawing = False


def draw_X(self, x, y, size=40):
    self.drawing = True
    l = (23.094 * 2) / 40
    diff = size / 2 - size * l / 4

    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + diff, y + m * 4)
    tur.down()
    tur.setheading(90)

    tur.rt(180 - 30)
    tur.fd(size * l)
    tur.bk(size * l / 2)
    tur.lt(120)
    tur.bk(size * l / 2)
    tur.fd(size * l)
    tur.lt(30)

    self.drawing = False


def draw_Y(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + 2 * m, y)
    tur.down()
    tur.setheading(90)

    tur.fd(size // 2 - size // 9)
    tur.lt(30)
    tur.fd(size / math.sqrt(2))
    tur.bk(size / math.sqrt(2))
    tur.rt(60)
    tur.fd(size / math.sqrt(2))
    tur.lt(30)

    self.drawing = False


def draw_Z(self, x, y, size=40):
    self.drawing = True
    tur = self.turtle
    m = size / 4
    tur.up()
    tur.setpos(x + m / 2, y + m * 4)
    tur.down()
    tur.setheading(90)

    tur.right(90)
    tur.fd(size / 4 * 3)
    tur.rt(90 + 36.87)
    tur.fd(size / 4 * 5)
    tur.lt(180 - 53.13)
    tur.fd(size / 4 * 3)
    tur.lt(90)

    self.drawing = False


letter_dict = {'A': draw_A, 'B': draw_B, 'C': draw_C, 'D': draw_D, 'E': draw_E, 'F': draw_F, 'G': draw_G, 'H': draw_H,
               'I': draw_I, 'J': draw_J, 'K': draw_K, 'L': draw_L, 'M': draw_M,
               'N': draw_N, 'O': draw_O, 'P': draw_P, 'Q': draw_Q, 'R': draw_R, 'S': draw_S, 'T': draw_T, 'U': draw_U,
               'V': draw_V, 'W': draw_W, 'X': draw_X, 'Y': draw_Y, 'Z': draw_Z, }
