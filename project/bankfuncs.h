struct bank
{
    char name[20];
    int age;
    int pin;
    int balance;
};
struct bank customer[3];
int count;

void add_customer();
void display_all();
void display_customer_info();
void with_dep();

