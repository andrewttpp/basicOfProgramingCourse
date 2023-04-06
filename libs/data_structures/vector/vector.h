//
// Created by user on 05.04.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#ifndef LAB_18_VECTOR_H
#define LAB_18_VECTOR_H


typedef struct Vector {
    int *data;          // указатель на элементы вектора
    size_t size;        // размер вектора
    size_t capacity;    // вместимость вектора
} Vector;

// выводит сообщение "bad alloc", если ОС не может предоставить нужный
// объем памяти под размещение динамического массива
void checker_malloc(Vector v);

// возвращает структуру-дескриптор вектор из n значений.
Vector create_vector(size_t n);

// изменяет количество памяти, выделенное под хранение элементов вектора
void reserve(Vector *v, size_t new_capacity);

// удаляет элементы из контейнера, но не освобождает выделенную память
void clear(Vector *v);

// освобождает память, выделенную под неиспользуемые элементы
void shrink_to_fit(Vector *v);

// освобождает память, выделенную вектору
void delete_vector(Vector *v);

// возвращает значение 'истина', если вектор пуст, иначе - 'ложь'
bool is_empty(Vector v);

// возвращает значение 'истина', если вектор полон, иначе - 'ложь'
bool is_full(Vector v);

// возвращает i-ый элемент вектора v
int get_vector_value(Vector *v, size_t i);

// добавляет элемент x в конец вектора v
void push_back(Vector *v, int x);

// удаляет последний элемент из вектора
void pop_back(Vector *v);

//  возвращает указатель на index-ый элемент вектора
int* at_vector(Vector *v, size_t index);

//  возвращает указатель на последний элемент вектора
int* back(Vector *v);

//  возвращает указатель на первый элемент вектора
int* front(Vector *v);

#endif //LAB_18_VECTOR_H
