#include <stdlib.h>
#include <string.h>
#include "forms.h"

/*
//Sentence structures
static const Sentence forms[NUM_FORMS]={
	{7,{noun_subject,space,are,space,a,noun_object,period}}
};
*/
char * form0(char * insult, char * noun) {
	strcpy(insult, "you are a ");
	strcat(insult, noun);
	strcat(insult, ".");
	return insult;
}
char * form1(char * insult, char * subject, char * noun) {
	strcpy(insult, subject);
	strcat(insult, " is a ");
	strcat(insult, noun);
	strcat(insult, ".");
	return insult;
}
