//
// Created by user on 05.04.2023.
//

#include "vector.h"

void output_vector(Vector v) {
    for (int i = 0; i < v.size - 1; ++i) {
        printf("%d ", v.data[i]);
    }
}

void checker_malloc(Vector v) {
    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

Vector create_vector(size_t n) {
    Vector v;
    if (n) {
        v.data = (int*)malloc(sizeof(int) * n);
        checker_malloc(v);
        v.size = 0;
        v.capacity = n;
    } else {
        v.data = NULL;
        v.size = 0;
        v.capacity = 0;
    }

    return v;
}

void reserve(Vector *v, size_t new_capacity) {
    if (!new_capacity) {
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
    } else {
        if (v->capacity > new_capacity) {
            v->data = &v->data[new_capacity - 1];
            v->size = new_capacity;
        } else {
            v->data = (int*)realloc(v->data, sizeof(int) * new_capacity);
            checker_malloc(*v);
        }

        v->capacity = new_capacity;
    }
}

void clear(Vector *v) {
    v->size = 0;
}

void shrink_to_fit(Vector *v) {
    v->capacity = v->size;
}

void delete_vector(Vector *v) {
    free(v->data);

    v->size = 0;
    v->capacity = 0;
}
