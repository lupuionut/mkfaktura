#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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

    input_product1_netto =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_product1_netto"));
    input_product1_vat_value =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_product1_vat_value"));
    input_product1_brutto =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_product1_brutto"));
    input_product2_netto =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_product2_netto"));
    input_product2_vat_value =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_product2_vat_value"));
    input_product2_brutto =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_product2_brutto"));
    input_total_netto =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_total_netto"));
    input_total_vat_value =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_total_vat_value"));
    input_total_brutto =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_total_brutto"));
     input_total =
        GTK_ENTRY(gtk_builder_get_object(builder, "input_total"));

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

// PRODUCT 1 CHANGES
void on_input_product1_net_changed
    (GtkEditable *input_product1_net, GtkComboBoxText *input_product1_qty)
{
    char* pnet;
    char* pqt;
    char totals[50];
    float netto, qty, total;
    pnet = gtk_editable_get_chars(input_product1_net, 0, -1);
    netto = atof(pnet);
    pqt = gtk_combo_box_text_get_active_text(input_product1_qty);
    qty = atof(pqt);
    total = netto * qty;
    snprintf(totals,sizeof(totals), "%.2f", total);
    gtk_entry_set_text(input_product1_netto, totals);
    free(pnet);free(pqt);
}

void on_input_product1_qty_changed
    (GtkComboBoxText *input_product1_qty, GtkEditable *input_product1_net)
{
    on_input_product1_net_changed(input_product1_net, input_product1_qty);
}

void on_input_product1_netto_changed
    (GtkEditable *input_product1_netto, GtkEntry *input_product1_vat_rate)
{
    const char* vat_rate;
    const char* netto;
    float vat_rate_float, total_float, vat_float, netto_float;
    char total[50];
    char vat[50];
    char total_netto[50];
    char total_vat_value[50];
    char total_brutto[50];

    vat_rate = gtk_entry_get_text(input_product1_vat_rate);
    netto = gtk_editable_get_chars(input_product1_netto, 0, -1);

    if (strcmp(vat_rate, "-") == 0) {
        vat_rate = "0";
    }

    vat_rate_float = atof(vat_rate);
    netto_float = atof(netto);
    total_netto_1 = netto_float;
    vat_float = netto_float * vat_rate_float / 100;
    total_vat_1 = vat_float;
    total_float = netto_float + vat_float;
    total_brutto_1 = total_float;
    snprintf(vat, sizeof(total), "%.2f", vat_float);
    snprintf(total, sizeof(total), "%.2f", total_float);
    snprintf(total_netto, sizeof(total_netto), "%.2f", total_netto_1 + total_netto_2);
    snprintf(total_vat_value, sizeof(total_vat_value), "%.2f", total_vat_1 + total_vat_2);
    snprintf(total_brutto, sizeof(total_brutto), "%.2f", total_brutto_1 + total_brutto_2);
    gtk_entry_set_text(input_product1_vat_value, vat);
    gtk_entry_set_text(input_product1_brutto, total);
    gtk_entry_set_text(input_total_netto, total_netto);
    gtk_entry_set_text(input_total_vat_value, total_vat_value);
    gtk_entry_set_text(input_total_brutto, total_brutto);
    gtk_entry_set_text(input_total, total_brutto);
}

void on_input_product1_vat_rate_changed
    (GtkEntry *input_product1_vat_rate, GtkEditable *input_product1_netto)
{
    on_input_product1_netto_changed(input_product1_netto, input_product1_vat_rate);
}
// PRODUCT1 CHANGES

// PRODUCT 2 CHANGES
void on_input_product2_net_changed
    (GtkEditable *input_product2_net, GtkComboBoxText *input_product2_qty)
{
    char* pnet;
    char* pqt;
    char totals[50];
    float netto, qty, total;
    pnet = gtk_editable_get_chars(input_product2_net, 0, -1);
    netto = atof(pnet);
    pqt = gtk_combo_box_text_get_active_text(input_product2_qty);
    qty = atof(pqt);
    total = netto * qty;
    snprintf(totals,sizeof(totals), "%.2f", total);
    gtk_entry_set_text(input_product2_netto, totals);
}

void on_input_product2_qty_changed
    (GtkComboBoxText *input_product2_qty, GtkEditable *input_product2_net)
{
    on_input_product2_net_changed(input_product2_net, input_product2_qty);
}

void on_input_product2_netto_changed
    (GtkEditable *input_product2_netto, GtkEntry *input_product2_vat_rate)
{
    const char* vat_rate;
    const char* netto;
    float vat_rate_float, total_float, vat_float, netto_float;
    char total[50];
    char vat[50];
    char total_netto[50];
    char total_vat_value[50];
    char total_brutto[50];

    vat_rate = gtk_entry_get_text(input_product2_vat_rate);
    netto = gtk_editable_get_chars(input_product2_netto, 0, -1);

    if (strcmp(vat_rate, "-") == 0) {
        vat_rate = "0";
    }

    vat_rate_float = atof(vat_rate);
    netto_float = atof(netto);
    total_netto_2 = netto_float;
    vat_float = netto_float * vat_rate_float / 100;
    total_vat_2 = vat_float;
    total_float = netto_float + vat_float;
    total_brutto_2 = total_float;
    snprintf(vat, sizeof(total), "%.2f", vat_float);
    snprintf(total, sizeof(total), "%.2f", total_float);
    snprintf(total_netto, sizeof(total_netto), "%.2f", total_netto_1 + total_netto_2);
    snprintf(total_vat_value, sizeof(total_vat_value), "%.2f", total_vat_1 + total_vat_2);
    snprintf(total_brutto, sizeof(total_brutto), "%.2f", total_brutto_1 + total_brutto_2);
    gtk_entry_set_text(input_product2_vat_value, vat);
    gtk_entry_set_text(input_product2_brutto, total);
    gtk_entry_set_text(input_total_netto, total_netto);
    gtk_entry_set_text(input_total_vat_value, total_vat_value);
    gtk_entry_set_text(input_total_brutto, total_brutto);
    gtk_entry_set_text(input_total, total_brutto);
}

void on_input_product2_vat_rate_changed
    (GtkEntry *input_product2_vat_rate, GtkEditable *input_product2_netto)
{
    on_input_product2_netto_changed(input_product2_netto, input_product2_vat_rate);
}
// PRODUCT2 CHANGES

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
