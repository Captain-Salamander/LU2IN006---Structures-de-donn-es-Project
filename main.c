/*
Alexander BAKALOV 21105567
Alexander Dimanachki 21112989
*/

#include"ArbreQuat.h"
#include<time.h>

int main(int argc, char** argv){
    /*Calcul durée de chaque structure*/
    struct timespec debut, fin;
    double tempsListe, tempsHach, tempsArbre;

    //Verification arguments
    if(argc<3){
        printf("Trop peu d'arguments\nUsage: %s nom_fichier taille table de hachage\n", argv[0]);
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

    int m; /*Taille de la table de hachage*/
    sscanf(argv[2], "%d", &m);


    /*Liste*/
    clock_gettime(CLOCK_MONOTONIC, &debut);
    Reseau *R1 = reconstitueReseauListe(C);
    Reseau *R2 = reconstitueReseauListe(C);
    Reseau *R3 = reconstitueReseauListe(C);
    Reseau *R4 = reconstitueReseauListe(C);
    Reseau *R5 = reconstitueReseauListe(C);
    Reseau *R6 = reconstitueReseauListe(C);
    Reseau *R7 = reconstitueReseauListe(C);
    Reseau *R8 = reconstitueReseauListe(C);
    Reseau *R9 = reconstitueReseauListe(C);
    Reseau *R10 = reconstitueReseauListe(C);
    clock_gettime(CLOCK_MONOTONIC, &fin);

    tempsListe = (fin.tv_sec - debut.tv_sec)+(fin.tv_nsec - debut.tv_nsec)/1e6;

    liberer_Reseau(R1);
    liberer_Reseau(R2);
    liberer_Reseau(R3);
    liberer_Reseau(R4);
    liberer_Reseau(R5);
    liberer_Reseau(R6);
    liberer_Reseau(R7);
    liberer_Reseau(R8);
    liberer_Reseau(R9);
    liberer_Reseau(R10);

    /*Table de hachage*/
    clock_gettime(CLOCK_MONOTONIC, &debut);
    Reseau *R11 = reconstitueReseauHachage(C, m);
    Reseau *R12 = reconstitueReseauHachage(C, m);
    Reseau *R13 = reconstitueReseauHachage(C, m);
    Reseau *R14 = reconstitueReseauHachage(C, m);
    Reseau *R15 = reconstitueReseauHachage(C, m);
    Reseau *R16 = reconstitueReseauHachage(C, m);
    Reseau *R17 = reconstitueReseauHachage(C, m);
    Reseau *R18 = reconstitueReseauHachage(C, m);
    Reseau *R19 = reconstitueReseauHachage(C, m);
    Reseau *R20 = reconstitueReseauHachage(C, m);
    clock_gettime(CLOCK_MONOTONIC, &fin);

    tempsHach = (fin.tv_sec - debut.tv_sec)+(fin.tv_nsec - debut.tv_nsec)/1e6;
    
    liberer_Reseau(R11);
    liberer_Reseau(R12);
    liberer_Reseau(R13);
    liberer_Reseau(R14);
    liberer_Reseau(R15);
    liberer_Reseau(R16);
    liberer_Reseau(R17);
    liberer_Reseau(R18);
    liberer_Reseau(R19);
    liberer_Reseau(R20);

    /*Arbre quaternaire*/
    clock_gettime(CLOCK_MONOTONIC, &debut);
    Reseau *R21 = reconstitueReseauArbre(C);
    Reseau *R22 = reconstitueReseauArbre(C);
    Reseau *R23 = reconstitueReseauArbre(C);
    Reseau *R24 = reconstitueReseauArbre(C);
    Reseau *R25 = reconstitueReseauArbre(C);
    Reseau *R26 = reconstitueReseauArbre(C);
    Reseau *R27 = reconstitueReseauArbre(C);
    Reseau *R28 = reconstitueReseauArbre(C);
    Reseau *R29 = reconstitueReseauArbre(C);
    Reseau *R30 = reconstitueReseauArbre(C);
    clock_gettime(CLOCK_MONOTONIC, &fin);

    tempsArbre = (fin.tv_sec - debut.tv_sec)+(fin.tv_nsec - debut.tv_nsec)/1e6;

    printf("%d %f %f %f\n", m, tempsListe, tempsHach, tempsArbre);

    liberer_Reseau(R21);
    liberer_Reseau(R22);
    liberer_Reseau(R23);
    liberer_Reseau(R24);
    liberer_Reseau(R25);
    liberer_Reseau(R26);
    liberer_Reseau(R27);
    liberer_Reseau(R28);
    liberer_Reseau(R29);
    liberer_Reseau(R30);

    liberer_chaines(C);
}