#include "../_share/print.h"  
#include <unistd.h>

#define TIME 2

int main(int argc, char** argv){
    if(argc!=2){
        printf("Usage: %s <num of nodes>\n", argv[0]);
        exit(0);
    }
    int n = atoi(argv[1]);

    Splay<int> S;

    printf("==============Insert==============");
    for(int i = 0; i < n; i++){
        S.insert(i);
        print(S);
        sleep(TIME);
    }
   
    printf("==============Search==============\n");

    printf("Press to see if you want to see the process of search\n");
    getchar();

    for(int i = 0; i < n; i++){
        int val = dice(n);
        printf("Search for %d\n", val);
        S.search(val);
        print(S);
        sleep(TIME);
    }
    /*
    printf("==============Remove==============");
    S.remove(22);
    print(S);
    */
    return 0;
}
