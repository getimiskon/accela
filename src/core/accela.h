/*
 *  accela.h
 *  The main header of Accela
 *  Author: getimiskon
 *  Contributors: getimiskon, KawaiiMeowz
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <espeak-ng/speak_lib.h>

/*
 * Flags
 */

#define VOICE 1 // Voice output
#define DEV 1 // Development features
#define CUSTOM_USERNAME 0 // Custom username option

/*
 * Configuration 
 */

// espeak-ng configuration
espeak_AUDIO_OUTPUT output = AUDIO_OUTPUT_SYNCH_PLAYBACK;
char *path = NULL;
void* user_data;
unsigned int *identifier;
int voiceOutputFirstRun = 1;

/*
 * Functions
 */

// Voice Output
void voiceOutput(char string[]) {
	char voicename[] = {"English"};
	char text[127];
	strcpy(text, string);
	int buflength = 500, options = 0;
	unsigned int position = 0, position_type = 0, end_position = 0, flags = espeakCHARS_AUTO;
	if (voiceOutputFirstRun == 1) {
		espeak_Initialize(output, buflength, path, options);
		espeak_SetVoiceByName(voicename);
		voiceOutputFirstRun = 0;
	}
	if (VOICE == 1)
		espeak_Synth(text, buflength, position, position_type, end_position, flags, identifier, user_data);
}

// Welcome Message
void welcomeMessage(void) {
	char welcomeMessage[64];
	char customUsername[] = "Your username here";
	if (CUSTOM_USERNAME == 1)
		sprintf(welcomeMessage, "Welcome, %s\n", customUsername);
	else
		sprintf(welcomeMessage, "Welcome, %s\n", getenv("USER"));
	printf(welcomeMessage);
	if (VOICE == 1)
	 voiceOutput(welcomeMessage);
}

// "No command" function
void noCommand();

// Keyword check
char inputStr[128];
char keyword[32];
char commandCompareStr[32];

void keywordCheck(char input[], char keyword[]) {
	char *commandCompare[32];
	*commandCompare == strstr(input, keyword) && *commandCompare == keyword;
	strcat(commandCompareStr, commandCompare);
}

/// CODE UNFINISHED
