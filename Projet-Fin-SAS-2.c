#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define n1 10000
#define n2 15



typedef struct 
{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct 
{
    char nom[n2];
    char prenom[n2];
    char telephone[10];
    int age;
    char status[10];
    char ID[5];
    Date date;
}reservation;

int Ajouter(reservation A[]);
int Mod_Sup(reservation A[]);
void Afficher(reservation A[]);
void Tri(reservation A[]);
void Recherche(reservation A[]);
void Statistique(reservation A[]);

void ID(reservation A[]);
void Status(reservation A[]);
void DATE(reservation A[]);
void cpy(char A[] ,char B[]);
int cmp(char A[] ,char B[]);
int len(char A[]);

void Menu();
int j=0;

int main()
{
    reservation patient[n1];
    int i,a1;
    Menu();

    do
    {
        printf("Choisir votre choix(7 pour reafficher la liste) : ");
        scanf("%d",&a1);

        switch (a1)
        {
        case 1:
            Ajouter(patient);
            break;





        case 2:
            Mod_Sup(patient);
            break;






        case 3:
            Afficher(patient);
            break;




        case 4:
            
            break;




        case 5:
            
            break;

        case 6:
            
            break;

        case 7:
            Menu();
            break;

        case 8:
            return 0;
            break;

        }
    } while (a1 != 0);
    

    return 0;
}

void Menu()
{
    printf("--------------MENU--------------\n");
    printf("   1.Ajouter une reservation.\n");
    printf("   2.Modifier ou Supprimer une reservation.\n");
    printf("   3.Afficher les details d'une reservation.\n");
    printf("   4.Tri des reservations.\n");
    printf("   5.Recherche des reservations.\n");
    printf("   6.Statistiques.\n");
    printf("   7.Afficher la liste.\n");
    printf("   8.Sortir.\n");
}

int Ajouter(reservation A[])
{
    char b[4],b1[11];
    int i,a,a1,a2,a3,a4,c,c1,c2,c3;
    printf("Saisir les information du patient : \n");
    printf("Nom : ");
    scanf(" %[^\n]s",A[j].nom);
    printf("Prenom : ");
    scanf(" %[^\n]s",A[j].prenom);

    // do
    // {
    //     printf("donner le nombre de telephone reel : ");
    //     scanf("%s",b1);
    //     for (int o = 0; o < 10; i++)
    //     {
    //         if (b1[o] < 48 || b1[o] > 57)
    //         {
    //             a = 0;
    //             break;
    //         }
            
    //     }
    //     if(a != 0)
    //     {
    //         if ((b1[0] != '0') || ((b1[1] != '7') && (b[1] != '6') && (b1[1] != '5')))
    //         {
    //             a = 0;
    //             break;
    //         }
    //         else if (len(b1) != 10)
    //         {
    //             a = 0;
    //             break;
    //         }
    //         else 
    //             cpy(A[j].telephone , b1);
    //             a = 1;
    //             break;
    //     }
    // } while (a == 0);
    printf("Age : ");
    scanf("%d",&A[j].age);

    Status(A);   
    ID(A);
    DATE(A);
    j++;
}

int Mod_Sup(reservation A[])
{
    char c[5],c1[n2],c2[n2],c3[11];
    int a1,i,c4,b1,b2,b3,a = 0,x;
    do
    {
        printf("\t====Menu====\n");
        printf("1.Modifier une reservation.\n");
        printf("2.Supprimer une reservation.\n");
        printf("3.Sortir.\n");
        printf("Choisir votre choix : ");
        scanf("%d",&a1);
        switch (a1)
        {
        case 1:
            printf("Saisir l'ID de patient a modifier : ");
            scanf(" %[^\n]s",c);
            for ( i = 0; i < j; i++)
            {
                if (cmp(A[i].ID ,c))
                {
                    printf("Le nouvelle nom : ");
                    scanf(" %[^\n]s",c1);
                    cpy(A[i].nom , c1);
                    printf("Nouvelle prenom : ");
                    scanf(" %[^\n]s",c2);
                    cpy(A[i].prenom , c1);
                    do
                    {
                        a = 1;
                        printf("Nouvelle telephone reel : ");
                        scanf("%s",c3);
                        for (int o = 0; o < 10; i++)
                        {
                            if (c3[o] < 48 || c3[o] > 57)
                            {
                                a = 0;
                                break;
                            }
                            
                        }
                        if(a != 0)
                        {
                            if ((c3[0] != '0') || ((c3[1] != '7') && (c3[1] != '6') && (c3[1] != '5')))
                            {
                                a = 0;
                                break;
                            }
                            else if (len(c3) != 10)
                            {
                                a = 0;
                                break;
                            }
                            else 
                                cpy(A[i].telephone , c3);
                        }
                    } while (a == 0);
                    

                    printf("Nouvelle Age : ");
                    scanf("%d",&c4);
                    A[i].age = c4;
                    printf("Saisire la nouvelle ststus :\n");
                    Status(A);
                    printf("La nouvelle date :\n");                  
                    DATE(A);
                }             
            }
            break;
        case 2:
            printf("Supprimer une reservation par reference :\n");
            for ( i = 0; i < j; i++)
            {
                if (cmp(A[i].ID ,c))
                {
                    j--;
                    for (int o = i; o < j-1; i++)
                    {
                        A[o] = A[o+1];
                    }
                    break;
                }             
            }
            break;
        case 3:
            return 0;
            break;
        }
    } while (a1 == 0);

}
void Afficher(reservation A[])
{
    printf("+---+--------+-------------------+-------------------+--------------+-----+------------+----------------------------+\n");
    printf("|   |---ID---|--------NOM--------|------PRENOM-------|--Telephone---|-AGE-|---Status---|---DATE : JOUR/MOIS/ANNEE---|\n");
    printf("+---+--------+-------------------+-------------------+--------------+-----+------------+----------------------------+\n");
    for (int i = 0; i < j; i++)
    {
        printf("| %-2d |  %-5s     %-15s     %-15s     %-10s    %-2d     %-8s            %2d/%2d/%4d          \n"
            ,i+1,A[i].ID,A[i].nom,A[i].prenom,A[i].telephone,A[i].age,A[i].status,A[i].date.jour,A[i].date.mois,A[i].date.annee);
        printf("+-------------------------------------------------------------------------------------------------------------------+\n");
    }
}

void Tri(reservation A[])
{
    reservation B;
    int c,a,b1,b2;
    printf("Les choix : \n");
    printf("1.Tri des réservations par Nom.\n");
    printf("2.Tri des réservations par date.\n");
    printf("3.Tri des réservations par statut (valide, reporte, annule, traite).\n");
    printf("Choisir votre choix : ");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        for (int i = 0; i < j-1; i++)
        {

            a = 1;
            for (int o = 0; o < j-i-1; i++)
            {
                if(cmp(A[o].nom,A[o+1].nom) > 0)
                {
                    B = A[o] ;
                    A[o] = A[o+1];
                    A[o+1] = B;
                    a = 0;
                }
            } 
        }        
        break;
    case 2 :
        break;
    case 3 :
        for (int i = 0; i < j-1; i++)
        {
            a = 1;
            for (int o = 0; o < j-i-1; i++)
            {
                if(cmp(A[o].status,A[o+1].status) > 0)
                {
                    B = A[o] ;
                    A[o] = A[o+1];
                    A[o+1] = B;
                    a = 0;
                }
            } 
        }      

        break;
    default:
        printf("Votre choix n'exist pas dans le menu.\n");
        Tri(A);
        break;
    }
    
}

