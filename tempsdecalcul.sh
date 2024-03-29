#!/bin/bash

[ -f timedata.txt ] && rm timedata.txt

#Boucle définissant la taille de la table de hachage
for i in {1..50}; do
    ./main "00014_burma.cha" $i >> timedata.txt
done

#make clean