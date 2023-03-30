#include <iostream>
#include <vector>

#include "graph.hpp"
#include "graphedge.hpp"
#include "graphnode.hpp"
using namespace std;

Graph::Graph(){

    //Initalisation of my graph
    
    //VERTICES
    GraphNode vert(0);
    GraphNode vert1(1);
    GraphNode vert2(2);
    GraphNode vert3(3);
    GraphNode vert4(4);
    GraphNode vert5(5);

    

    //EDGES
    GraphEdge edge0to1(&vert,&vert1,4);
    GraphEdge edge1to2(&vert1,&vert2,0);
    GraphEdge edge2to3(&vert2,&vert3,0);
    GraphEdge edge3to0(&vert3,&vert,0);
    GraphEdge edge1to3(&vert1,&vert3,0);
    GraphEdge edge1to5(&vert1,&vert5,0);
    GraphEdge edge5to4(&vert5,&vert4,0);
    GraphEdge edge2to4(&vert2,&vert4,0);

    vert.add_edge(&edge0to1);
    vert1.add_edge(&edge1to2);
    vert1.add_edge(&edge1to3);
    vert2.add_edge(&edge2to3);
    vert3.add_edge(&edge3to0);
    vert1.add_edge(&edge1to5);
    vert5.add_edge(&edge5to4);
    vert2.add_edge(&edge2to4);

    m_list.push_back(&vert);
    m_list.push_back(&vert1);
    m_list.push_back(&vert2);
    m_list.push_back(&vert3);
    m_list.push_back(&vert4);
    m_list.push_back(&vert5);

}


vector<GraphNode *> Graph::getVList(){
    return m_list;
}