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
    for (int i = 0; i < graph.size() ; i++)
    {
        //for each edge (u,v) in G.edges
        for (int j = 0; j < EdgeList.size(); j++)
        {
            EdgeList[j]->relax();
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

void Graph::DAG_shortest_paths(GraphNode *source){

    vector<GraphNode *> Initgraph = this->getList();
    
    Linkedlist SortedGraph = NULL;

    SortedGraph = Initgraph[1]->Topological_sort(Initgraph);

    source->Initialize_single_source(Initgraph);

    while (SortedGraph != NULL)
    {
        GraphNode *Node = SortedGraph->val;
        vector<GraphEdge *> EList = Node->getEdges();
        for (int i = 0; i < EList.size(); i++)
        {
            EList[i]->relax();
        }

        SortedGraph = SortedGraph->next;
    }
    
    

}

void Graph::Dijkstra(GraphNode *source){
    vector<GraphNode *> Initgraph = this->getList();
    source->Initialize_single_source(Initgraph);

    //Min priority queue
    priority_queue<GraphNode *, vector<GraphNode *>, Compare> Q;
    // Q = G.V 
    for (int i = 0; i< v_list.size(); i++)
    {
        Q.push(v_list[i]);
    }

    while (!Q.empty())
    {
        GraphNode *U = Q.top();
        Q.pop();
        vector<GraphEdge *> EdgeList = U->getEdges();
        for (int i = 0; i < EdgeList.size(); i++)
        {
            EdgeList[i]->relax();
        }
        
    }
    
}

vector<vector<int>> Graph::floyd_marshall(vector<vector<int>>& pred){
    //GET W
    vector<vector<int>> W = this->ListtoMatrix();
    //N NUMBER OF ROWS/COLUMN
    int n = W.size();
    //D = W
    vector<vector<int>> D = W;
    vector<GraphNode *> Vlist;

    for (int k = 0; k < n; k++)
    {
        
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (k == 0)
                {
                    
                    if (i==j || W[i][j] == INF)
                    {
                        
                        pred[i][j] = INF;
                    }else if (i != j && W[i][j] < INF)
                    {
                        
                        pred[i][j] = i+1;
                    }
                    
                }
                if (D[i][j] <= D[i][k] + D[k][j])
                {
                    pred[i][j] = pred[i][j];
                }else if (D[i][j] > D[i][k] + D[k][j])
                {
                    pred[i][j] = pred[k][j];
                }
                
                
                
                D[i][j] = min(D[i][j],D[i][k] + D[k][j]);
                
            }
            
        }
        
    }
    return D;
    
}

vector<vector<int>> Graph::ListtoMatrix(){
    //Compute MATRIX W
    vector<GraphNode *> Vlist = this->getList();

    int num_vertices = Vlist.size();

    // Create an n x n matrix initialized with INF
    vector<vector<int>> adj_matrix(num_vertices, vector<int>(num_vertices, INF));

    // Iterate through each vertex and its neighbors, marking the corresponding entry in the matrix as 1
    for (int vertex = 0; vertex < num_vertices; vertex++) {
        vector<GraphNode *> Nlist = Vlist[vertex]->SNQ();
        vector<GraphEdge *> Elist = Vlist[vertex]->getEdges();
        for (int neighbor = 0; neighbor < Nlist.size(); neighbor++) {
            
            
            if (Nlist[neighbor])
            {
                adj_matrix[vertex][Nlist[neighbor]->getId()] = Elist[neighbor]->getWeight();

            }
            
        }
    }
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            if (i == j)
            {
                adj_matrix[i][j] = 0;
            }
            
        }
        
    }
    
    return adj_matrix;
}

vector<vector<int>> Graph::Slow_all_pairs_shortest_paths(){
    vector<vector<int>> W = this->ListtoMatrix();
    vector<vector<int>> L = W;
    int n = W.size();
    for (int m = 2; m < n ; m++)
    {
        L = Extended_shortest_path(L,W);
    }
    return L;
    
}

vector<vector<int>> Graph::Faster_all_pairs_shortest_paths(){
    vector<vector<int>> W = this->ListtoMatrix();
    int n = W.size();
    vector<vector<int>> L = W;
    int m = 1;
    while (m < n - 1)
    {
        L = Extended_shortest_path(L,L);
        m = 2*m;
    }
    return L;
}

vector<vector<int>> Extended_shortest_path(vector<vector<int>> L, vector<vector<int>> W){
    int n = L.size();
    vector<vector<int>> L2(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            L2[i][j] = INF;
            for (int k = 0; k < n; k++)
            {
                L2[i][j] = min(L2[i][j],L[i][k] + W[k][j]);
            }
            
        }
        
    }
    return L2;
     
}

