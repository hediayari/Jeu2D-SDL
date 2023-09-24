
#include "animation.h"


void drawanimatedplayer(void)
{
        /* Gestion du timer */
        // Si notre timer (un compte � rebours en fait) arrive � z�ro
        if (player.frameTimer <= 0)
        {
                //On le r�initialise
                player.frameTimer = TIME_BETWEEN_2_FRAMES;

                //Et on incr�mente notre variable qui compte les frames de 1 pour passer � la suivante
                player.frameNumber++;

                //Mais si on d�passe la frame max, il faut revenir � la premi�re
                //Pour conna�tre la frame max, il suffit de diviser la longueur du spritesheet
                //Puisque la premi�re frame est la num�ro 0, la derni�re est donc la num�ro 11
                if(player.frameNumber >= player.sprite->w / PLAYER_WIDTH - 1)
                        player.frameNumber = 0;

        }
        //Sinon, on d�cr�mente notre timer
        else
                player.frameTimer--;


        //Ensuite, on peut passer la main � notre fonction
        drawplayer();


}


void drawmap(void)
{
        /* Gestion du timer */
        // Si notre timer (un compte � rebours en fait) arrive � z�ro
        if (player.frameTimer <= 0)
        {
                //On le r�initialise
                player.frameTimer = TIME_BETWEEN_2_FRAMES;

                //Et on incr�mente notre variable qui compte les frames de 1 pour passer � la suivante
                player.frameNumber++;

                //Mais si on d�passe la frame max, il faut revenir � la premi�re
                //Pour conna�tre la frame max, il suffit de diviser la longueur du spritesheet
                //par la longueur de notre h�ros : 480 / 40 = 12 frames
                //Puisque la premi�re frame est la num�ro 0, la derni�re est donc la num�ro 11
                if(player.frameNumber >= player.sprite->w / PLAYER_WIDTH - 1)
                        player.frameNumber = 0;

        }
        //Sinon, on d�cr�mente notre timer
        else
                player.frameTimer--;


        //Ensuite, on peut passer la main � notre fonction
        drawplayer();


}


void drawlifespot_vie(void)
{
        /* Gestion du timer */
        // Si notre timer (un compte � rebours en fait) arrive � z�ro
        if (vie.frameTimer <= 0)
        {
                //On le r�initialise
                vie.frameTimer = TIME_BETWEEN_2_FRAMES;

                //Et on incr�mente notre variable qui compte les frames de 1 pour passer � la suivante
                vie.frameNumber++;

                //Mais si on d�passe la frame max, il faut revenir � la premi�re
                //Pour conna�tre la frame max, il suffit de diviser la longueur du spritesheet
                //par la longueur de notre h�ros : 480 / 40 = 12 frames
                //Puisque la premi�re frame est la num�ro 0, la derni�re est donc la num�ro 11
                //if(vie.frameNumber >= vie.lifespot->w / 400 )
                        vie.frameNumber = 0;

        }
        //Sinon, on d�cr�mente notre timer
        else
                vie.frameTimer--;


        //Ensuite, on peut passer la main � notre fonction
        drawvie();


}
