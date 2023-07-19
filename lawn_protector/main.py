import sys
from entities import *

pygame.init()
pygame.font.init()
myfont = pygame.font.SysFont('Comic Sans MS', 30)
pygame.display.set_caption("Protect the lawn")
icon = pygame.image.load('lawnmower.png')
pygame.display.set_icon(icon)
size = width, height = 1000, 800
fps = 60
speed = 600 // fps
bg = 0, 0, 0
screen = pygame.display.set_mode(size)
clock = pygame.time.Clock()
score = 0
high_score = 0
rocket_group = pygame.sprite.GroupSingle()


def game_over():
    global high_score
    over = pygame.image.load('ded.jpg')
    over = pygame.transform.scale(over, (1000, 800))
    over_rect = over.get_rect(center=(500, 500))
    high_score = max(high_score, score)
    pygame.mixer.music.stop()
    pygame.mixer.music.load('dark.mp3')
    pygame.mixer.music.play(0)
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()

                print('High score:' + str(high_score))
                sys.exit()
        screen.fill(bg)
        screen.blit(over, over_rect)

        mouse = pygame.mouse.get_pos()

        if 420 < mouse[0] < 620 and 650 < mouse[1] < 700:
            pygame.draw.rect(screen, (150, 150, 150), (420, 650, 200, 50))
            pygame.draw.rect(screen, (100, 100, 100), (420, 580, 200, 50))
            if pygame.mouse.get_pressed()[0] == 1:
                s = 0  # s je aby som vedel rozoznať ktore tlacitko bolo stlacene
                break

        elif 420 < mouse[0] < 620 and 580 < mouse[1] < 630:
            pygame.draw.rect(screen, (150, 150, 150), (420, 580, 200, 50))
            pygame.draw.rect(screen, (100, 100, 100), (420, 650, 200, 50))
            if pygame.mouse.get_pressed()[0] == 1:
                s = 1
                break

        else:
            pygame.draw.rect(screen, (100, 100, 100), (420, 580, 200, 50))
            pygame.draw.rect(screen, (100, 100, 100), (420, 650, 200, 50))
        menusurface = myfont.render('Menu', False, (255, 255, 255))
        screen.blit(menusurface, (450, 580))
        textsurface = myfont.render('New Game', False, (255, 255, 255))
        screen.blit(textsurface, (450, 650))
        scoresurface = myfont.render('Score:' + str(score), False, (255, 255, 255))
        screen.blit(scoresurface, (450, 50))
        pygame.display.update()
        clock.tick(60)
    if s == 0:
        hra()
    elif s == 1:
        menu()


def victory():
    global high_score
    win = pygame.image.load('win.png')
    win = pygame.transform.scale(win, (1000, 800))
    win_rect = win.get_rect(center=(500, 500))

    wded = pygame.image.load('Wded.png')
    wded = pygame.transform.scale(wded, (300, 250))
    wded_rect = wded.get_rect(center=(800, 150))

    high_score = max(high_score, score)
    pygame.mixer.music.stop()
    pygame.mixer.music.load('victory.mp3')
    pygame.mixer.music.play(0)

    menu_coords = (200, 650, 200, 50)
    new_game_coords = (600, 650, 200, 50)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()

                print('High score:' + str(high_score))
                sys.exit()
        screen.fill(bg)
        screen.blit(win, win_rect)
        screen.blit(wded, wded_rect)

        mouse = pygame.mouse.get_pos()

        if 200 < mouse[0] < 400 and 650 < mouse[1] < 700:
            pygame.draw.rect(screen, (150, 150, 150), menu_coords)
            pygame.draw.rect(screen, (100, 100, 100), new_game_coords)
            if pygame.mouse.get_pressed()[0] == 1:
                s = 0  # s je aby som vedel rozoznať ktore tlacitko bolo stlacene
                break

        elif 600 < mouse[0] < 800 and 650 < mouse[1] < 700:
            pygame.draw.rect(screen, (150, 150, 150), new_game_coords)
            pygame.draw.rect(screen, (100, 100, 100), menu_coords)
            if pygame.mouse.get_pressed()[0] == 1:
                s = 1
                break

        else:
            pygame.draw.rect(screen, (100, 100, 100), new_game_coords)
            pygame.draw.rect(screen, (100, 100, 100), menu_coords)
        menusurface = myfont.render('Menu', False, (255, 255, 255))
        screen.blit(menusurface, (200, 650))
        textsurface = myfont.render('New Game', False, (255, 255, 255))
        screen.blit(textsurface, (600, 650))
        scoresurface = myfont.render('Score:' + str(score), False, (255, 255, 255))
        screen.blit(scoresurface, (450, 50))
        pygame.display.update()
        clock.tick(60)
    if s == 0:
        hra()
    elif s == 1:
        menu()


