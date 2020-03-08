#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#ifdef linux
# define clear  system("clear");
#elif APPLE_
# define clear system("clear");
#elif __WIN32__
#define clear system("cls");
#endif
struct Contact {
    char prenom[31], nom[31], phone_nbr[14];

};
unsigned int contact_nbr = 0;
struct Contact contact_list[900];
void saveContact () {
    FILE* save;
    save = fopen("anulaire.txt", "w");
    fprintf(save, "%s\n", contact_list[contact_nbr].nom);
    fprintf(save, "%s\n", contact_list[contact_nbr].prenom);
    fprintf(save, "%s", contact_list[contact_nbr].phone_nbr);
    fclose(save);
    contact_nbr++;
}
void ajouterContact () {
    clear
    printf(  "+----------------------------------"
           "\n| Nouveau contact"
           "\n+----------------------------------"
           "\n| Prenom    : ");
    scanf("%s", &contact_list[contact_nbr].prenom);
    printf(  "| Nom       : ");
    scanf("%s", &contact_list[contact_nbr].nom);
    printf(  "| Telephone : ");
    scanf("%s", &contact_list[contact_nbr].phone_nbr);
    saveContact();
}
/*void trier() {
    FILE* liste;
    liste = fopen("anulaire.txt", "r");
    bool inFunction = false;
    char selection;
    printf(  "+----------+"
           "\n|  Trier   |"
           "\n+----------+"
           "\n| (P)renom |"
           "\n| (N)om    |"
           "\n+----------+");
    scanf(" %c",&selection);
    switch(selection){
    case 'p':case 'P':

        break;
    case 'n':case 'N':

        break;
    default:{
        clear
        inFunction = true;
    }
    bool longeur_fichier = feof(liste);
    while (longeur_fichier) {
            if (mot[j] < mot[i]) {
                char swap = mot[j];
                mot[j] = mot[i];
                mot[i] = swap;
            }
            i++;
        }
    }
    if(inFunction)
        trier();
    }
    fclose(liste);
}*/
void menu (){
    clear
    char selection;
    bool inFunction = true;
    printf(  "+--------------+"
           "\n|   Annuaire   |"
           "\n+--------------+"
           "\n| (A)jouter    |"
           "\n| (L)ister     |"
           "\n| (R)echercher |"
           "\n| (T)rier      |"
           "\n| (Q)uitter    |"
           "\n+--------------+");
    scanf(" %c", &selection);
    switch (selection) {
    case 'a': case 'A':
        ajouterContact();
        clear
        break;
    case 'l': case 'L':
        break;
    case 'r': case 'R':
        break;
    case 't': case 'T':
        //trier();
        break;
    case 'q': case 'Q':
        inFunction = false;
        break;
    }
    if(inFunction)
       menu();
}
void onInit() {
    FILE* load;
    load = fopen("anulaire.txt", "r");
    if (!load)
        load = fopen("anulaire.txt", "w");
    while (!feof(load)) {
        fscanf(load, "%s\n", &contact_list[contact_nbr].nom);
        fscanf(load, "%s\n", &contact_list[contact_nbr].prenom);
        if (feof(load))
            fscanf(load, "%s", &contact_list[contact_nbr].phone_nbr);
        else
            fscanf(load, "%s\n", &contact_list[contact_nbr].phone_nbr);
    contact_nbr++;
    }
    fclose(load);
}

void saveContactList() {
    FILE* save;
    save= fopen("anulaire.txt","w");
    unsigned int i=0;
    while (i < contact_nbr){
        fprintf(save, "%s\n", contact_list[i].nom);
        fprintf(save, "%s\n", contact_list[i].prenom);
        if (i == contact_nbr)
            fprintf(save, "%s", contact_list[i].phone_nbr);
        else
            fprintf(save, "%s\n", contact_list[i].phone_nbr);
        i++;
    }
    fclose(save);
}
int main()
{
    onInit();
    menu();
    saveContactList();
    return 0;
}
