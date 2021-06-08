/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2020. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <typeinfo>

template <typename T> struct Cleaner {
   static void clean ( T x ) { /
#ifdef _DEBUG
      static int n = 0;
      if ( 7 > strlen ( typeid ( T ).name() ) ) { 
         printf ( "\t<%s>[%d]=", typeid ( T ).name(), ++n );
         print ( x );
         printf ( " purged\n" );
      }
#endif
   }
};

template <typename T> struct Cleaner<T*> {
   static void clean ( T* x ) {
      if ( x ) { delete x; } 
#ifdef _DEBUG
      static int n = 0;
      printf ( "\t<%s>[%d] released\n", typeid ( T* ).name(), ++n );
#endif
   }
};

template <typename T> void release ( T x ) { Cleaner<T>::clean ( x ); }