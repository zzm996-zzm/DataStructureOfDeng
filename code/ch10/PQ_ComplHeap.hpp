#pragma once

#include "../ch02/Vector.hpp"
#include "PQ.hpp" 
#include "PQ_operation.hpp"


template<typename T>
class PQ_ComplHeap : public PQ<T>, public Vector<T> {
public:
    PQ_ComplHeap(){ }
    PQ_ComplHeap(T* A, Rank n) {    Vector<T>::copyFrom(A, 0, n); heapify(this->_elem, n);  }
    void insert(T);
    T getMax();
    T delMax();
};


template<typename T>
T PQ_ComplHeap<T>::getMax(){
    return Vector<T>::_elem[0];
}

template<typename T>
void PQ_ComplHeap<T>::insert(T e){
    Vector<T>::insert(e);
    percolateUp(this->_elem, this->_size - 1);
}

template<typename T>
T PQ_ComplHeap<T>::delMax() {
    T maxElem = this->_elem[0];
    this->_elem[0] = this->_elem[--this->_size];
    percolateDown(this->_elem, this->_size, 0);
    return maxElem;
}



