#include "Graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Graph::Graph(){
// }

// Graph::~Graph(){
//     //dtor
// }

void Graph::addEdge(string v1, string v2, int distance){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j=0; j<vertices.size(); j++){
                if(vertices[j].name==v2 && i!=j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = distance;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    /*adjVertex av2;
                    av2.v = &vertices[i];
                    av2.distance = distance;
                    vertices[j].adj.push_back(av2);*/
                }
            }
        }
    }
}

void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" already in the graph."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);

    }
}

int Graph::isAdjacent(string v1, string v2){
    for(int i = 0; i<vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int x=0; x<vertices[i].adj.size(); x++){
                if(vertices[i].adj[x].v->name == v2){
                    // cout<<"True"<<endl;
                    return true;
                }
            }
        }
    }
    // cout<<"False"<<endl;
    return false;
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name;
            if(j != vertices[i].adj.size()-1){
                cout<<"***";
            }
        }
        cout<<endl;
    }
}