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
    
    //GRAPH FOR DIJKSTRA

    Graph DJ;
    DJ.insert_node(6);

    vector<GraphNode *> DJ_graph = DJ.getList();

    //EDGES

    GraphEdge DJedge0to1(DJ_graph[0],DJ_graph[1],10,&DJ);
    GraphEdge DJedge0to3(DJ_graph[0],DJ_graph[3],5,&DJ);
    GraphEdge DJedge4to0(DJ_graph[4],DJ_graph[0],7,&DJ);
    GraphEdge DJedge1to3(DJ_graph[1],DJ_graph[3],2,&DJ);
    GraphEdge DJedge3to1(DJ_graph[3],DJ_graph[1],2,&DJ);
    GraphEdge DJedge1to2(DJ_graph[1],DJ_graph[2],1,&DJ);
    GraphEdge DJedge3to4(DJ_graph[3],DJ_graph[4],2,&DJ);
    GraphEdge DJedge3to2(DJ_graph[3],DJ_graph[2],9,&DJ);
    GraphEdge DJedge4to2(DJ_graph[4],DJ_graph[2],6,&DJ);
    GraphEdge DJedge2to4(DJ_graph[2],DJ_graph[4],4,&DJ);
    GraphEdge DJedge2to5(DJ_graph[2],DJ_graph[5],6,&DJ);
    GraphEdge DJedge4to5(DJ_graph[4],DJ_graph[5],3,&DJ);

    DJ_graph[0]->add_edge(&DJedge0to1);
    DJ_graph[0]->add_edge(&DJedge0to3);
    DJ_graph[4]->add_edge(&DJedge4to0);
    DJ_graph[1]->add_edge(&DJedge1to3);
    DJ_graph[3]->add_edge(&DJedge3to1);
    DJ_graph[1]->add_edge(&DJedge1to2);
    DJ_graph[3]->add_edge(&DJedge3to4);
    DJ_graph[3]->add_edge(&DJedge3to2);
    DJ_graph[4]->add_edge(&DJedge4to2);
    DJ_graph[2]->add_edge(&DJedge2to4);
    DJ_graph[2]->add_edge(&DJedge2to5);
    DJ_graph[4]->add_edge(&DJedge4to5);


    //GRAPH FOR ALL PAIRS SHORTEST PATH

    Graph AP;

    AP.insert_node(5);
    vector<GraphNode *> AP_graph = AP.getList();

    GraphEdge APedge0to1(AP_graph[0],AP_graph[1],3,&AP);
    GraphEdge APedge0to2(AP_graph[0],AP_graph[2],8,&AP);
    GraphEdge APedge0to4(AP_graph[0],AP_graph[4],-4,&AP);
    GraphEdge APedge1to4(AP_graph[1],AP_graph[4],7,&AP);
    GraphEdge APedge1to3(AP_graph[1],AP_graph[3],1,&AP);
    GraphEdge APedge2to1(AP_graph[2],AP_graph[1],4,&AP);
    GraphEdge APedge3to2(AP_graph[3],AP_graph[2],-5,&AP);
    GraphEdge APedge3to0(AP_graph[3],AP_graph[0],2,&AP);
    GraphEdge APedge4to3(AP_graph[4],AP_graph[3],6,&AP);

    AP_graph[0]->add_edge(&APedge0to1);
    AP_graph[0]->add_edge(&APedge0to2);
    AP_graph[0]->add_edge(&APedge0to4);
    AP_graph[1]->add_edge(&APedge1to4);
    AP_graph[1]->add_edge(&APedge1to3);
    AP_graph[2]->add_edge(&APedge2to1);
    AP_graph[3]->add_edge(&APedge3to2);
    AP_graph[3]->add_edge(&APedge3to0);
    AP_graph[4]->add_edge(&APedge4to3);


    cout << "Start : " << graph[0]->getId() << endl;
    graph[0]->BFS(graph);

    cout << "Shortest Path : " << endl;
    graph[0]->ShortestPath(graph[4]);
    cout << endl;

    //graph[0]->DFS(graph);
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
    
    
    //Graph A;
    //test.Kruskal(&A);
    
    cout << "Shortest path with Bellman-Ford" << endl;
    bool ford;
    ford = test.Bellman_ford(graph[0]);
    graph[0]->ShortestPath(graph[4]);
    cout << endl;
    

    cout << "Shortest Path with Dijkstra" << endl;
    DJ.Dijkstra(DJ_graph[0]);
    DJ_graph[0]->ShortestPath(DJ_graph[2]);
    cout << endl;

    cout << "Shortest path with matrix" << endl;
    //DJ.floyd_marshall();
    
    vector<vector<int>> test2 = AP.ListtoMatrix();
    

    for (int i = 0; i < test2.size(); i++)
    {
        for (int j = 0; j < test2.size(); j++)
        {
            cout << test2[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Distance : " << endl;
    test2 = AP.Slow_all_pairs_shortest_paths();
    

    for (int i = 0; i < test2.size(); i++)
    {
        for (int j = 0; j < test2.size(); j++)
        {
            cout << test2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}