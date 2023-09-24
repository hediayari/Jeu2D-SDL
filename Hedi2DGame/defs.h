

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

/* Taille de la fenétre / résolution en plein écran */
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600



#define MAX_X 8000
#define MAX_Y 600





/* Taille du sprite de notre héros (largeur = width et hauteur = heigth) */
#define PLAYER_WIDTH 27
#define PLAYER_HEIGTH 50

/* Constantes pour l'animation */
#define TIME_BETWEEN_2_FRAMES 6

//Vitesse de d�placement en pixels du sprite
#define PLAYER_SPEED 5


//Valeurs attribuées aux états/directions
  #define WALK_RIGHT 1
  #define WALK_LEFT 2
  #define WALK_UP 4
  #define WALK_DOWN 5
  #define IDLE 3
  #define JUMP_RIGHT 4
  #define JUMP_LEFT 5
  #define RIGHT 1
  #define LEFT 2
  #define UP 3
  #define DOWN 4

//Constantes définissant la gravité et la vitesse max de chute
#define GRAVITY_SPEED 0.6
#define MAX_FALL_SPEED 10
#define JUMP_HEIGHT 13
