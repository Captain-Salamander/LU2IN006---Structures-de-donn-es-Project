/*
Alexander BAKALOV 21105567
Alexander Dimanachki 21112989
*/

#include"Graphe.h"

/*Creation et Liberation*/
/*Creation Arete*/
Arete* creerArete(int u, int v){
    Arete *a = (Arete*)malloc(sizeof(Arete));
    if(a==NULL){
        printf("Erreur malloc création Arete\n");
        return NULL;
    }
    a->u = u;
    a->v = v;

    return a;
}

/*Liberation Arete*/
void libererArete(Arete *a){
    if(a==NULL){
        printf("Arete deja libérée\n");
        return;
    }

    free(a);
}

/*Creation Cellule_arete*/
Cellule_arete* creerCellule_arete(Arete *a){
    if(a==NULL){
        printf("Impossible de creer Cellule_arete pour arete qui n'existe pas\n");
        return NULL;
    }

    Cellule_arete* c = (Cellule_arete*)malloc(sizeof(Cellule_arete));
    if(c==NULL){
        printf("Erreur malloc creation Cellule_arete\n");
        return NULL;
    }

    c->a = a;
    c->suiv = NULL;

    return c;
}

/*Liberation Cellule_arete*/
void libererCellule_Arete(Cellule_arete *c){
    if(c==NULL){
        printf("Cellule_arete deja libérée\n");
        return;
    }

    c->a = NULL;
    c->suiv = NULL;

    free(c);
}

/*Creation Commod (Pas un pointeur!)*/
Commod creerCommod(int e1, int e2){
    Commod C;

    C.e1 = e1;
    C.e2 = e2;

    return C;
}

/*Creation Sommet*/
Sommet* creerSommet(int num, double x, double y){
    Sommet* s = (Sommet*)malloc(sizeof(Sommet));
    if(s==NULL){
        printf("Erreur malloc création sommet\n");
        return NULL;
    }
    s->num = num;
    s->x = x;
    s->y = y;
    s->L_voisin = NULL;

    return s;
}

/*Liberation Sommet*/
void libererSommet(Sommet *s){
    if(s==NULL){
        printf("Sommet deja libere\n");
        return;
    }

    s->L_voisin = NULL;
    free(s);
}

/*Creation Graphe*/
Graphe* creerGraphe(Reseau* r){
    if(r == NULL){
        printf("Impossible de creer Graphe a partir d'un reseau qui n'existe pas\n");
        return NULL;
    }

    Graphe *g = (Graphe*)malloc(sizeof(Graphe));
    if(g==NULL){
        printf("Erreur malloc création Graphe\n");
        return NULL;
    }

    /*Initialisation des variables de g*/
    g->nbsom = 0;
    g->gamma = r->gamma;
    g->nbcommod = 0;

    g->T_som = (Sommet**)malloc(sizeof(Sommet*) * r->nbNoeuds);
    if(g->T_som == NULL){
        printf("Erreur malloc T_som création Graphe\n");
        free(g);
        return NULL;
    }

    g->T_commod = (Commod*)malloc(sizeof(Commod) * nbCommodites(r));
    if(g->T_commod == NULL){
        printf("Erreur malloc T_commod création Graphe\n");
        free(g->T_som);
        free(g);
        return NULL;
    }

    /*Boucle qui parcours tous les noeuds du Reseau*/
    CellNoeud *cr = r->noeuds;
    Sommet* s;
    for(int i=0; i<(r->nbNoeuds); i++){
        /*Creation des sommets*/
        s = creerSommet(i, cr->nd->x, cr->nd->y);
        g->T_som[i] = s;
        
        /*Mise a jour aretes*/
            /*Boucle passant par tous les voisins du noeud*/
        /*Boucle passant par toutes les commodites du Reseau*/

        cr = cr->suiv;
    }

    return g;
}