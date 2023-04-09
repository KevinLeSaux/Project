#include <iostream>
#include <vector>
#include "graph.hpp"
using namespace std;

GraphEdge::GraphEdge(GraphNode* src, GraphNode* dst, double weight) : m_src(src), m_dst(dst), m_weight(weight) {}

GraphNode* GraphEdge::getSrc() const {
    return m_src; 
    
}

GraphNode* GraphEdge::getDst() const {
    return m_dst;
}

double GraphEdge::getWeight() const {
    return m_weight;
}