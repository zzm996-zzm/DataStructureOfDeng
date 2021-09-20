#pragma once

#define  Parent(i)         ( ( ( i ) - 1 ) >> 1 ) //PQ[i]的父节点（floor((i-1)/2)，i无论正负）
#define  LChild(i)         ( 1 + ( ( i ) << 1 ) ) //PQ[i]的左孩子
#define  RChild(i)         ( ( 1 + ( i ) ) << 1 ) //PQ[i]的右孩子
#define  InHeap(n, i)      ( ( ( -1 ) < ( i ) ) && ( ( i ) < ( n ) ) ) //判断PQ[i]是否合法
#define  LChildValid(n, i) InHeap( n, LChild( i ) ) //判断PQ[i]是否有一个（左）孩子
#define  RChildValid(n, i) InHeap( n, RChild( i ) ) //判断PQ[i]是否有两个孩子
#define  Bigger(PQ, i, j)  ( lt( PQ[i], PQ[j] ) ? j : i ) //取大者（等时前者优先）
#define  ProperParent(PQ, n, i) /*父子（至多）三者中的大者*/ \
            ( RChildValid(n, i) ? Bigger( PQ, Bigger( PQ, i, LChild(i) ), RChild(i) ) : \
            ( LChildValid(n, i) ? Bigger( PQ, i, LChild(i) ) : i \
            ) \
            ) //相等时父节点优先，如此可避免不必要的交换


template<typename T>
int percolateUp(T* A, int i){
    while(i > 0){
        int j = Parent(i);
        if(lt(A[i], A[j])) break;
        swap(A[i], A[j]);
        i = j;
    }
    return i;
}

template<typename T>
int percolateDown(T* A, int n, int i){
    int j;
    while(i != (j = ProperParent(A, n, i))){
        swap(A[i], A[j]);
        i = j;
    }
    return i;
}

template <typename T> 
void heapify(T* A, int n) { //Floyd建堆算法，O(n)时间
   for ( int i = n/2 - 1; 0 <= i; i-- ) //自底而上，依次
      percolateDown (A, n, i ); //下滤各内部节点
}