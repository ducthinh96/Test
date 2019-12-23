#include <stdio.h>

int hp, xp, lvl, choix=12, x, y;

//----------initialisation-----------------
void premier_tour();
void afficher_terrain();


int main()
{

    char bidon;
    
    premier_tour();
    printf("\n");
    
    //-------Menu choix------------
    while (choix != 0)
    {
        printf("--------------------------\n");
        printf("Que voulez-vous faire ?\n");
        printf("-1-Afficher terrain\n");
        printf("-2-Mouvement\n");
        printf("-3-Attaquer\n");
        printf("-4-Voir inventaire\n");
        printf("-5-Voir Fiche personnage\n");
        printf("-0-Quitter jeu\n");
        printf("Choix : ");
        scanf("%d", &choix);
        printf("--------------------------\n");
        
        if (choix >= 0 && choix < 6)
        {
            switch (choix)
            {
                case 1:
                    afficher_terrain();
                    break;
                case 0:
                    printf("Au revoir !\n");
                    break;
                default: 
                    printf("Choix invalide !\n");
                    break;
            }
        }
        else 
        {
            while ((bidon=getchar()) != '\n') ;
            printf("Saisie incorrecte !\n");
        }

    }

    return 0;

}

//-----------------------Premier Tour--------------------------
void premier_tour()
{
    int i, j;

    //----------------Saisie emplacement joueur1-----------------
    printf("\n");
    printf("Entrez l'emplacement du joueur : ");
    scanf("%d %d", &x, &y);
    printf("\n");

    y--;

    afficher_terrain();
}

//-----------------------Afficher Terrain--------------------------
void afficher_terrain()
{
    int i, j;

    //-------------Afficher terrain------------------
    for (i = 0; i < 11; i++)
    {
        printf(" %3d ", i);

        for (j = 0; j < 10; j++)
        {
            if (i == 0)
            {
                printf(" %d ", j+1);
            }//fin if
            else
            {
                if (i == x && j == y)
                {
                    printf("[X]");
                }//fin if
                else
                {
                    printf("[ ]");
                }//fin else
            }//fin else
        }//fin boucle for j

        printf("\n");
    }//fin boucle for i

}
