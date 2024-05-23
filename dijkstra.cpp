#include<iostream>
using namespace std;

int graph[20][20];
int visited[20];
int dist[20];
int path[20];

void Dijkstra(int source, int nodes)
{
    visited[source] = 1;

    for(int i = 0; i < nodes; i++)
    {
        if(graph[source][i] && dist[source] + graph[source][i] < dist[i])
        {
            dist[i] = dist[source] + graph[source][i];
            path[i] = source;
        }
    }

    int minNonVisitedDist = INT_MAX;
    int minNonVisitedIndex = INT_MAX;
    for(int i = 0; i < nodes; i++)
    {
        if(!visited[i] && dist[i] < minNonVisitedDist)
        {
            minNonVisitedDist = dist[i];
            minNonVisitedIndex = i;
        }
    }

    if(minNonVisitedIndex != INT_MAX)
    {
        Dijkstra(minNonVisitedIndex, nodes);
    }
}

void PrintPath(int dest)
{
    if(dest == -1)
        return;

    PrintPath(path[dest]);
    cout<<char(dest + 'A')<< " ";
}

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    for(int i = 0; i < edges; i++)
    {
        int from, to, weight;
        cin>>from>>to>>weight;
        graph[from][to] = weight;
    }

    for(int i = 0; i < nodes; i++)
    {
        dist[i] = INT_MAX;
    }

    cout<<"Printing the graph: "<<endl;

    for(int i = 0; i < nodes; i++)
    {
        for(int j = 0; j < nodes; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    int source;
    cin>>source;
    dist[source] = 0;
    path[source] = -1;
    Dijkstra(source, nodes);

    cout<<"Printing shortest distances to each node: ";
    for(int i = 0; i < nodes; i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;

    cout<<"Enter destination to print path to it: ";
    int destination;
    cin>>destination;

    cout<<"Path to destination "<<destination<<": ";
    PrintPath(destination);
    cout<<endl;
}

/*
5 9
0 1 4
1 2 3
0 2 2
2 1 1
2 3 4
2 4 5
1 3 2
1 4 3
4 3 1
*/