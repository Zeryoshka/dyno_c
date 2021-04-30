// doubly_linked_stack.cpp

#include <stddef.h>
#include "doubly_linked_stack.h"
#include "../data_dyno_type.h"


// Инициализация двусвязного стека
Doubly_linked_stack* init_stack(){
    Doubly_linked_stack* stack = new Doubly_linked_stack;
    stack->start = NULL;
    return stack;
}

// Добавление элемента в двусвязный стек
void push(Doubly_linked_stack* stack, Data_dyno_type data) {
    Node_doubly_linked_stack* node = new Node_doubly_linked_stack;
    node->data = data;
    node->next = stack->start;
    node->prev = NULL;
    if (stack->start != NULL)
        stack->start->prev = node;
    stack->start = node;
}

// Удаляет элемент из двусвязного стека и возвращает его назад
Data_dyno_type pop(Doubly_linked_stack* stack) {
    Data_dyno_type data = stack->start->data;
    Node_doubly_linked_stack* new_top = stack->start->next;
    new_top->prev = NULL;
    delete stack->start;
    stack->start = new_top;
    return data;
}

// Проверяет двусвязный стек на пустоту
int is_empty(Doubly_linked_stack* stack) {
    return stack->start == NULL;
}

// Просмотреть верхний элемент двусвязного стека
Data_dyno_type top(Doubly_linked_stack* stack){
    return stack->start->data;
}