#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *suiv;
} Node;

// Fonction pour insérer en tête dans une liste circulaire
void insererTete(Node **l, int v) {
    Node *p = malloc(sizeof(Node));
    if (p == NULL) {
        fprintf(stderr, "Erreur allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    p->val = v;

    if (*l == NULL) {
        // Premier élément, il pointe sur lui-même
        p->suiv = p;
        *l = p;
    } else {
        // Trouver le dernier élément
        Node *tmp = *l;
        while (tmp->suiv != *l) {
            tmp = tmp->suiv;
        }
        // Insérer p avant *l
        p->suiv = *l;
        tmp->suiv = p;
        *l = p; // mise à jour de la tête
    }
}

// Fonction pour insérer en queue dans une liste circulaire
void insererQueue(Node **l, int v) {
    Node *p = malloc(sizeof(Node));
    if (p == NULL) {
        fprintf(stderr, "Erreur allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    p->val = v;

    if (*l == NULL) {
        // Premier élément
        p->suiv = p;
        *l = p;
    } else {
        Node *tmp = *l;
        while (tmp->suiv != *l) {
            tmp = tmp->suiv;
        }
        tmp->suiv = p;
        p->suiv = *l; // bouclage
    }
}

// Fonction pour afficher la liste circulaire
void afficher(Node *l) {
    if (l == NULL) {
        printf("Liste vide\n");
        return;
    }
    Node *tmp = l;
    do {
        printf("%d ", tmp->val);
        tmp = tmp->suiv;
    } while (tmp != l);
    printf("\n");
}

int main() {
    Node *l = NULL; // liste vide

    // Insertion en tête
    insererTete(&l, 10);
    insererTete(&l, 20);
    insererTete(&l, 30);

    printf("Liste apres insertion en tete : ");
    afficher(l);

    // Insertion en queue
    insererQueue(&l, 40);
    insererQueue(&l, 50);

    printf("Liste apres insertion en queue : ");
    afficher(l);

    return 0;
}