def hra():
    global score, high_score
    pygame.mixer.music.load('darude.mp3')
    pygame.mixer.music.play(-1)

    rocket = Rocket()

    strela = pygame.image.load("strela.png")

    strela = pygame.transform.scale(strela, (100, 20))
    strela = pygame.transform.rotate(strela, 90)
    strela_group = pygame.sprite.Group()

    p_strela = pygame.image.load("strela2.png")
    p_strela = pygame.transform.scale(p_strela, (100, 20))
    p_strela = pygame.transform.rotate(p_strela, 90)

    rock = pygame.image.load("rock.png")
    rock = pygame.transform.scale(rock, (100, 55))
    rock_group = pygame.sprite.Group()

    mushroom = pygame.image.load("mushroom.png")
    mushroom = pygame.transform.scale(mushroom, (55, 55))
    mushroom_group = pygame.sprite.Group()

    hitbox = pygame.image.load("grass.jpg").convert_alpha()
    hitbox = pygame.transform.scale(hitbox, (1000, 200))

    score = 0
    running = True
    strela_cooldown = 0
    powerup_cd = 0
    bossfight_cd = 0
    i = 60 * 2
    j = 60 * 10
    paused = False
    powerupped = False
    bossfight = False

    tick = 0
    while running:
        pause = 0
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                running = False

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_p:
                    pause = 1
        if not running:
            high_score = max(high_score, score)
            print('High score:' + str(high_score))
            sys.exit()
        pressed = pygame.key.get_pressed()
        a_held = pressed[pygame.K_a]
        d_held = pressed[pygame.K_d]
        space_held = pressed[pygame.K_SPACE]
        if pause:

            if paused:
                paused = False
            else:
                paused = True

        if paused:
            pygame.display.flip()

            continue

        if score == 2:
            if not bossfight:
                waluigi = BOSS(game_over, victory, screen)
                bossfight = True

        if i == 0 and not bossfight:
            new_rock = rocks(rock, random.randrange(60, 740), 0, game_over)
            rock_group.add(new_rock)
            i = 40
        i -= 1

        if j == 0:
            new_mushroom = mushrooms(mushroom, random.randrange(60, 740), 0)
            mushroom_group.add(new_mushroom)
            j = random.choice([60 * 10, 60 * 12, 60 * 8])
        j -= 1

        x_move = 0
        if a_held and not d_held and rocket.rect.left > 15:
            x_move = -speed

        elif d_held and not a_held and rocket.rect.right < width - 15:
            x_move = speed

        if powerup_cd == 0:
            powerupped = False
        else:
            powerup_cd -= 1

        if space_held and strela_cooldown == 0:
            if not powerupped:
                bullet = strely(rocket.rect.top, rocket.rect.left, strela)
                strela_group.add(bullet)
                strela_cooldown = 30
            else:
                bullet = strely(rocket.rect.top, rocket.rect.left - 20, p_strela)
                strela_group.add(bullet)
                bullet = strely(rocket.rect.top, rocket.rect.left + 20, p_strela)
                strela_group.add(bullet)
                strela_cooldown = 10

        elif strela_cooldown > 0:
            strela_cooldown -= 1

        before = len(rock_group)
        pygame.sprite.groupcollide(rock_group, strela_group, True, True)
        after = len(rock_group)
        score += (before - after)

        before = len(mushroom_group)
        pygame.sprite.spritecollide(rocket, mushroom_group, True)
        after = len(mushroom_group)
        if before - after > 0:
            powerupped = True
            powerup_cd = 60 * 5
        screen.fill(bg)

        hitbox_rect = hitbox.get_rect(center=(500, 740))
        screen.blit(hitbox, hitbox_rect)

        mushroom_group.update()
        mushroom_group.draw(screen)
        rock_group.update()

        rock_group.draw(screen)

        strela_group.update()
        strela_group.draw(screen)

        tick += 1
        if 25 > score > 15 and tick % 45 < 30:
            approach = myfont.render('!!!BOSS APPROACHING!!!', False, (255, 0, 0))
            screen.blit(approach, (320, 100))

        if bossfight:
            waluigi.update()
            waluigi.draw(screen)

            before = len(waluigi.tenis_group)
            pygame.sprite.spritecollide(rocket, waluigi.tenis_group, True)
            after = len(waluigi.tenis_group)
            if before - after > 0:
                game_over()

            waluigi.tenis_group.update()
            waluigi.tenis_group.draw(screen)

            collisions = pygame.sprite.spritecollide(waluigi, strela_group, True)
            for col in collisions:
                waluigi.hp -= 1
                if waluigi.hp == 175:
                    waluigi.state = 3
                    waluigi.change_state()
                elif waluigi.hp == 100 or waluigi.hp == 125 or waluigi.hp == 150:
                    waluigi.state = 1
                    waluigi.change_state()
                elif waluigi.hp == 75 or waluigi.hp == 50 or waluigi.hp == 25:
                    waluigi.state = 2
                    waluigi.change_state()

            if waluigi.state == 1 and waluigi.chargup_cd <= 0:
                if waluigi.beam.colliderect(rocket.rect):
                    game_over()

            if waluigi.state == 2:
                if waluigi.chargup_cd <= 0 and waluigi.beam.colliderect(rocket.rect):
                    game_over()

            if waluigi.state == 3:
                pygame.sprite.groupcollide(waluigi.bomb_group, strela_group, True, True)
                waluigi.bomb_group.update()
                waluigi.bomb_group.draw(screen)

        rocket.draw(screen)
        rocket.update(x_move)

        scoresurface = myfont.render('Score:' + str(score), False, (255, 255, 255))
        screen.blit(scoresurface, (450, 50))

        pygame.display.flip()
        pygame.event.pump()
        clock.tick(fps)


