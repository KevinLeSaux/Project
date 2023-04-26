#include <iostream>
#include <vector>
#include "graph.hpp"
using namespace std;

GraphEdge::GraphEdge(GraphNode* src, GraphNode* dst, double weight, Graph *graph) : m_src(src), m_dst(dst), m_weight(weight) {
    graph->insert_edge(this);
}

GraphNode* GraphEdge::getSrc() const {
    return m_src; 
    
}

GraphNode* GraphEdge::getDst() const {
    return m_dst;
}

double GraphEdge::getWeight() const {
    return m_weight;
}

void GraphEdge::relax(){
    GraphNode *u = this->m_src;
    GraphNode *v = this->m_dst;

    if (u->getDist() > u->getDist() + this->m_weight)
    {
        v->setDistance(u->getDist() + this->m_weight);
        v->setPred(u);
    }
    
}