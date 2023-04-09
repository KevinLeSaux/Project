#include <iostream>
#include "graph.hpp"
#include <vector>

using namespace std;

void Graph::insert_node(int nbVert){
    //VERTICES
    for (int i = 0; i < nbVert + 1; i++)
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

Graph Graph::transposeGraph(Graph* graph){
    //GET EVERY VERTICES FROM GRAPH
    for (int i = 0; i < graph.v_list.size; i++)
    {
        //GET EVERY NEIGHBOR OF EVERY VERTICES
        vector<GraphNode *> nlist = graph.v_list[i]->SNQ();

        for (int j = 0; j < nlist.size; j++)
        {
            
            nlist[i].
        }
        
        
    }
    
}