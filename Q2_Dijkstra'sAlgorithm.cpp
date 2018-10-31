/*
    Q.2: From a given vertex in a weighted connected graph, find shortest
         paths to other vertices using Dijkstra's algorithm.
    Submitted By: Anjali Bansal (04)
    Date: 24th Oct, 2018
*/

#include <iostream>
using namespace std;

int G[20][20];

//******************************
//function declaration
//******************************

void dijkstra(int G[20][20], int s);


//******************************
//main function
//******************************

int main () {
    /*
        Objective       : From a given vertex in a weighted connected graph, find shortest
                          paths to other vertices using Dijkstra's algorithm.
        Input parameters: None
        Return Value    : Integer
    */

    int n;                        //number of vertices
    cout << "\n Enter number of vertices in graph: ";
    cin >> n;

    //Input G
    cout << "\n Enter Graph: \n\n";
    for(int i = 0; i < n; i++) {

        cout << " Enter Row" << i << ": ";
        for(int j = 0; j < n; j++) {

            cin >> G[i][j];
        }
    }

    int s;                      //source vertex
    cout << "\n Enter source vertex(0-" << (n-1) << "): ";
    cin >> s;
    dijkstra(G, s);

    cout << endl;
    return 0;
}


//******************************
//function definition
//******************************

void dijkstra(int G[20][20], int s) {
    /*
        Objective       : From a given vertex in a weighted connected graph, find shortest
                          paths to other vertices using Dijkstra's algorithm.
        Input parameters: G - 2D Integer array, to store graph edge weights
                          s - Integer, source vertex
        Return Value    : None
    */


}
