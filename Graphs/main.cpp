//
//  main.cpp
//  Graphs
//
//  Created by Vinod Gupta on 2/23/15.
//  Copyright (c) 2015 vinodg. All rights reserved.
//

#include <iostream>
#include "Graphs.h"

int main(int argc, const char * argv[]) {
    
    Graph *graph = new AdjacencyList(7);
    //Graph *graph = new AdjacencyMatrix(7);
    graph->addEdge(0,1);
    graph->addEdge(0,2);
    graph->addEdge(0,3);
    
    graph->addEdge(1,4);
    graph->addEdge(1,5);
    graph->addEdge(1,6);
    

    graph->BFS(0);
    graph->DFS(0);
    delete graph;
    return 0;
}
