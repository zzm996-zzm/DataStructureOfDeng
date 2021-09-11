#include "../_share/print.h"  

int main(){
    Splay<int> S;

    printf("==============Insert==============");
    for(int i = 0; i < 10; i++){
        S.insert(i);
        print(S);
    }
        
    printf("==============Search==============");
    for(int i = 0; i < 10; i++){
        S.search(i);
        print(S);
    }

    printf("==============Remove==============");
    for(int i = 0; i < 10; i++){
        S.remove(i);
        print(S);
    }

    return 0;
}
