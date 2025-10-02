#include <stdio.h>
#include <stdlib.h>

struct cellule {
    int info;
    struct cellule* next;
    struct cellule* prev;
};
struct cellule* createcellule(int info);
void AfficherListe(struct cellule* head);

//Exercice5: Insertion en tête et en queue dans une liste doublement chaîne circulaire 



//Fonction pour inserer un élément en tete de liste
void AjoutEntete(struct cellule** head_ref, int info) {
    struct cellule* newcellule = createcellule(info);
    if (*head_ref == NULL) {
        *head_ref = newcellule;
        return;
    }

    struct cellule* last = (*head_ref)->prev;
    newcellule->next = *head_ref;
    (*head_ref)->prev = newcellule;
    newcellule->prev = last;
    last->next = newcellule;
    *head_ref = newcellule;
}

//Fonction pour insérer un élément en queue
void AjoutEnQueue(struct cellule** head_ref, int info) {
    if (*head_ref == NULL) {
        AjoutEntete(head_ref, info);
        return;
    }


    struct cellule* newcellule = createcellule(info);

    struct cellule* last = (*head_ref)->prev;

    last->next = newcellule;
    newcellule->prev = last;
    newcellule->next = *head_ref;
    (*head_ref)->prev = newcellule;
}



//Menu principal
int main() {
    struct cellule* head = NULL;
    int i, n, info, choix;

    printf("Combien d'elements souhaitez vous dans votre liste? \n");
    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        printf("  Entrez le %de nombre : ", i + 1);
        scanf("%d", &info);
        AjoutEnQueue(&head, info);
    }

    printf("\nListe initiale creee avec succes \n");
    AfficherListe(head);


    // Menu interactif
    do {
        printf("\n-- MENU --\n");
        printf("Quelle operation souhaitez vous effectuer? \n");
        printf("1. Inserer un element en tete\n");
        printf("2. Inserer un element en queue\n");
        printf("3. Afficher la liste\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        if(choix ==1 ) {
                printf("Entrez la valeur a inserer en tete : ");
                scanf("%d", &info);
                AjoutEntete(&head, info);
                printf("Element %d insere en tete.\n", info);
                AfficherListe(head);
        }
        else if (choix ==2){
            printf("Entrez la valeur a inserer en queue : ");
                scanf("%d", &info);
                AjoutEnQueue(&head, info);
                printf("Element %d insere en queue.\n", info);
                AfficherListe(head);
        }
        else if (choix ==3){
            AfficherListe(head);
        }
        else if (choix==4) {
            printf("Fin du programme.\n");
            }
        else {
            printf("Choix invalide. Veuillez reessayer.\n");
        }

    } while (choix != 0);

    return 0;
}
struct cellule* createcellule(int info) {
    struct cellule* newcellule = (struct cellule*)malloc(sizeof(struct cellule));
    newcellule->info = info;
    newcellule->next = newcellule;
    newcellule->prev = newcellule;
    return newcellule;
}
//Fonction pour afficher la liste
void AfficherListe(struct cellule* head) {
    if (head == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    struct cellule* current = head;
    printf("Etat de la liste : Tete -> ");
    do {
        printf("%d <-> ", current->info);
        current = current->next;
    } while (current != head);

    printf(" (retour a la tete %d)\n", head->info);
}



