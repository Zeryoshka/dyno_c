// doubly_linked_stack.h

#ifndef DOUBLY_LINKED_CYCLIC_STACK_H
#define DOUBLY_LINKED_CYCLIC_STACK_H


#include "../data_dyno_type.h"


// Структура для описания узла двусвязного циклического стека
typedef struct{
    Node_doubly_linked_cyclic_stack* next;
    Node_doubly_linked_cyclic_stack* prev;
    Data_dyno_type data;
} Node_doubly_linked_cyclic_stack;

// Структура для двусвязного циклического стека
typedef struct {
    Node_doubly_linked_cyclic_stack* start;
    Node_doubly_linked_cyclic_stack* end;
} Doubly_linked_cyclic_stack;

// Инициализация двусвязного циклического стека
Doubly_linked_cyclic_stack* init_stack();

// Добавление элемента в двусвязный цкилический стек
void push(Doubly_linked_cyclic_stack* stack, Data_dyno_type data);

// Удаляет элемент из двусвязного стека и возвращает его назад
Data_dyno_type pop(Doubly_linked_cyclic_stack* stack);

// Проверяет двусвязный стек на пустоту
int is_empty(Doubly_linked_cyclic_stack* stack);

// Просмотреть верхний элемент двусвязного стека
Data_dyno_type top(Doubly_linked_cyclic_stack* stack);

#endif