template<typename T>
void swap(T& ls, T& rs){
    T temp = ls;
    ls = rs;
    rs = temp;
}

template<typename T>
void swap(T* ls, T* rs){
    T* temp = ls;
    ls = rs;
    rs = temp;
}