#include <iostream>
#include <vector>
#include <queue>
#include "graph.hpp"


using namespace std;

Linkedlist List;

GraphNode::GraphNode(int id) : m_id(id), m_distance(0), m_visited(false){}

void print_linked_list(Linkedlist l){

	if(l != NULL){
	
		cout << l->val->getId() << " ";
		print_linked_list(l->next);
	
	}else{
		cout << endl;
	}
}

int GraphNode::getId() const {

    return m_id;

}

void GraphNode::add_edge(GraphEdge* edge) {
    m_edges.push_back(edge); 
}

std::vector<GraphEdge*> GraphNode::getEdges() const {
    return m_edges;
}

vector<GraphNode *> GraphNode::SNQ(GraphNode* Node) const{
    int i = 0;
    vector<GraphEdge *> edges = Node->getEdges();
    vector<GraphNode *> neighbours;
    while (edges[i] != NULL)
    {
        neighbours.push_back(edges[i]->getDst());
    }
    return neighbours;
}

int GraphNode::getDist() const {
    return m_distance;
}

void GraphNode::setVerif(bool boolean){
    m_visited = boolean;
}

void GraphNode::setDistance(int distance){
    m_distance = distance;
}

void GraphNode::setFinish(int time){
    m_finish = time;
}

bool GraphNode::getVerif() const {
    return m_visited;
    }

void GraphNode::BFS(vector<GraphNode*> graph){


    //Default : nothing as been visited and the distance are 0
    for (int i = 0; i < graph.size(); i++)
    {
        graph[i]->m_pred = NULL;
        graph[i]->m_visited = false;
        graph[i]->m_distance = 0;
    }
    
    //Queue system
    queue<GraphNode*> queue;
    
    //Starting node as been visited
    this->m_visited = true;

    queue.push(this);

    

    while(!queue.empty()){
        //Take first element of the queue
        GraphNode* u = queue.front();
        cout << u->getId() << " ";
        //Erase this element from the queue
        queue.pop();

        //Get the list of the edges of the current node
        vector<GraphEdge*> list = u->getEdges();

        /*cout << "Size : " << list.size() << endl;*/
        for (int i = 0; i < list.size(); i++)
        {
            int v = list[i]->getDst()->getId();
            if (!list[i]->getDst()->getVerif())
            {
                list[i]->getDst()->m_pred = u;
                list[i]->getDst()->m_distance = u->getDist() + 1;
                list[i]->getDst()->setVerif(true);
                queue.push(list[i]->getDst());
            }
            
        }
        cout << "distance from start : " << u->getDist() << " " << endl;

    }
    cout << endl;

}

void GraphNode::DFS(vector<GraphNode*> graph){
    

    //Default : nothing as been visited and the distance are 0
    for (int i = 0; i < graph.size(); i++)
    {
        graph[i]->m_visited = false;
        graph[i]->m_pred = NULL;
    }

    int time = 0;

    for (int i = 0; i <graph.size(); i++)
    {
        if (!graph[i]->m_visited)
        {   
                DFS_VISIT(graph[i],time);

        }
        
    }
   
    
}

void DFS_VISIT(GraphNode* Node, int time){

    time = time + 1;
    Node->setDistance(time);
    Node->setVerif(true);
    vector<GraphEdge*> list = Node->getEdges();
    for (int j = 0; j < list.size(); j++)
    {
        if (!(list[j]->getDst()->getVerif()))
        {
            DFS_VISIT(list[j]->getDst(),time);
        }
        
    }
    time = time + 1;
    Node->setFinish(time);
    List =  insert_head(List,Node);
    
    

    
}

void GraphNode::ShortestPath(GraphNode* Destination){
    if (this == Destination)
    {
        cout << this->m_id << " ";
    }else if(Destination->m_pred == NULL)
    {
        cout << "No path from " << this->m_id << " to " << Destination->m_id << endl;
    }else{
        
        
        this->ShortestPath(Destination->m_pred); 
        cout << Destination->m_id << " ";
    }
    
    
}

Linkedlist insert_head(Linkedlist l, GraphNode *Node){
    
    Linkedlist temp;
	temp = (DListElement *)malloc(sizeof(DListElement));
	temp->val = Node;
	temp->next = l;
	return temp;
    
    
}

Linkedlist GraphNode::Topological_sort(vector<GraphNode*> graph){
    List = NULL;
    graph[0]->DFS(graph);
    return List;

}