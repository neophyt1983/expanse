/*----------------------------------------------//
//      This is the Expanse Game Project        //
//                      2017                    //
//              Maintainer/s: Dale Kipple       //
//----------------------------------------------*/

// Includes
#include <stdbool.h>

// Definitions


// Functions

/* Menu construction is incomplete right now */

/* This function will select the appropriate menu design but the designer is responsible for passing the correct arguments */
int menu(char type, bool colors, char *options[], position location);
/* The is the horizontal menu builder for building a standard window menu (file edit help...) You can pass menu trees starting with the base
   menu title so that when a menu option is chosen it will drop down and display suboptions and so on.
   The string for building these is written like this ".File..Open..Exit.Edit..Copy...Copy Different...Copy Same..Cut..Paste.Help..About" */
int hmenu(bool colors, char *options[]);
/* This is the verticle menu builder for building the kinds of menus that would usually be found in games. There is no option for submenues with this builder
   The string for building these is written like this ".Start.Options.Quit" */
int vmenu(bool colors, char *options[]);
/* This is the horizontal context menu that will come up when a particular part of the screen is right clicked or the [key/combination] is pressed.
   This menu looks very much like the hmenu in structure but the content is based on where one the screen the cursor is located */
int cmenu(bool colors, char *options[], position location);

/* Menu construction is incomplete right now */

int menu(char type, bool colors, char *options[], position location)
{

	return 0;
}

int hmenu(bool colors, char *options[])
{
	return 0;
}

int vmenu(bool colors, char *options[])
{
	return 0;
}

int cmenu(bool colors, char *options[], position location)
{

	return 0;
}
