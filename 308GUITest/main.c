


// Source from https://developer.gnome.org/gtk3/stable/gtk-getting-started.html

#include <gtk/gtk.h>


static void print_hello (GtkWidget *widget, gpointer data)
{
  g_print ("Hello World\n");
}


static void generate_insult (GtkWidget *widget, gpointer data)
{


 gtk_text_buffer_set_text(buffer, insult, -1);


}



static void activate (GtkApplication *app, gpointer user_data)
{

  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *button_box;
  GtkWidget *app_menu;
  GtkWidget *button2;
  GtkTextView *textbox;
  GtkTextBuffer *buffer;
  char * insult= " ";

//Makes window, sets name of window, and size of window.
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Insult Generator");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 500);
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);




//Makes button box and places in window
  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  textbox = gtk_text_view_new();


scrolled_window = gtk_scrolled_window_new(NULL, NULL);
gtk_container_add(GTK_CONTAINER(scrolled_window), textbox);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);



  buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textbox));
  textbox = gtk_text_view_new_with_buffer(buffer);
  //gtk_container_add(GTK_CONTAINER(window),textbox);
  gtk_container_add (GTK_CONTAINER (window), button_box, textbox);

  gtk_text_view_set_wrap_mode(textbox, wrap_mode);
  gtk_text_view_set_editable(textbox, FALSE);



//Text Box view portion/buffer
// textbox = gtk_text_view_new_with_buffer( buffer );
// gtk_container_add( GTK_CONTAINER (box), textbox);
// gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textbox), GTK_WRAP_WORD);


//gtk_container_add(GTK_CONTAINER(window), box);
//gtk_container_add(GTK_CONTAINER(box), textbox);




//Puts another button Box in window for button2
  gtk_container_add(GTK_CONTAINER(window), button_box);
//Makes button2 and gives its label, then tells what it does when pushed.
  button2 = gtk_button_new_with_label("Generate Insult");
  g_signal_connect(button2, "clicked", G_CALLBACK(generate_insult), NULL);
  gtk_container_add(GTK_CONTAINER (button_box), button2);//adds second button



//first button labeled, tells what it does when pressed.
  button = gtk_button_new_with_label ("Hello World");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);//closes the app when button is pushed.
  gtk_container_add (GTK_CONTAINER (button_box), button); // adds the first  button into button_box



  gtk_widget_show_all (window);// shows all the widgets in the window.
}




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


