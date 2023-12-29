# projet_SE
1͟-͟l͟e͟s͟ ͟s͟t͟r͟u͟c͟t͟u͟r͟e͟s͟ ͟d͟e͟ ͟d͟o͟n͟n͟é͟e͟s͟ ͟à͟ ͟u͟t͟i͟l͟i͟s͟e͟r͟ ͟:͟

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

  
  
2͟-͟P͟O͟U͟R͟ ͟P͟R͟O͟T͟É͟G͟E͟R͟ ͟L͟'͟A͟C͟C͟È͟S͟ ͟A͟ ͟C͟E͟S͟ ͟D͟O͟N͟N͟É͟E͟S͟ ͟P͟A͟R͟T͟A͟G͟É͟E͟S͟ ͟O͟N͟ ͟U͟T͟I͟L͟I͟S͟E͟ ͟D͟E͟S͟ ͟M͟É͟C͟A͟N͟I͟S͟M͟E͟S͟ ͟D͟E͟ ͟S͟Y͟N͟C͟H͟R͟O͟N͟I͟S͟A͟T͟I͟O͟N͟ ͟T͟E͟L͟S͟ ͟Q͟U͟E͟ ͟L͟E͟S͟ ͟M͟U͟T͟E͟X͟ ͟E͟T͟ ͟L͟E͟S͟ ͟S͟É͟M͟A͟P͟H͟O͟R͟E͟S͟ ͟:͟


*) Mutex (pthread_mutex_t mutex) :Utilisez le mutex pour assurer l'exclusion mutuelle lors de l'accès aux données partagées. Cela signifie que lorsqu'un thread acquiert le mutex, aucun autre thread ne peut y accéder jusqu'à ce que le mutex soit libéré.


*) Sémaphores (sem_t empty et sem_t full) :
Utilisez les sémaphores pour gérer la synchronisation entre les threads producteurs et consommateurs. Le sémaphore empty indique le nombre de places vides dans le tampon, tandis que le sémaphore full indique le nombre de places remplies.


3͟)͟ ͟L͟E͟S͟ ͟R͟I͟S͟Q͟U͟E͟S͟ ͟S͟O͟N͟T͟ ͟:͟

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






