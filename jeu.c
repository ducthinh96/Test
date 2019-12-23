#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int hp = 50, xp = 0, xpmax = 10, lvl = 1, choix=12, x, y, weapon_dmg = 0, armor_def = 0;
int atk = 1, def = 1;
int ennemy_atk, ennemy_def;
char weapon[30] = "Bâton en bois", armor[30] = "Armure en tissu", random_ennemy[30];

//----------initialisation-----------------
void premier_tour();
void afficher_terrain();
void voir_inventaire();
void init_obj();
void fiche_personnage();
void rand_ennemy();


int main()
{

    char bidon;

    init_obj();
    premier_tour();
    printf("\n");
    
    //-------Menu choix------------
    while (choix != 0)
    {
        printf("--------------------------\n");
        printf("Que voulez-vous faire ?\n");
        printf("-1-Afficher terrain\n");
        printf("-2-Mouvement\n");
        printf("-3-Fouiller\n");
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
                case 3:
                    rand_ennemy();
                    break;
                case 4:
                    voir_inventaire();
                    break;
                case 5:
                    fiche_personnage();
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
    afficher_terrain();

    printf("\n");
    printf("Entrez l'emplacement du joueur (x y) : ");
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

//--------------Voir inventaire-------------
void voir_inventaire()
{
    printf("Armes/Armures \n");
    printf("Arme : %s\n", weapon);
    printf("+%d Atk\n", weapon_dmg);
    printf("Armure : %s\n", armor);
    printf("+%d Def\n", armor_def);
}

//-----------Initialisation objets----------
void init_obj()
{
    int dif;

    //----init weapon----
    if ((dif = strncmp(weapon,"Bâton en bois", 30)) == 0)
    {
        weapon_dmg = 1 ;
    }

    //-----init armor----
    if ((dif = strncmp(armor,"Armure en tissu", 30)) == 0)
    {
        armor_def = 1;
    }

}

//-------------Afficher fiche personnage---------
void fiche_personnage()
{
    printf("Niveau : %d\n", lvl);
    printf("XP : %d/%d\n", xp, xpmax);
    printf("Attaque : %d\n", atk + weapon_dmg);
    printf("Défense : %d\n", def + armor_def);
}

//-------------Ennemi aléatoire---------------
void rand_ennemy()
{
    int r;

    srand(time(NULL)); 

    r = rand() %100;

    if (r >= 0 && r <= 50)
    {
        strcpy(random_ennemy,"Gobelin faiblard");
        ennemy_atk = 1;
        ennemy_def = 1;
    }
    else
    {
        strcpy(random_ennemy,"Loup maigre");
        ennemy_atk = 2;
        ennemy_def = 1;
    }

    printf("Un ennemi vous attaque : %s (Atk : %d, Def : %d)\n", random_ennemy, ennemy_atk, ennemy_def);
}