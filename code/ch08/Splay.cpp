#include "../_share/print.h"  

int main(){
    Splay<int> S;
    for(int i = 0; i < 10; i++)
        S.insert(i);
    
    print(S);

    for(int i = 0; i < 10; i++){
        S.search(i);
        print(S);
    }

    S.search(0);
    print(S);

    return 0;
}
