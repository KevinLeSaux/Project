#include <iostream>
#include <vector>
#include <typeinfo>

#include "graph.hpp"

using namespace std;

int main(){
    
    //Initalisation of my graphs

    //Graph for Strongly connected component
    /*
    Graph test;
    test.insert_node(8);
    
    vector<GraphNode *> graph = test.getList();
    
    
    //EDGES
    GraphEdge edge0to1(graph[0],graph[1],4,&test);
    GraphEdge edge1to2(graph[1],graph[2],7,&test);
    GraphEdge edge2to3(graph[2],graph[3],3,&test);
    GraphEdge edge3to2(graph[3],graph[2],1,&test);
    GraphEdge edge3to7(graph[3],graph[7],9,&test);
    GraphEdge edge7to7(graph[7],graph[7],4,&test);
    GraphEdge edge6to7(graph[6],graph[7],2,&test);
    GraphEdge edge5to6(graph[5],graph[6],4,&test);
    GraphEdge edge2to6(graph[2],graph[6],1,&test);
    GraphEdge edge6to5(graph[6],graph[5],8,&test);
    GraphEdge edge1to4(graph[1],graph[4],9,&test);
    GraphEdge edge4to0(graph[5],graph[0],0,&test);
    GraphEdge edge4to5(graph[4],graph[5],7,&test);
    

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

    */

    //Graph for Bellman-Ford

    Graph test;
    test.insert_node(5);

    vector<GraphNode *> graph = test.getList();

    //EDGES

    GraphEdge edge0to1(graph[0],graph[1],6,&test);
    GraphEdge edge0to3(graph[0],graph[3],7,&test);
    GraphEdge edge4to0(graph[4],graph[0],2,&test);
    GraphEdge edge1to3(graph[1],graph[3],8,&test);
    GraphEdge edge1to2(graph[1],graph[2],5,&test);
    GraphEdge edge2to1(graph[2],graph[1],-2,&test);
    GraphEdge edge3to4(graph[3],graph[4],9,&test);
    GraphEdge edge3to2(graph[3],graph[2],-3,&test);
    GraphEdge edge1to4(graph[1],graph[4],-4,&test);
    GraphEdge edge4to2(graph[4],graph[2],7,&test);

    graph[0]->add_edge(&edge0to1);
    graph[0]->add_edge(&edge0to3);
    graph[4]->add_edge(&edge4to0);
    graph[1]->add_edge(&edge1to3);
    graph[1]->add_edge(&edge1to2);
    graph[2]->add_edge(&edge2to1);
    graph[3]->add_edge(&edge3to4);
    graph[3]->add_edge(&edge3to2);
    graph[1]->add_edge(&edge1to4);
    graph[4]->add_edge(&edge4to2);
    

    cout << "Start : " << graph[0]->getId() << endl;
    graph[0]->BFS(graph);

    cout << "Shortest Path : " << endl;
    graph[0]->ShortestPath(graph[4]);
    cout << endl;

    graph[0]->DFS(graph);
    /*
    cout << "Topological sort : " << endl;
    Linkedlist SortedGraph = NULL;
    SortedGraph = graph[1]->Topological_sort(graph);
    print_linked_list(SortedGraph);
    */
/*
    cout << "Transpose" << endl;
    
    Graph GT;
    test.transposeGraph(&GT);
    
    vector<GraphNode *> GTlist = GT.getList();
    GTlist[4]->BFS(GTlist);
    */
 
   cout << endl;
   //Strongly connected component
   cout << "Strongly connected component" << endl;
    vector<vector<GraphNode *>> component = test.SCC();
    
    for (int i = 0; i < component.size(); i++)
    {
        for (int j = 0; j < component[i].size(); j++)
        {
            cout << component[i][j]->getId() << " " ;
        }
        cout << endl;
    }
    
    
    Graph A;
    test.Kruskal(&A);
    
    cout << "Shortest path with Bellman-Ford" << endl;
    bool ford;
    ford = test.Bellman_ford(graph[1]);
    //graph[1]->BFS(graph);
    cout << ford << endl;
    cout << true << endl;
    graph[0]->ShortestPath(graph[4]);
    return 0;
    
}