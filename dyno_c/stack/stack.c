//stack.cpp

#include <stddef.h>
#include <stdlib.h>
#include "stack.h"
#include "data_dyno_type.h"

// Инициализация стека
Stack* init_stack(Stack* stack) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->start = NULL;
    return stack;
}

// Добавление элемента в стек
void push(Stack* stack, Data_dyno_type data) {
    Node_stack* node = (Node_stack*) malloc(sizeof(Node_stack));
    node->data = data;

    node->next = stack->start;
    stack->start = node;
}

// Удаляет элемент из стека и возвращает его назад
Data_dyno_type pop(Stack* stack) {
    Data_dyno_type data = stack->start->data;
    Node_stack* new_top = stack->start->next;
    free(stack->start);
    stack->start = new_top;
    return data;
}

// Проверяет элемент стека на пустоту
int is_empty(Stack* stack) {
    return stack->start == NULL;
}

// Просмотреть верхний элемент
Data_dyno_type top(Stack* stack) {
    return stack->start->data;
}