#ifndef DEF_GRAPH
#define DEF_GRAPH

#include <vector>
#include "graph.hpp"

class GraphNode;

//LINKED LIST FOR TOPOLOGICAL SORT
typedef struct elem {

GraphNode *val;
struct elem *next;


}DListElement;

typedef DListElement *Linkedlist;

Linkedlist insert_head(Linkedlist l, GraphNode *Node);
void print_linked_list(Linkedlist l);


class GraphEdge;

//GRAPHNODE

class GraphNode
{
    public:
        //Constructor
        GraphNode(int id);


        //Accessors
        int getId() const;
        bool getVerif() const;
        int getDist() const;
        int  getFinish() const;
        int getKey() const;
        std::vector<GraphEdge*>getEdges() const;
        //simple neighbourhood queries
        std::vector<GraphNode *> SNQ() const;
        void ShortestPath(GraphNode* Destination);
        void BFS(std::vector<GraphNode*> graph);
        void DFS(std::vector<GraphNode*> graph);
        void Initialize_single_source(std::vector<GraphNode*> graph);
        Linkedlist Topological_sort(std::vector<GraphNode*> graph);
        
        //Mutator
        void add_edge(GraphEdge* edge);
        void setVerif(bool boolean);
        void setDistance(int distance);
        void setFinish(int time);
        void setPred(GraphNode* Node);
        void setKey(int key);
        void make_set();
        GraphNode* find_set();
        void link(GraphNode* Node);
        void unionSet(GraphNode *Node);

    private:
        int m_id;
        int m_distance;
        int m_finish;
        bool m_visited;
        GraphNode* m_pred;
        std::vector<GraphEdge*> m_edges;
        GraphNode* parent;
        int rank;
        int m_key; //minimum weight of any edge connecting 
        

};

void DFS_VISIT(GraphNode* Node);

//GRAPH EDGE
class Graph;
class GraphEdge
{
    public:
        //Constructor
        GraphEdge(GraphNode* src, GraphNode* dst, double weight, Graph* graph);

        //Mutator
        void relax();

        //Accessors
        GraphNode* getSrc() const;
        GraphNode* getDst() const;
        double getWeight() const;

    private:
        GraphNode* m_src;
        GraphNode* m_dst;
        double m_weight;
        

};


//GRAPH

class Graph
{
    public : 
        //MUTATOR
        void insert_node(int nbVert);
        void insert_edge(GraphEdge* Edge);
        void setEdgeList(std::vector<GraphEdge *> EdgeList);
        bool Bellman_ford(GraphNode *source);


        //ACCESSOR
        std::vector<GraphNode *> getList();
        std::vector<GraphEdge *> getEdgeList() const;
        void transposeGraph(Graph* graph);
        std::vector<std::vector<GraphNode *>> SCC();
        void Kruskal(Graph* temp);
        void MST_PRIM(Graph* temp, GraphNode* start);

    private :
        std::vector<GraphNode *> v_list;
        std::vector<GraphEdge *> e_list;

};

class Compare {
public:
    bool operator()(GraphNode *a, GraphNode *b) {
        return a->getKey() > b->getKey();  // returns true if a has higher priority than b (i.e., a < b)
    }
};

void DFS_VISIT_SCC(GraphNode* Node,int count);
void quickSort(std::vector<GraphEdge *>& arr, int low, int high);
int partition(std::vector<GraphEdge *>& arr, int low, int high);
#endif