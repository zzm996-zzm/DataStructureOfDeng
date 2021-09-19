#pragma once

#include <cstdio> //采用C风格精细控制输出格式

#include "../ch02/Vector.hpp"
#include "../ch03/List.hpp"
#include "../ch04/Stack.hpp"
#include "../ch05/BinTree.hpp"
#include "../ch07/BST.hpp"
#include "../ch07/AVL.hpp"  
#include "../ch07/Entry.hpp"
#include "../ch08/Splay.hpp"
#include "../ch08/BTree.hpp"
#include "../ch08/RedBlack.hpp"
#include "../ch09/Quadlist.hpp"  
#include "../ch09/Skiplist.hpp"  
#include "../ch09/Hashtable.hpp"

static void print ( char* x ) {  printf ( " %s", x ? x : "<NULL>" );  } //字符串特别处理
static void print ( const char* x ) {  printf ( " %s", x ? x : "<NULL>" );  } //字符串特别处理

class UniPrint {
public:
   static void p ( int );
   static void p ( float );
   static void p ( double );
   static void p ( char );

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
   template <typename T> static void p ( T& ); //向量、列表等支持traverse()遍历操作的线性结构
   template <typename T> static void p ( T* s ) //所有指针
   {  s ? p ( *s ) : print ( "<NULL>" ); } //统一转为引用
}; //UniPrint

void UniPrint::p ( int e ) {  printf ( " %04d", e ); }
void UniPrint::p ( float e ) { printf ( " %4.3f", e ); }
void UniPrint::p ( double e ) { printf ( " %4.3f", e ); }
void UniPrint::p ( char e ) { printf ( " %c", ( 31 < e ) && ( e < 128 ) ? e : '$' ); }

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
#include "print_btree.h"  
#include "print_RBTree.h"
#include "print_Entry.h"
#include "print_QuadList.h"  
#include "print_SkipList.h"
#include "print_HashTable.h"




