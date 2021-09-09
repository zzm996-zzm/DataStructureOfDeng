#include <iostream>
#include "../_share/print.h"

#define TIME 100 

int main(){
    Vector<double> vec;
    for(int i = 0; i < TIME; i++){
        vec.insert(dice((i+1)*2.0));
        std::cout << vec[i] 
                  << "  size: " << vec.size() 
                  << "  capacity: " << vec.capacity()
                  << std::endl;
    }
    print(vec);
    increase(vec);
    print(vec);
    std::cout << "Is it empty?  " << vec.empty() << std::endl;
    
    

    if(vec.disordered()){
        vec.deduplicate();
    }

    print(vec);
    vec.sort();
    print(vec);

    std::cout << "Search: " << vec.search(2.0) << std::endl;
    
    vec.unsort();
    print(vec);
    std::cout << "Find: " << vec.find(2) << std::endl;
}