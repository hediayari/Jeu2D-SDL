#include "structs.h"

/* Prototypes des fonctions utilis�es */

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern void draw(void);
extern void loadGame(void);
extern void delay(unsigned int frameLimit);
extern void updatePlayer(void);

extern void initializePlayer(void);
extern void initvie(void);
extern void loadGame_level11(void);
extern void changeAnimation(void);
extern void mapCollision(Hero);

/* D�claration des structures globales utilis�es par le jeu */


Input input;
Gestion jeu;
Map map;
Hero player;

Vie vie;
