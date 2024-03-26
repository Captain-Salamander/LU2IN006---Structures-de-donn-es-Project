/*
Alexander BAKALOV 21105567
Alexander Dimanachki 21112989
*/

#include"Chaine.h"

int main(int argc, char** argv){
    if(argc<2){
        printf("Trop peu d'arguments\nUsage: %s nom_fichier\n", argv[0]);
        return 1;
    }

    //Lecture fichier
    FILE* f1 = fopen(argv[1], "r");
    if(f1==NULL){
        printf("Erreur ouverture fichier %s\n", argv[1]);
        return 2;
    }

    Chaines* C = lectureChaines(f1);
    fclose(f1);

    //Ecriture fichier
    FILE *f2 = fopen("testEcriture.cha", "w");
    if(f2==NULL){
        printf("Erreur ouverture fichier %s\n", argv[1]);
        return 2;
    }

    ecrireChaines(C, f2);
    fclose(f2);

    //Creation fichier SVG
    afficheChainesSVG(C, "affichageChainesSVG");

    //Calcul longueur totale
    double longueur = longueurTotale(C);
    printf("Longueur totale = %.2lf\n", longueur);

    //Comptage de points
    int nbPoints = comptePointsTotal(C);
    printf("Nombre de points au total: %d\n", nbPoints);

    liberer_chaines(C);
}