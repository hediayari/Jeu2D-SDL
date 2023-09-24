

#include "main.h"

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, NULL, destination, &offset );
}
int main(int argc, char *argv[])
{
								unsigned int frameLimit = SDL_GetTicks() + 16;

								/* Initialisation de la SDL */
								init("Yasmine");

								/* On initialise le joueur */
								initvie();
								
								/* Chargement des ressources (graphismes, sons) */

								loadGame_level11();

								initializePlayer();
								/* Appelle la fonction cleanup à la fin du programme */

								atexit(cleanup);

								jeu.go = 1;
					SDL_Surface* image;
					SDL_Surface* ani;
					int Run=1;
					int img=17,i,j,choix=0,n=0;
					char titre[20],an[20];
					SDL_Event event ;
					SDL_Surface* ng;
SDL_Surface* ng1;
SDL_Surface* sg;
SDL_Surface* sg1;
SDL_Surface* o;
SDL_Surface* o1;
SDL_Surface* cre;
SDL_Surface* cre1;
SDL_Surface* qu;
SDL_Surface* qu1;
ng=IMG_Load("newgame1.png");
ng1=IMG_Load("newgame2.png");
sg=IMG_Load("savegame1.png");
sg1=IMG_Load("savegame2.png");
o=IMG_Load("options1.png");
o1=IMG_Load("options2.png");
cre=IMG_Load("credits1.png");
cre1=IMG_Load("credits2.png");
qu=IMG_Load("quitter1.png");
qu1=IMG_Load("quitter2.png");
								/* Boucle infinie, principale, du jeu */
while (Run)
{      SDL_PollEvent(&event);
	

	    switch(event.type)
	    {
	        case SDL_QUIT: Run=0 ;	
             
            case SDL_KEYDOWN :
            {
                if (event.key.keysym.sym==SDLK_DOWN)
		        {
		        choix++;
		        }
		        else if (event.key.keysym.sym==SDLK_UP)
		        {
		        choix--;
		        }   
		        else if ((event.key.keysym.sym==SDLK_RETURN) && (choix==1))
		        {

								/* Boucle infinie, principale, du jeu */

								while (jeu.go == 1)
								{

																/* On prend on compte les input (clavier, joystick... */
																getInput();
																/* On met � jour le jeu */

																updatePlayer();
															

																/* On affiche tout */
																draw();

																/* Gestion des 60 fps (1000ms/60 = 16.6 -> 16 */
																delay(frameLimit);
																frameLimit = SDL_GetTicks() + 16;

								}
								 } 

		        else if ((event.key.keysym.sym==SDLK_RETURN) && (choix==5))
		        {
		        	Run=0 ;
		        }
		        else if ((event.key.keysym.sym==SDLK_RETURN) && (choix==3))
		        { 
		        	int option =1;
		        	while (option)
		        	{
		        		 switch(event.type)
	   					 {
						 case SDL_KEYDOWN :
            				{
		        		if (event.key.keysym.sym==SDLK_LEFT)
		        			option=0;

		        		  }		
		        			}
		        	}

		        }
                
		        if(choix==6)
	            {choix=1;}
	
	            if(choix==0)
	            {choix=5;} break ;
            }break ;  

         
        
        }
			
		switch (choix)
	    {
		   
		    case 0:
		    {
		    	
		if (img>20)
	img=1;
        sprintf(titre,"%d",img);
        strcat(titre,".png");
        image = IMG_Load(titre);
		img++;	
	 apply_surface(0,0,image,jeu.screen);
	 apply_surface(550,145,ng1,jeu.screen);
 apply_surface(550,225,sg1,jeu.screen);
 apply_surface(550,305,o1,jeu.screen);
 apply_surface(550,385,cre1,jeu.screen);
 apply_surface(550,465,qu,jeu.screen);

        SDL_Flip(jeu.screen); 
	SDL_FreeSurface(image);
		    	break ;
		    }
		    case 1:
		   {		
				if (img>20)
	img=1;
        sprintf(titre,"%d",img);
        strcat(titre,".png");
        image = IMG_Load(titre);
		img++;	
	 apply_surface(0,0,image,jeu.screen);
	 apply_surface(550,145,ng,jeu.screen);
 apply_surface(550,225,sg1,jeu.screen);
 apply_surface(550,305,o1,jeu.screen);
 apply_surface(550,385,cre1,jeu.screen);
 apply_surface(550,465,qu1,jeu.screen);

        SDL_Flip(jeu.screen); 
	SDL_FreeSurface(image);	
		        break;
	        }

		    case 2:
		   {
		        if (img>20)
	img=1;
        sprintf(titre,"%d",img);
        strcat(titre,".png");
        image = IMG_Load(titre);
		img++;	
	 apply_surface(0,0,image,jeu.screen);
	 apply_surface(550,145,ng1,jeu.screen);
 apply_surface(550,225,sg,jeu.screen);
 apply_surface(550,305,o1,jeu.screen);
 apply_surface(550,385,cre1,jeu.screen);
 apply_surface(550,465,qu1,jeu.screen);

        SDL_Flip(jeu.screen); 
	SDL_FreeSurface(image);
			    break;
			}

		    case 3:
		    {	
		     	         if (img>20)
	img=1;
        sprintf(titre,"%d",img);
        strcat(titre,".png");
        image = IMG_Load(titre);
		img++;	
	 apply_surface(0,0,image,jeu.screen);
	 apply_surface(550,145,ng1,jeu.screen);
 apply_surface(550,225,sg1,jeu.screen);
 apply_surface(550,305,o,jeu.screen);
 apply_surface(550,385,cre1,jeu.screen);
 apply_surface(550,465,qu1,jeu.screen);

        SDL_Flip(jeu.screen); 
	SDL_FreeSurface(image);	
			    break;
		    }

		    case 4:
		     {   
		  
 	         	if (img>20)
	img=1;
        sprintf(titre,"%d",img);
        strcat(titre,".png");
        image = IMG_Load(titre);
		img++;	
	 apply_surface(0,0,image,jeu.screen);
	 apply_surface(550,145,ng1,jeu.screen);
 apply_surface(550,225,sg1,jeu.screen);
 apply_surface(550,305,o1,jeu.screen);
 apply_surface(550,385,cre,jeu.screen);
 apply_surface(550,465,qu1,jeu.screen);

        SDL_Flip(jeu.screen); 
	SDL_FreeSurface(image);
			    break;
		    }

		    case 5:
		     {	
		       if (img>20)
	img=1;
        sprintf(titre,"%d",img);
        strcat(titre,".png");
        image = IMG_Load(titre);
		img++;	
	 apply_surface(0,0,image,jeu.screen);
	 apply_surface(550,145,ng1,jeu.screen);
 apply_surface(550,225,sg1,jeu.screen);
 apply_surface(550,305,o1,jeu.screen);
 apply_surface(550,385,cre1,jeu.screen);
 apply_surface(550,465,qu,jeu.screen);

        SDL_Flip(jeu.screen); 
	SDL_FreeSurface(image);

		        break;
		    }
        }

	
}
SDL_FreeSurface(jeu.screen);
SDL_Quit();
								

								/* Exit */
								exit(0);
}



							