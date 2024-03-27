#!/bin/bash

make
rm time*
#Liste chainée
start_time=$(date +%s%N)
./ReconstitueReseau "00014_burma.cha" 1
end_time=$(date +%s%N)

nano_time=$(($end_time - $start_time))
echo "$nano_time" >> "timeliste.txt"

#Table de hachage
#Boucle définissant la taille de la table de hachage
for i in {1..10}; do
    start_time=$(date +%s%N)
    echo "$i" | ./ReconstitueReseau "00014_burma.cha" 2
    end_time=$(date +%s%N)

    nano_time=$(($end_time - $start_time))
    echo "$i $nano_time" >> "timehachage.txt"
done

start_time=$(date +%s%N)
./ReconstitueReseau "00014_burma.cha" 3
end_time=$(date +%s%N)

nano_time=$(($end_time - $start_time))
echo "Temps pris pour arbrequat $nano_time ns" >> "timearbre.txt"

#make clean