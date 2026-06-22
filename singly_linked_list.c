# include <stdio.h>    
# include <stdlib.h>    
struct node{
    int data;
    struct node* next;
};

struct node *createnode(int d){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = d;
    new->next = NULL;
    return new;
}

struct node *insertfirst(struct node *h, int d){
    struct node *new = createnode(d);
    if(new == NULL){
        return NULL;
    }
    new->next = h;
    h = new;
    return h;
}

struct node *insertlast(struct node *h, int d){
    struct node *new = createnode(d);
    if(h == NULL){
        return new;
    }
    struct node *temp = h;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new;
    return h;
}


struct node *insert_at_index(struct node* h, int d, int index){
    if(index <= 1){
        return insertfirst(h, d);
    }
    struct node *t = h;
    for(int i=1; i<index-1 && t->next!=NULL; i++){
        t = t->next;
    }
    if(t->next == NULL){
        return insertlast(h, d);
    }
    struct node *new = createnode(d);
    new->next = t->next;
    t->next = new;
    return h;
}


struct node *removefirst(struct node *h){
    if(h == NULL){
        return NULL;
    }
    h = h->next;
    return h;
}

struct node *removelast(struct node *h){
    if(h->next == NULL || h == NULL){
        return NULL;
    }
    struct node *temp = h;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return h;
}

struct node *remove_at_index(struct node *h, int index){
    if(h == NULL){
        return NULL;
    }
    if(index == 1){
        return removefirst(h);
    }

    struct node *t = h;
    for(int i=1; i<index-1 && t->next!=NULL; i++){
        t = t->next;
    }
    if(t->next == NULL){
        return removelast(h);
    }
    t->next = t->next->next;
    return h;
}


void display(struct node *h){
    struct node *t = h;
    if(t == NULL){
        printf("NO NODES IN THE LINKED LIST\n");
        return;
    }
    while(t!=NULL){
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main(){
    struct node *head = NULL;
    head = insertfirst(head, 25);
    head = insertfirst(head, 67);
    head = insert_at_index(head, 77, 2);
    head = insert_at_index(head, 3343, 1);
    head = insert_at_index(head, 11, 4);
    head = insert_at_index(head, 9999, 6);
    head = remove_at_index(head, 3);
    display(head);
    return 0;
}