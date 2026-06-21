# include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *create(int d){
    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        return NULL;
    }
    newnode->data = d;
    newnode->next = NULL;
    return newnode;
}

struct node *push(struct node *h, int d){
    struct node *newnode = create(d);
    newnode->next = h;
    h = newnode;
    return h;
}

struct node *pop(struct node *h){
    if(h == NULL){
        return NULL;
    }
    else {
        h = h->next;
        return h;
    }
}

void topper(struct node *h){
    if(h == NULL){
        printf("THE STACK IS EMPTY\n");
        return;
    }
    else{
        printf("THE TOP MOST VALUE IS %d\n", h->data);
    }
}

void display(struct node *h){
    if(h == NULL){
        printf("THE STACK IS EMPTY\n");
        return;
    }
    struct node *temp = h;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct node *head = NULL;
    head = push(head, 33);
    head = push(head, 36);
    head = push(head, 44);
    topper(head);
    display(head);
    return 0;
}
