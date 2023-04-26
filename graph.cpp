#include <iostream>
#include "graph.hpp"
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

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

std::vector<GraphEdge *> Graph::getEdgeList() const {
    return this->e_list;
}

void Graph::setEdgeList(vector<GraphEdge *> EdgeList){
    e_list == EdgeList;
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
            auto nedge = new GraphEdge(graphl[nlist[j]->getId()],graphl[this->v_list[i]->getId()],0,graph);
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




void Graph::Kruskal(Graph* temp){

    
    vector<GraphNode *> Nodelist = this->getList();
    for (int i = 0; i < Nodelist.size(); i++)
    {
        Nodelist[i]->make_set();
    }
    vector<GraphEdge *> Edgelist = this->e_list;
    quickSort(Edgelist,0,Edgelist.size()-1);
    for (int i = 0; i < Edgelist.size(); i++)
    {
        if (Edgelist[i]->getSrc()->find_set() != Edgelist[i]->getDst()->find_set())
        {
            temp->insert_edge(Edgelist[i]);
            Edgelist[i]->getSrc()->unionSet(Edgelist[i]->getSrc());

        }
        
    }

}

void Graph::MST_PRIM(Graph* temp, GraphNode* start){
    vector<GraphNode *> Vlist = this->v_list;
    for (int i = 0; i < Vlist.size(); i++)
    {
        Vlist[i]->setKey(INF);//INF FOR NOW
        Vlist[i]->setPred(NULL);
    }
    start->setKey(0);
    //min-priority queue
    priority_queue<GraphNode *, vector<GraphNode *>, Compare> Q;
    // Q = G.V 
    for (int i = 0; i< v_list.size(); i++)
    {
        Q.push(v_list[i]);
    }
    
    while (!Q.empty())
    {
        GraphNode *U = Q.top();

        vector<GraphNode *> adjList = U->SNQ();
        vector<GraphEdge *> EdgeList = U->getEdges();
        Q.pop();
        for (int i = 0; i < adjList.size(); i++)
        {
            //Check if v E Q
            bool compared;
            int j = 0;
            priority_queue<GraphNode *, vector<GraphNode *>, Compare> temp = Q;

            while (!compared && !temp.empty())
            {
                if (U->getId() == temp.top()->getId())
                {
                    compared = true;
                }
                temp.pop();
            }
            
            
            if (compared && (EdgeList[i]->getWeight() < adjList[i]->getKey()))
            {
                adjList[i]->setPred(U);
                adjList[i]->setKey(EdgeList[i]->getWeight());
            }
            
        }
        
        
    }
    
}

// Partition function to split the array into two sub-arrays
int partition(vector<GraphEdge *>& arr, int low, int high) {
    GraphEdge *pivot = arr[high]; // choose last element as pivot
    int i = low - 1; // initialize i to be one index before the first element
    for (int j = low; j < high; j++) {
        if (arr[j]->getWeight() < pivot->getWeight()) { // if current element is greater than pivot
            i++; // increment i
            swap(arr[i], arr[j]); // swap the elements at i and j
        }
    }
    swap(arr[i + 1], arr[high]); // swap the pivot with the element at i + 1
    return i + 1; // return the index of the pivot
}

// QuickSort function to sort the array
void quickSort(vector<GraphEdge *>& arr, int low, int high) {
    //At the beginning low = 0
    // high = arr.size() - 1
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // partition the array
        quickSort(arr, low, pivotIndex - 1); // sort the left sub-array
        quickSort(arr, pivotIndex + 1, high); // sort the right sub-array
    }
    
    
}

bool Graph::Bellman_ford(GraphNode *source){

    vector<GraphNode *> graph = this->getList();
    vector<GraphEdge *> EdgeList = this->getEdgeList();

    source->Initialize_single_source(graph);
    

    //for i = 1 to |G.V| - 1 in pdf/book
    for (int i = 1; i < graph.size() ; i++)
    {
        //for each edge (u,v) in G.edges
        for (int j = 0; j < EdgeList.size(); j++)
        {
            EdgeList[i]->relax();
        }
    }    
    for (int i = 0; i < EdgeList.size(); i++)
    {
        GraphNode *u = EdgeList[i]->getSrc();
        GraphNode *v = EdgeList[i]->getDst();
        if (v->getDist() > u->getDist() + EdgeList[i]->getWeight())
        {
            return false;
        }
        
    }
    
    return true;
}

