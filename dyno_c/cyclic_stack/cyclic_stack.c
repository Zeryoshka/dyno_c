//stack.c

#include <stddef.h>
#include <stdlib.h>
#include "cyclic_stack.h"
#include "../data_dyno_type.h"


// Инициализация циклического стека
// Cyclic stack initialization
Cyclic_stack* init_stack(Cyclic_stack* stack) {
    Cyclic_stack* stack = (Cyclic_stack*) malloc(sizeof(Cyclic_stack));
    stack->top = NULL;
    stack->bottom = NULL;
    return stack;
}

// Добавление элемента в циклический стек
// Push element to cyclic stack
void push(Cyclic_stack* stack, Data_dyno_type data) {
    Node_cyclic_stack* node = (Node_cyclic_stack*) malloc(sizeof(Node_cyclic_stack));
    node->data = data;
    node->next = stack->top;

    stack->top = node;
    if (stack->bottom == NULL)
        stack->bottom = stack->top;

    stack->bottom->next = stack->top;
}

// Удаляет элемент из стека и возвращает его назад
// Remove top element and return it
Data_dyno_type pop(Cyclic_stack* stack) {
    Data_dyno_type data = stack->top->data;
    if (stack->top == stack->bottom) {
        free(stack->top);
        stack->top = NULL;
        stack->bottom = NULL;
        return data;
    }
    Node_cyclic_stack* new_top = stack->top->next;
    free(stack->top);
    stack->top = new_top;
    stack->bottom->next = stack->top;
    return data;
}

// Проверка циклического стека на пустоту
// Check stack is empty
int is_empty(Cyclic_stack* stack) {
    return stack->top == NULL;
}

// Просмотреть верхний элемент циклического стека
// Return top element of stack
Data_dyno_type top(Cyclic_stack* stack) {
    return stack->top->data;
}