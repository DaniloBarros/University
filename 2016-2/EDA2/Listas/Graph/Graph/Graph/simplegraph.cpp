//
//  simplegraph.cpp
//  Graph
//
//  Created by Danilo Mendes on 12/2/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//
#include <sstream>
#include "simplegraph.hpp"


/*
 * Vertex member implementations
 */
Vertex::Vertex(const std::string& name) : name(name), cost(0.0) {
    resetData();
}

Vertex::Vertex(const Vertex &other) : name(other.name), edges(other.edges), cost(other.cost), visited(other.visited),
previous(other.previous), m_color(other.m_color) {
    // empty
}

Vertex::~Vertex() {
    
}

int Vertex::getColor() const {
    return m_color;
}

void Vertex::resetData() {
    cost = 0.0;
    edges = std::set<Edge*>();
    previous = nullptr;
    visited = false;
    m_color = /* UNCOLORED */ 0;
}

void Vertex::setColor(int c) {
    m_color = c;
}

std::string Vertex::toString() const {
    std::ostringstream out;
    out << *this;
    return out.str();
}

Vertex& Vertex::operator =(const Vertex& other) {
    name = other.name;
    edges = other.edges;
    cost = other.cost;
    visited = other.visited;
    previous = other.previous;
    m_color = other.m_color;
    return *this;
}

Vertex& Vertex::operator =(Vertex&& other) {
    name = other.name;
    edges = other.edges;
    cost = other.cost;
    visited = other.visited;
    previous = other.previous;
    m_color = other.m_color;
    return *this;
}

std::ostream& operator <<(std::ostream& out, const Vertex& v) {
    out << "Vertex{name=" << v.name;
    if (v.cost != 0.0) {
        out << ", cost=" << v.cost;
    }
    out << ", visited=" << (v.visited ? "true" : "false");
    out << ", previous=" << (v.previous == nullptr ? std::string("NULL") : v.previous->name);
    
    out << ", neighbors={";
    int i = 0;
    for (Edge* edge : v.edges) {
        if (i > 0) {
            out << ", ";
        }
        
        i++;
        if (edge->finish != &v) {
            out << edge->finish->name;
            
        } else if (edge->start != &v){
            out << edge->start->name;
            
        }else {
            out << "NULL";
        }
    }
    out << "}";
    out << "}";
    return out;
}

/*
 * Edge member implementations
 */
Edge::Edge(Vertex* start, Vertex* finish, double cost)
: start(start), finish(finish), cost(cost){
    this->resetData();
}

Edge::~Edge() {

}

void Edge::resetData() {
    this->visited = false;
}

std::string Edge::toString() const {
    std::ostringstream out;
    out << *this;
    return out.str();
}

Edge& Edge::operator =(const Edge& other) {
    start = other.start;
    finish = other.finish;
    cost = other.cost;
    visited = other.visited;
    return *this;
}

//Edge& Edge::operator =(Edge&& other) {
//    start = other.start;
//    finish = other.finish;
//    cost = other.cost;
//    visited = other.visited;
//    return *this;
//}

std::ostream& operator <<(std::ostream& out, const Edge& edge) {
    out << "Edge{start=";
    if (!edge.start) {
        out << "NULL";
    } else {
        out << edge.start->name;
    }
    out << ", finish=";
    if (!edge.finish) {
        out << "NULL";
    } else {
        out << edge.finish->name;
    }
    if (edge.cost != 0.0) {
        out << ", cost=" << edge.cost;
    }
    if (edge.visited) {
        out << ", visited=" << (edge.visited ? "true" : "false");
    }
    out << "}";
    return out;
}
