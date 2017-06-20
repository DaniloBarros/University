//
//  simplegraph.hpp
//  Graph
//
//  Created by Danilo Mendes on 12/2/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#ifndef simplegraph_hpp
#define simplegraph_hpp

#include <string>
#include <set>

struct Vertex;
struct Edge;

struct Vertex {
public:
    std::string name;
    std::set<Edge*> edges;
    
    double cost;        // cost to reach this vertex (initially 0; you can set this)
    bool visited;       // whether this vertex has been visited before (initally false; you can set this)
    Vertex* previous;   // vertex that comes before this one (initially nullptr; you can set this)
    
    /*
     * Constructs a vertex with the given name.
     */
    Vertex(const std::string& name = "");
    
    /*
     * Copy constructor (rule of three).
     */
    Vertex(const Vertex& other);
    
    /*
     * Frees up any memory dynamically allocated by this vertex.
     */
    ~Vertex();
    
    /*
     * Returns the color of this vertex, if any.  Initially WHITE.
     */
    /* Color */ int getColor() const;
    
    /*
     * Wipes the supplementary data of this vertex back to its initial state.
     * Specifically, sets cost to 0, visited to false, and previous to nullptr.
     */
    void resetData();
    
    /*
     * Sets the color of this vertex to be the given color.
     * The color must be one of WHITE, GRAY, YELLOW, or GREEN.
     * Future calls to getColor will return the color you pass here.
     */
    void setColor(/* Color */ int c);
    
    /*
     * Returns a string representation of this vertex for debugging, such as
     * "Vertex{name=r13c42, cost=11, visited=true, previous=r12c41, neighbors={r12c41, r12c43}}".
     */
    std::string toString() const;
    
    /*
     * Copy assignment operator (rule of three).
     */
    Vertex& operator =(const Vertex& other);
    
    /*
     * Move assignment operator (rule of three).
     */
    Vertex& operator =(Vertex&& other);
    
private:
    /* Color */ int m_color;   // vertex's color as passed to setColor
};

std::ostream& operator <<(std::ostream& out, const Vertex& v);


#define Node Vertex


struct Edge {
public:
    Vertex* start;    // edge's starting vertex (required by Graph)
    Vertex* finish;   // edge's ending vertex (required by Graph)
    double cost;      // edge weight (required by Graph)
    bool visited;     // whether this edge has been visited before (initally false; you can set this)
    
    /*
     * Constructs a new edge between the given start/end vertices with
     * the given cost.
     */
    Edge(Vertex* start = nullptr, Vertex* finish = nullptr, double cost = 0.0);
    
    /*
     * Frees up any memory dynamically allocated by this edge.
     */
    ~Edge();
    
    /*
     * Wipes the supplementary data of this vertex back to its initial state.
     * Specifically, sets visited to false.
     */
    void resetData();
    
    /*
     * Returns a string representation of this edge for debugging, such as
     * "Arc{start=r12c42, finish=r12c41, cost=0.75}".
     */
    std::string toString() const;
    
    /*
     * Copy assignment operator (rule of three).
     */
    Edge& operator =(const Edge& other);
    
    /*
     * Move assignment operator (rule of three).
     */
    //Edge& operator =(Edge&& other);
};

std::ostream& operator <<(std::ostream& out, const Edge& edge);


#endif /* simplegraph_hpp */
