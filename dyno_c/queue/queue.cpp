// queue.cpp

#include <stddef.h>
#include <iostream>

#include "../data_dyno_type.h"

typedef struct NodeQ{
    struct NodeQ* next;
    Data_dyno_type data;
} NodeQ;

typedef struct Queue{
    NodeQ* front, *rear;
} Queue;

NodeQ* newNodeQ(Data_dyno_type data){
    NodeQ* n = new NodeQ;
    n->data = data;
    n->next = NULL;
    return n;
}

Queue* createQueue(){
    Queue* queue = new Queue;
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
    NodeQ* n = newNodeQ(data);
    if(q->front == NULL){
        q->front = n;
        q->rear = n;
        return;
    }
    q->rear->next = n;
    q->rear = n;
}

void deQueue(Queue* q){
    if(is_emptyQueue(q) == 1)
        return;

    NodeQ* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear == NULL;

    delete(temp);
}

int searchQueue(Queue* q, Data_dyno_type data){ // rewrite if u want to use it
    NodeQ* temp = q->front;
    while(temp){
        if(temp->data == data)
            return 1;
        
        temp = temp->next;
    }
    return 0;
}

void printQueue(Queue* q){ // right now works only for integer
    if(q->front == NULL)
        std::cout << "Queue is empty" << std::endl;
    else{
        NodeQ* tmp = q->front;
        while(tmp){
            std::cout << tmp->data << std::endl;
            tmp = tmp->next;
        }
    }
}
