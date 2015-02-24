
//
//  Graphs.h
//  Graphs
//
//  Created by Vinod Gupta on 2/23/15.
//  Copyright (c) 2015 vinodg. All rights reserved.
//

#ifndef Graphs_Graphs_h
#define Graphs_Graphs_h

#include <vector>
#include <list>

class Graph
{
public:
    Graph(int v):_v(v) {}
    virtual ~Graph() {}
    virtual void addEdge(int u,int v) = 0;
    virtual void DFS(int v) = 0;
    virtual void BFS(int v) = 0;
protected:
    int _v;
};

class AdjacencyList: public Graph
{
public:
    AdjacencyList(int v):Graph(v)
    {
        _graph = new std::list<int>[v];
    }
    virtual ~AdjacencyList()
    {
        if(_graph)
            delete [] _graph;
    }
    
    
    void addEdge(int u,int v)
    {
        if(u>=_v)
            return;
        
        _graph[u].push_back(v);
        _graph[v].push_back(u);
    }
    
    void DFS(int v)
    {
        bool *visited = new bool[_v];
        for(int i=0;i<_v;++i)
            visited[i] = false;
        
        std::cout<<"DFS Traversal at:"<<v<<std::endl;
        DFSutil(v,visited);
        std::cout<<std::endl;
    }
    
    void BFS(int v)
    {
        
    }
    
private:
    
    void DFSutil(int v,bool visited[])
    {
        visited[v] = true;
        std::cout<<v<<"\t";
        for(std::list<int>::iterator itr = _graph[v].begin();
            itr != _graph[v].end();++itr)
        {
            if(!visited[*itr])
                DFSutil(*itr,visited);
        }
        
    }
    std::list<int> *_graph;
};

#endif
