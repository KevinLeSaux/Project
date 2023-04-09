#include <iostream>
#include <vector>
#include <typeinfo>

#include "graph.hpp"

using namespace std;

int main(){
    
    //Initalisation of my graph
    
    Graph test;
    test.insert_node(8);
    
    vector<GraphNode *> graph = test.getList();
    
    //EDGES
    GraphEdge edge0to1(graph[0],graph[1],4);
    GraphEdge edge1to2(graph[1],graph[2],0);
    GraphEdge edge2to3(graph[2],graph[3],0);
    GraphEdge edge3to2(graph[3],graph[2],0);
    GraphEdge edge3to7(graph[3],graph[7],0);
    GraphEdge edge7to7(graph[7],graph[7],0);
    GraphEdge edge6to7(graph[6],graph[7],0);
    GraphEdge edge5to6(graph[5],graph[6],0);
    GraphEdge edge2to6(graph[2],graph[6],0);
    GraphEdge edge6to5(graph[6],graph[5],0);
    GraphEdge edge1to4(graph[1],graph[4],0);
    GraphEdge edge4to0(graph[5],graph[0],0);
    GraphEdge edge4to5(graph[4],graph[5],0);
    
    graph[0]->add_edge(&edge0to1);
    graph[1]->add_edge(&edge1to2);
    graph[1]->add_edge(&edge1to4);
    graph[2]->add_edge(&edge2to3);
    graph[2]->add_edge(&edge2to6);
    graph[3]->add_edge(&edge3to7);
    graph[3]->add_edge(&edge3to2);
    graph[4]->add_edge(&edge4to0);
    graph[4]->add_edge(&edge4to5);
    graph[5]->add_edge(&edge5to6);
    graph[6]->add_edge(&edge6to5);
    graph[6]->add_edge(&edge6to7);
    graph[7]->add_edge(&edge7to7);

    cout << "Start : " << graph[1]->getId() << endl;
    graph[1]->BFS(graph);

    cout << "Shortest Path : " << endl;
    graph[1]->ShortestPath(graph[7]);
    cout << endl;

    graph[0]->DFS(graph);
    
    Linkedlist List = NULL;
    
    cout << "Topological sort : " << endl;
    List = graph[1]->Topological_sort(graph);
    print_linked_list(List);
/*
    cout << "Transpose" << endl;
    
    Graph GT;
    test.transposeGraph(&GT);
    
    vector<GraphNode *> GTlist = GT.getList();
    GTlist[4]->BFS(GTlist);
    */
    
    test.SCC();
    return 0;
    
}