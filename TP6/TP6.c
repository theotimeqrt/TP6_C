#include <stdio.h>
#include <stdlib.h>
#include "TP6.h"

int main() {
    //créé la racine
    ListNode* racine = malloc(sizeof(ListNode));
    racine->suivant = NULL;
    racine->valeur = 0;

    insertEnd(racine, 1);
    insertEnd(racine, 2);
    racine = insertBeginning(racine, 100);
    racine = insertMiddle(racine, 200, 0);
    int position = searchNode(racine, 100) ;

    printList(racine);
    printf("et on trouve la position : %d \n", position); //0 si 1er

    // On passe aux arbres

    TreeNode* arbre = malloc(sizeof(TreeNode));
    arbre->valeur = 0;
    arbre->d = NULL;
    arbre->g = NULL;

    arbre = insert(arbre, 101);
    arbre = insert(arbre, 8);
    arbre = insert(arbre, 14);
    arbre = insert(arbre, 129);
    arbre = insert(arbre, 4);
    arbre = insert(arbre, 99);
    arbre = insert(arbre, 13);
    arbre = insert(arbre, 55);

    inorder(arbre);

    return 0;
}

void printList(ListNode* racine) { //fonction qui affiche la liste chainée
    while (racine != NULL) {
        printf("%d -> ", racine->valeur);
        racine = racine->suivant;
    }
    printf("NULL\n");
}

void insertEnd(ListNode* racine, int valeur) {
    ListNode* new = (ListNode*)malloc(sizeof(ListNode));
    new->valeur = valeur;
    new->suivant = NULL;

    if (racine == NULL) {
        racine = new;
    } else {
        while (racine->suivant != NULL) {
            racine = racine->suivant;
        }
        racine->suivant = new;
    }
}

ListNode* insertBeginning(ListNode* racine,int valeur) {
    ListNode* new = (ListNode*)malloc(sizeof(ListNode));
    new->valeur = valeur;
    new->suivant = racine;

    return new ;
}

ListNode* insertMiddle(ListNode* racine, int valeur, int position) { //position 0 pour début
    ListNode* new = (ListNode*)malloc(sizeof(ListNode));
    new->valeur = valeur;

    if (racine == NULL || position <= 0) { // Insérer au début si la liste est vide
        new->suivant = racine;
        return new;
    } else {

        // Trouve l'élément précédent à position spécifiée
        for (int i = 1; i < position && racine != NULL; i++) {
            racine = racine->suivant;
        }

        // Insére nouvel élément après l'élément trouvé
        if (racine != NULL) {
            new->suivant = racine->suivant;
            racine->suivant = new;
        }
    }
    return racine;
}

void deleteNode(ListNode* racine, int valeur) {

    ListNode* precedent = NULL;

    // Recherche élément à suppr et de celui avant
    while (racine != NULL && racine->valeur != valeur) {
        precedent = racine;
        racine = racine->suivant;
    }

    // Si élément trouvé, le supprimer
    if (racine != NULL) {
        if ( precedent == NULL) {
            // élément à supprimer en tête de liste
            racine = racine->suivant;
        } else {
            // élément à supprimer intérieur de la liste
            precedent->suivant = racine->suivant;
        }
        free(racine); //Libere celui supprimé, qui est décroché
    }
}

int searchNode(ListNode* racine, int valeur) {

    int position = 0; //position 0 est donc 1er position

    while (racine != NULL) {
        if (racine->valeur == valeur) {
            // Trouvé
            return position;
        }
        racine = racine -> suivant;
        position++;
    }

    // Non trouvé
    return 0;
    printf("Non trouvé");
}

TreeNode* newNode(int valeur) {
    TreeNode* new = (TreeNode*)malloc(sizeof(TreeNode));
    new->valeur = valeur;
    new->g = NULL;
    new->d = NULL;
    return new;
}

TreeNode* insert(TreeNode* racine, int valeur) {
    if (racine == NULL) { // Si racine vide
        return newNode(valeur);
    }

    if (valeur < racine->valeur) { 
        racine->g = insert(racine->g, valeur); // On continue dans sous arbre gauche si valeur plus petite
    }

    else if (valeur >= racine->valeur) {
        racine->d = insert(racine->d, valeur); // On continue dans sous arbre droit si valeur plus grande ou egale
    }

    return racine; 
}

void inorder(TreeNode* racine) {
    
    if (racine != NULL) {
        // Parcours sous-arbre gauche
        inorder(racine->g);

        printf("%d \n", racine->valeur);

        // Parcours sous-arbre droit
        inorder(racine->d);

        //printf("%d \n", racine->valeur);
    }
}
