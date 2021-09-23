#pragma once

#include <cstdio> //采用C风格精细控制输出格式

#include "./util.hpp"
#include "../ch02/Vector.hpp"
#include "../ch03/List.hpp"
#include "../ch04/Stack.hpp"
#include "../ch05/BinTree.hpp"
#include "../ch06/Graph.hpp"
#include "../ch06/GraphMatrix.hpp"
#include "../ch07/BST.hpp"
#include "../ch07/AVL.hpp"  
#include "../ch07/Entry.hpp"
#include "../ch08/Splay.hpp"
#include "../ch08/BTree.hpp"
#include "../ch08/RedBlack.hpp"
#include "../ch09/Quadlist.hpp"  
#include "../ch09/Skiplist.hpp"  
#include "../ch09/Hashtable.hpp"
#include "../ch10/PQ_ComplHeap.hpp"
#include "../ch10/PQ_LeftHeap.hpp"  
#include "../ch11/String.hpp"

#define N 40
#define RANDOM 100

static void print ( char* x ) {  printf ( " %s", x ? x : "<NULL>" );  } //字符串特别处理
static void print ( const char* x ) {  printf ( " %s", x ? x : "<NULL>" );  } //字符串特别处理

static void print ( String x) {
   const char* c = x.c_str();
   while(*c){
      putchar(*c);
      c++;
   }
}

static int cntChar = 0;
static int cntInt = 0;

class WrappedInt {
private:
   int i;
public:
   int get() { return i;  }
   WrappedInt(){  i = cntInt++;}
};

class WrappedChar {
private:
   char i;
public:
   char get() { return i;  }
   WrappedChar() {
      if(cntChar == 0){
         i = 'S';
         cntChar++;
      } else if(cntChar < 27){
         i = 64 + cntChar; 
         cntChar++;
      } else {
         i = '$';
      }
   }
   WrappedChar(int i){
      i = dice();
   }

   

};

class UniPrint {
public:
   static void p ( int );
   static void p ( float );
   static void p ( double );
   static void p ( char );
   static void p ( size_t );
   static void p ( String& );
   static void p ( VStatus ); //图顶点的状态
   static void p ( EType ); //图边的类型
   static void p ( WrappedInt); 
   static void p ( WrappedChar); 

   template <typename K, typename V> static void p ( Entry<K, V>& ); //Entry
   template <typename T> static void p ( BinNode<T>&); //BinTree节点
   template <typename T> static void p ( BinTree<T>& ); //二叉树
   template <typename T> static void p ( BST<T>& ); //BST
   template <typename T> static void p ( AVL<T>& ); //AVL
   template <typename T> static void p ( Splay<T>& ); //Splay
   template <typename T> static void p ( BTree<T>& ); //B-树
   template <typename T> static void p ( Quadlist<T>& ); //Quadlist
   template <typename K, typename V> static void p ( Skiplist<K, V>& ); //Skiplist
   template <typename K, typename V> static void p ( Hashtable<K, V>& ); //Hashtable
   template <typename T> static void p ( PQ_ComplHeap<T>& ); //PQ_ComplHeap
   template <typename T> static void p ( PQ_LeftHeap<T>& ); //PQ_LeftHeap
   template <typename Tv, typename Te> static void p ( GraphMatrix<Tv, Te>& ); //Graph
   template <typename T> static void p ( T& ); //向量、列表等支持traverse()遍历操作的线性结构
   template <typename T> static void p ( T* s ) //所有指针
   {  s ? p ( *s ) : print ( "<NULL>" ); } //统一转为引用
}; //UniPrint

void UniPrint::p ( int e ) {  printf ( " %04d", e ); }
void UniPrint::p ( size_t e) {   printf ("-%lu", e); }
void UniPrint::p ( float e ) { printf ( " %4.3f", e ); }
void UniPrint::p ( double e ) { printf ( " %4.3f", e ); }
void UniPrint::p ( char e ) { printf ( " %c", ( 31 < e ) && ( e < 128 ) ? e : '$' ); }
void UniPrint::p ( WrappedInt e) {  printf( " %04d", e.get() ); }
void UniPrint::p ( WrappedChar e) {  printf ( " %c", ( 31 < e.get() ) && ( e.get() < 128 ) ? e.get() : '$' ); }
void UniPrint::p ( String& e) {
   const char* c = e.c_str();
   while(*c){
      putchar(*c);
      c++;
   }
}
void UniPrint::p ( VStatus e ) {
   switch ( e ) {
      case VStatus::UNDISCOVERED:   printf ( "U" ); break;
      case VStatus::DISCOVERED:     printf ( "D" ); break;
      case VStatus::VISITED:        printf ( "V" ); break;
      case VStatus::SOURCE:         printf ( "S" ); break;
      default:             printf ( "X" ); break;
   }
}
void UniPrint::p ( EType e ) {
   switch ( e ) {
      case EType::UNDETERMINED:   printf ( "U" ); break;
      case EType::TREE:           printf ( "T" ); break;
      case EType::CROSS:          printf ( "C" ); break;
      case EType::BACKWARD:       printf ( "B" ); break;
      case EType::FORWARD:        printf ( "F" ); break;
      default:             printf ( "X" ); break;
   }
}



template <typename T> static void print ( T& x ) {  UniPrint::p ( x );  }
template <typename T> static void print ( const T& x ) {  UniPrint::p ( x );  } //for Stack
template <typename T> static void print ( T* x ) { 
   if(x)  
      print(*x); 
   else
      printf("<NULL>\n");
}

template<typename T> struct Print{
    virtual void operator()(T& e) {  print(e); }
};

#include "print_traversable.hpp"
#include "print_binNode.h"  
#include "print_bintree.h"  
#include "print_GraphMatrix.h"  
#include "print_btree.h"  
#include "print_RBTree.h"
#include "print_Entry.h"
#include "print_QuadList.h"  
#include "print_SkipList.h"
#include "print_HashTable.h"
#include "print_PQ_ComplHeap.h"
#include "print_PQ_LeftHeap.h"



