GtkCalendar     *input_date;
GtkEntry        *input_invoice_nr;
GtkComboBoxText *input_currency;
GtkEntry        *input_seller_name;
GtkEntry        *input_seller_business;
GtkEntry        *input_seller_address;
GtkEntry        *input_seller_zip;
GtkEntry        *input_seller_city;
GtkComboBoxText *input_seller_country;
GtkEntry        *input_seller_nip;
GtkEntry        *input_buyer_name;
GtkEntry        *input_buyer_business;
GtkEntry        *input_buyer_address;
GtkEntry        *input_buyer_zip;
GtkEntry        *input_buyer_city;
GtkComboBoxText *input_buyer_country;
GtkEntry        *input_buyer_nip;
GtkEntry        *input_product1_name;
GtkEntry        *input_product1_qty;
GtkEntry        *input_product1_net;
GtkEntry        *input_product1_netto;
GtkEntry        *input_product1_vat_rate;
GtkEntry        *input_product1_vat_value;
GtkEntry        *input_product1_brutto;
GtkEntry        *input_product2_name;
GtkEntry        *input_product2_qty;
GtkEntry        *input_product2_net;
GtkEntry        *input_product2_netto;
GtkEntry        *input_product2_vat_rate;
GtkEntry        *input_product2_vat_value;
GtkEntry        *input_product2_brutto;
static void destroy(GtkWidget *widget, gpointer data);
char* insert_date(char* html);
void on_input_product1_net_changed
    (GtkEditable *input_product1_net, GtkComboBoxText *input_product1_qty);
void on_input_product1_qty_changed
    (GtkComboBoxText *input_product1_qty, GtkEditable *input_product1_net);
void on_input_product1_netto_changed
    (GtkEditable *input_product1_netto, GtkEntry *input_product1_vat_rate);
void on_input_product1_vat_rate_changed
    (GtkEntry *input_product1_vat_rate, GtkEditable *input_product1_netto);
void on_input_product2_net_changed
    (GtkEditable *input_product2_net, GtkComboBoxText *input_product2_qty);
void on_input_product2_qty_changed
    (GtkComboBoxText *input_product2_qty, GtkEditable *input_product2_net);
void on_input_product2_netto_changed
    (GtkEditable *input_product2_netto, GtkEntry *input_product2_vat_rate);
void on_input_product2_vat_rate_changed
    (GtkEntry *input_product2_vat_rate, GtkEditable *input_product2_netto);
