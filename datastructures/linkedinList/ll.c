#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void printlist(struct Node* list){
    while(list!=NULL){
        printf("%d ",list->data);
        list=list->next;
    }
}

int main(){
    struct Node* n1;
    struct Node* n2;
    struct Node* n3;
    n1=(struct Node*)malloc(sizeof(struct Node));
    n2=(struct Node*)malloc(sizeof(struct Node));
    n3=(struct Node*)malloc(sizeof(struct Node));

    n1->data=10;
    n1->next=n2;

    n2->data=20;
    n2->next=n3;

    n3->data=30;
    n3->next=NULL;

    printlist(n1);

    return 0;
}


// gcc -Wall ll.c -o ll.out 
// ./ll.out                 

// output
// 10 20 30 %