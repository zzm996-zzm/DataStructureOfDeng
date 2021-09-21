#include "../_share/print.h"  
#include <unistd.h>

int main(){

    List<int> list;
    system("clear");
    int temp;

    for(int i = 0; i < 10; i++){
        temp = dice(1000);
        printf("InsertAsLast:  %d\n\n", temp);
        list.insertAsLast(temp);
        print(list);
        sleep(1);
        system("clear");
    }

    for(int i = 0; i < 10; i++){
        temp = dice(1000);
        printf("InsertAsFirst:  %d\n\n", temp);
        list.insertAsFirst(temp);
        print(list);
        sleep(1);
        system("clear");
    }

    for(int i = 0; i < 10; i++){
        temp = dice(1000);
        if(dice(2021) & 1){
            printf("InsertAsFirst:  %d\n\n", temp);
            list.insertAsFirst(temp);
        }
        else{
            printf("InsertAsLast:  %d\n\n", temp);
            list.insertAsLast(temp);
        }
        print(list);
        sleep(1);
        system("clear");
    }

    for(int i = 0; !list.empty() && i < 50; i++){
        list.sort();
        printf("\n");
        print(list);
        sleep(5);
        system("clear");
        int die = dice(2021) % 5;
        if(die == 0){
            list.reverse();
            printf("Reverse List.  \n\n");
            print(list);
            sleep(5);
        } else if(die == 1){
            temp = dice(1000);
            printf("InsertAsFirst:  %d\n\n", temp);
            list.insertAsFirst(temp);
            print(list);
            sleep(1);
        } else if(die == 2){
            temp = dice(1000);
            printf("InsertAsLast:  %d\n\n", temp);
            list.insertAsLast(temp);
            print(list);
            sleep(1);
        } else if(die == 3) {
            printf("Remove first:  %d\n\n", list.first()->data);
            list.remove(list.first());
            print(list);
            sleep(1);
        } else {
            printf("Remove last:   %d\n\n", list.last()->data);
            list.remove(list.last());
            print(list);
            sleep(1);
        }
        system("clear");
    }

    return 0;
}