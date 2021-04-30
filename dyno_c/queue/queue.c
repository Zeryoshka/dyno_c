// queue.c

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "../data_dyno_type.h"

typedef struct NodeQ{
    struct NodeQ* next;
    Data_dyno_type data;
} NodeQ;

typedef struct Queue{
    NodeQ* front, *rear;
} Queue;

NodeQ* newNodeQ(Data_dyno_type data){
    NodeQ* new = (NodeQ*)malloc(sizeof(NodeQ));
    new->data = data;
    new->next = NULL;
    return new;
}

Queue* createQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int is_emptyQueue(Queue *q){
    if(q->rear == NULL || q->front == NULL)
        return 1;

    return 0;
}

int lenQueue(Queue *q){
    if(is_emptyQueue(q) == 1)
        return 0;

    else{
        int len = 0;
        NodeQ* temp = q->front;
        while(temp){
            len += 1;
            temp = temp->next;
        }
        return len;
    }
}

void enQueue(Queue* q, Data_dyno_type data){
    NodeQ* new = newNodeQ(data);
    if(q->front == NULL){
        q->front = new;
        q->rear = new;
        return;
    }
    q->rear->next = new;
    q->rear = new;
}

void deQueue(Queue* q){
    if(is_emptyQueue(q) == 1)
        return;

    NodeQ* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear == NULL;

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