void Recherche(reservation A[])
{
    reservation B;
    char b1[5],b2[n2];
    int c1,c2,c3;
    int c,a;
    printf("Les choix : \n");
    printf("1.Recherche d'une reservation par reference(ID).\n");
    printf("2.Recherche d'une reservation par nom.\n");
    printf("3.Recherche d'une réservation par date.\n");
    printf("Choisir votre choix : ");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        printf("Saisir le reference de resevation a rechercher : ");
        scanf("%s",b1);
        a = 0;
        for (int i = 0; i < j; i++)
        {
            if (cmp(A[i].ID,b1))
            {
                printf("Les information :\n");
                printf("Nom       : %s\n",A[i].nom);
                printf("Prenom    : %s\n",A[i].prenom);
                printf("Telephone : %s\n",A[i].telephone);
                printf("Age       : %d\n",A[i].age);
                printf("Status    : %s\n",A[i].status);
                printf("Reference : %s\n\n",A[i].ID);
                printf("Date      : %d/%d/%d\n",A[i].date.jour,A[i].date.mois,A[i].date.annee);
                a = 1;
            }
        }
        if (a != 1)
        {
            printf("Cette reservation n'existe pas dans la liste des reservation.\n");
        }
        break;
    case 2 :
        printf("Saisir le nom de resevation a rechercher : ");
        scanf("%s",b2);
        a = 0;
        for (int i = 0; i < j; i++)
        {
            if (cmp(A[i].nom,b2))
            {
                printf("Les information :\n");
                printf("Nom       : %s\n",A[i].nom);
                printf("Prenom    : %s\n",A[i].prenom);
                printf("Telephone : %s\n",A[i].telephone);
                printf("Age       : %d\n",A[i].age);
                printf("Status    : %s\n",A[i].status);
                printf("Reference : %s\n\n",A[i].ID);
                printf("Date      : %d/%d/%d\n\n",A[i].date.jour,A[i].date.mois,A[i].date.annee);
                a = 1;
            }
        }
        if (a != 1)
        {
            printf("Cette reservation n'existe pas dans la liste des reservation.\n");
        }
        break;
    case 3 :
        printf("Saisir la date de resevation a rechercher : \n");
        printf("Jour :");
        scanf("%d",c1);
        printf("Mois :");
        scanf("%d",c2);
        printf("Annee :");
        scanf("%d",c3);
        a = 0;
        for (int i = 0; i < j; i++)
        {
            if ((A[i].date.annee == c1) && (A[i].date.mois == c2) && (A[i].date.jour == c3))
            {
                printf("Les information :\n");
                printf("Nom       : %s\n",A[i].nom);
                printf("Prenom    : %s\n",A[i].prenom);
                printf("Telephone : %s\n",A[i].telephone);
                printf("Age       : %d\n",A[i].age);
                printf("Status    : %s\n",A[i].status);
                printf("Reference : %s\n\n",A[i].ID);
                printf("Date      : %d/%d/%d\n",A[i].date.jour,A[i].date.mois,A[i].date.annee);
                a = 1;
            }
        }
        if (a != 1)
        {
            printf("Cette reservation n'existe pas dans la liste des reservation.\n");
        }
        break;
    default:
        printf("Votre choix n'exist pas dans le menu.\n");
        Tri(A);
        break;
    }
}

