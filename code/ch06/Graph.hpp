#pragma once

#include "../ch04/Stack.hpp" 
#include "../ch04/Queue.hpp"

#include <climits>
enum class VStatus {
    SOURCE,
    UNDISCOVERED,
    DISCOVERED,
    VISITED
};//顶点状态

enum class EType {
    UNDETERMINED,
    TREE,
    CROSS,
    FORWARD,
    BACKWARD
};//边状态

enum class GType {
    GRAPH,
    WEIGHTEDGRAPH
};

template<typename Tv, typename Te>
class Graph {
private:
    void reset(){
        for(int i = 0; i < n; i++){
            status(i) = VStatus::UNDISCOVERED;
            dTime(i) = -1;
            fTime(i) = -1;
            parent(i) = -1;
            priority(i) = INT_MAX;
            for(int j = 0; j < n; j++)
                if(exists(i,j))
                    type(i, j) = EType::UNDETERMINED;
        }
    }
    void BFS(int, int& );//广度优先搜索
    void DFS(int, int& );//深度优先搜索
    void BCC(int, int&, Stack<int>& );//双连通分量分解
    bool TSort(int, int&, Stack<Tv>* );//拓扑排序
    template<typename PU> void PFS(int, PU);//优先级搜索

public:
    //顶点接口
    int n;
    virtual int insert(Tv const& ) = 0;//插入顶点，返回编号
    virtual Tv remove(int) = 0;//删除顶点及其关联边，返回顶点信息
    virtual Tv& vertex(int) = 0;//顶点v的数据
    virtual int inDegree(int) = 0;//顶点v的入度
    virtual int outDegree(int) = 0;//顶点v的出度
    virtual int firstNbr(int) = 0;//顶点v的首个邻接顶点
    virtual int nextNbr(int, int) = 0;//顶点v的下一个邻接顶点
    virtual VStatus& status(int) = 0;
    virtual int& dTime(int) = 0;//时间标签
    virtual int& fTime(int) = 0;
    virtual int& parent(int) = 0;
    virtual int& priority(int) = 0;
    //边接口
    int e;
    virtual bool exists(int, int) = 0;
    virtual void insert(Te const& edge, int, int, int) = 0;//在顶点v和u之间插入权重为w的边e
    virtual Te remove(int, int) = 0;
    virtual EType& type(int, int) = 0;
    virtual Te& edge(int, int) = 0;
    virtual double& weight(int, int) = 0;
    //算法
    void bfs(int);//广度优先搜索
    void dfs(int);//深度优先搜索
    void vcc(int);//双连通分量分解
    Stack<Tv>* tSort(int);//基于DFS的拓扑排序
    void prim(int);//最小生成树
    void dijkstra(int);//最短路径
    template<typename PU> void pfs(int, PU);
}; 

template<typename Tv, typename Te>
void Graph<Tv, Te>::bfs(int s) {
    reset();
    int clock = 0;
    int v = s;
    do 
        if(VStatus::UNDISCOVERED == status(v))
            BFS(v, clock); 
    while(s != (v = (++v%n)));
}

template<typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int& clock) {
    Queue<int> Q;
    status(v) = VStatus::SOURCE;
    Q.enqueue(v);
    while(!Q.empty()) {
        int v = Q.dequeue();
        dTime(v) = ++clock;
        for(int u = firstNbr(v); -1 < u; u = nextNbr(v, u))
            if(VStatus::UNDISCOVERED == status(u)){
                status(u) = VStatus::DISCOVERED;
                Q.enqueue(u);
                type(v, u) = EType::TREE;
                parent(u) = v;
            } else {
                type(v, u) = EType::CROSS;
            }
        if(status(v)!=VStatus::SOURCE)
            status(v) = VStatus::VISITED;
    }
}