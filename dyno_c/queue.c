// queue.c

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "data_type_dyno.h"

typedef struct NodeQ{
    NodeQ *next;
    Data_dyno_type data;
} NodeQ;

typedef struct Queue{
    NodeQ *front, *rear;
} Queue;

NodeQ* newNodeQ(Data_dyno_type data){
    NodeQ* new = (NodeQ*)malloc(sizeof(NodeQ));
    new->data = data;
    new->next = NULL;
    return new;
}
Queue *createQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enQueue(Queue* q, Data_dyno_type data){
    NodeQ* new = newNodeQ(data);
    if(q->rear == NULL){
        q->front = q->rear = new;
        return;
    }
    q->rear->next = new;
    q->rear = new;
}

void deQueue(Queue* q, Data_dyno_type data){
    if(q->front == NULL)
        return;

    NodeQ* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL)
        q->front == NULL;

    free(temp);
}

void printQueue(Queue* q){ // right now works only for integer
    if(q->front == NULL)
        printf("Queue is empty\n");
    else{
        NodeQ *tmp = q->front;
        while(tmp){
            printf("%4d\n", tmp->data);
            tmp = tmp->next;
        }
    }
}