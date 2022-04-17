#include <vector>
#include <queue>
#include <iostream>

#include "Precinct.h"
#include "Graph.h"

using std::vector;
using std::queue;
using std::cout;

void Graph::BFS(int start, int end){

    //established temporary vector to keep track of visited nodes
    vector<int> visited;
    vector<int> distance;
    for(int i = 0; i < precincts.size(); i++){
        visited.push_back(-1);
        distance.push_back(-1);
    }
    distance[start] = 0;

    queue<int> search;
    search.push(start);

    while(!search.empty()){
        int cur = search.front();

        // otherwise, if not searched, set searched and add everything in connected
        if(visited[cur] == -1){
            visited[cur] = 1;

            for(int i = 0; i < edges[cur].size(); i++){
                //if there is an edge between the presincts
                if(edges[cur][i] == 1){
                    if(i == end){
                        cout << "PRESINCT " << end << " IS " <<  distance[cur] + 1 << " EDGES FROM " << start << "\n";
                        return;
                    }

                    search.push(i);
                    distance[i] = distance[cur] + 1;
                }
            }
        }
    }
}

//