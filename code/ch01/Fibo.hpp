#ifndef DSA_DENG_FIBO
#define DSA_DENG_FIBO

#include<ctime>
#include<iostream>
#include<functional>

using uint64_t = unsigned long;

enum class Method {
    BINARY_RECURSION,
    LINEAR_RECURSION,
    DYNAMIC_PROGRAMMING
};

class Fibonacci {
public:

    static uint64_t calculate(int n, Method f);

private:

    static uint64_t binary(int n);
    static uint64_t linear(int n, uint64_t& prev);
    static uint64_t dynamic(int n);
};


uint64_t 
Fibonacci::calculate(int n, Method f){
    time_t begin, end;
    uint64_t res;
    uint64_t prev;
    printf("Method:  ");
    begin = clock();
    switch(f){
        case Method::BINARY_RECURSION:
            res = binary(n);
            printf("binary recursion\t");
            break;
        case Method::LINEAR_RECURSION:
            res = linear(n, prev);
            printf("linear recursion\t");
            break;
        case Method::DYNAMIC_PROGRAMMING:
            res = dynamic(n);
            printf("dynamic recursion\t");
            break;
        default:
            break;
    }
    end = clock();
    printf("Time: %lf\n", double(end-begin)/CLOCKS_PER_SEC);
    return res;
}

uint64_t 
Fibonacci::binary(int n){
    return (n < 2) ? (uint64_t) n : binary(n-1) + binary(n-2);
}

uint64_t
Fibonacci::linear(int n, uint64_t& prev){
    if(n == 0){
        prev = 1;
        return 0;
    } else {
        uint64_t prevPrev;
        prev = linear(n-1, prevPrev);
        return prevPrev + prev;
    }
}

uint64_t
Fibonacci::dynamic(int n){
    uint64_t f = 1, g = 0;
    while (0 < n--){
        g += f;
        f = g - f;
    }
    return g;
} 
#endif