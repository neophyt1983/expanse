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
#include <curses.h>
#include <stdbool.h>
#include <ctype.h>
#include <termios.h>
#include <termcap.h>
#include <unistd.h>
#include <stdlib.h>
#include <X11/Xlib.h>

// Definitions
const int SCR_Width = 640;
const int SCR_Height = 480;

// Functions

// Credit vVv
int mygetch ( void ) 
{
  int ch;
  struct termios oldt, newt;

  tcgetattr ( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr ( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr ( STDIN_FILENO, TCSANOW, &oldt );

  return ch;
}

void clear_screen()
{
char buf[1024];
char *str;

tgetent(buf, getenv("TERM"));
str = tgetstr("cl", NULL);
fputs(str, stdout);
} 



int main(int argc, char **argv)
{
	SDL_Window* WinMain = NULL;			// The main window
	//SDL_Surface* surfaceMain = NULL;		// Main window draw surface	
	int init_mode = 0;				// This will indicate what type of display we're using
	
	//printf("%s", getenv("Xorg"));
	//return 1;

	if(argc > 1)
		if( strcmp(argv[1], "T") == 0 || strcmp(argv[1],"t") == 0)
		{
			init_mode = 3;
			clear_screen();
			printf("Running in standard terminal\n");
			mygetch();
			return 0;
		}
		
	if(argc > 1)
		if( strcmp(argv[1], "C") == 0 || strcmp(argv[1],"c") == 0)
		{
			init_mode = 2;
			initscr();
			printw("Running in curses terminal\n");
			refresh();
			getch();
			endwin();
			return 0;
		}
	
	//if(isatty(fileno(stdin)))
	//if(!getenv("Xorg"))
	if(XOpenDisplay(NULL) && init_mode == 0)
	{
		if( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
		{
			printf("error initializing SDL: %s\n", SDL_GetError());
		}
		else
			init_mode = 1;
	}
	else
	if( initscr())
	{
		init_mode = 2;
		getch();
		endwin();
		return 0;
	}
	else
	if(init_mode == 0)
	{
		char std_term = 0;
		printf("\nWould you like to run in the standard terminal? (Y)es/(N)o\n");
		scanf("%c", &std_term);
		if(toupper(std_term) == 'Y' )
		{
			init_mode = 3;
			clear_screen();
			printf("Running in standard terminal\n");
			mygetch();
			endwin();
			return 0;
		}
		if(toupper(std_term) == 'N' )
		{
			printf("no\n");
			//SDL_Quit();
			endwin();
			clear_screen();
			return 0;
		}

	}
	else
	if(init_mode)
	{
		return 1;
	}

	
	WinMain = SDL_CreateWindow("Expanse",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				640,
				480,
				SDL_WINDOW_OPENGL);
	
	//surfaceMain = SDL_GetWindowSurface ( WinMain );
	//SDL_FillRect( surfaceMain, NULL, SDL_MapRGB( surfaceMain->format, 0x00, 0x00, 0x00));

	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer* rend = SDL_CreateRenderer(WinMain, -1, render_flags);
	if (!rend)
	{
		printf("error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(WinMain);
		SDL_Quit();
		return 1;
	}
	
	SDL_UpdateWindowSurface( WinMain );
	
	if ( WinMain == NULL){
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}
	
	SDL_SetRenderDrawColor(rend, 0,0,0,255);
	bool running = true;
	SDL_Event event;
	while(running)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				running = false;
			}
		}
		SDL_RenderClear(rend);

		SDL_RenderPresent(rend);
	}
	
	SDL_DestroyWindow(WinMain);			// Close and destroy the window
	SDL_Quit();					// Clean up
	return 0;       	                        // Full stop exit with no errors
}
