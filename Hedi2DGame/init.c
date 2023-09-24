
#include "init.h"


void init(char *title)
{
/* declaration des variable*/

								char logo[25]=" ";

								/* Initialise SDL Video. Si la valeur de retour est inférieure à zéro, la SDL n'a pas pu
								   s'initialiser et on quite */

								if (SDL_Init(SDL_INIT_EVERYTHING ) < 0)
								{
																printf("Could not initialize SDL: %s\n", SDL_GetError());
																exit(1);
								}


								/* On crée la fenêtre, représentée par le pointeur jeu.screen en utilisant la largeur et la
								   hauteur définies dans les defines (defs.h). On utilise aussi la mémoire vidéo
								   (SDL_HWPALETTE) et le double buffer pour éviter que ça scintille
								   (SDL_DOUBLEBUF) */

								jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32,
																										SDL_HWSURFACE|SDL_DOUBLEBUF);

								/* Si on y arrive pas, on quitte */

								if (jeu.screen == NULL)
								{
																printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH,
																							SCREEN_HEIGHT, SDL_GetError());
																exit(1);
								}


								/* On entre le titre et l'icon de la fenêtre */

								sprintf(logo, "graphics/%s.png", title);
								SDL_WM_SetIcon(IMG_Load(logo), NULL);
								SDL_WM_SetCaption(title, NULL);


								/* On cache le curseur de la souris par default et on charge notre curseur  */

								SDL_ShowCursor(SDL_DISABLE);
								//jeu.curseur=IMG_Load("graphics/curseur.png");

}







void cleanup()
{

								/* Lib�re l'image du background */

								if (map.background != NULL)
								{
																SDL_FreeSurface(map.background);
								}
								
								if (map.levelCollision != NULL)
								{
																SDL_FreeSurface(map.levelCollision);
								}




								/* Quitte la SDL */
								SDL_Quit();

}
