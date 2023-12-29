# projet_SE
1-les structures de données à utiliser :

1/-Matrices B, C, A :


B (n1 * m1) : Matrice contenant les valeurs aléatoires pour la première matrice.

C (n2 * m2) : Matrice contenant les valeurs aléatoires pour la deuxième matrice.

A (n1 * m2) : Matrice résultante de la multiplication B * C.

2/-Tampon T :
Tampon de taille N pour stocker les résultats intermédiaires de la multiplication.
 
 3/-Mutex et Sémaphores :

pthread_mutex_t mutex; : Mutex pour assurer l'exclusion mutuelle lors de l'accès aux données partagées.

sem_t empty; : Sémaphore représentant les places vides dans le tampon.

sem_t full; : Sémaphore représentant les places remplies dans le tampon.

Chaque thread producteur calculera une ligne de la matrice résultante A et stockera les résultats dans le tampon T. Les threads consommateurs récupéreront les éléments du tampon T et les placeront dans la matrice résultante A au bon emplacement.

2-POUR PROTÉGER L'ACCÈS A CES DONNÉES PARTAGÉES ON UTILISE DES MÉCANISMES DE SYNCHRONISATION TELS QUE LES MUTEX ET LES SÉMAPHORES :


*) Mutex (pthread_mutex_t mutex) :Utilisez le mutex pour assurer l'exclusion mutuelle lors de l'accès aux données partagées. Cela signifie que lorsqu'un thread acquiert le mutex, aucun autre thread ne peut y accéder jusqu'à ce que le mutex soit libéré.


*) Sémaphores (sem_t empty et sem_t full) :
Utilisez les sémaphores pour gérer la synchronisation entre les threads producteurs et consommateurs. Le sémaphore empty indique le nombre de places vides dans le tampon, tandis que le sémaphore full indique le nombre de places remplies.


3) LES RISQUES SONT :

*)Conditions de concurrence :
Des conditions de concurrence peuvent se produire lorsqu'il y a un accès simultané aux données partagées par plusieurs threads sans la protection adéquate. Cela peut entraîner des résultats incorrects dans les calculs.

*)Deadlocks :
Un deadlock peut se produire si les threads ne sont pas correctement synchronisés. Par exemple, si un thread consommateur attend des données alors qu'aucun producteur ne produit, et vice versa, cela peut conduire à un blocage complet du programme.


*)Starvation :
La starvation peut se produire si l'un des types de threads (producteurs ou consommateurs) est favorisé, et l'autre type n'a jamais l'opportunité de s'exécuter. Cela peut résulter d'une mauvaise gestion des sémaphores ou de la planification des threads.


*)Problèmes de performance :
Une mauvaise gestion de la synchronisation peut entraîner une surcharge importante liée à l'acquisition et à la libération fréquentes de mutex, ce qui peut affecter les performances globales du programme.



*)Inversion de priorité :
L'inversion de priorité peut se produire lorsqu'un thread de priorité inférieure acquiert un verrou alors qu'un thread de priorité supérieure attend. Cela peut affecter les performances du système et la réactivité.


*)Dépassement de tampon :
Si la taille du tampon n'est pas correctement gérée par les sémaphores, il peut y avoir un dépassement de tampon, entraînant la perte de données ou des erreurs dans les résultats






