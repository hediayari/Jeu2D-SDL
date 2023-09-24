

#include "defs.h"

/* Structures qui seront utilisées pour gérer le jeu */

/* Structure pour gérer l'input (clavier puis joystick) */

typedef struct Input
{
	int left, right, up, down, jump;
} Input;


/* Structure pour gérer le niveau (à compléter plus tard) */

typedef struct Gestion
{

    SDL_Surface *screen;
		int go;

} Gestion;


/* Structure pour gérer la map à afficher (à compléter plus tard) */

typedef struct Map
{

	SDL_Surface *background;
	SDL_Surface *levelCollision;
	SDL_Rect start_pos;
	//animation 
	SDL_Surface* animationImage[24];
	  char imageMapFile[250];
    int i;
 int animtionCounter;

	/* Coordonnées de début, lorsqu'on doit dessiner la map */
	int startX, startY;



} Map;




typedef struct Vie
{
	SDL_Surface *coeur1;
		SDL_Surface *coeur2;
			SDL_Surface *coeur3;
				SDL_Surface *coeur4;
	
	int nbr_vie;
	int frameNumber, frameTimer;
	int spot;
} Vie;

/* Structure pour gérer notre héros */

typedef struct Hero
{
    //Sprite du héros (pas d'animation pour l'instant)
	SDL_Surface *sprite;

	/* Coordonnées du héros */
	int x, y;
	/* Largeur, hauteur du sprite */
     int h, w;
	/* Variables utiles pour l'animation */
	int frameNumber, frameTimer;
  	//animation 
	  SDL_Surface* upImage[8];
	SDL_Surface* downImage[8];
	SDL_Surface* rightImage[8];
	SDL_Surface* leftImage[8];
	SDL_Surface* idlelImage[8];
	SDL_Surface* idlerImage[8];
	SDL_Surface* top_upImage[17];
	SDL_Surface* top_downImage[19];
	SDL_Surface* top_rightImage[19];
	SDL_Surface* top_leftImage[15];
	SDL_Surface* top_idlelImage[24];
	SDL_Surface* top_idlerImage[24];
	SDL_Surface* top_idleuImage[24];
	SDL_Surface* top_idledImage[20];
	  char imageHeroFile[250];
    int i,j,k,l,e,f,t,a,b;
 int idlercounter;
 int idlelcounter;
 int idledcounter;
 int idleucounter;
 int downcounter;
 int upcounter;
 int rightcounter;
 int leftcounter;

	int etat, direction;
int jump;
	/* Variables utiles pour la gestion des collisions */
     int onGround, timerMort;
     float dirX, dirY;

} Hero;





int currentlevel;
extern Hero player;
int Top_view_mode;