// Doubly_queue.c

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "../data_dyno_type.h"

typedef struct Doubly_node{
    struct Doubly_node* next, *prev;
    Data_dyno_type data;
} Doubly_node;

typedef struct Doubly_queue{
    Doubly_node* front, *rear;
} Doubly_queue;

Doubly_node* newDoubly_node(Data_dyno_type data){
    Doubly_node* new = (Doubly_node*)malloc(sizeof(Doubly_node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

Doubly_queue* createDoubly_queue(){
    Doubly_queue* q = (Doubly_queue*)malloc(sizeof(Doubly_queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int is_emptyDoubly_queue(Doubly_queue *q){
    if(q->rear == NULL || q->front == NULL)
        return 1;

    return 0;
}

int lenDoubly_queue(Doubly_queue *q){
    if(is_emptyDoubly_queue(q) == 1)
        return 0;

    else{
        int len = 0;
        Doubly_node* temp = q->front;
        while(temp){
            len += 1;
            temp = temp->next;
        }
        return len;
    }
}

void enDoubly_queue(Doubly_queue* q, Data_dyno_type data){
    Doubly_node* new = newDoubly_node(data);
    if(q->front == NULL){
        q->front = new;
        q->rear = new;
        return;
    }
    
    q->rear->next = new;
    new->prev = q->rear;
    q->rear = new;
}

void deDoubly_queue(Doubly_queue* q){
    if(is_emptyDoubly_queue(q) == 1)
        return;

    Doubly_node* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear == NULL;

    free(temp);

}

int searchDoubly_queue(Doubly_queue* q, Data_dyno_type data){ // rewrite if u want to use it
    Doubly_node* temp = q->front;
    while(temp){
        if(temp->data == data)
            return 1;
        
        temp = temp->next;
    }
    return 0;
}

void printDoubly_queueFront(Doubly_queue* q){ // right now works only for integer
    if(q->front == NULL)
        printf("Doubly_queue is empty\n");
    else{
        Doubly_node* tmp = q->front;
        while(tmp){
            printf("%4d\n", tmp->data);
            tmp = tmp->next;
        }
    }
}

void printDoubly_queueBack(Doubly_queue* q){ // right now works only for integer
    if(q->front == NULL)
        printf("Doubly_queue is empty\n");
    else{
        Doubly_node* tmp = q->rear;
        while(tmp){
            printf("%4d\n", tmp->data);
            tmp = tmp->prev;
        }
    }
}