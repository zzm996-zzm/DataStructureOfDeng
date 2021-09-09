#include "../_share/print.h"
#include <iostream>

#define TIME 100
int main(){
    Stack<int> S;
    for(int i = 0; i < TIME; i++)
        S.push(dice(100));
    print(S);
    for(int i = 0; i < TIME/3; i++)
        S.pop();
    print(S);
    std::cout << S.top() << std::endl;
    return 0;
}