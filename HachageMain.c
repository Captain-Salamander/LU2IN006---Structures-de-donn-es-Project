/*
Alexander BAKALOV 21105567
Alexander Dimanachki 21112989
*/

#include"Hachage.h"

int main(){
    int cle, hach;
    for(double x=1; x<=10; x++){
        for(double y=1; y<=10; y++){
            cle = clef(x, y);
            hach = hachage(cle, 10);
            printf("x = %.2lf; y = %.2lf; clef = %d; hach = %d\n", x, y, cle, hach);
        }
    }
}