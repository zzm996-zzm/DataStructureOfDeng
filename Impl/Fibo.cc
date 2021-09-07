#include "Fibo.hh"
#include <iostream>
#include <cassert>

using namespace::std;

int main(int argc, char** argv){
    if(argc!=2){
        printf("Usage: %s <num>\n", argv[0]);
        return 0;
    }

    int term = atoi(argv[1]);

    uint64_t result = Fibonacci::calculate(term, Method::DYNAMIC_PROGRAMMING);
    printf("%lu\n", result);
    result = Fibonacci::calculate(term, Method::LINEAR_RECURSION);
    printf("%lu\n", result);
    result = Fibonacci::calculate(term, Method::BINARY_RECURSION);
    printf("%lu\n", result);
    return 0;
}