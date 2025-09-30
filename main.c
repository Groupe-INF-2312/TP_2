#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* createNode(int val) {
    Node *n = (Node*) malloc(sizeof(Node));
    n->data = val;
    n->prev = n->next = n;
    return n;
}

void afficherListe(Node *head) {
    if(head == NULL) return;
    Node *tmp = head;
    do {
        printf("%d <-> ", tmp->data);
        tmp = tmp->next;
    } while(tmp != head);
    printf("(retour tete)\n");
}

Node* insererTete(Node *head, int val) {
    Node *nn = createNode(val);
    if(head == NULL) return nn;
    Node *dernier = head->prev;
    nn->next = head;
    nn->prev = dernier;
    head->prev = nn;
    dernier->next = nn;
    return nn;
}

Node* insererQueue(Node *head, int val) {
    Node *nn = createNode(val);
    if(head == NULL) return nn;
    Node *dernier = head->prev;
    nn->next = head;
    nn->prev = dernier;
    dernier->next = nn;
    head->prev = nn;
    return head;
}

int main() {
    Node *head = NULL;

    head = insererTete(head, 10);
    head = insererQueue(head, 20);
    head = insererTete(head, 5);
    head = insererQueue(head, 30);

    printf("Liste doublement chainee circulaire : ");
    afficherListe(head);

    return 0;
}
