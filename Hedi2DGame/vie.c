#include "vie.h"

void initvie(void)
{

        vie.nbr_vie=4;
        vie.coeur1 = IMG_Load("graphics/HP1.png");
          vie.coeur2 = IMG_Load("graphics/HP2.png");
            vie.coeur3 = IMG_Load("graphics/HP3.png");
              vie.coeur4 = IMG_Load("graphics/HP4.png");
       
        vie.frameNumber = 0;
        vie.frameTimer = TIME_BETWEEN_2_FRAMES;
}

void drawvie(void)
{
        SDL_Rect dest;
        
        dest.x = -map.startX+6000;
        dest.y = -110;
        dest.w = 400;
        dest.h = 516;


        /* Rectangle source � blitter */
        SDL_Rect src;

      
        src.x = vie.frameNumber * 400;
        src.y = 0;
        src.w = 400;
        src.h = 516;
        if (map.startX>5790 && vie.spot ==1) { // test si el Vie woufet ou nn 
                vie.spot=0;
                if (vie.nbr_vie!=3) {
                        vie.nbr_vie++;
                }

        }
if (vie.nbr_vie==4) {
                drawImage(vie.coeur4, 0,0);
                
        }
        else if (vie.nbr_vie==3) {
                drawImage(vie.coeur3, 0,0);
               
        }
        else if (vie.nbr_vie==2)
        {
                drawImage(vie.coeur2, 0,0);
               
        }
        else if (vie.nbr_vie==1)
        {
                drawImage(vie.coeur1, 0,0);
              
        }
        else
        {
                jeu.go=0;

        }

}
