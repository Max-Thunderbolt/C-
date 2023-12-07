#include <iostream>
#include <list>

using namespace std;

//From GeeksForGeeks
class Graph
{
    int V;          // number of verticles
    list<int> *adj; // A dynamic array of adjency lists

public:
    Graph(int V)
    {
        this->V = V; 
        adj = new list<int>[V];
    };
    ~Graph();

    void addEdge(int v, int w);
    int isEulerian();
    bool isConnected();
    void DFSUtil(int v, bool visited[]);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

bool Graph::isConnected()
{
    bool visited[V]; 
    int i; 

    for (i = 0; i < V; i++)
        visited[i] = false; 

//Fix vertex with non-zero degree 
    for (i = 0; i < V; i++ )
        if (adj[i].size() != 0)
        break;

    if (i == V)
        return true;

    DFSUtil(i, visited);

    for (i = 0; i < V; i++)
        if (visited[i] == false && adj[i].size() > 0)
        return false;

    return true; 
}

/* The function returns one of the following values: 
    0 --> If graph is not Eulerian 
    1 --> If graph has an Euler path (Semi-Eulerian)
    2 --> If graph has an Euler circuit (Eulerian) */ 

int Graph::isEulerian()
{ 
    if (isConnected() == false)
        return 0;

    int odd = 0; 
    for (int i = 0; i < V; i++)
        if(adj[i].size() & 1)
            odd++;

    //if count is > 2, then graph is not Eulerian
    if (odd > 2)
        return 0;

    return (odd)? 1 : 2;
}

void test(Graph &g)
{
    int res = g.isEulerian(); 
    if (res == 0)
        cout << "Graph is not Eulerian" << endl; 
    else if(res == 1)
        cout << "Graph has an Euler path" << endl; 
    else
        cout << "Graph has an Euler cycle" << endl; 

}

int main()
{

    //Graph 1: 
    Graph g1(5);
    g1.addEdge(1,0);
    g1.addEdge(0,2);
    g1.addEdge(2,1); 
    g1.addEdge(0,3); 
    g1.addEdge(3,4); 
    test(g1);
    
}