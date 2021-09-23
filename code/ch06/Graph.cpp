#include "../_share/print.h"  
#include <fstream>
#include <iostream>

using std::cout;

int main(){
    std::ifstream is("./files/tinyG.txt");
    GraphMatrix<WrappedChar, WrappedInt> graph(is, GType::GRAPH);

    putchar('\n');

    //bfs
    std::cout << "BFS:  " << std::endl;
    graph.bfs(0);
    print(graph);
    int n = graph.n;
    for(int i = 0; i < n; i++){
        List<size_t> path;
        size_t pos = i;
        while(pos != -1){
            path.insertAsFirst(pos);
            pos = graph.V()[pos].parent;
        }
        print(path);
    }
    

    
    //dfs
    std::cout << "DFS:  " << std::endl;
    graph.dfs(0);
    //print(graph);
    n = graph.n;
    for(int i = 0; i < n; i++){
        List<size_t> path;
        size_t pos = i;
        while(pos != -1){
            path.insertAsFirst(pos);
            pos = graph.V()[pos].parent;
        }
        print(path);
        //putchar('\n');
    }
    
    return 0;
}