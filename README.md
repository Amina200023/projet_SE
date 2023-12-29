# projet_SE
1-les structures de données à utiliser :

1/-Matrices B, C, A :


-B (n1 * m1) : Matrice contenant les valeurs aléatoires pour la première matrice.

-C (n2 * m2) : Matrice contenant les valeurs aléatoires pour la deuxième matrice.

-A (n1 * m2) : Matrice résultante de la multiplication B * C.

2/-Tampon T :
Tampon de taille N pour stocker les résultats intermédiaires de la multiplication.
 
 3/-Mutex et Sémaphores :
pthread_mutex_t mutex; : Mutex pour assurer l'exclusion mutuelle lors de l'accès aux données partagées.
sem_t empty; : Sémaphore représentant les places vides dans le tampon.
sem_t full; : Sémaphore représentant les places remplies dans le tampon.
Chaque thread producteur calculera une ligne de la matrice résultante A et stockera les résultats dans le tampon T. Les threads consommateurs récupéreront les éléments du tampon T et les placeront dans la matrice résultante A au bon emplacement.

2-Pour protéger l'accès a ces données partagées on utilise des mécanismes de synchronisation tels que les mutex et les sémaphores :

*1) Mutex (pthread_mutex_t mutex) :Utilisez le mutex pour assurer l'exclusion mutuelle lors de l'accès aux données partagées. Cela signifie que lorsqu'un thread acquiert le mutex, aucun autre thread ne peut y accéder jusqu'à ce que le mutex soit libéré.
*2) Sémaphores (sem_t empty et sem_t full) :
Utilisez les sémaphores pour gérer la synchronisation entre les threads producteurs et consommateurs. Le sémaphore empty indique le nombre de places vides dans le tampon, tandis que le sémaphore full indique le nombre de places remplies.






