from projectiles import *

    


class Rocket(pygame.sprite.Sprite):
    rocket = pygame.image.load("rocket.png") 
    rocket = pygame.transform.scale(rocket,(75,125))
    def __init__(self):
        self.image = Rocket.rocket
        self.rect = self.image.get_rect(center = (700,700))
        pygame.sprite.Sprite.__init__(self)

    def update(self,x_move):
        self.rect.x+=x_move
        
    def draw(self,surface):
        surface.blit(self.image,self.rect)


class BOSS(pygame.sprite.Sprite):
    
    
    image0 = pygame.image.load('basic_wah.png') 
    image0 = pygame.transform.scale(image0,(75,125))

    image1 = pygame.image.load('Tpose.png')
    image1 = pygame.transform.scale(image1,(int(144*1.5),int(140*1.5)))

    image2 = pygame.image.load('tenispose.png') 
    image2 = pygame.transform.scale(image2,(int(144*1.5),int(140*1.5)))

    image3 = pygame.image.load('bomber.png') 
    image3 = pygame.transform.scale(image3,(250,150))

    bomb_image = pygame.image.load("bomb.png")
    bomb_image = pygame.transform.scale(bomb_image,(50,50))
            
    images = [image0, image1, image2, image3]
    
    def __init__(self,game_over,victory,screen):
        pygame.sprite.Sprite.__init__(self)
        self.state = 0
 
        self.images = BOSS.images
        self.image = self.images[0]
        self.bomb_image = BOSS.bomb_image
                
        self.rect = self.image.get_rect(top = 100,left = 500)
        
        self.change_x = 3
        self.charging = False
        self.max_hp = 200
        self.hp = 200

        self.bomb_group = pygame.sprite.Group()
        self.tenis_group = pygame.sprite.Group()

        self.game_over = game_over
        self.victory = victory
        self.screen = screen
        
        self.tick = 0


    def update(self):
        
        state = self.state
        
        if self.hp<= 0:
            self.victory()
            
        self.tick+=1

        self.health_bar()
        if state == 0:
            self.state_0()

        elif state == 1:
            self.state_1()

        elif state == 2:
            self.state_2()
        
        elif state == 3:
            self.state_3()




    def health_bar(self):
        length = int(1000*(self.hp/self.max_hp))
        healthbar = pygame.draw.rect(self.screen,(200,0,0),(0,0,length,25))
        
    def change_state(self):
        
        self.image =  self.images[self.state]
        self.rect = self.image.get_rect(top = 100,left = 500)
        
        if self.state == 1:
            
            self.chargup_cd = 60*2
            new_x = random.randrange(200, 800)
            self.rect.x = new_x
            self.starting_beam_coords = (self.rect.x+100,self.rect.y+200,30,500)
            self.charging = True

        elif self.state == 2:
            self.chargup_cd = 60*2
            new_x = random.randrange(200, 800)
            self.rect.x = new_x
            self.starting_beam_coords = (self.rect.x+100,self.rect.y+200,30,500)
            self.charging = True
            
        elif self.state == 3:
            
            self.change_x = 3
            

    def state_0(self):
        self.rect.x += self.change_x
        if self.rect.x < 25 or self.rect.x>900: 
            self.change_x*=-1


    def state_1(self):
        if self.chargup_cd > 0:
            self.beam = pygame.draw.rect(self.screen,(0,0,150),self.starting_beam_coords)
            self.chargup_cd-=1
            x,y,width,height = self.starting_beam_coords
            if self.tick%9 == 0:
                self.starting_beam_coords = (x+1,y,width-2,height)
            
        else:
            self.chargup_cd-=1
            if self.chargup_cd == -120:
                self.state = 3
                self.hp-=1
                self.change_state()
            else:
                self.beam = pygame.draw.rect(self.screen,(150,0,0),(self.rect.x+30,self.rect.y+200,170,500))


    def state_2(self):
        x,y,width,height =self.starting_beam_coords
        if self.chargup_cd > 0:
            self.beam = pygame.draw.rect(self.screen,(0,0,150),self.starting_beam_coords)
            self.chargup_cd-=1
            
            if self.tick%9 == 0:
                self.starting_beam_coords = (x+1,y,width-2,height)


            if self.tick%50 == 0:
                self.tenis_group.add(tball(x-30,y+20))

        else:
            self.chargup_cd-=1
            if self.chargup_cd == -120:
                self.state = 3
                self.hp-=1
                self.change_state()
                
            self.beam = pygame.draw.rect(self.screen,(150,0,0),(self.rect.x+30,self.rect.y+200,170,500))
            if self.tick%50 == 0:
                self.tenis_group.add(tball(x-30,y+20))



    def state_3(self):
        self.rect.x += self.change_x
        if self.rect.x < 20 or self.rect.x>750: 
            self.change_x*=-1
            image3 = pygame.transform.flip(self.image,True,False)
            self.image = image3
            
        self.tick+=1
        if self.tick%55 == 0:
            self.bomb_group.add( rocks(self.bomb_image,self.rect.x+100,self.rect.y + 150,self.game_over,y_speed=3))

    
    def draw(self,surface):
        surface.blit(self.image,self.rect)


        
