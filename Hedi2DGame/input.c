

#include "input.h"


void getInput(void)
{
								SDL_Event event;
								while (SDL_PollEvent(&event))
								{
																switch (event.type)
																{

																case SDL_QUIT:
																								exit(0);
																								break;

																case SDL_KEYDOWN:
																								switch (event.key.keysym.sym)
																								{
																								case SDLK_ESCAPE:
																																exit(0);
																																break;

																								

																								case SDLK_SPACE:
																																input.jump = 1;
																																break;

																								
																								case SDLK_LEFT:
																																input.left = 1;
																																break;

																								case SDLK_RIGHT:
																																input.right = 1;
																																break;

																								case SDLK_DOWN:
																																input.down = 1;
																																break;

																								case SDLK_UP:
																																input.up = 1;
																																break;


																								

																								default:
																																break;
																								}
																								break;

																case SDL_KEYUP:
																								switch (event.key.keysym.sym)
																								{
																								
																								case SDLK_SPACE:
																																input.jump = 0;
																																break;

																								case SDLK_LEFT:
																																input.left = 0;
																																break;

																								case SDLK_RIGHT:
																																input.right = 0;
																																break;

																								case SDLK_DOWN:
																																input.down = 0;
																																break;

																								case SDLK_UP:
																																input.up = 0;
																																break;

																								

																								default:
																																break;
                                                                                            }
																								break;


																}


								}
}
