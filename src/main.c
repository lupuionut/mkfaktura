#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int main(int argc, char *argv[])
{
    GtkBuilder      *builder;
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "design.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "faktura"));
    gtk_builder_connect_signals(builder, NULL);

    input_date =
        GTK_CALENDAR(gtk_builder_get_object(builder, "input_date"));
    input_invoice_nr =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_invoice_nr"));
    input_currency =
        GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder, "input_currency"));
    input_seller_name =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_seller_name"));
    input_seller_business =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_seller_business"));
    input_seller_address =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_seller_address"));
    input_seller_zip =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_seller_zip"));
    input_seller_city =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_seller_city"));
    input_seller_country =
        GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder, "input_seller_country"));
    input_seller_nip =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_seller_nip"));
    input_buyer_name =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_buyer_name"));
    input_buyer_business =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_buyer_business"));
    input_buyer_address =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_buyer_address"));
    input_buyer_zip =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_buyer_zip"));
    input_buyer_city =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_buyer_city"));
    input_buyer_country =
        GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder, "input_buyer_country"));
    input_buyer_nip =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_buyer_nip"));

    g_signal_connect (window, "destroy",
                  G_CALLBACK (destroy), NULL);

    g_object_unref(builder);
    gtk_widget_show(window);
    gtk_main();

    return 0;
}

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

void on_btn_print_clicked()
{
    char* html = malloc(1000*sizeof(char));
    char* buffer = malloc(1000*sizeof(char));
    html = "year %u month %u day%u and this %u and %u";
    buffer = insert_date(html);
    printf("%s", buffer);
}

char* insert_date(char* html)
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
    char* buffer = malloc(1000*sizeof(char));

    gtk_calendar_get_date(input_date, &year, &month, &day);
    sprintf(buffer, html, year, month, day);
    return buffer;
}
