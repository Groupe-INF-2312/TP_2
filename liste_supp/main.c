#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Création d’un nouveau nœud
Node* createNode(int val) {
    Node* n = (Node*) malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
    return n;
}

// Affichage de la liste
void afficherListe(Node *head) {
    Node *tmp = head;
    while(tmp != NULL) {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

// Suppression des occurrences
Node* supprimerOcc(Node *head, int x) {
    Node *tmp = head, *prec = NULL;
    while(tmp != NULL) {
        if(tmp->data == x) {
            Node *del = tmp;
            if(prec == NULL) {
                head = tmp->next;
            } else {
                prec->next = tmp->next;
            }
            tmp = tmp->next;
            free(del);
        } else {
            prec = tmp;
            tmp = tmp->next;
        }
    }
    return head;
}

int main() {
    Node *head = NULL, *last = NULL;
    int n, val, x;

    printf("Nombre d’elements : ");
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        printf("Element %d : ", i+1);
        scanf("%d", &val);
        Node *nn = createNode(val);
        if(head == NULL) head = nn;
        else last->next = nn;
        last = nn;
    }

    printf("Liste initiale : ");
    afficherListe(head);

    printf("Donner la valeur a supprimer : ");
    scanf("%d", &x);

    head = supprimerOcc(head, x);

    printf("Liste apres suppression : ");
    afficherListe(head);

    return 0;
}