void PairShortestPath(vector<vector<int>> pred, int i, int j){
    if (i == j)
    {   
        // I add 1 so I can compare to the graph in the pdf
        cout << i + 1;
    }else if (pred[i][j] == INF)
    {
        cout << "Not path from " << i << " to " << j << " exists" << endl;
    }else
    {
        PairShortestPath(pred,i,pred[i][j]-1);
        cout << j + 1;
    }
    
    
    
}
vector<vector<int>> Graph::TransitiveClosure(){
    int n = this->getList().size();
    bool verif = false;

    vector<vector<int>> prevT;
    vector<GraphNode *> NodeList = this->getList();
    vector<vector<int>> T(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            vector<GraphNode *> Neighbors = NodeList[i]->SNQ();

            for (int l = 0; l < Neighbors.size(); l++)
            {
                if (Neighbors[l]->getId() == j)
                {
                    verif = true;
                }
                
            }
            //cout << i << " " << j << " "<< verif << endl;
            if (i == j || verif)
            {
                T[i][j] = 1;

            }else
            {
                T[i][j] = 0; 
            }

            verif = false;
        }
        
    }

    for (int k = 0; k < n; k++)
    {
        vector<vector<int>> nextT(n, vector<int>(n, 0)); 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nextT[i][j] = T[i][j] || (T[i][k] && T[k][j]);
            }
            
        }
        T = nextT;

    }
    return T;
}

vector<vector<int>> Graph::Johnson(){
    Graph* G2 = this;
    vector<int> h(G2->getList().size(),INF);
    GraphNode newNode(G2->getList().size());
    vector<GraphNode *> Vlist = this->getList();
    G2->insert_vert(&newNode);
    int compteur = Vlist.size();
    for (int i = 0; i < Vlist.size(); i++)
    {
        auto edge = new GraphEdge(&newNode, Vlist[i],0,G2);
        newNode.add_edge(edge);
    }

    if (!G2->Bellman_ford(&newNode))
    {
        cout << "the input graph contain a negative-weight cycle" << endl;
        vector<vector<int>> def(G2->getList().size(), vector<int>(G2->getList().size(), INF)); 
        return def;
    }else
    {
        vector<GraphNode *> Nodelist = G2->getList(); 
        int weight;
        //Line 4
        /*for (int i = 0; i < Nodelist.size(); i++)
        {
            G2->Bellman_ford(Nodelist[i]);
            vector<GraphEdge* > Edge = newNode.getEdges();
            for (int j = 0; j < newNode.getEdges().size(); j++)
            {
                if (Edge[j]->getDst()->getId() == Nodelist[i]->getId())
                {
                    weight = Edge[j]->getWeight();
                }
                
            }
            
            h[Nodelist[i]->getId()] = weight;

        }*/
        //Line 6
        vector<GraphEdge *> EdgeList = G2->getEdgeList();
        for (int i = 0; i < EdgeList.size(); i++)
        {
            EdgeList[i]->setWeight(EdgeList[i]->getWeight() +  h[EdgeList[i]->getSrc()->getId()] - h[EdgeList[i]->getDst()->getId()]);
        }

        vector<vector<int>> D(this->getList().size() - 1, vector<int>(this->getList().size() - 1, 0));
        //Line 9
        Nodelist.pop_back();
        Nodelist = this->getList();
        Nodelist.pop_back();
        cout << Nodelist.size() << endl;
        cout << this->getList().size()<<endl;
        bool existed = false;
        vector<int> distance(Nodelist.size(),INF);
        for (int i = 0; i < Nodelist.size(); i++)
        {
            G2->Dijkstra(Nodelist[i]);
            distance[Nodelist[i]->getId()] = Nodelist[i]->getDist();
            for (int j = 0; j < Nodelist.size(); j++)
            {   
                D[i][j] = distance[j] + h[Nodelist[j]->getId()] - h[Nodelist[i]->getId()];
                
            }
                            
                

        }
        
        return D;
        
    }
    
    
    
}

void Graph::insert_vert(GraphNode* Node){
    v_list.push_back(Node);
}

void Graph::FordFulkerson(GraphNode* source, GraphNode* sink){
    int residual;
    vector<GraphEdge *>EdgeList = this->getEdgeList();
    for (int i = 0; i < EdgeList.size(); i++)
    {
        EdgeList[i]->setFlow(0);
    }
    vector<GraphNode* > Vlist = this->getList();
    source->BFS(Vlist);
    while (sink->getVerif())
    {
        
    }
    
    
}