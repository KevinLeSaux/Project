#ifndef DEF_GRAPHEDGE
#define DEF_GRAPHEDGE

#include "graphnode.hpp"
#include "graph.hpp"
#include <vector>
class GraphNode;
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



#endif