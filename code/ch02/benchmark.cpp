#include "../_share/print.h"
#include <unistd.h>

int main(){
    Vector<int> vec;
    for(int i = 0; i < 100000; i++){
        vec.insert(i);
    }
    return 0;
}