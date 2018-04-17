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
GtkComboBoxText *input_product1_qty;
GtkEntry        *input_product1_net;
GtkEntry        *input_product1_netto;
GtkEntry        *input_product1_vat_rate;
GtkEntry        *input_product1_vat_value;
GtkEntry        *input_product1_brutto;
GtkEntry        *input_product2_name;
GtkComboBoxText *input_product2_qty;
GtkEntry        *input_product2_net;
GtkEntry        *input_product2_netto;
GtkEntry        *input_product2_vat_rate;
GtkEntry        *input_product2_vat_value;
GtkEntry        *input_product2_brutto;
GtkEntry        *input_total_netto;
GtkEntry        *input_total_vat_value;
GtkEntry        *input_total_brutto;
GtkEntry        *input_total;
GtkTextBuffer   *model_faktura;
float total_netto_1;
float total_netto_2;
float total_vat_1;
float total_vat_2;
float total_brutto_1;
float total_brutto_2;

static void destroy(GtkWidget *widget, gpointer data);
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
void output_to_file(char* html);
char* read_template(char* location);
char* insert_date(char* html);
char* insert_total_netto(char* html);
char* insert_total_vat(char* html);
char* insert_total_brutto(char* html);
char* insert_total(char* html);
char* insert_currency(char* html);
char* replace_str(char* str, const char* orig, const char* rep);
char* insert_invoice_nr(char* html);
char* insert_product_1(char* html, char* html_part);
char* insert_product_2(char* html, char* html_part);
char* build_product_row(char* html_part, const char* name, const char* qty,
        const char* net, const char* netto, const char* vat_rate,
        const char* vat_value, const char* brutto);
void pdf_print();

