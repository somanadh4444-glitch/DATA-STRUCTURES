# include <stdio.h>
# define MAX_SIZE 6

int isempty(int *stack, int top){
    return top == -1;
}

int isfull(int *stack, int top){
    return top == MAX_SIZE-1;
}

void push(int *stack, int *top, int data){
    if(isfull(stack, *top)){
        printf("THE STACK IS EXHAUSTED\n");
        return;
    }
    else{
        *top = *top + 1;
        stack[*top] = data;
        printf("THE STACK IS:- \n");
        for(int i=0; i<=*top; i++){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void pop(int *stack, int *top){
    if(isempty(stack, *top)){
        printf("THE STACK IS EMPTY\n");
        return;
    }
    else{
        *top = *top - 1; //else *top--;
        printf("THE STACK IS:- \n");
        for(int i=0; i<=*top; i++){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void topper(int *stack, int *top){
    if(isempty(stack, *top)){
        printf("THE STACK IS EMPTY\n");
        return;
    }
    else if(isfull(stack, *top)){
        printf("THE STACK IS FULL, btw U CAN CONSIDER %d\n", stack[MAX_SIZE-1]);
        return;
    }
    else{
        printf("THE TOP MOST ELEMENT IS %d", stack[*top]);
    }
}
int main(){
    int arr[MAX_SIZE];
    int top = -1;
    push(arr, &top, 44);
    push(arr, &top, 33);
    push(arr, &top, 36);
    push(arr, &top, 67);
    
    
    topper(arr, &top);
    return 0;
}