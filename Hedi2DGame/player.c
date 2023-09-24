
#include "player.h"

void loadPlayer(void)
{
         for(player.i=0;player.i<4;player.i++){ //chargement d'images dans un tableau fi kol position
        sprintf( player.imageHeroFile,"graphics/characters/sarra/side/left%d.png",player.i+1);
        player.upImage[player.i] = IMG_Load(player.imageHeroFile);

}


 for(player.j=0;player.j<4;player.j++){
        sprintf( player.imageHeroFile,"graphics/characters/sarra/side/right%d.png",player.j+1);
        player.rightImage[player.j] = IMG_Load(player.imageHeroFile);
}



 for(player.k=0;player.k<4;player.k++){
        sprintf( player.imageHeroFile,"graphics/characters/sarra/side/left%d.png",player.k+1);
        player.leftImage[player.k] = IMG_Load(player.imageHeroFile);
}


 for(player.l=0;player.l<4;player.l++){
        sprintf( player.imageHeroFile,"graphics/characters/sarra/side/right%d.png",player.l+1);
        player.downImage[player.l] = IMG_Load(player.imageHeroFile);
    }

}








void changeAnimation(void)
{    if (player.frameTimer <= 0)
        {
                player.frameTimer = TIME_BETWEEN_2_FRAMES;

                player.frameNumber++;



    if( player.etat == WALK_LEFT) //hasb l'etat mtaa joueur mteena fel player.c on charge l'animation 
    {
    player.sprite = player.leftImage[player.leftcounter-1];

   player.leftcounter++;

        if(player.leftcounter == 4)
            player.leftcounter = 1;
    }
     if( player.etat == WALK_RIGHT)
    {
    player.sprite = player.rightImage[player.rightcounter-1];
  player.rightcounter++;
        if(player.rightcounter == 4)
            player.rightcounter = 1;
    }
     if(player.etat == JUMP_LEFT)
    {
    player.sprite = player.upImage[player.upcounter-1];
 player.upcounter++;
        if(player.upcounter == 4)
            player.upcounter = 1;
    }
     if(player.etat == JUMP_RIGHT)
    {
    player.sprite = player.downImage[player.downcounter-1];
  player.downcounter++;
        if(player.downcounter == 4)
            player.downcounter = 1;
    }

  if( player.onGround  == 1 && player.etat == IDLE && player.direction == LEFT)
    {
    player.sprite = player.upImage[player.upcounter-1];
  player.upcounter++;
        if(player.upcounter == 4)
            player.upcounter = 1;

    }

 if( player.onGround  == 1 && player.etat == IDLE && player.direction == RIGHT)
    {
   player.sprite = player.downImage[player.downcounter-1];
  player.downcounter++;
        if(player.downcounter == 4)
            player.downcounter = 1;
    }
      }
        else
                player.frameTimer--;
	//On charge la nouvelle
}




void initializePlayer(void)
{      
                 loadPlayer();
        
 
        
        /* Charge le sprite de notre h�ros */
      //  changeanimation();
          
         player.sprite = IMG_Load("graphics/characters/alex/side/standl1.png");
         player.idlercounter = 1;
         player.idlelcounter= 1;
         player.upcounter = 1;
         player.downcounter= 1;
         player.leftcounter= 1;
         player.rightcounter= 1;
         player.idledcounter=1;
         player.idleucounter=1;
        //Indique l'�tat et la direction de notre h�ros
       
        player.direction = RIGHT;
        player.etat = IDLE;
        
        player.frameNumber = 0;// temps entre deux frames maneha zouz tsawer bech meyetblokech 
        player.frameTimer = TIME_BETWEEN_2_FRAMES;

        player.w = PLAYER_WIDTH;
        player.h = PLAYER_HEIGTH;

        player.timerMort = 0;
        player.onGround = 0;// sur le sol 
player.x = map.start_pos.x + 100 ;// position initial du joueur 
player.y = map.start_pos.y ;// kifkif
}


void drawplayer() // affichage du joueur 
{
        SDL_Rect dest;

        dest.x = player.x - map.startX;// position du player plus w et h du joueur niblitiwhaa
        dest.y = player.y - map.startY;// kifkif
        dest.w = PLAYER_WIDTH;//kifkif
        dest.h = PLAYER_HEIGTH;//kifkif

        SDL_BlitSurface(player.sprite, NULL, jeu.screen, &dest);

}


