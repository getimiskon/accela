#include <stdio.h>
#include <string.h>

// Flags
#define VOICE 1 // Voice output
#define DEV 1 // Development - debugging options

void main();
int intro();
int input();

void weather();
void time();
void date();
void website();

void noCommand();
void end();

void main(){
	intro();
}

int intro(){
	system("echo Welcome, $USER");
	if (VOICE == 1)
		system("espeak-ng \"Welcome, $USER\"");
	input();
	return 0;
}

int input(){
	char command[100];
	const char weatherCommand[20] = "weather";
	const char timeCommand[20] = "time";
	const char dateCommand[20] = "date";
	const char websiteCommand[20] = "website";
	const char applicationCommand[20] = "application";
	char *cmdcmp[20];

	puts("What do you want to look for?");
	if (VOICE == 1)
		system("espeak-ng \"What do you want to look for?\"");
	puts("Type here: ");
	gets(command);

	if (DEV == 1){
		puts("\nKeep in mind that this software is under development. Various issues may be expected.\n");
		if (VOICE == 1)
			system("espeak-ng \"Keep in mind that this software is under development. Various issues may be expected.\"");
	}
	
	// Just a "dirty" way to test the code. I'll try to find a better way to check if the keyword exists in the user's input.
	if ((*cmdcmp = strstr(command, weatherCommand)) && (*cmdcmp = weatherCommand))
		weather();
	else{
		if ((*cmdcmp = strstr(command, timeCommand)) && (*cmdcmp = timeCommand))
			time();
		else{
			if ((*cmdcmp = strstr(command, dateCommand)) && (*cmdcmp = dateCommand))
				date();
			else{
				if ((*cmdcmp = strstr(command, websiteCommand)) && (*cmdcmp = dateCommand))
					website();
				else
					noCommand();
			}
		}
	}
	return 0;
}

void weather(){
	puts("Here's the weather for your area.");
	if (VOICE == 1)
		system("espeak-ng \"Here's the weather for your area.\"");
	system("curl wttr.in");
	end();
}

void time(){
	system("date +\"The time is: %I:%M %p\"");
	if (VOICE == 1)
		system("date +\"The time is: %I:%M %p\" | espeak-ng");
	end();
}

void date(){
	system("date +\"The date is: %A, %B %d %Y\"");
	if (VOICE == 1)
		system("date +\"The date is: %A, %B %d %Y\" | espeak-ng");
	end();
}

void website(){
	char website[50];
	char syscommand[] = "xdg-open http://";
	puts("Please type the website here:");
	if (VOICE == 1)
		system("espeak-ng \"Please type the website here:\"");
	gets(website);
	strcat(syscommand, website);
	system(syscommand);
	end();
}


void noCommand(){
	puts("I'm sorry, but I can't do that.");
	if (VOICE == 1)
		system("espeak-ng \"I'm sorry, but I can't do that.\"");
	if (DEV == 1){
		puts("At least, not yet...");
		if (VOICE == 1)
			system("espeak-ng \"At least, not yet...\"");
	}
	end();
}

void end() {
	char confirmation;
	puts("\nWould you like something else? [Y/n]: ");
	if (VOICE == 1)
		system("espeak-ng \"Would you like something else? Type Y for yes or N for no.\"");
	scanf("%c", &confirmation); // Used scanf() instead of gets() because of a segmentation fault error I had.
	getchar(); // getchar() helps to prevent any random loops in the following code.
	switch(confirmation){
		case 'N': case 'n':
			puts("Have a nice day!");
			if (VOICE == 1)
				system("espeak-ng \"Have a nice day!\"");
			
			break;
		case 'Y': case 'y':
			input();
			break;
		default:
			puts("This is not an option.");
			if (VOICE == 1)
				system("espeak-ng \"This is not an option.\"");
			end();
	}
}
