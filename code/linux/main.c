//----------------------------------------------//
//      This is the Expanse Game Project        //
//                      2017                    //
//              Maintainer/s: Dale Kipple       //
//----------------------------------------------//

// Includes
#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_audio.h>
//#include <vulkan/vulkan.h>
#include <curses.h>
#include <stdbool.h>
#include <X11/Xlib.h>
//#include "sdl_main.c"


// Definitions

// Functions
int shutdown();
int sdl_main();
int curses_main();


int main(int argc, char **argv)
{
	//Checks to see if user selected curses mode
	if(argc > 1)
		if( strcmp(argv[1], "C") == 0 || strcmp(argv[1],"c") == 0)
		{
			curses_main();
			return 0;
		}
	
	// Checks to see if there is a window manager before attempting to run SDL
	if(XOpenDisplay(NULL))
	{
		if( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
		{
			printf("error initializing SDL: %s\n", SDL_GetError());
			return 1;
		}
		else
		{
			sdl_main();
			return 0;
		}
	}
	//SDL has failed so trying to start in curses mode
	else
	if( initscr())
	{
		curses_main();
		endwin();
		return 0;
	}
	//Don't know what happened but nothing worked
	return 1;
}