void Statistique(reservation A[])
{
    int T[7] = {0,0,0,0,0,0,0};
    float S;
    for (int i = 0; i < j; i++)
    {
        if (A[i].age > 0 && A[i].age <= 18)
            T[0] += 1;
        else if (A[i].age >= 19 && A[i].age <= 35)
        {
            T[1] += 1;
        }
        else
            T[2] += 1;
        if (cmp(A[i].status,"valide"))
            T[3] += 1;
        if (cmp(A[i].status,"reporte"))
            T[4] += 1;
        if (cmp(A[i].status,"annule"))
            T[5] += 1;
        else 
            T[6] += 1;
    }
    S = (T[0]+T[1]+T[2])/j;
    printf("1.La moyenne d'age des patients ayant reserve est %d\n\n",S/j);
    printf("2.Affichage le nombre de patients par tranche d'age :\n");
    printf("Les patient d'age entre 0 et 18 ans  : %d\n",T[0]);
    printf("Les patient d'age entre 19 et 35 ans : %d\n",T[1]);
    printf("Les patient d'age plus grand 35 ans  : %d\n",T[2]);
    printf("le nombre total de reservations par status :\n");
    printf("Les valides  : %d\n",T[3]);
    printf("Les reportes : %d\n",T[4]);
    printf("Les annules  : %d\n",T[5]);
    printf("Les traites  : %d\n",T[6]);

}

