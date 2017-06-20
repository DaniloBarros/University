//
//  main.cpp
//  Graph
//
//  Created by Danilo Mendes on 11/20/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits>
#include "simplegraph.hpp"

std::vector<Vertex*> initialize_graph(){
    Vertex *bsb = new Vertex("BSB");
    Vertex *lax = new Vertex("LAX");
    Vertex *gio = new Vertex("GIO");
    Vertex *poi = new Vertex("POI");
    Vertex *cmp = new Vertex("CMP");
    Vertex *hue = new Vertex("HUE");
    
    Edge *bsb_lax = new Edge(bsb, lax, 100);
    Edge *bsb_poi = new Edge(bsb, poi, 20);
    
    Edge *poi_lax = new Edge(poi, lax, 50);
    Edge *poi_hue = new Edge(poi, hue, 40);
    
    Edge *lax_gio = new Edge(lax, gio, 10);
    Edge *lax_cmp = new Edge(lax, cmp, 30);
    
    Edge *gio_bsb = new Edge(gio, bsb, 70);
    Edge *cmp_hue = new Edge(cmp, hue, 90);
    
    bsb->edges.insert(bsb_lax);
    bsb->edges.insert(bsb_poi);
    bsb->edges.insert(gio_bsb);
    
    lax->edges.insert(lax_gio);
    lax->edges.insert(lax_cmp);
    lax->edges.insert(bsb_lax);
    lax->edges.insert(poi_lax);
    
    poi->edges.insert(poi_lax);
    poi->edges.insert(poi_hue);
    poi->edges.insert(bsb_poi);
    
    gio->edges.insert(gio_bsb);
    gio->edges.insert(lax_gio);
    
    cmp->edges.insert(cmp_hue);
    cmp->edges.insert(lax_cmp);
    
    hue->edges.insert(cmp_hue);
    hue->edges.insert(poi_hue);
    
    std::vector<Vertex*> vertex;
    
    vertex.push_back(bsb);
    vertex.push_back(lax);
    vertex.push_back(poi);
    vertex.push_back(gio);
    vertex.push_back(cmp);
    vertex.push_back(hue);
    
    return vertex;
}

void add_vertex(std::vector<Vertex *> &graph, std::string name){
    
    Vertex *new_vertex = new Vertex(name);
    graph.push_back(new_vertex);
    
}

Vertex* search_vertex(std::vector<Vertex *> &graph, std::string name){
    Vertex *v = nullptr;
    for (int i=0; i<graph.size(); i++) {
        if (graph[i]->name == name) {
            v = graph[i];
            break;
        }
    }
    
    return v;
}

int vertex_index(const std::vector<Vertex *> &graph, Vertex* v){
    int index = -1;
    for (int i=0; i<graph.size(); i++) {
        if (graph[i] == v) {
            index = i;
            break;
        }
    }
    
    return index;
}


double dijkstra(const std::vector< Vertex* > &graph, Vertex *source, Vertex *target) {
    double infinity = std::numeric_limits<double>::max();
    std::vector<double> min_distance( graph.size(),  infinity);
    
    int source_index = vertex_index(graph, source);
    min_distance[source_index] = 0; // distance = 0 for source
    
    std::set< std::pair<int,int> > active_vertices;
    active_vertices.insert( {0,source_index} );
    
    int target_index = vertex_index(graph, target);
    while (!active_vertices.empty()) {
        int where = active_vertices.begin()->second;
        
        
        if (where == target_index){
            return min_distance[target_index];
        }
        
        active_vertices.erase( active_vertices.begin() );
        
        for (auto ed : graph[where]->edges){
            int dest = vertex_index(graph, ed->finish);
            
            if (ed->finish == graph[where]){
                dest = vertex_index(graph, ed->start);
            }
        
            if (min_distance[dest] > min_distance[where] + ed->cost) {
                
                active_vertices.erase( { min_distance[dest], dest } );
                min_distance[dest] = min_distance[where] + ed->cost;
                
                active_vertices.insert( { min_distance[dest], dest } );
            }
        }
    }
    
    return infinity;
}

int main(int argc, const char * argv[]) {
    
    std::vector<Vertex *> graph = initialize_graph();
    
    std::cout << dijkstra(graph, graph[0], graph[4]);
    
    
    return 0;
}
