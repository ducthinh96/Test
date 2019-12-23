#include <stdio.h>
#include <math.h>

int nb1, nb2;
int somme, soustraction, multiplication, quotient, reste, puissance;


main()

{
    printf("Entrez deux entiers : ");
    scanf("%d %d", &nb1, &nb2);

    somme = (nb1 + nb2);
    soustraction = (nb1 - nb2);
    multiplication = (nb1 * nb2);
    quotient = (nb1 / nb2);
    reste = (nb1%nb2);
    puissance = pow(2,2);

    printf("%d %d %d %d %d %d\n", somme, soustraction, multiplication, quotient, reste, puissance);

}

