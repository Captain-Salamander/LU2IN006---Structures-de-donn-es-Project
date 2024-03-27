/*
Alexander BAKALOV 21105567
Alexander Dimanachki 21112989
*/

#include"ArbreQuat.h"
#include<time.h>

int main(int argc, char** argv){
    /*Calcul durée de chaque structure*/
    clock_t debut, fin;
    double temps;

    //Verification arguments
    if(argc<2){
        printf("Trop peu d'arguments\nUsage: %s nom_fichier\n", argv[0]);
        return 1;
    }

    //Lecture fichier
    FILE* f= fopen(argv[1], "r");
    if(f==NULL){
        printf("Erreur ouverture fichier %s\n", argv[1]);
        return 2;
    }
    Chaines* C = lectureChaines(f);
    fclose(f);
    /*Liste*/
    debut = clock();
    Reseau *R1 = reconstitueReseauListe(C);
    fin = clock();

    temps = (fin - debut)/CLOCKS_PER_SEC;

    printf("La liste a pris %fs pour etre reconstituée\n", temps);

    liberer_Reseau(R1);

    debut = clock();
    Reseau *R2 = reconstitueReseauHachage(C, 10);
    fin = clock();

    temps = (fin - debut)/CLOCKS_PER_SEC;

    printf("Le tableau de hachage de taille 10 a pris %fs pour etre reconstitué\n", temps);
    

    liberer_Reseau(R2);
    /*Arbre quaternaire*/
    debut = clock();
    Reseau *R3 = reconstitueReseauArbre(C);
    fin = clock();

    temps = (fin - debut)/CLOCKS_PER_SEC;

    printf("L'arbre a pris %fs pour etre reconstitué\n", temps);

    liberer_Reseau(R3);


    liberer_chaines(C);
}