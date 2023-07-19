def draw_noose(self, x=-165, y=20, erase=False):
    if not erase:
        c1 = 'brown'
        c2 = 'black'
    else:
        c1 = 'white'
        c2 = 'white'

    tur = self.turtle
    self.drawing = True
    tur.up()
    tur.setpos(x, y)
    tur.down()

    tur.setheading(270)

    tur.pencolor(c1)
    tur.fd(50)
    tur.rt(90)
    tur.circle(15, 360)

    tur.pencolor(c2)
    tur.rt(90)

    self.drawing = False


def draw_head(self, x=-165, y=10):
    tur = self.turtle
    self.drawing = True
    tur.up()
    tur.setpos(x, y)
    tur.down()

    tur.setheading(180)
    tur.fillcolor('white')
    tur.begin_fill()
    tur.circle(30, 360)
    tur.end_fill()
    tur.rt(90)

    self.drawing = False


def draw_body(self, x=-165, y=-50):
    tur = self.turtle
    self.drawing = True
    tur.up()
    tur.setpos(x, y)
    tur.down()

    tur.setheading(270)
    tur.fd(70)
    tur.rt(180)

    self.drawing = False


def draw_lhand(self, x=-165, y=-50):
    tur = self.turtle
    self.drawing = True
    tur.up()
    tur.setpos(x, y)
    tur.down()

    tur.setheading(240)
    tur.fd(40)
    tur.rt(150)

    self.drawing = False


def draw_rhand(self, x=-165, y=-50):
    tur = self.turtle
    self.drawing = True
    tur.up()
    tur.setpos(x, y)
    tur.down()

    tur.setheading(300)
    tur.fd(40)
    tur.lt(150)

    self.drawing = False


def draw_lleg(self, x=-165, y=-120):
    tur = self.turtle
    self.drawing = True
    tur.up()
    tur.setpos(x, y)
    tur.down()

    tur.setheading(240)
    tur.fd(40)
    tur.rt(150)

    self.drawing = False


def draw_rleg(self, x=-165, y=-120):
    tur = self.turtle
    self.drawing = True
    tur.up()
    tur.setpos(x, y)
    tur.down()

    tur.setheading(300)
    tur.fd(40)
    tur.lt(150)

    self.drawing = False


def draw_eyes(self, x=-175, y=-10):
    tur = self.turtle
    self.drawing = True
    tur.up()
    tur.setpos(x, y)
    tur.down()

    tur.setheading(135)
    tur.fd(10)
    tur.bk(20)
    tur.fd(10)
    tur.rt(90)
    tur.fd(10)
    tur.bk(20)
    tur.rt(45)

    tur.up()
    tur.fd(20)
    tur.lt(45)
    tur.down()

    tur.fd(20)
    tur.bk(10)
    tur.lt(90)
    tur.fd(10)
    tur.bk(20)
    tur.rt(45)
    self.drawing = False
