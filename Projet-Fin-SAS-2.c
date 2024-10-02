#include<stdio.h>
#define n1 1000
#define n2 30

// typedef struct 
// {
//     char nom[n2];
//     char prenom[n2];
//     char telephone[10];
//     int age;
//     char stuts[4][7];
//     char ID;
//     Date date;
// }reservation;

// typedef struct 
// {
//     int jour;
//     int mois;
//     int annee;
// }Date;

void Menu();
int j=0;

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    printf("--------------MENU--------------\n");
    printf("   1.Ajouter une reservation.\n");
    printf("   2.Modifier une reservation.\n");
    printf("   3.Supprimer une reservation.\n");
    printf("   4.Afficher les details d'une reservation.\n");
    printf("   5.Tri des reservations.\n");
    printf("   6.Recherche des réservations.\n");
    printf("   7.Statistiques.\n");
    printf("   7.Afficher la liste.\n");
    printf("   7.Sortir.\n");
}
