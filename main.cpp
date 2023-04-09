#include <iostream>
#include <vector>
#include <typeinfo>

#include "graph.hpp"

using namespace std;

int main(){
    
    //Initalisation of my graph
    
    Graph test;
    test.insert_node(5);

    vector<GraphNode *> graph = test.getList();
    
    //EDGES
    GraphEdge edge0to1(graph[0],graph[1],4);
    GraphEdge edge1to2(graph[1],graph[2],0);
    GraphEdge edge2to3(graph[2],graph[3],0);
    GraphEdge edge3to0(graph[3],graph[0],0);
    GraphEdge edge1to3(graph[1],graph[3],0);
    GraphEdge edge1to5(graph[1],graph[5],0);
    GraphEdge edge5to4(graph[5],graph[4],0);
    GraphEdge edge2to4(graph[2],graph[4],0);

    //vert.add_edge(&edge0to1);
    graph[1]->add_edge(&edge1to2);
    graph[1]->add_edge(&edge1to3);
    graph[2]->add_edge(&edge2to3);
    graph[3]->add_edge(&edge3to0);
    graph[1]->add_edge(&edge1to5);
    graph[5]->add_edge(&edge5to4);
    graph[2]->add_edge(&edge2to4);
    

    cout << "Start : " << graph[1]->getId() << endl;
    graph[1]->BFS(graph);

    cout << "Shortest Path : " << endl;
    graph[1]->ShortestPath(graph[4]);
    cout << endl;

    graph[0]->DFS(graph);
    
    Linkedlist List = NULL;
    
    cout << "Topological sort : " << endl;
    List = graph[1]->Topological_sort(graph);
    print_linked_list(List);
    
    return 0;
    
}