#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 7
#define ERREUR 8

char demande_char();
void affiche_instruction();
int verif(char);
int MaJ(int , int , int , char);

    char tab_base1[TAILLE] = {'I','P','H','O','N','E'};
    char tab_base2[TAILLE] = {'i','p','h','o','n','e'};
    char tab_affiche[TAILLE]= {'-','-','-','-','-','-'};
    char tab_faux[ERREUR]= {'-','-','-','-','-','-','-'};


int main()
{

    char car_prop = ' ';
    int isJuste;
    int j = 0;
    int essai=1;
    int faux= 7;

    printf("Bienvenue dans cette version du pendu en C\n");
    printf("Le mot que vous devez trouver contient %d lettres\n",TAILLE-1);

    while (tab_affiche != tab_base1)
        {
        fflush(stdin);
        affiche_instruction(essai);
        car_prop = demande_char();
        isJuste = verif(car_prop);
        faux = MaJ( isJuste, faux, j, car_prop);

        j++;
        essai++;

        }






    return 0;
}

void affiche_instruction(int essai)
{
    printf("|| ESSAI No : %d ||\n", essai);
    printf("Vous avez des essaye : %s\n", tab_faux);
    printf("==========================================================\n");
    printf("%s\n",tab_affiche);
    printf("==========================================================\n\n");
    printf("Pour proposer un caractere, entrez le dans le champ suivant : \n");
}

char demande_char()
{
    char car_prop;
   scanf("%c",&car_prop);

   return car_prop;
}

int verif(char car_prop)
{
    int i;

       for (i=0;i<strlen(tab_base1);i++)
    {
        if ((car_prop == tab_base1[i]) || (car_prop == tab_base2[i]) )
            {
                tab_affiche[i]=tab_base1[i];

               fflush(stdin);

               return 1;

            }

           if ((car_prop != tab_base1[i]) && (car_prop != tab_base2[i]) )
            {
               return 0;

            }

    }
}

int MaJ(int isJuste, int faux, int j, char car_prop)
{
    if (!isJuste)
        {
        faux --;
    tab_faux[j]= car_prop;
    printf("OUPS! Tentez encore votre chance !\n");


        }

        if (isJuste)
        {
            printf("Bravo !!!! Vous avez trouve une lettre!\n");
        }

        return faux;

}


