/*----------------------------------------------//
//      This is the Expanse Game Project        //
//                      2017                    //
//              Maintainer/s: Dale Kipple       //
//----------------------------------------------//
//                    License/s:                //
//                                              //
//					 SDL2 - Zlib                //
//                stdio.h - GNU lGPL            //
//              curses.h - see curses.h         //
//                unistd.h - GNU lGPL           //
//                string.h - GNU lGPL           //
//                ctype.h - GNU lGPL            //
//                socket.h - GNU lGPL           //
//                 in.h - GNU lGPL              //
//----------------------------------------------*/

// Includes
//#include <SDL2/SDL.h> // SDL2 does not yet work
//#include <stdio.h>
//#include <SDL2/SDL_timer.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_audio.h>
#include <X11/Xlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/socket.h>
#include <netinet/in.h>


// Definitions

// Functions
int shutdown();
//int sdlMain();
int curses_main();


int main(int argc, char **argv)
{
	// Looks for arguments
	
	int count = -1;

	while ((count = getopt(argc, argv,"crh:")) != -1) {
		
		switch (count)
		{
			case 'c':  /* Curses Mode */
				curses_main();
				return 0;
				break;
			case 'r': /* Set the resolution */
				printf("This is not yet implemented\n");
				return 0;
				break;
			case 'h':
				printf("/nExpanse -R <option>\n\n-c, --curses\n\tSelect Curses mode\n\n-h --help\n\tHelp and general tips\n");
				return 0;
				break;
			default:
				curses_main();
				break;
		}
	}
	// Checks to see if there is a window manager before attempting to run SDL
	/*if(XOpenDisplay(NULL))
	{
		if( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
		{
			printf("error initializing SDL: %s\n", SDL_GetError());
			return 1;
		}
		else
		{
			sdlMain();
			return 0;
		}
	}
	//SDL has failed so trying to start in curses mode
	curses_main();
	
	//Don't know what happened but nothing worked*/
	return 1;
}

