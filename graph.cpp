#include <iostream>
#include "graph.hpp"
#include <vector>

using namespace std;



void Graph::insert_node(int nbVert){
    //VERTICES
    cout << "nbvert = " << nbVert <<endl;
    for (int i = 0; i < nbVert; i++)
    {
        auto vert = new GraphNode(i);
        v_list.push_back(vert);
    }
}

void Graph::insert_edge(GraphEdge* Edge){
    this->e_list.push_back(Edge);
}

vector<GraphNode *> Graph::getList(){
    return this->v_list;
}

std::vector<GraphEdge *> Graph::getEdgelist(){
    return this->e_list;
}

void Graph::transposeGraph(Graph* graph){
    //ALL THE VERTICES FOR THE TRANSPOSE ARE THE SAME
    graph->insert_node(this->v_list.size());
    
    //GET EVERY VERTICES FROM GRAPH
    vector<GraphNode *> graphl = graph->getList();
    
    for (int i = 0; i < this->v_list.size(); i++)
    {
        //GET EVERY NEIGHBOR OF EVERY VERTICES
        vector<GraphNode *> nlist = this->v_list[i]->SNQ();
        
        for (int j = 0; j < nlist.size(); j++)
        {
            auto nedge = new GraphEdge(graphl[nlist[j]->getId()],graphl[this->v_list[i]->getId()],0);
            graphl[nlist[j]->getId()]->add_edge(nedge);
        }
        
        
    }
    
}

std::vector<std::vector<GraphNode *>> Graph::SCC(){

    vector<GraphNode *> Initgraph = this->getList();
    Initgraph[2]->DFS(Initgraph);
    
    Graph GT;
    this->transposeGraph(&GT);
    
    vector<GraphNode *> Transgraph = GT.getList();

    
    vector<GraphNode *> GTlist = GT.getList();
    cout << Initgraph[3]->getDist() << endl;
    cout << Initgraph[3]->getFinish() << endl;
    vector<std::vector<GraphNode *>> test;
    return test;
}