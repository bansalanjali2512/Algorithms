/*
    Q.2: From a given vertex in a weighted connected graph, find shortest
    paths to other vertices using Bellman’s ford algorithm.
    Submitted By: Anjali Bansal (04)
    Date: 24th Oct, 2018
*/

#include <iostream>
using namespace std;

struct edge {
    int u;                  //source
    int v;                  //destination
    int w;                  //weight
};

struct Graph {
    int v;                  //no. of vertices
    int e;                  //no. of edges
    struct edge* edges;     //graph edges
};

//******************************
//function declaration
//******************************

void bellmanFord(Graph* graph, int source);

//******************************
//main function
//******************************

int main () {
    /*
        Objective       : From a given vertex in a weighted connected graph, find shortest
                          paths to other vertices using Bellman’s ford algorithm.
        Input parameters: None
        Return Value    : Integer
    */

    int v;                        //number of vertices
    int e;                        //number of edges
    cout << "\n Enter number of vertices in graph: ";
    cin >> v;
    cout << "\n Enter number of edges in graph: ";
    cin >> e;

    //creating graph
    struct Graph* graph = new Graph;
    graph->v = e;
    graph->e = e;
    graph->edges = new edge[e];


    //Input G
    cout << "\n Enter Graph: \n";
    for(int i = 0; i < e; i++) {
        cout << "\n Enter Edge" << (i+1) << ": ";
        cout << "\n Source: ";
        cin >> graph->edges[i].u;
        cout << "\n Destination: ";
        cin >> graph->edges[i].v;
        cout << "\n Weight: ";
        cin >> graph->edges[i].w;
    }

    int source;                      //source vertex
    cout << "\n Enter source vertex(0-" << (v-1) << "): ";
    cin >> source;
    bellmanFord(graph, source);

    cout << endl;
    return 0;
}


//******************************
//function definition
//******************************

void bellmanFord(Graph* graph, int source) {
    /*
        Objective       : From a given vertex in a weighted connected graph, find shortest
                          paths to other vertices using Bellman’s ford algorithm.
        Input parameters: graph - pointer to Graph structure
                          source - Integer, source vertex
        Return Value    : Integer
    */

    int u;                  //source
    int v;                  //destination
    int w;                  //weight
    int distance[graph->v];      //distance array

    //set distance to infinity i.e. INT_MAX here
    for (int i = 0; i < graph->v; i++) {
        distance[i] = INT_MAX;
    }

    //set distance of source vertex to 0
    distance[source] = 0;

    //relax edges
    for(int i = 0; i < graph->v; i++) {
        for(int j = 0; j < graph->e; j++) {
            u = graph->edges[j].u;
            v = graph->edges[j].v;
            w = graph->edges[j].w;

            if(distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    //check negative cycle
    for (int i = 0; i < graph->e; i++) {
        u = graph->edges[i].u;
        v = graph->edges[i].v;
        w = graph->edges[i].w;

        if (distance[u] != INT_MAX && distance[u] + w < distance[v])
            cout << "\n Graph has -ve weight cycle! ";
    }

    //print distances from source vertex
    cout << "\nDistance from Source vertex (" << source << "): \n\n";
    for(int i = 0; i < graph->v; i ++) {
        cout << distance[i] << " ";
    }
}
