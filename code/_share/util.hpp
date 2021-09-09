#include "comparator.hpp"
#include "rand.h" 
#include "swap.hpp"  
#include "print.h"
template <typename T> struct Double {  
    virtual void operator() ( T& e ) { e *= 2; }  
};

template<typename T> struct Increase{
    virtual void operator() (T& e) { e++; }
};

