#ifndef QUEUE_H
#define QUEUE_H

typedef struct NodeQ{
    struct NodeQ *next;
    Data_dyno_type data;
} NodeQ;

typedef struct Queue{
    NodeQ *front, *rear;
} Queue;

#endif