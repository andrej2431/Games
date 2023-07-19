import pygame,random

class Flying(pygame.sprite.Sprite):
    
    def __init__(self,image,left,top,x_speed=0,y_speed=0):
        pygame.sprite.Sprite.__init__(self)
        
        self.image = image
        self.rect = image.get_rect(left=left,top=top)
        
        
        self.change_x = x_speed
        self.change_y = y_speed

        
    def draw(self,surface):
        surface.blit(self.image,self.rect)

class rocks(Flying): 
    def __init__(self,image,left,top,game_over,y_speed=5,x_speed=0):
        Flying.__init__(self,image,left,top,x_speed=x_speed,y_speed=y_speed)
        
        self.game_over = game_over

    def update(self):
        self.rect.y += self.change_y 
        if self.rect.top+45 >640: 
            self.game_over()



        
class mushrooms(Flying):
    
    def __init__(self,image,left,top,x_speed=0,y_speed=5):
        Flying.__init__(self,image,left,top,x_speed=x_speed,y_speed=y_speed)
        

    def update(self):
        self.rect.y += self.change_y 
        



class strely(Flying):
    def __init__(self,top,left,image,y_speed=10,x_speed=0):
        Flying.__init__(self,image,left+27,top-75,x_speed=x_speed,y_speed=y_speed)
        
    def update(self): 
        self.rect.y -= self.change_y 
        if self.rect.y < 0: 
            self.kill() 



class tball(Flying):
    def __init__(self,left,top):
        image = pygame.image.load('tenis.png') 
        image = pygame.transform.scale(image,(50,50))
        Flying.__init__(self,image,left,top,x_speed=random.randrange(-5,5),y_speed=random.randrange(3,5))


    def update(self):
        self.rect.y += self.change_y
        self.rect.x += self.change_x
        if self.rect.x < 50 or self.rect.x > 950:
            self.change_x *= -1

            
        if self.rect.y >800: 
            self.kill()
