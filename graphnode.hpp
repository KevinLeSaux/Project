#ifndef DEF_GRAPHNODE
#define DEF_GRAPHNODE

#include <vector>
#include "graphedge.hpp"
#include "graph.hpp"

class GraphNode;
typedef struct elem {

GraphNode *val;
struct elem *next;


}DListElement;

typedef DListElement *Linkedlist;

Linkedlist insert_head(Linkedlist l, GraphNode *Node);
void print_linked_list(Linkedlist l);


class GraphEdge;
class GraphNode
{
    public:
        //Constructor
        GraphNode(int id);


        //Accessors
        int getId() const;
        bool getVerif() const;
        int getDist() const;
        std::vector<GraphEdge*>getEdges() const;
        void ShortestPath(GraphNode* Destination);
        void BFS(std::vector<GraphNode*> graph);
        void DFS(std::vector<GraphNode*> graph);
        
        Linkedlist Topological_sort(std::vector<GraphNode*> graph);
        
        //Mutator
        void add_edge(GraphEdge* edge);
        void setVerif(bool boolean);
        void setDistance(int distance);
        void setFinish(int time);


    private:
        int m_id;
        int m_distance;
        int m_finish;
        bool m_visited;
        GraphNode* m_pred;
        std::vector<GraphEdge*> m_edges;
        
        

};

void DFS_VISIT(GraphNode* Node, int time);

#endif