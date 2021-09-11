#include "../_share/print.h"  

int main(){
    Splay<int> S;

    printf("==============Insert==============");
    for(int i = 40; i > 0; i-=2){
        S.insert(i);
    }

    print(S);    
    printf("==============Search==============");

    S.search(40);
    print(S);
    S.search(36);
    print(S);
    printf("==============Remove==============");
    S.remove(22);
    print(S);
    return 0;
}
