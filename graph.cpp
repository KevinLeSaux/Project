#include <iostream>
#include "graph.hpp"
#include <vector>

using namespace std;

vector<vector<GraphNode *>> result;

void Graph::insert_node(int nbVert){
    //VERTICES
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

vector<vector<GraphNode *>> Graph::SCC(){

    vector<GraphNode *> Initgraph = this->getList();
    
    Linkedlist SortedGraph = NULL;
    //USES DFS AND I GET THE SORTED LIST
    SortedGraph = Initgraph[1]->Topological_sort(Initgraph);

    //print_linked_list(SortedGraph);

    //TRANSPOSE OF THE GRAPH
    Graph GT;
    
    this->transposeGraph(&GT);
    vector<GraphNode *> Transgraph = GT.getList();
    
    

    int count = 0;
    int i = 0;

    while (SortedGraph!=NULL)
    {
      
        
        if (!Transgraph[SortedGraph->val->getId()]->getVerif())
        { 

            result.push_back(vector<GraphNode *>{Transgraph[SortedGraph->val->getId()]});

            DFS_VISIT_SCC(Transgraph[SortedGraph->val->getId()],count);
            count = count + 1;

        }
        SortedGraph = SortedGraph->next;
        i = i +1;
    }
    
    return result;
}

void DFS_VISIT_SCC(GraphNode* Node,int count){

    Node->setVerif(true);
    vector<GraphEdge*> list = Node->getEdges();
    for (int j = 0; j < list.size(); j++)
    {
        if (!(list[j]->getDst()->getVerif()))
        {
            result[count].push_back(list[j]->getDst()); 
            list[j]->getDst()->setPred(Node);
            DFS_VISIT_SCC(list[j]->getDst(),count);
        }
        
    }
}