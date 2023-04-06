#include "libs/data_structures/vector/vector.h"

#define SIZE_MAX 10

void test_pushBack_emptyVector() {
    Vector v = create_vector(SIZE_MAX);

    if(!is_empty(v)){
        fprintf(stderr, "Test 1 failed");
        exit(1);
    }
}

void test_pushBack_fullVector() {
    Vector v = create_vector(2);

    if(is_full(v)){
        fprintf(stderr, "Test 3 failed");
        exit(1);
    }

    push_back(&v,0);
    push_back(&v,2);

    if(!is_full(v)){
        fprintf(stderr, "Test 4 failed");
        exit(1);
    }
}

void test_atVector_notEmptyVector() {
    Vector v = create_vector(SIZE_MAX);

    push_back(&v,0);
    push_back(&v,2);

    if(is_empty(v)){
        fprintf(stderr, "Test 5 failed");
        exit(1);
    }
}

void test_atVector_requestToLastElement() {
    Vector v = create_vector(5);

    push_back(&v,0);
    push_back(&v,2);

    if(get_vector_value(&v, v.size - 1) != 2){
        fprintf(stderr, "Test 6 failed");
        exit(1);
    }
}

void test_back_oneElementInVector() {
    Vector v = create_vector(2);

    push_back(&v,0);

    if(back(&v) != &v.data[0]){
        fprintf(stderr, "Test 7 failed");
        exit(1);
    }

    push_back(&v,10);

    if(back(&v) != &v.data[1]) {
        fprintf(stderr, "Test 8 failed");
        exit(1);
    }
}

void test_front_oneElementInVector() {
    Vector v = create_vector(2);

    push_back(&v,0);

    if(back(&v) != &v.data[0]){
        fprintf(stderr, "Test 7 failed");
        exit(1);
    }

    push_back(&v,10);

    if(back(&v) != &v.data[1]) {
        fprintf(stderr, "Test 8 failed");
        exit(1);
    }
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}


int main() {
    test();

    printf("All tested passed");

    return 0;
}
