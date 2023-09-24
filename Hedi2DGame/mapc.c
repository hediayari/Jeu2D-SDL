#include "map.h"

SDL_Color GetPixel(SDL_Surface *Background, int x, int y)
{
        SDL_Color color, white={0,0,0};
        Uint32 col = 0;
        //Determine position

        if (x<8000 && y<600)
        {
                char *pixelPosition = (char*)Background->pixels;
                //Offset by Y
                pixelPosition += (Background->pitch * y);
                //Offset by X
                pixelPosition += (Background->format->BytesPerPixel * x);
                //Copy pixel data
                memcpy(&col, pixelPosition, Background->format->BytesPerPixel);
                //Convert to color
                SDL_GetRGB(col, Background->format, &color.r, &color.g, &color.b);

                return (color);
        }
        else
                return (white);

}


void mapCollision(Hero *entity)
{

        int i, xg, xd, yg, yd,test;
        SDL_Color PixelToCompare1,PixelToCompare2;


        SDL_LockSurface(map.levelCollision);//bech mataamelch decalage


        xg = entity->x + entity->dirX;
        xd = entity->x + entity->dirX + entity->w;

        yg = yd = entity->y + entity->h / 1.2;




        if (xg >0 && xd < MAX_X && yg >= 0 && yd < MAX_Y)
        {

                if (entity->dirX > 0)
                {

                        PixelToCompare1= GetPixel(map.levelCollision,xd,yg);
                        PixelToCompare1= GetPixel(map.levelCollision,xd,yd);
                        test = ((PixelToCompare1.r == 0) && (PixelToCompare1.b == 0) && (PixelToCompare1.g == 0)) && ((PixelToCompare2.r == 0) && (PixelToCompare2.b == 0) && (PixelToCompare2.g == 0));
                        if (test)
                        {


                                entity->x -=   entity->dirX;
                                entity->dirX = 0;

                        }

                }

                //Même chose à gauche

                else if (entity->dirX < 0)
                {
                        PixelToCompare1= GetPixel(map.levelCollision,xg,yg);
                        PixelToCompare1= GetPixel(map.levelCollision,xg,yd);
                        test = ((PixelToCompare1.r == 0) && (PixelToCompare1.b == 0) && (PixelToCompare1.g == 0)) && ((PixelToCompare2.r == 0) && (PixelToCompare2.b == 0) && (PixelToCompare2.g == 0));

                        if (test)
                        {

                                entity->x -= entity->dirX;

                                entity->dirX = 0;
                        }


                }

        }

        //On sort de la boucle si on a testé toutes les tiles le long de la hauteur du sprite.






        xg = (entity->x);
        xd = entity->x + entity->w /2;

        yg = (entity->y + entity->dirY);
        yd = (entity->y + entity->dirY + entity->h);

        if (xg >= 0 && xd < MAX_X && yg >= 0 && yd < MAX_Y)
        {
                if (entity->dirY > 0)
                {
                        PixelToCompare1= GetPixel(map.levelCollision,xd,yd);
                        PixelToCompare1= GetPixel(map.levelCollision,xg,yd);
                        test = ((PixelToCompare1.r == 0) && (PixelToCompare1.b == 0) && (PixelToCompare1.g == 0)) && ((PixelToCompare2.r == 0) && (PixelToCompare2.b == 0) && (PixelToCompare2.g == 0));

                        if (test)
                        {

                                entity->y = yd;
                                if(Top_view_mode==0)
                                entity->y -= entity->h+0.1;
                                else entity->y -= entity->h;

                                entity->dirY = 0;

                                entity->onGround = 1;
                        }

                }

                else if (entity->dirY < 0)
                {


                        PixelToCompare1= GetPixel(map.levelCollision,xd,yg);
                        PixelToCompare1= GetPixel(map.levelCollision,xg,yg);
                        test = ((PixelToCompare1.r == 0) && (PixelToCompare1.b == 0) && (PixelToCompare1.g == 0)) &&((PixelToCompare2.r == 0) && (PixelToCompare2.b == 0) && (PixelToCompare2.g == 0));

                        if (test)
                        {

                                entity->y = (yg + 1);

                                entity->dirY = 0;


                        }

                }
        }



        entity->x += entity->dirX;
        entity->y += entity->dirY;

        if (entity->x < 0)
        {
                entity->x = 0;
        }

        else if (entity->x + entity->w >= MAX_X)
        {
                entity->x = MAX_X - entity->w - 1;
        }


        if (entity->y > MAX_Y)
        {
                entity->timerMort = 60;
        }
        SDL_UnlockSurface(map.levelCollision);
}