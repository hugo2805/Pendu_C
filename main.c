#include <stdio.h>
#include <stdlib.h>
#define TAILLE 7
#define ERREUR 8

int main()
{
    char tab_base1[TAILLE] = {'I','P','H','O','N','E'};
    char tab_base2[TAILLE] = {'i','p','h','o','n','e'};
    char tab_affiche[TAILLE]= {'-','-','-','-','-','-'};
    char tab_faux[ERREUR]= {'-','-','-','-','-','-','-'};
    char car_prop;
    int i,j;
    int essai=1;
    int faux;

    printf("Bienvenue dans cette version du pendu en C\n");
    printf("Le mot que vous devez trouver contient %d lettres\n",TAILLE-1);

    while (tab_affiche != tab_base1 || faux < 7) {

    printf("|| ESSAI No : %d ||\n", essai);
    printf("Vous avez des essaye : %s\n", tab_faux);
    printf("==========================================================\n");
    printf("%s\n",tab_affiche);
    printf("==========================================================\n\n");
    printf("Pour proposer un caractere, entrez le dans le champ suivant : \n");
    scanf("%c",&car_prop);
    for (i=0;i<7;i++)
    {
        if (car_prop == tab_base1[i] || car_prop == tab_base2[i] )
            {
                tab_affiche[i]=tab_base1[i];
                printf("Bravo vous avez trouve une Lettre\n");

            }
            else
            {
                printf("Dommage essayez encore !\n");
                faux += 1;
                tab_faux[j]= car_prop;
            }

    }

    essai++;
    j++;

    }




    return 0;
}


