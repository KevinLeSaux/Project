#include <iostream>
#include <vector>
#include <typeinfo>

#include "graph.hpp"

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){


    
    //Initalisation of my graphs

    //Graph for Strongly connected component page 616 on pdf
    
    Graph SCC;
    SCC.insert_node(8);
    
    vector<GraphNode *> SCCgraph = SCC.getList();
    
    
    //EDGES
    GraphEdge SCCedge0to1(SCCgraph[0],SCCgraph[1],7,&SCC);
    GraphEdge SCCedge1to2(SCCgraph[1],SCCgraph[2],7,&SCC);
    GraphEdge SCCedge2to3(SCCgraph[2],SCCgraph[3],3,&SCC);
    GraphEdge SCCedge3to2(SCCgraph[3],SCCgraph[2],1,&SCC);
    GraphEdge SCCedge3to7(SCCgraph[3],SCCgraph[7],9,&SCC);
    GraphEdge SCCedge7to7(SCCgraph[7],SCCgraph[7],4,&SCC);
    GraphEdge SCCedge6to7(SCCgraph[6],SCCgraph[7],2,&SCC);
    GraphEdge SCCedge5to6(SCCgraph[5],SCCgraph[6],4,&SCC);
    GraphEdge SCCedge2to6(SCCgraph[2],SCCgraph[6],1,&SCC);
    GraphEdge SCCedge6to5(SCCgraph[6],SCCgraph[5],8,&SCC);
    GraphEdge SCCedge1to4(SCCgraph[1],SCCgraph[4],9,&SCC);
    GraphEdge SCCedge4to0(SCCgraph[5],SCCgraph[0],0,&SCC);
    GraphEdge SCCedge4to5(SCCgraph[4],SCCgraph[5],7,&SCC);
    

    SCCgraph[0]->add_edge(&SCCedge0to1);
    SCCgraph[1]->add_edge(&SCCedge1to4);
    SCCgraph[2]->add_edge(&SCCedge2to3);
    SCCgraph[2]->add_edge(&SCCedge2to6);
    SCCgraph[3]->add_edge(&SCCedge3to7);
    SCCgraph[3]->add_edge(&SCCedge3to2);
    SCCgraph[4]->add_edge(&SCCedge4to0);
    SCCgraph[4]->add_edge(&SCCedge4to5);
    SCCgraph[5]->add_edge(&SCCedge5to6);
    SCCgraph[6]->add_edge(&SCCedge6to5);
    SCCgraph[6]->add_edge(&SCCedge6to7);
    SCCgraph[7]->add_edge(&SCCedge7to7);

    

    //Graph for Bellman-Ford page 652 on pdf

    Graph bellman;
    bellman.insert_node(5);

    vector<GraphNode *> graph = bellman.getList();

    //EDGES

    GraphEdge edge0to1(graph[0],graph[1],6,&bellman);
    GraphEdge edge0to3(graph[0],graph[3],7,&bellman);
    GraphEdge edge4to0(graph[4],graph[0],2,&bellman);
    GraphEdge edge1to3(graph[1],graph[3],8,&bellman);
    GraphEdge edge1to2(graph[1],graph[2],5,&bellman);
    GraphEdge edge2to1(graph[2],graph[1],-2,&bellman);
    GraphEdge edge3to4(graph[3],graph[4],9,&bellman);
    GraphEdge edge3to2(graph[3],graph[2],-3,&bellman);
    GraphEdge edge1to4(graph[1],graph[4],-4,&bellman);
    GraphEdge edge4to2(graph[4],graph[2],7,&bellman);

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
    
    //GRAPH FOR DIJKSTRA page 659 on pdf

    Graph DJ;
    DJ.insert_node(6);

    vector<GraphNode *> DJ_graph = DJ.getList();

    //EDGES

    GraphEdge DJedge0to1(DJ_graph[0],DJ_graph[1],10,&DJ);
    GraphEdge DJedge0to3(DJ_graph[0],DJ_graph[3],5,&DJ);
    GraphEdge DJedge4to0(DJ_graph[4],DJ_graph[0],7,&DJ);
    GraphEdge DJedge1to3(DJ_graph[1],DJ_graph[3],2,&DJ);
    GraphEdge DJedge3to1(DJ_graph[3],DJ_graph[1],3,&DJ);
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


    //GRAPH FOR ALL PAIRS SHORTEST PATH page 690 in pdf

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


    //Graph for transitive closure from page 698 in pdf

    Graph TC;

    TC.insert_node(4);

    vector<GraphNode *> TC_graph = TC.getList();

    GraphEdge TCedge3to0(TC_graph[3],AP_graph[0],0,&TC);
    GraphEdge TCedge1to3(TC_graph[1],AP_graph[3],0,&TC);
    GraphEdge TCedge3to2(TC_graph[3],AP_graph[2],0,&TC);
    GraphEdge TCedge1to2(TC_graph[1],AP_graph[2],0,&TC);
    GraphEdge TCedge2to1(TC_graph[2],AP_graph[1],0,&TC);

    TC_graph[1]->add_edge(&TCedge1to3);
    TC_graph[1]->add_edge(&TCedge1to2);
    TC_graph[2]->add_edge(&TCedge2to1);
    TC_graph[3]->add_edge(&TCedge3to0);
    TC_graph[3]->add_edge(&TCedge3to2);


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
    vector<vector<GraphNode *>> component = SCC.SCC();
    
    for (int i = 0; i < component.size(); i++)
    {
        for (int j = 0; j < component[i].size(); j++)
        {
            cout << component[i][j]->getId() << " " ;
        }
        cout << endl;
    }
    
    
    
    
    cout << "Shortest path with Bellman-Ford" << endl;
    bool ford;
    ford = bellman.Bellman_ford(graph[0]);
    graph[0]->ShortestPath(graph[4]);
    cout << endl;
    

    cout << "Shortest Path with Dijkstra" << endl;
    DJ.Dijkstra(DJ_graph[0]);
    DJ_graph[0]->ShortestPath(DJ_graph[2]);
    cout << endl;

    cout << "Matrix W  : " << endl;
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
    cout << "With Slow" << endl;

    for (int i = 0; i < test2.size(); i++)
    {
        for (int j = 0; j < test2.size(); j++)
        {
            cout << test2[i][j] << " ";
        }
        cout << endl;
    }
    vector<vector<int>> test3 = AP.Faster_all_pairs_shortest_paths();
    cout << "With Faster : " << endl;

    for (int i = 0; i < test3.size(); i++)
    {
        for (int j = 0; j < test3.size(); j++)
        {
            cout << test3[i][j] << " ";
        }
        cout << endl;
    }
    vector<vector<int>> predMat(test3.size(), vector<int>(test3.size(), INF));
    vector<vector<int>> test4 = AP.floyd_marshall(predMat);
    cout << "With floyd marshall : " << endl;

    for (int i = 0; i < test4.size(); i++)
    {
        for (int j = 0; j < test4.size(); j++)
        {
            cout << test4[i][j] << " ";
        }
        cout << endl;
    }

    
    cout << "Pred Matrix : " << endl;
    for (int i = 0; i < predMat.size(); i++)
    {
        for (int j = 0; j < predMat.size(); j++)
        {
            cout << predMat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Shortest Path from 1 to 3 (in pdf, here 0 to 2 because we start at 0)" << endl;
    PairShortestPath(predMat,0,2);
    cout << endl;

    cout << "Transitive closure" << endl;
    vector<vector<int>> TransitiveCLose = TC.TransitiveClosure();

    for (int i = 0; i < TransitiveCLose.size(); i++)
    {
        for (int j = 0; j < TransitiveCLose.size(); j++)
        {
            cout << TransitiveCLose[i][j] << " ";
        }
        cout << endl;
    }
    
    vector<int>testvect = {1,2};
    testvect.push_back(3);
    for (int i = 0; i < testvect.size(); i++)
    {
            cout << testvect[i];
    }
    
    cout << endl;

    cout << "Johnson" << endl;
    vector<vector<int>> JohnsonDist = AP.Johnson();

    for (int i = 0; i < JohnsonDist.size(); i++)
    {
        for (int j = 0; j < JohnsonDist.size(); j++)
        {
            cout << JohnsonDist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}