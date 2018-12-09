#include <stdlib.h>
#include <string.h>
#include "forms.h"

/*
//Sentence structures
static const Sentence forms[NUM_FORMS]={
	{7,{noun_subject,space,are,space,a,noun_object,period}}
};
*/
char * form0(char * insult, char * nounMean) {
	strcpy(insult, "you are a ");
	strcat(insult, nounMean);
	strcat(insult, ".");
	return insult;
}
char * form1(char * insult, char * subjectPersonal, char * nounMean) {
	strcpy(insult, subjectPersonal);
	strcat(insult, " is a ");
	strcat(insult, nounMean);
	strcat(insult, ".");
	return insult;
}
char * form2(char * insult, char *subjectBody, char *verbSense, char *adjective, char *nounRand) {
	strcpy(insult, "your ");
	strcat(insult, subjectBody);
	strcat(insult, " ");
	strcat(insult, verbSense);
	strcat(insult, " like a ");
	strcat(insult, adjective);
	strcat(insult, " ");
	strcat(insult, nounRand);
	strcat(insult, ".");
	return insult;
}
char * form3(char * insult, char *subjectPersonal, char *subjectBody, char *verbSense, char *adjective,
	char *nounRand) {
	strcpy(insult, subjectPersonal);
	strcat(insult, "'s ");
	strcat(insult, subjectBody);
	strcat(insult, " ");
	strcat(insult, verbSense);
	strcat(insult, " like a ");
	strcat(insult, adjective);
	strcat(insult, " ");
	strcat(insult, nounRand);
	strcat(insult, ".");
	return insult;
}
