// doubly_linked_stack.c

#include <stddef.h>
#include <stdlib.h>
#include "doubly_linked_cyclic_stack.h"
#include "../data_dyno_type.h"


// Инициализация двусвязного циклического стека
Doubly_linked_cyclic_stack* init_doubly_linked_cyclic_stack() {
    Doubly_linked_cyclic_stack* stack = 
        (Doubly_linked_cyclic_stack*) malloc(sizeof(Doubly_linked_cyclic_stack));
    stack->start = NULL;
    stack->end = NULL;
    return stack;
}

// Добавление элемента в двусвязный стек
void push(Doubly_linked_cyclic_stack* stack, Data_dyno_type data) {
    Node_doubly_linked_cyclic_stack* node = 
        (Node_doubly_linked_cyclic_stack*) malloc(sizeof(Node_doubly_linked_cyclic_stack));
    node->data = data;

    if (stack->start == NULL) {
        node->next = node;
        node->prev = node;
    }
    else {
        stack->start->prev = node;

        node->next = stack->start;
        node->prev = stack->end;
        stack->end->next = node;
    }
    stack->start = node;
    stack->end = node->prev;
}

// Удаляет элемент из двусвязного стека и возвращает его назад
Data_dyno_type pop(Doubly_linked_cyclic_stack* stack) {
    Data_dyno_type data = stack->start->data;
    Node_doubly_linked_cyclic_stack* new_top = stack->start;
    if (stack->start == stack->end) {
        free(stack->start);
        stack->start = NULL;
        return data;
    }
    Node_doubly_linked_cyclic_stack* new_top = stack->start->next;
    new_top->prev = stack->end;
    free(stack->start);
    stack->start = new_top;
    return data;
}

// Проверяет двусвязный цкилический стек на пустоту
int is_empty(Doubly_linked_cyclic_stack* stack) {
    return stack->start == NULL;
}

// Просмотреть верхний элемент двусвязного цкилического стека
Data_dyno_type top(Doubly_linked_cyclic_stack* stack) {
    return stack->start->data;
}