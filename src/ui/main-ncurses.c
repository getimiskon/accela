#include <stdio.h>
#include <string.h>
#include <ncurses.h>

/* The main functions of the program */
void main();		// loads all the functions that are needed
int display();		// initializes the user interface
int intro();		// the introduction text that is being displayed every time the program starts
int input();		// the input function

/* Commands */
void weather();		// displays the weather by parsing data from wttr.in
void time();		// displays the time
void date();		// displays the date
void website();		// opens a website using the xdg-open command

void command();
void end();			// the ending sequence of the program

void main() {
	display();
}

int display() {
	char prog_title[] = "CLI Assistant";
	char dev_text[] = "Testing build with ncurses";
	char prompt[] = "Press F1 to close the program: ";
	char prompt_input[127];
	int row, col, ch;

	initscr();
	cbreak();	
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	// Starts ncurses in color mode.
	use_default_colors();
	// Uses the default colors of the terminal. It's useful with terminal emulators that don't have a black background.
	getmaxyx(stdscr, row, col);
	// Gets the maximum values of rows and columns from your terminal
		
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_YELLOW, COLOR_RED);
	// Initializes the pairs of colors that will be used
	
	/* Program title */
	mvprintw(0, 0, "%s\n", prog_title);
	mvchgat(0, 0, -1, A_NORMAL, 1, NULL);
		
	/* Secondary text, temporarily named "dev_text" */
	mvprintw(row - 2, (col - strlen(dev_text))/2, "%s\n", dev_text);
	mvchgat(row - 2, 0, -1, A_NORMAL, 2, NULL);

	mvprintw(row - 1, 0, prompt);
	getstr(prompt_input);
	mvprintw(row - 1, strlen(prompt), "%s", prompt_input);
	getch();


//	while ((ch = getch()) != KEY_F(1)) {	
		// Prints text now, it will probably be changed for input
		
//	}
	
//	for(row = 1; row < (LINES - 2); row)
	
//	refresh();
	endwin();
	return 0;
}