void updatePlayer(void)// etat du joueur ++ new ett 
{       
        
        printf("%d | ",player.direction);
        if (player.timerMort == 0) // ki itih fel hofra il meurt 
        {


                player.dirX = 0;// bech la vitesse fel x matawalich infinii sinon looba tetehlek 

                player.dirY += GRAVITY_SPEED; // taa la gravitee 
                if (player.dirY >= MAX_FALL_SPEED)// si la grav sup a 13 sinon yokood infini 1" exemple bien defini 
                {
                        player.dirY = MAX_FALL_SPEED;
                }

                if (input.left == 1)
                {
                        player.direction = LEFT;
                        player.dirX -= PLAYER_SPEED;// ken left bech inakes mel speed khatrou yemchi belaakes wala 


                        if(player.etat != WALK_LEFT && player.onGround == 1)// ken fel right bech iwali left bech yokood ql ground
                        {
                                player.etat = WALK_LEFT;
                                player.frameNumber = 0;
                        }
                }

                else if (input.right == 1)// kima left 
                {
                        player.direction = RIGHT;
                        player.dirX += PLAYER_SPEED;

                        if(player.etat != WALK_RIGHT && player.onGround == 1)
                        {
                                player.etat = WALK_RIGHT;
                               // player.sprite = IMG_Load("graphics/walkright.png");
                                player.frameNumber = 0;
                        }
                }

                //Si on n'appuie sur rien et qu'on est sur le sol, on charge l'animation marquant l'inactivité (Idle)
                else if(input.right == 0 && input.left == 0 && player.onGround == 1)
                {
                        //On teste si le joueur n'était pas déjà inactif, pour ne pas recharger l'animation
                        //à chaque tour de boucle

                        if(player.etat != IDLE)// cette fonction est juste pour regler sa  posture
                        {
                                player.etat = IDLE;
                                //On change l'animation selon la direction
                                if(player.direction == LEFT)
                                {
                                        
                                        player.frameNumber = 0;
                                }
                                else
                                {
                                       
                                        player.frameNumber = 0;
                                }

                        }

                }



                //Et voici la fonction de saut très simple :
                //Si on appuie sur la touche saut et qu'on est sur le sol, alors on attribue une valeur
                //négative au vecteur Y
                //parce que sauter veut dire se rapprocher du haut de l'écran et donc de y=0.
                if (input.jump == 1)// el vecteur bech yonkos taa Y mech fel 9a3 el jump twali 1 
                {
                        if(player.onGround == 1)
                        {
                                player.dirY = -JUMP_HEIGHT;
                                player.onGround = 0;
                                player.jump = 1;
                        }
                        /* Si on est en saut 1, on peut faire un deuxième bond et on remet jump1 à 0 */
                        else if (player.jump == 1)
                        {
                                player.dirY = -JUMP_HEIGHT;
                                player.jump = 0;
                        }
                        //On remet les input à 0 par sécurité
                        input.jump = 0;


                        /* Réactive la possibilité de double saut si on tombe sans sauter */
                        if (player.onGround == 1)
                                player.jump = 1;


                        //On gère l'anim du saut


                }
                if(player.onGround == 0)
                {
                        if(player.direction == RIGHT && player.etat != JUMP_RIGHT)
                        {
                                player.etat = JUMP_RIGHT;
                                //player.sprite = IMG_Load("graphics/JumpRight.png");
                                player.frameNumber = 0;
                        }
                        else if(player.direction == LEFT && player.etat != JUMP_LEFT)
                        {
                                player.etat = JUMP_LEFT;
                               // player.sprite = IMG_Load("graphics/JumpLeft.png");
                                player.frameNumber = 0;
                        }

                }

                //On rajoute notre fonction de détection des collisions qui va mettre à jour les coordonnées
                //de notre super lapin, puis on centre le scrolling comme avant.
                mapCollision(&player);
                centerScrollingOnPlayer();
                drawplayer();
                changeAnimation();
                

        }

        //Gestion de la mort quand le héros tombe dans un trou :
        //Si timerMort est différent de 0, c'est qu'il faut réinitialiser le joueur.
        //On ignore alors ce qui précède et on joue cette boucle (un wait en fait) jusqu'à ce que
        // timerMort == 1. A ce moment-là, on le décrémente encore . il vaut 0 et on réinitialise
        //le jeu avec notre bonne vieille fonction d'initialisation ;) !

        if (player.timerMort > 0)// time mort tout ce qui est hofra 
        {
                player.timerMort--;// ken hbat lel hofra imout w yarjaa mel loul 

                if (player.timerMort == 0)
                {
                        /* Si on est mort */
                        initializePlayer();
                        if ( player.timerMort==0) {
                                vie.nbr_vie--;
                        }
                }
        }

}
void centerScrollingOnPlayer(void)
{
        //On d�finit les coordonn�es du d�but de l'affichage de la map par rapport � celles
        //du joueur.
        //Pour centrer le joueur, la map doit donc s'afficher � un demi-�cran avant la position
        //du joueur.
        //Puis on "clamp" (limite) l'affichage de l'�cran pour ne pas sortir de la map.




        map.startX = player.x - (SCREEN_WIDTH / 6);

        if (map.startX < 0) // si le joueur a atteint la bordure de l'ecran a droite yo93ad ghadi 
        {
                map.startX = 0;
        }

        else if (map.startX + SCREEN_WIDTH >= MAX_X) // nafs l'operation fel bordure gauche 
        {
                map.startX = MAX_X - SCREEN_WIDTH;
        }

        map.startY = player.y - (SCREEN_WIDTH / 2); // ki yousel le joueur lel chtar l'ecran 

        if (map.startY < 0) //l'operation Dans l'axe Y 
        {
                map.startY = 0;
        }

        else if (map.startY + SCREEN_HEIGHT >= MAX_Y)
        {
                map.startY = MAX_Y - SCREEN_HEIGHT;
        }
}


