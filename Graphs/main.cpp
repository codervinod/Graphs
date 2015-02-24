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
    
    Graph *graph = new AdjacencyList(4);
    graph->addEdge(0,1);
    graph->addEdge(0,2);
    graph->addEdge(1,2);
    graph->addEdge(2,0);
    graph->addEdge(2,3);
    graph->addEdge(3,3);
    
    graph->DFS(2);
    delete graph;
    return 0;
}
