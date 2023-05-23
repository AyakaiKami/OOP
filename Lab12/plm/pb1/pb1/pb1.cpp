#include "Contact.h"

void main()
{
    Agenda Xiaomi;
    Contact:Prieten Leon("Leon", "30.7.1996", "idk", "072221142");
    Xiaomi.Adauga(&Leon);
    Coleg Penis("Penis", "plm", "07coi");
    Xiaomi.Adauga(&Penis);
    std::string nume = "Penis";
    Xiaomi.Sterge(nume);
    Xiaomi.Show();
}