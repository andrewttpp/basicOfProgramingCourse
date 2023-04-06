#include "libs/data_structures/vector/vector.h"

#define SIZE_MAX 10

void test_pushBack_emptyVector() {
    Vector v = create_vector(2);

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

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
}


int main() {
    test();

    printf("All tested passed");

    return 0;
}