def menu():
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                print('High score:' + str(high_score))
                return
        screen.fill(bg)
        mouse = pygame.mouse.get_pos()
        if 420 < mouse[0] < 620 and 350 < mouse[1] < 400:
            pygame.draw.rect(screen, (150, 150, 150), (420, 350, 200, 50))
            pygame.draw.rect(screen, (100, 100, 100), (420, 550, 200, 50))
            if pygame.mouse.get_pressed()[0] == 1:
                a = 1  # to iste ako 's' pri gameover
                break

        elif 420 < mouse[0] < 620 and 550 < mouse[1] < 600:
            pygame.draw.rect(screen, (150, 150, 150), (420, 550, 200, 50))
            pygame.draw.rect(screen, (100, 100, 100), (420, 350, 200, 50))
            if pygame.mouse.get_pressed()[0] == 1:
                a = 0
                break
        else:
            pygame.draw.rect(screen, (100, 100, 100), (420, 350, 200, 50))
            pygame.draw.rect(screen, (100, 100, 100), (420, 550, 200, 50))

        text1 = myfont.render('New Game', False, (255, 255, 255))
        screen.blit(text1, (450, 350))
        text2 = myfont.render('Options', False, (255, 255, 255))
        screen.blit(text2, (450, 550))

        pygame.display.update()
        clock.tick(60)
    if a == 1:
        hra()
    elif a == 0:
        options()


option = pygame.image.load('options.png')
option = pygame.transform.scale(option, (500, 500))
option_rect = option.get_rect(center=(500, 250))


def options():
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                print('High score:' + str(high_score))
                return
        screen.fill(bg)
        screen.blit(option, option_rect)
        hint = myfont.render('Protect your lawn from evil meteors and bombs', False, (255, 255, 255))
        screen.blit(hint, (250, 450))
        mouse = pygame.mouse.get_pos()

        if 420 < mouse[0] < 620 and 650 < mouse[1] < 700:
            pygame.draw.rect(screen, (150, 150, 150), (420, 650, 200, 50))
            if pygame.mouse.get_pressed()[0] == 1:
                break
        else:
            pygame.draw.rect(screen, (100, 100, 100), (420, 650, 200, 50))
        menusurface = myfont.render('Back', False, (255, 255, 255))
        screen.blit(menusurface, (450, 650))
        pygame.display.update()
        clock.tick(60)
    menu()


menu()
