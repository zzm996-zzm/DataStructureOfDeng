#  高级搜索树  

### Splay树

![](./pic/Splay.png)  

[Splay.cpp](./Splay.cpp)  
[Splay.hpp](./Splay.hpp)  

#### Insert  

![](./pic/Splay_insert.png)  

#### search worst value (40 and 32)  

![](./pic/Splay_search_worst.png)

#### remove in-between value(22)  
 
![](./pic/Splay_remove_22.png)  

> 伸展树看似退化成了一条单链，但其在查询时会伸展起来。运用了程序的局部性原理，将查询的元素置于根节点，若该节点不存在，则可采用其直接后继。  

> 伸展后的Splay树高度减半，总体复杂度可均摊分析。

> 伸展树没有雷同节点，故适用于局部性较强的应用场合。  
