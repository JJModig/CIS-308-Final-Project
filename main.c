
// Source from https://developer.gnome.org/gtk3/stable/gtk-getting-started.html

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "forms.h"
#include "list.h"

//Generates random integer from 0 to x
int randZeroToX(int x) {
	return (int)((double)rand() / ((double)RAND_MAX + 1.0) * (double)x);
}

//Remove underscores from a string
char * removeUnderscores(char * str) {
	int length = strlen(str);
	for(int i=0; i<length; i++){
		if(str[i] == '_'){
			str[i] = ' ';
		}
	}
	return str;
}
static void print_hello (GtkWidget *widget, gpointer data)
{
  g_print ("Hello World\n");
}

static void activate (GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *button_box;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);

  button = gtk_button_new_with_label ("Hello World");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_container_add (GTK_CONTAINER (button_box), button);

  gtk_widget_show_all (window);
}
//GUI Main method
/*
int main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
*/
//Console main method

int main (int argc, char **argv)
{
	if(argc != 2) {
		printf("Incorrect number of arguments. Format is ./main dictionary_file_name\n");
		return 1;
	}
	FILE * f = fopen(argv[1], "r");
	if(f == NULL) {
		printf("Input file does not exist.\n");
		return 1;
	}	//Initializes word lists
	List *dump = malloc(sizeof(List));
	initList(dump, 1);
	List *subjectsPersonal = malloc(sizeof(List));
	initList(subjectsPersonal, 10);
	List *nounsMean = malloc(sizeof(List));
	initList(nounsMean, 10);
	List *subjectsBody = malloc(sizeof(List));
	initList(subjectsBody, 10);
	List *verbsSense = malloc(sizeof(List));
	initList(verbsSense, 10);
	List *adjectives = malloc(sizeof(List));
	initList(adjectives, 10);
	List *nounsRand = malloc(sizeof(List));
	initList(nounsRand, 10);
	//Reading from file
	uintptr_t currentList = (uintptr_t)dump;
	char str[STR_LEN + 1];
	while(fscanf(f, "%s", str) == 1){
		if(str[0] == '>') {
			if(strcmp(str, ">subjects_personal") == 0){
				currentList = (uintptr_t)subjectsPersonal;
			}
			else if(strcmp(str, ">nouns_mean") == 0){
				currentList = (uintptr_t)nounsMean;
			}
			else if(strcmp(str, ">subjects_body") == 0){
				currentList = (uintptr_t)subjectsBody;
			}
			else if(strcmp(str, ">verbs_sense") == 0){
				currentList = (uintptr_t)verbsSense;
			}
			else if(strcmp(str, ">adjectives") == 0){
				currentList = (uintptr_t)adjectives;
			}
			else if(strcmp(str, ">nouns_rand") == 0){
				currentList = (uintptr_t)nounsRand;
			}
			else{
				currentList = (uintptr_t)dump;
			}
		}
		else {
			insertList((List *) currentList, str);
		}
	}
	//Primary functionality
	printf("Press ENTER to generate an insult (press x to exit).");
	while((char)getchar() != 'x'){
		//Just some testing
		/*
		printf("dump:\n");
		for(int i = 0; i < (int)dump->used; i++){
			printf("%s\n", dump->array[i]);
		}
		printf("subjects:\n");
		for(int i = 0; i < (int)subjects->used; i++){
			printf("%s\n", subjects->array[i]);
		}*/
		//Chooses a random form
		int r = randZeroToX(NUM_FORMS);
		char insult[100];
		switch(r) {
		case 0:
			//(Not yet implemented) Calls a function to generate an insult
			//in the form of form0
			strcpy(insult, form0(insult, nounsMean->array[randZeroToX(nounsMean->used)]));
			printf("%s\n", removeUnderscores(insult));
			break;
		case 1:
			strcpy(insult, form1(insult, subjectsPersonal->array[randZeroToX(subjectsPersonal->used)],
				nounsMean->array[randZeroToX(nounsMean->used)]));
			printf("%s\n", removeUnderscores(insult));
			break;
		case 2:
			strcpy(insult, form2(insult, subjectsBody->array[randZeroToX(subjectsBody->used)],
				verbsSense->array[randZeroToX(verbsSense->used)],
				adjectives->array[randZeroToX(adjectives->used)],
				nounsRand->array[randZeroToX(nounsRand->used)]));
			printf("%s\n", removeUnderscores(insult));
			break;
		case 3:
			strcpy(insult, form3(insult,
				subjectsPersonal->array[randZeroToX(subjectsPersonal->used)],
				subjectsBody->array[randZeroToX(subjectsBody->used)],
				verbsSense->array[randZeroToX(verbsSense->used)],
				adjectives->array[randZeroToX(adjectives->used)],
				nounsRand->array[randZeroToX(nounsRand->used)]));
			printf("%s\n", removeUnderscores(insult));
			break;
		case 4:
			printf("form4\n");
			break;
		default:
			printf("error\n");
		}
	}
	//Free word lists
	freeList(dump);
	free(dump);
	freeList(subjectsPersonal);
	free(subjectsPersonal);
	freeList(nounsMean);
	free(nounsMean);
	freeList(subjectsBody);
	free(subjectsBody);
	freeList(verbsSense);
	free(verbsSense);
	freeList(adjectives);
	free(adjectives);
	freeList(nounsRand);
	free(nounsRand);
}

