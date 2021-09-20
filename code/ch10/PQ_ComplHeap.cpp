#include "../_share/print.h"  
#include <unistd.h>

int main(){
    system("clear");
    PQ_ComplHeap<int> pq;
    for(int i = 1; i < 100; i++){
        int temp = dice(i);
        printf("Insert: %d\n\n", temp);
        pq.insert(temp);
        print(pq);
        sleep(1);
        system("clear");
    }
        
    printf("Press to see deletion: \n");
    getchar();
    
    system("clear");

    while(!pq.empty()){
        printf("Delete: %d\n\n", pq.delMax());
        print(pq);
        sleep(1);
        system("clear");
    }
    getchar();

    return 0;
}