#include "../_share/print.h"
#include <unistd.h>  


#define TIME 100
int main(){
    Stack<int> S;
    system("clear");
    int temp;
    for(int i = 0; i < 5; i++){
        temp = dice(RANDOM);
        S.push(temp);
        printf("Push  %d\n\n", temp);
        print(S);
        sleep(1);
        system("clear");
    }
    
    while(!S.empty()){
        temp = dice(RANDOM);
        if(temp & 1){
            S.push(temp);
            printf("Push  %d\n\n", temp);
        }
        else {
            temp = S.pop();
            printf("Pop   %d\n\n", temp);
        }
        print(S);
        sleep(1);
        system("clear");
    }
    
    return 0;
}