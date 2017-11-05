/*----------------------------------------------//
//      This is the Expanse Game Project        //
//                      2017                    //
//              Maintainer/s: Dale Kipple       //
//----------------------------------------------//
//                    License/s:                //
//                                              //
//                ioctl.h - GNU lGPL            //
//                stdio.h - GNU lGPL            //
//                stdlib.h - GNU lGPL           //
//              curses.h - see curses.h         //
//                unistd.h - GNU lGPL           //
//                string.h - GNU lGPL           //
//                ctype.h - GNU lGPL            //
//----------------------------------------------*/

//Includes
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

//Declerations


//Functions

// Clean up escape key codes so that they work correctly.
	char kb_cleanup(char);
// Initialize all 64 color options (standard Ubuntu Terminal)
	void setColors();
// Place menu options correctly on the screen and don't
// display options that go beyond the vertical edges
// Options may be no more than 30 characters long
// Must be counted 1..10
// Must contin a shortcut remembering that it may only require two keys
// Shortcuts go in instructions & help files not on the main interface
	void TitlePlaque(char *text[]);
	void CenterLeftJustify(int sHeight, int sWidth, int totalOptions, char *option[]);
// Call to get the size of the window
	bool scr_size(void);
// The interface processor
	int cursInterface();

// Global Var

	bool colours = TRUE;
	struct winsize crs_winSz;
	struct winsize tst_winSz;

int curses_main()
{
	scr_size();

	if(!initscr())
	{
		printf("Unable to enter curses mode");
		return 1;
	}

	if(has_colors())
	{
		if(!can_change_color())
		{
			mvprintw(crs_winSz.ws_row/2, (crs_winSz.ws_col/2)-(strlen("Color is unavailable on this system."))/2,"Color is unavaliable on this system.");
			colours = FALSE;
		}
		start_color();
		setColors();
	}
	else
	{
		mvprintw(crs_winSz.ws_row/2, (crs_winSz.ws_col/2)-(strlen("Color is unavailable on this system."))/2,"Color is unavailable on this system.");
		colours = FALSE;
	}
	setColors();
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &crs_winSz);
	raw();
	timeout(0);
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	noecho();

	clear();

	//init_pair(1, 1, 2);

	while(toupper(getch()) != 'E')
	{
		for(int x = 1; x <= 64; x++)
		{
			attron(COLOR_PAIR(x));
			printw("!");
			refresh();
		}
		cursInterface();
		scr_size();
	}
	endwin();
	return 0;
}

char kb_cleanup(char key)
{
	int kbhit = 0;
	if(key == 27)
		{
			if(getch() == -1) return 27;
			return kbhit;
		}
		
	return 0;
}

void CenterLeftJustify(int sHeight, int sWidth, int totalOptions, char *option[])
{
	
}

void setColors()
{
    /* Color Chart:
    // COLOR_BLACK	0
    // COLOR_RED	1
    // COLOR_GREEN	2
    // COLOR_YELLOW	3
    // COLOR_BLUE	4
    // COLOR_MAGENTA	5
    // COLOR_CYAN	6
    // COLOR_WHITE	7
    // 1(0,0);2(0,1);3(0,2);4(0,3);5(0,4);6(0,5);7(0,6);8(0,7)
    // 9(1,0);10(1,1);11(1,2);12(1,3);13(1,4);14(1,5);15(1,6);16(1,7)
    // 17(2,0);18(2,1);19(2,2);20(2,3);21(2,4);22(2,5);23(2,6);24(2,7)
    // 25(3,0);26(3,1);27(3,2);28(3,3);29(3,4);30(3,5);31(3,6);32(3,7)
    // 33(4,0);34(4,1);35(4,2);36(4,3);37(4,4);38(4,5);39(4,6);40(4,7)
    // 41(5,0);42(5,1);43(5,2);44(5,3);45(5,4);46(5,5);47(5,6);48(5,7)
    // 49(6,0);50(6,1);51(6,2);52(6,3);53(6,4);54(6,5);55(6,6);56(6,7)
    // 57(7,0);58(7,1);59(7,2);60(7,3);61(7,4);62(7,5);63(7,6);64(7,7)
    */
	// The counter, z, has to start at 1 as 0 isn't anything and will result in white text on a black background.
	int z = 1;
	
	// The algorithum below will produce 8x8 colors.
	// This means every combination of 8 forground and background colors is represented
	for(int x = 0; x <= 7; x++)
		for(int y = 0; y <= 7; y++)
		{
			init_pair(z,y,x);
			z++;
		}
	return;
}

bool scr_size(void)
{
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &tst_winSz);
    if((crs_winSz.ws_col != tst_winSz.ws_col) | (crs_winSz.ws_row != tst_winSz.ws_row))
    {
        crs_winSz = tst_winSz;
        return true;
    }
    return false;
}

int cursInterface()
{
	vmenu(colours,"Hello World");
	return 0;
}
