#include <stdio.h>
#include <stdlib.h>

// Structure pour un élément de la liste doublement chaînée
typedef struct Liste {
    int nombre;
    struct Liste* precedant;
    struct Liste* suivant;
} Liste;

// Fonction pour créer un nouvel élément
Liste* creerElement(int nombre) {
    Liste* nouvelElement = (Liste*) malloc(sizeof(Liste));
    if (nouvelElement == NULL) {
        printf("Erreur d'allocation mémoire !\n");
        exit(1);
    }
    nouvelElement->nombre = nombre;
    nouvelElement->precedant = NULL;
    nouvelElement->suivant = NULL;
    return nouvelElement;
}

// Insertion triée
void insererTrie(Liste** tete, int nombre) {
    Liste* nouvelElement = creerElement(nombre);
    Liste* courant = *tete;

    // Cas 1 : liste vide
    if (*tete == NULL) {
        *tete = nouvelElement;
        return;
    }

    // Cas 2 : insérer avant la tête
    if (nombre <= (*tete)->nombre) {
        nouvelElement->suivant = *tete;
        (*tete)->precedant = nouvelElement;
        *tete = nouvelElement;
        return;
    }

    // Cas 3 : insertion au milieu ou à la fin
    while (courant->suivant != NULL && courant->suivant->nombre < nombre) {
        courant = courant->suivant;
    }

    nouvelElement->suivant = courant->suivant;
    if (courant->suivant != NULL) {
        courant->suivant->precedant = nouvelElement;
    }
    nouvelElement->precedant = courant;
    courant->suivant = nouvelElement;
}

// Affichage de la liste
void afficherListe(Liste* tete) {
    Liste* temp = tete;
    if (tete == NULL) {
        printf("La liste est vide.\n");
        return;
    }
    printf("\nListe finale triée : ");
    while (temp != NULL) {
        printf("%d ", temp->nombre);
        temp = temp->suivant;
    }
    printf("\n");
}

int main() {
    Liste* tete = NULL;
    int n, valeur;

    printf("Combien d'elements voulez-vous entrer ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez l'entier %d : ", i + 1);
        scanf("%d", &valeur);
        insererTrie(&tete, valeur);
    }

    afficherListe(tete);

    return 0;
}
