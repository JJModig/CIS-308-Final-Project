#ifndef sentence_h
#define sentence_h

#define MAX_COMP 50

//All possible types of strings that can make up a form
typedef enum component{space,period,comma,exclamation,noun_subject,noun_object,verb,adjective,adverb,
	are,a} component;

//Data structure for creating forms
typedef struct{
	int numComp;
	component sentence[MAX_COMP];
} Sentence;

#endif /* sentence_h */
