#pragma once

enum class VStatus {
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

template<typename Tv, typename Te>
class Graph {
private:
    void reset(){
        
    }
};