#include "../_share/print.h"  
#include <fstream>
#include <iostream>

using std::cout;

int main(){
    std::ifstream is("./files/tinyCG.txt");
    GraphMatrix<char, WrappedInt> graph(is, GType::GRAPH);

    print(graph);
    putchar('\n');

    graph.bfs(0);

    print(graph);
    /*bfs
    for(int v = 0; v < graph.n; v++){
        cout << s << " to " << v << ": ";
        if(bfs->marked(v))
            for(int x: bfs->pathTo(v))
                if(x == s) cout << x;
                else cout << "-" << x;
        cout << endl;
    }
    */
    return 0;
}