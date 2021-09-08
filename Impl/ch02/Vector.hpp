using Rank = int;
#define DEFAULT_CAPACITY 3

template<typename T>
class Vector{
protected:
    Rank _size;
    int _capacity;
    T* _elem;

    void copyFrom(T const* A, Rank lo, Rank hi);
    void expand();
    void shrink();
    bool bubble(Rank lo, Rank hi);
    void bubbleSort(Rank lo, Rank hi);
    Rank max(Rank lo, Rank hi);
    void selectionSort(Rank lo, Rank hi);
    void merge(Rank lo, Rank mi, Rank hi);
    void mergeSort(Rank lo, Rank hi);
    Rank partition(Rank lo, Rank hi);
    void quickSort(Rank lo, Rank hi);
    void heapSort(Rank lo, Rank hi);
public:
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0){
        _elem = new T[_capacity = c];
        for(_size = 0; _size < s; _elem[_size++] = v);
    }
    Vector(T const* A, Rank n){ copyFrom(A, 0, n); }
    Vector(T const* A, Rank lo, Rank hi){   copyFrom(A, lo, hi);    }
    Vector(Vector<T> const& V) {    copyFrom(V._elem, 0, V._size);   }//copy constructor
    Vector(Vector<T> const& V, Rank lo, Rank hi) {  copyFrom(V._elem, lo, hi); }

    ~Vector()   {delete []_elem; }

    //Read Only
    Rank size() const { return _size; }
    bool empty() const { return !_size; }
    int disordered()  const;
    Rank find(T const& e) const { return find(e, 0, _size); }
    Rank find(T const& e, Rank lo, Rank hi) const;
    Rank search(T const& e) const { return (0 >= _size)?-1:search(e, 0, _size); }
    Rank search(T const& e, Rank lo, Rank hi) const;
    //writable
    T& operator[] (Rank r) const;
    Vector<T> & operator=(Vector<T> const&);
    //move
    T remove(Rank r);
    int remove(Rank lo, Rank hi);
    Rank insert(Rank r, T const& e);
    Rank insert(T const& e) {   return insert(_size, e);  }
    void sort() {   sort(0, _size); }
    void unsort(Rank lo, Rank hi);
    void unsort() { unsort(0, _size); }
    int deduplicate();
    int uniquify();

    void traverse(void(*)(T&));
    template<typename VST> void traverse(VST&);
};