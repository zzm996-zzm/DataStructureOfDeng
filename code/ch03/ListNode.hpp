#pragma once  

using Rank = int;

template<typename T>
struct ListNode {
    T data;
    ListNode<T>* pred;
    ListNode<T>* succ;

    ListNode(){}
    ListNode(T e, ListNode<T>* p = nullptr, ListNode<T>* s = nullptr)
        : data(e), pred(p), succ(s) {}

    ListNode<T>* insertAsPred(T const& e);
    ListNode<T>* insertAsSucc(T const& e);  
};