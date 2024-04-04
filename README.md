# LU2IN006 Structures de donnes Project
A faire: Exercice 6 et 7

Alexander BAKALOV 21105567
Alexander Dimanachki 21112989

Code pour rotation: Cours 6, page 24

Question 4.2
La fonction clef semble etre bien appropriée car toutes les clefs sont uniques et ne sont pas une valeur trop grande.

Question 6.1
Graphique: meilleurCourbesVitesseBurma.ps
Nous observons que l'execution du programme est rapide pour toutes les différentes structures.
Cependant, l'arbre quaternaire est plus lent que la liste et la table de hachage, qui eux s'exécutent en un temps similaire.
Nous pensons que la rapidité est dûe au fait que le reseau "00014_burma" contient peu de points, donc les bénéfices de la table de hachage ou de l'arbre ne sont pas visibles.
L'arbre quaternaire est en plus de cela plus lent car son implémentation prend plus de temps.

Question 6.4
Grapiques : meilleurCourbesVitesseListe.ps meilleurCourbesVitesseHachArbre.ps
Nous observons que lorsqu'il y a un grand nombre de points, l'utilisation d'un tableau de hachage ou d'un arbre quaternaire permettent une execution beaucoup plus rapide de la fonction de reconstitution que si nous utilisons une simple liste. 
En effet, les graphes nous montrent que reconstituer le reseau peut prendre plusieurs heures dans le cas de la liste, alors que quelques secondes suffissent dans le cas de la table de hachage, et la reconstitution est faite en moins d'une seconde dans le cas de l'arbre.
Cela correspond aux complexités attendues:
o(n²) pour la liste: 
    Nous parcourons tous les points de toutes les chaines, et pour chacun de ces points nous parcourons les noeuds du Reseau pour savoir si nous l'avons deja créé ou pas.
o(n/m) pour la table de hachage:
    La taille de la table de hachage (m) correspond au nombre de points maximal pouvant être créé (n). La complexité, dans le cas idéal serait donc o(1) mais nous rencontrons sûrement des collisions qui augmentent la complexité.
o(log4(n)) pour l'arbre:
    L'arbre quaternaire permet une recherche dichotomique qui permet de trouver un point très rapidement. Cela explique pourquoi l'efficacité relative de l'arbre augmente le plus il a de points dans le reseau.