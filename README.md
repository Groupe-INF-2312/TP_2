# TP_2
TP du jeudi 25 septembre
#include <stdio.h>
#include <stdlib.h>

// Définition d'un nœud de la liste
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Création d’un nouveau nœud
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d’allocation mémoire\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insertion dans une liste doublement chaînée triée
void insertSorted(Node** head, int value) {
    Node* newNode = createNode(value);

    // Cas 1 : liste vide
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;

    // Cas 2 : insertion avant le premier élément (si plus petit)
    if (value < current->data) {
        newNode->next = current;
        current->prev = newNode;
        *head = newNode;
        return;
    }

    // Parcours pour trouver la position
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    // Insertion après current
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Affichage de la liste
void printList(Node* head) {
    Node* temp = head;
    printf("Liste : ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Programme principal
int main() {
    Node* head = NULL;

    insertSorted(&head, 10);
    insertSorted(&head, 5);
    insertSorted(&head, 20);
    insertSorted(&head, 15);
    insertSorted(&head, 7);

    printList(head);

    return 0;
}
