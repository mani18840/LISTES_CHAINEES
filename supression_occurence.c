#include <stdio.h>
#include <stdlib.h>


typedef struct Cellule {
    float val;
    struct Cellule *suiv;
} Cellule;

typedef Cellule *Liste;


void AjouterFin(Liste *l, float valeur) {
    Cellule *nouveau = (Cellule*)malloc(sizeof(Cellule));
    nouveau->val = valeur;
    nouveau->suiv = NULL;
    
    if (*l == NULL) {
        *l = nouveau;
    } else {
        Cellule *courant = *l;
        while (courant->suiv != NULL) {
            courant = courant->suiv;
        }
        courant->suiv = nouveau;
    }
}


void AfficherListe(Liste l) {
    Cellule *courant = l;
    printf("Liste : ");
    while (courant != NULL) {
        printf("%f ", courant->val);
        courant = courant->suiv;
    }
    printf("\n");
}

void LibererListe(Liste *l) {
    Cellule *courant = *l;
    Cellule *temp;
    
    while (courant != NULL) {
        temp = courant;
        courant = courant->suiv;
        free(temp);
    }
    *l = NULL;
}

int main() {
    Liste l = NULL, nouveau = NULL, temp;
    int n, i;
    float val_supp;
   
    printf("Nombre d'éléments : ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) {
        printf("Valeur %d : ", i);
        scanf("%f", &val_supp);
        AjouterFin(&l, val_supp);
    }
    
    printf("Valeur à supprimer : ");
    scanf("%f", &val_supp);
    
    
    Cellule *courant = l;
    l = NULL; 
    
    while (courant != NULL) {
        if (courant->val != val_supp) {
            AjouterFin(&l, courant->val);
        }
        temp = courant;
        courant = courant->suiv;
        free(temp); // Libère l'ancienne cellule
    }
    
    AfficherListe(l);
    LibererListe(&l);
    
    return 0;
}