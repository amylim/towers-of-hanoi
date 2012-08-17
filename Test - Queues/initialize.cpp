#include "initialize.h"

void initialize()
{ 
	initscr ();                 //Turn on curses
	cbreak ();                  //Turn off carriage return to enter data
	noecho ();                  //Turn off echoing of input
	timeout(1000);
	start_color ();             //Turn on coloring of output
	keypad (stdscr, TRUE);      //Turn on F key entry and arrowkeys
	curs_set(0);                //Set cursor to underline

	if (!has_colors ())         //If colors not available, kill program
    {
		endwin ();
		fputs ("No colors!", stderr); 
		exit (1);
	}
    //Initialize color pairs
	
	init_pair (WHITEONBLACK, COLOR_WHITE, COLOR_BLACK);
	init_pair (WHITEONBLUE, COLOR_WHITE, COLOR_BLUE);
	init_pair (BLACKONBLUE, COLOR_BLACK, COLOR_BLUE);
	init_pair (BLACKONGREEN, COLOR_BLACK, COLOR_GREEN);
	init_pair (BLACKONCYAN, COLOR_BLACK, COLOR_CYAN);
	init_pair (BLACKONRED, COLOR_BLACK, COLOR_RED);
	init_pair (BLACKONMAGENTA, COLOR_BLACK, COLOR_MAGENTA);
	init_pair (BLACKONWHITE, COLOR_BLACK, COLOR_WHITE);
	init_pair (BLACKONYELLOW, COLOR_BLACK, COLOR_YELLOW);
	//                 Foreground , Background
	
	srand(time(NULL));
}     


void myExit()
{
	erase ();   //Clears the entire screen
	refresh (); //Puts your graphics on the screen
	endwin ();  //Turns off graphics mode
	exit(0);
} 