void Status(reservation A[])
{
    int a;
    printf("Les types de la status :\n");
    printf("\t1.Valide.\n");
    printf("\t2.Reporte.\n");
    printf("\t3.Annule.\n");
    printf("\t4.Traite.\n");
    printf("Entrer la status : ");
    do 
    {
        scanf("%d",&a);
        switch (a)
        {
        case 1 :
            cpy(A[j].status , "valide");
            break;
        case 2 :
            cpy(A[j].status , "reporte");
            break;
        case 3 :
            cpy(A[j].status , "annule");
            break;
        case 4 :
            cpy(A[j].status , "traite");
            break;
        default:
            printf("Votre choix n'existe pas...Choix exacte : \n");
            a = 0;
            break;
        }
    
    } while (a == 0);
}
void DATE(reservation A[])    
{
    int a,c,c1,c2,c3;   
    do
    {
        a = 1;
        printf("la date de reservation : \n");
        
        do
        {
            printf("Saisir le mois : ");
            scanf("%d",&c1);
        }while((c1 <= 0) || (c1 > 12));
        do
        {
            printf("Entrer le jour : ");
            scanf("%d",&c2);
            if (c2 <= 0)
            {
                printf("Erreur...\n");
                a = 0;
                break;
            }
            else
            {
                switch (c1)
                {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    if (c2 <= 31)
                        a = 1;
                    else
                        a = 0;
                case 4: case 6: case 9: case 11: 
                    if (c2 <= 30)
                        a = 1;
                    else
                        a = 0;
                    break;
                case 2 :
                    if (c2 <= 29)
                        a = 1;
                    else
                        a = 0;
                    break;
                }
            }
        }while (a == 0);
        do
        {
            printf("Saisir l'annee du reservation : ");
            scanf("%d",&c3);
        } while (c3 < 2024 || c3 > 2025);
        c = 0;
        for (int o = 0; o < 20; o++)
        {
            if ((A[o].date.annee == c3) && (A[j].date.mois , c1) && (A[j].date.jour == c2))
            {
                c++;
                if (c == 11)
                {
                    printf("Les reservations pour cette date sont completes.\n");
                    printf("Choise une autre date pour la reservation.\n");
                    a = 0;
                    break;
                }   
            }   
        }
    } while (a == 0);
    A[j].date.jour = c2;
    A[j].date.mois = c1;
    A[j].date.annee = c3;
}
void ID(reservation A[])
{
    char b[4];
    int a,a1,a2,a3,a4;
    do
    {
        srand(time(0));
        a = 1;
        a1 = 'a' + rand() % 26;
        a2 = 'a' + rand() % 26;
        a3 = '0' + rand() % 10;
        a4 = '0' + rand() % 10;
        b[0] = a1;
        b[1] = a2;
        b[2] = a3;
        b[3] = a4;
        for ( int o = 0; o < j; o++)
        {
            if (cmp(A[o].ID , b))
            {
                a = 0;
                break;
            }
        }               
    } while (a == 0);
    cpy(A[j].ID , b);
}
void cpy(char A[] ,char B[])
{
    int i;
    for ( i = 0; i < n2; i++)
    {
        A[i] = B[i];
    }
}
int cmp(char A[] ,char B[])
{
    int i,a = 0;
    if (len(A) == len(B))
    {
        a = 1;
        for ( i = 0; i < len(A); i++)
        {
            if (A[i] != B[i])
            {
                a = 0;
                break;
            }
            
        }
        
    }
    return a;
}
int len(char A[])
{
    int i;
    for ( i = 0; i < n2; i++)
    {
        {
            if (A[i] == '\0')
            {
                break;
            }
        }
    }
    return i;
}






