//----------------------------------------------//
//      This is the Expanse Game Project        //
//                      2017                    //
//              Maintainer/s: Dale Kipple       //
//----------------------------------------------//

//Includes
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <string.h>

//Declerations


//Functions
char kb_cleanup(char);


int curses_main()
{
	int kb_press = 0;
	//int m_location[2][2];
	struct winsize crs_winSz;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &crs_winSz);

	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);

	printw("Running in curses terminal\n");
	printw("Press any key to continue\n");
	refresh();
	getch();
	clear();

	while(getch() != 27)
	{
		//Remember mvprintw and other mv functions in curses are always written (columns, rows) or (y,x)
		mvprintw((crs_winSz.ws_row/2),((crs_winSz.ws_col/2)-(strlen("Press any key with an escape code to leave!")/2)), "Press any key with an escape code to leave!");
		mvprintw(1,1,"%c",kb_press);
		refresh();
		noecho();
		kb_press = kb_cleanup(getch());

	}
	endwin();
	return 0;
}

char kb_cleanup(char key)
{
	if(key == 27)
		if(getch() == 0) return 27;
		
	return 0;
}
