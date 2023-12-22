#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int valeur;
    struct ListNode* suivant;
} ListNode;

typedef struct TreeNode {
    int valeur;
    struct TreeNode* g;
    struct TreeNode* d;
} TreeNode;

void printList(ListNode* racine);
void insertEnd(ListNode* racine, int valeur) ;
ListNode* insertBeginning(ListNode* racine, int valeur) ;
ListNode* insertMiddle(ListNode* racine, int valeur, int position) ;
void deleteNode(ListNode* racine, int valeur);
int searchNode(ListNode* racine, int valeur);

TreeNode* newNode(int valeur) ;
TreeNode* insert(TreeNode* racine, int valeur) ;
void inorder(TreeNode* racine) ;
