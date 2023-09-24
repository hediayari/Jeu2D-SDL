
#include "draw.h"


void drawImage(SDL_Surface *image, int x, int y)
{
								SDL_Rect dest;

								/* R�gle le rectangle � blitter selon la taille de l'image source */

								dest.x = x;
								dest.y = y;
								dest.w = image->w;
								dest.h = image->h;

								/* Blitte l'image enti�re sur l'�cran aux coordonn�es x et y */

								SDL_BlitSurface(image, NULL, jeu.screen, &dest);
}

 
SDL_Surface *loadImage(char *name)
{
SDL_Surface *temp = IMG_Load(name) ;
SDL_Surface *image ; 
if (temp == NULL){
printf("FAILED TO LOAD IMAGE  ");
return NULL ; 
}
}

void draw(void)// Le draw de La game Loop
{

								/* Affiche la map	 aux coordonn�es (0,0) */
								drawImage(map.background, -map.startX	,-map.startY);
			
								 drawplayer();
								drawlifespot_vie();
								/* Affiche l'�cran */
								SDL_Flip(jeu.screen);

								/* Delai */

								SDL_Delay(1);

}




void delay(unsigned int frameLimit)
{

								/* Gestion des 60 fps */

								unsigned int ticks = SDL_GetTicks();// fonction predef calcule La duré de retard FPS

								if (frameLimit < ticks)
								{
																return;
								}

								if (frameLimit > ticks + 16)
								{
																SDL_Delay(16);
								}

								else
								{
																SDL_Delay(frameLimit - ticks);
								}
}
