#include "../_share/print.h"  
#include <iostream>

int main(){
    List<int> list;
    for(int i = 100; i < 199; i++)
        list.insertAsLast(dice(200));
    print(list);
    for(int i = 0; i < 99; i++)
        list.insertAsFirst(dice(100));
    print(list);
    if(list.empty())
        std::cout << "The list is empty." << std::endl;
    if(list.valid(list.first()))
        std::cout << "The first element is valid" << std::endl;
    for(int i = 0; i < 50; i++)
        list.insertAsLast(dice(300));
    print(list);
    list.sort();
    print(list);
    list.reverse();
    print(list);

    return 0;
}