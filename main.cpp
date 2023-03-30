#include <iostream>
#include <vector>
#include <typeinfo>

#include "graphnode.hpp"
#include "graphedge.hpp"
#include "graph.hpp"

using namespace std;

int main(){

    //Initalisation of my graph
    
    //VERTICES
    GraphNode vert(0);
    GraphNode vert1(1);
    GraphNode vert2(2);
    GraphNode vert3(3);
    GraphNode vert4(4);
    GraphNode vert5(5);

    //List of the nodes
    vector<GraphNode *> graph = {
        &vert,&vert1,&vert2,&vert3,&vert4,&vert5
    };

    
    //EDGES
    GraphEdge edge0to1(&vert,&vert1,4);
    GraphEdge edge1to2(&vert1,&vert2,0);
    GraphEdge edge2to3(&vert2,&vert3,0);
    GraphEdge edge3to0(&vert3,&vert,0);
    GraphEdge edge1to3(&vert1,&vert3,0);
    GraphEdge edge1to5(&vert1,&vert5,0);
    GraphEdge edge5to4(&vert5,&vert4,0);
    GraphEdge edge2to4(&vert2,&vert4,0);

    //vert.add_edge(&edge0to1);
    vert1.add_edge(&edge1to2);
    vert1.add_edge(&edge1to3);
    vert2.add_edge(&edge2to3);
    vert3.add_edge(&edge3to0);
    vert1.add_edge(&edge1to5);
    vert5.add_edge(&edge5to4);
    vert2.add_edge(&edge2to4);
    

    cout << "Start : " << graph[1]->getId() << endl;
    graph[1]->BFS(graph);

    cout << "Shortest Path : " << endl;
    vert1.ShortestPath(&vert4);
    cout << endl;

    //graph[0]->DFS(graph);
    
    Linkedlist List = NULL;
    
    cout << "Topological sort : " << endl;
    List = graph[1]->Topological_sort(graph);
    print_linked_list(List);
    
    return 0;
    
}