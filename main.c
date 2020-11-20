#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define TAILLE 7
#define ERREUR 10

char demande_char();
void affiche_instruction();
int verif(char);
int MaJ(int , int , int , char);
void affiche_pendu();
void modifAffich(int);
void perdu(int);

    char tab_base1[TAILLE] = {'I','P','H','O','N','E'};
    char tab_base2[TAILLE] = {'i','p','h','o','n','e'};
    char tab_affiche[TAILLE]= {'-','-','-','-','-','-'};
    char tab_faux[ERREUR]= {'-','-','-','-','-','-','-','-','-'};

    char tab_dessin[10] [15] =
    {
        {'*','*','*','*','-','P','E','N','D','U','-','*','*','*','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}

    };

int main()
{

    char car_prop = ' ';
    int isJuste;
    int j = 0;
    int essai=1;
    int faux= 9;

    printf("Bienvenue dans cette version du pendu en C\n");
    printf("Le mot que vous devez trouver contient %d lettres\n",TAILLE-1);

    while (tab_affiche != tab_base1)
        {
        system("cls");
        fflush(stdin);
        affiche_instruction(essai);
        car_prop = demande_char();
        isJuste = verif(car_prop);
        faux = MaJ( isJuste, faux, j, car_prop);
        modifAffich(faux);
        if (isJuste == 0){j++;}
        perdu(faux);



        essai++;


        }






    return 0;
}

void affiche_instruction(int essai)
{
    printf("|| ESSAI No : %d ||\n", essai);
    printf("Vous avez des essaye : %s\n", tab_faux);
    printf("==========================================================\n");
    affiche_pendu();
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
    int verif;

       for (i=0;i<strlen(tab_base1);i++)
    {
        if ((car_prop == tab_base1[i]) || (car_prop == tab_base2[i]) )
            {
                tab_affiche[i]=tab_base1[i];

               fflush(stdin);
               verif = 1;



            }

           if ((car_prop != tab_base1[i]) && (car_prop != tab_base2[i]) )
            {
               verif = 0;

            }

            if (verif == 1)
            {
                return verif;
            }


    }
    return verif;
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

void affiche_pendu()
{
    int i_pen;
    int j_pen;
    for (i_pen=0;i_pen<10;i_pen++)
        {
        for (j_pen=0;j_pen<15;j_pen++)
        {
            printf("%c", tab_dessin[i_pen][j_pen]);
        }
            printf("\n");
        }

}

void modifAffich(int faux){
    switch(faux){
        case 8:
            tab_dessin[8][1]='=';
            tab_dessin[8][2]='=';
            tab_dessin[8][3]='=';
            tab_dessin[8][4]='=';
            tab_dessin[8][5]='=';
            tab_dessin[8][6]='=';
            tab_dessin[8][7]='=';
            break;
        case 7:
            tab_dessin[7][3]='|';
            tab_dessin[6][3]='|';
            tab_dessin[5][3]='|';
            tab_dessin[4][3]='|';
            tab_dessin[3][3]='|';
            tab_dessin[2][3]='|';
            tab_dessin[7][4]='|';
            tab_dessin[6][4]='|';
            tab_dessin[5][4]='|';
            tab_dessin[4][4]='|';
            tab_dessin[3][4]='|';
            tab_dessin[2][4]='|';
            break;
        case 6:
            tab_dessin[1][2]='_';
            tab_dessin[1][3]='_';
            tab_dessin[1][4]='_';
            tab_dessin[1][5]='_';
            tab_dessin[1][6]='_';
            tab_dessin[1][7]='_';
            tab_dessin[1][8]='_';
            tab_dessin[1][9]='_';
            tab_dessin[1][10]='_';
            tab_dessin[1][11]='_';
            tab_dessin[1][12]='_';
            break;
        case 5:
            tab_dessin[2][6]='/';
            tab_dessin[3][5]='/';
            break;
        case 4:
            tab_dessin[2][10]='|';
            break;
        case 3:
            tab_dessin[3][10]='0';
            break;
        case 2:
            tab_dessin[4][10]='|';
            break;
        case 1:
            tab_dessin[4][9]='/';
            tab_dessin[4][11]='\\';
            break;
        case 0:
            tab_dessin[5][9]='/';
            tab_dessin[5][11]='\\';
            break;


    }
}
void perdu(int faux)
{
    if (faux==0)
    {
        printf("VOUS AVEZ PERDU !\n");
    }
}


/*
***************
*  ___________*
*   || /   |  *
*   ||/    0  *
*   ||    /|\ *
*   ||    / \ *
*   ||        *
*   ||        *
* =======     *
***************

*/

