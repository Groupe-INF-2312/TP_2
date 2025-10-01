#include <stdio.h>
#include <stdlib.h>

typedef struct noeud {
    int info;
    struct noeud *next;
} cell, *liste;

liste newlist();
liste ins(int);
void afficher(liste);

//EX4: insertion en tete et en queue dans un liste simple chainee circulaire
//1. insertion en tete
liste instete(int v, liste tete){
    cell *tmp = ins(v);
    if(tete == NULL){
        tmp->next = tmp;
        return tmp;
    }
    cell *cou = tete;
    while(cou->next != tete){
        cou = cou->next;
    }
    cou->next = tmp;
    tmp->next = tete;
    return tmp;  // new head
}

//2. insertion en queue
liste insfin(int v, liste l){
    if(l == NULL){
        return instete(v, l);
    }
    cell *tmp = ins(v);
    cell *cou = l;
    while(cou->next != l){
        cou = cou->next;
    }
    cou->next = tmp;
    tmp->next = l;
    return l;  // head unchanged
}

liste ins(int v){
    cell *tmp = (cell*)malloc(sizeof(cell));
    if(tmp == NULL){
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    tmp->info = v;
    tmp->next = NULL;
    return tmp;
}

void afficher(liste tete){
    printf("LISTE: ");
    if(tete == NULL){
        printf("Liste vide!\n");
        return;
    }
    cell *p = tete;
    do{
        printf("%d -> ", p->info);
        p = p->next;
    }while(p != tete);
    printf("(back to head)\n");
}

liste newlist(){
    return NULL;
}

int main(){
    liste l = newlist();
    int choix, v, n, i;
    do{
        printf("\n======= MENU =======\n");
        printf("1. Ajouter en tete\n");
        printf("2. Ajouter en queue\n");
        printf("0. Quitter\nChoix: ");
        scanf("%d", &choix);
        switch(choix){
            case 1:
                printf("Entrer le nombre d'element(s) : ");
                scanf("%d", &n);
                printf("Entrer le(s) element(s):\n");
                for(i = 0; i < n; i++){
                    scanf("%d", &v);
                    l = instete(v, l);
                    afficher(l);
                }
                break;
            case 2:
                printf("Entrer le nombre d'element(s) : ");
                scanf("%d", &n);
                printf("Entrer le(s) element(s):\n");
                for(i = 0; i < n; i++){
                    scanf("%d", &v);
                    l = insfin(v, l);
                    afficher(l);
                }
                break;
            case 0:
                printf("Fin\n");
                break;
            default:
                printf("Choix invalide!\n");
                break;
        }
    }while(choix != 0);
    return 0;
}