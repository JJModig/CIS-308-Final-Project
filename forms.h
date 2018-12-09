#ifndef forms_h
#define forms_h

#define NUM_FORMS 4
char * form0(char * insult, char * nounMean);
char * form1(char * insult, char * subjectPersonal, char * nounMean);
char * form2(char * insult, char * subjectBody, char * verbSense, char * adjective, char * nounRand);
char * form3(char * insult, char * subjectPersonal, char * subjectBody, char * verbSense,
	char * adjective, char * nounRand);
#endif
