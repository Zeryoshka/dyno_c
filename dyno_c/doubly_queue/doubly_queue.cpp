// Doubly_queue.cpp

#include <stddef.h>
#include <iostream>

#include "../data_dyno_type.h"

typedef struct Doubly_node{
    struct Doubly_node* next, *prev;
    Data_dyno_type data;
} Doubly_node;

typedef struct Doubly_queue{
    Doubly_node* front, *rear;
} Doubly_queue;

Doubly_node* newDoubly_node(Data_dyno_type data){
    Doubly_node* n = (Doubly_node*)malloc(sizeof(Doubly_node));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    return n;
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
    Doubly_node* n = newDoubly_node(data);
    if(q->front == NULL){
        q->front = n;
        q->rear = n;
        return;
    }
    
    q->rear->next = n;
    n->prev = q->rear;
    q->rear = n;
}

void deDoubly_queue(Doubly_queue* q){
    if(is_emptyDoubly_queue(q) == 1)
        return;

    Doubly_node* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear == NULL;

    delete(temp);

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
        std::cout << "Doubly_queue is empty" << std::endl;
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
        std::cout << "Doubly_queue is empty" << std::endl;
    else{
        Doubly_node* tmp = q->rear;
        while(tmp){
            std::cout << tmp->data << std::endl;
            tmp = tmp->prev;
        }
    }
}