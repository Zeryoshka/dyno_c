//cyclic_stack.h

#ifndef STACK_H
#define STACK_H

#include "../data_dyno_type.h"


// Структура для описания узла циклического стека
typedef struct{
    Node_cyclic_stack* next;
    Data_dyno_type data;
} Node_cyclic_stack;

// Структура для стека
typedef struct {
    Node_cyclic_stack* start;
} Cyclic_stack;

// Инициализация стека
Cyclic_stack* init_cyclic_stack();

// Добавление элемента в стек
void push(Cyclic_stack* stack, Data_dyno_type data);

// Удаляет элемент из стека и возвращает его назад
Data_dyno_type pop(Cyclic_stack* stack);

// Проверяет элемент стека на пустоту
int is_empty(Cyclic_stack* stack);

// Просмотреть верхний элемент
Data_dyno_type top(Cyclic_stack* stack);

#endif