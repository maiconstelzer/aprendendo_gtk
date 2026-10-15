#include <gtk/gtk.h>
int contador = 0;

void contar(GtkWidget *widget, gpointer data )
{
   g_print("Welcome to GTK\n");
   g_print("%s clicked %d times\n", (char*)data, ++contador);
}

void sair(GtkWidget *widget, gpointer data )
{
	gtk_main_quit();
}

int main(int argc, char *argv[] )
{
    GtkWidget *window;
    GtkWidget *button;
    
    gtk_init (&argc, &argv);
    
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	button = gtk_button_new_with_label("Click Me!");

	g_signal_connect(window, "destroy", G_CALLBACK(sair), NULL);                 
	g_signal_connect(GTK_OBJECT(button), "clicked", G_CALLBACK(contar), "button");
    
    gtk_container_add(GTK_CONTAINER (window), button);  
	gtk_widget_show_all(window);
    gtk_main ();
    
    return 0;
}
