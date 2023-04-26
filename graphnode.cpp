#include <iostream>
#include <vector>
#include <queue>
#include "graph.hpp"


using namespace std;

Linkedlist List;
int timing;
const int INF = 0x3f3f3f3f;
int visit;

GraphNode::GraphNode(int id) : m_id(id), m_distance(0), m_visited(false), m_pred(NULL) {}

void print_linked_list(Linkedlist l){

	if(l != NULL){
	
		cout << l->val->getId() << " finish : " << l->val->getFinish() << endl;
		print_linked_list(l->next);
	
	}else{
		cout << endl;
	}
}

int GraphNode::getId() const {

    return m_id;

}

int GraphNode::getKey() const {
    return m_key;
}

void GraphNode::add_edge(GraphEdge* edge) {
    m_edges.push_back(edge); 
}

std::vector<GraphEdge*> GraphNode::getEdges() const {
    return m_edges;
}

vector<GraphNode *> GraphNode::SNQ() const{
    int i = 0;
    vector<GraphEdge *> edges = this->getEdges();
    vector<GraphNode *> neighbours;
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbours.push_back(edges[i]->getDst());
    }
    return neighbours;
}

int GraphNode::getDist() const {
    return m_distance;
}

int  GraphNode::getFinish() const {
    return m_finish;
}

void GraphNode::setVerif(bool boolean){
    m_visited = boolean;
}

void GraphNode::setKey(int key){
    m_key = key;
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

    timing = 0;

    for (int i = 0; i <graph.size(); i++)
    {
        if (!graph[i]->m_visited)
        {   
                DFS_VISIT(graph[i]);

        }
        
    }
   
    
}

void DFS_VISIT(GraphNode* Node){

    timing = timing + 1;
    Node->setDistance(timing);
    Node->setVerif(true);
    vector<GraphEdge*> list = Node->getEdges();
    for (int j = 0; j < list.size(); j++)
    {
        if (!(list[j]->getDst()->getVerif()))
        {
            list[j]->getDst()->setPred(Node);
            DFS_VISIT(list[j]->getDst());
        }
        
    }
    timing = timing + 1;
    Node->setFinish(timing);
    List =  insert_head(List,Node);
    
    

    
}

//void GraphNode::DFS_SCC(){}

void GraphNode::setPred(GraphNode* Node){
    m_pred = Node;
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

void GraphNode::make_set(){

    this->parent = this;
    this->rank = 0;

}

GraphNode* GraphNode::find_set(){
    if (this != this->parent)
    {
        this->parent = this->parent->find_set();
    }
    return this->parent;
}

void GraphNode::link(GraphNode* Node){

    if(this->rank > Node->rank){
        Node->parent = this;
    }else{
        this->parent = Node;
        if (this->rank == Node->rank)
        {
            Node->rank = Node->rank+1;
        }
        
    }

}

void GraphNode::unionSet(GraphNode *Node){
    this->find_set()->link(Node->find_set());
}

void GraphNode::Initialize_single_source(std::vector<GraphNode*> graph){
    for (int i = 0; i < graph.size(); i++)
    {
        graph[i]->m_distance = INF;
        graph[i]->m_pred = NULL;
    }
    this->m_distance = 0;
    
}

