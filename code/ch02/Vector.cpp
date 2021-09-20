#include "../_share/print.h"
#include <unistd.h>

int main(){
    Vector<int> vec;
    system("clear");
    int temp;

    for(int i = 0; i < 10; i++){
        temp = dice(1000);
        vec.insert(temp);
        printf("Insert:  %d  Size:  %d   Capacity:  %d\n\n", temp, vec.size(), vec.capacity());
        print(vec);
        sleep(1);
        system("clear");
    }  

    for(int i = 0; !vec.empty() && i < 50; i++){
        vec.sort();
        printf("\n");
        print(vec);
        sleep(5);
        system("clear");
        int die = dice(2021) % 5;
        if(die == 0){//unsort
            vec.unsort();
            printf("Unsort.  \n\n");
            print(vec);
            sleep(5);
        } else if(die == 1){
            temp = dice(1000);
            vec.insert(dice(2021)%vec.size(),temp);
            printf("Insert:  %d  Size:  %d   Capacity:  %d\n\n", temp, vec.size(), vec.capacity());
            print(vec);
            sleep(1);
        } else {
            int lo = dice(vec.size()+1);
            int hi = dice(vec.size()+1);
            if(hi < lo){
                swap(lo, hi);
            }
            vec.remove(lo, hi);
            printf("Remove: %d-%d  Size:  %d   Capacity:  %d\n\n", lo, hi, vec.size(), vec.capacity());
            print(vec);
            sleep(5);
        }
        system("clear");
    }
    return 0;
}