/*
 *  accela.c
 *  The main source code of Accela
 *  Author: getimiskon
 */

#include <stdio.h>
#include <string.h>
#include "accela.h"

// Main functions
void main(void);
void intro();
void input();

// No command and end functions
void noCommand();
void end();

void main(void) {
	intro();
}

void intro() {
	welcomeMessage();
	input();
}

void input() {
	char *inputStr[128];
	char inputQuestion[] = "What do you want to look for?";
	char inputPrompt[] = "Type here: ";
	
	puts(inputQuestion);
	voiceOutput(inputQuestion);
	puts(inputPrompt);
	gets(inputStr);
	
	puts(inputStr);	
}

void noCommand() {
	char noCommandStr[] = "Error. This is not an available command.";
	puts(noCommandStr);
	voiceOutput(noCommandStr);
	
	end();
}

void end() {
	char endQuestion[] = "Would you like something else? [Y/n]: ";
	char endQuestionVoice[] = "Would you like something else? Press Y for yes or N for no.";
	char endMessage[] = "Goodbye!";
	char endNotAnOption[] = "This is not an option.";
	char confirmationChar;
	
	puts(endQuestion);
	voiceOutput(endQuestionVoice);
	scanf("%c", &confirmationChar);
	getchar();
	switch(confirmationChar) {
		case 'N': case 'n':
			puts(endMessage);
			voiceOutput(endMessage);
			break;
		case 'Y': case 'y':
			input();
			break;
		default:
			puts(endNotAnOption);
			voiceOutput(endNotAnOption);
			end();
	}
}

// CODE UNFINISHED
