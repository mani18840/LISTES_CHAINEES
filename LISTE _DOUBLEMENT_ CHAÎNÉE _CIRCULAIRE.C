#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


typedef struct liste{
	
	int val;
	struct liste * suivant;
	struct liste * precedent;
		
}liste;

void inserertete(liste** l, int valeur){
	liste* nouveau = (liste*)malloc(sizeof(liste));
		nouveau -> val = valeur;
		
	if(*l == NULL){
		
	
	nouveau -> suivant = nouveau;
	nouveau -> precedent = nouveau;
	*l = nouveau;
	

		
//	return nouveau;
	
	}else{
	liste* t = (*l)-> precedent;
	
	nouveau->suivant = *l;
	nouveau-> precedent= t;
	
	t->suivant = nouveau;
	(*l)->precedent= nouveau;
	
	*l = nouveau;
			
		
	}
		
}

void insererfin(liste** l, int valeur){
	
	liste* nouveau = (liste*)malloc(sizeof(liste));
	nouveau->val = valeur;
	
	if(*l == NULL){
		
		
	nouveau->suivant = nouveau;
	nouveau->precedent = nouveau;
		
	*l = nouveau;
	
		
	}
	else{
	liste* tmp = (*l)-> precedent;
	
     tmp->suivant = nouveau;	
	nouveau->precedent = tmp;
	nouveau->suivant = (*l);
	(*l)->precedent = nouveau;
		
		
	}
	
	
	
}





 void afficher(liste * l){
 	if(l == NULL){
 		printf("la liste est vide \n");
 		return;
 		
	 }
	 liste * tmp = l;
	 
	 	do{
	 	printf("%d",tmp->val);
		 tmp = tmp->suivant;
		 		
		 }while(tmp != l);
		 
		 printf("\n");
		 
	 
 }






int main(int argc, char *argv[]) {
	
	liste* l = NULL;
	int n;
	// element de depart d ou l ajout ce fera!
	
	inserertete(&l, 50);
	inserertete(&l, 1);
	afficher(l);
	
	// ajout en tete de notre liste doublement chainee circulaire
	
	printf("entrer un chiffres\n");
	scanf("%d",&n);
	
	
 inserertete( &l, n);
 	
	afficher(l);
	
	printf("\n");
	
// ajout pesonel pour mieux illustrer la situation ces element sont ajouter en fin de liste et affiche a la suite !
	
	insererfin(&l,9);
	insererfin(&l,5);
	
	afficher(l);
	
	
	// ajout en fin de notre liste tous en conservant sa caracteristique circulaire !!
	
		printf("entrer un chiffres\n");
	scanf("%d",&n);
	
	
 insererfin( &l, n);
 	
	afficher(l);

	return 0;
}
