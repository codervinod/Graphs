
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
#include <queue>

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
        _adj = new std::list<int>[v];
    }
    virtual ~AdjacencyList()
    {
        if(_adj)
            delete [] _adj;
    }
    
    
    void addEdge(int u,int v)
    {
        if(u>=_v)
            return;
        
        _adj[u].push_back(v);
        _adj[v].push_back(u);
    }
    
    void DFS(int v)
    {
        bool *visited = new bool[_v];
        for(int i=0;i<_v;++i)
            visited[i] = false;
        
        std::cout<<"DFS Traversal at:"<<v<<std::endl;
        DFSutil(v,visited);
        std::cout<<std::endl;
        delete [] visited;
    }
    
    void BFS(int v)
    {
        bool *visited = new bool[_v];
        for(int i=0;i<_v;++i)
            visited[i] = false;
        
        std::cout<<"BFS Traversal at:"<<v<<std::endl;
        
        std::queue<int> q;
        q.push(v);
        
        visited[v] = true;
        while(!q.empty())
        {
            int c = q.front();
            q.pop();
            std::cout<<c<<"\t";
            for(std::list<int>::iterator itr = _adj[c].begin();
                itr != _adj[c].end();++itr)
            {
                if(!visited[*itr])
                {
                    visited[*itr] = true;
                    q.push(*itr);
                }
            }
        }
        std::cout<<std::endl;
        delete [] visited;
    }
    
private:
    
    void DFSutil(int v,bool visited[])
    {
        visited[v] = true;
        std::cout<<v<<"\t";
        for(std::list<int>::iterator itr = _adj[v].begin();
            itr != _adj[v].end();++itr)
        {
            if(!visited[*itr])
                DFSutil(*itr,visited);
        }
        
    }
    std::list<int> *_adj;
};

class AdjacencyMatrix: public Graph
{
public:
    AdjacencyMatrix(int v):Graph(v)
    {
        _m = new int[v*v];
        for(int i=0;i<(v*v);++i)
            _m[i]=0;
    }
    
    virtual ~AdjacencyMatrix()
    {
       if(_m)
           delete []_m;
    }
    
    void addEdge(int u,int v)
    {
        int id = (u*_v)+v;
        _m[id] = 1;
    }
    
    void DFS(int v)
    {
        bool *visited = new bool[_v];
        for(int i=0;i<_v;++i)
            visited[i] =false;
        
        std::cout<<"DFS Traversal at:"<<v<<std::endl;
        
        DFSutil(v,visited);
        std::cout<<std::endl;
        delete [] visited;
    }
    
    void BFS(int v)
    {
        bool *visited = new bool[_v];
        for(int i=0;i<_v;++i)
            visited[i] =false;
        
        std::cout<<"BFS Traversal at:"<<v<<std::endl;
        
        std::queue<int> q;
        q.push(v);
        
        visited[v] = true;
        
        while(!q.empty())
        {
            int c = q.front();
            std::cout<<c<<"\t";
            q.pop();
            
            int cr=c*_v;
            for(int i=0;i<_v;++i)
            {
                int nextEdge = cr+i;
                if(_m[nextEdge] && !visited[nextEdge])
                {
                    visited[nextEdge] = true;
                    q.push(i);
                }
            }
        }
        std::cout<<std::endl;
        delete [] visited;
    }
    
private:
    void DFSutil(int v,bool visited[])
    {
        visited[v] = true;
        std::cout<<v<<"\t";
        
        int cr = v*_v;
        for(int i=0;i<_v;++i)
        {
            int nextEdge = cr+i;
            if(_m[nextEdge] && !visited[nextEdge])
                DFSutil(i,visited);
        }
    }
    int *_m;
    
};

#endif
