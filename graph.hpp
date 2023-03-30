#ifndef DEF_GRAPH
#define DEF_GRAPH

#include <vector>
#include "graphedge.hpp"
#include "graphnode.hpp"
class GraphNode;
class GraphEdge;
class Graph
{
    public:
        //Constructor
       Graph();
        //Accessors
        std::vector<GraphNode *> getVList();
        
        //Mutator

        std::vector<GraphNode *> m_list;
    private:
        
        
        

};

#endif