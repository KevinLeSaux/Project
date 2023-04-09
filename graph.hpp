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
        std::vector<GraphEdge*>getEdges() const;
        //simple neighbourhood queries
        std::vector<GraphNode *> SNQ() const;
        void ShortestPath(GraphNode* Destination);
        void BFS(std::vector<GraphNode*> graph);
        void DFS(std::vector<GraphNode*> graph);
        
        Linkedlist Topological_sort(std::vector<GraphNode*> graph);
        
        //Mutator
        void add_edge(GraphEdge* edge);
        void setVerif(bool boolean);
        void setDistance(int distance);
        void setFinish(int time);
        void setPred(GraphNode* Node);


    private:
        int m_id;
        int m_distance;
        int m_finish;
        bool m_visited;
        GraphNode* m_pred;
        std::vector<GraphEdge*> m_edges;
        
        

};

void DFS_VISIT(GraphNode* Node);

//GRAPH EDGE

class GraphEdge
{
    public:
        //Constructor
        GraphEdge(GraphNode* src, GraphNode* dst, double weight);


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
        //ACCESSOR
        std::vector<GraphNode *> getList();
        std::vector<GraphEdge *> getEdgelist();
        void transposeGraph(Graph* graph);
        std::vector<std::vector<GraphNode *>> SCC();
    private :
        std::vector<GraphNode *> v_list;
        std::vector<GraphEdge *> e_list;

};

#endif