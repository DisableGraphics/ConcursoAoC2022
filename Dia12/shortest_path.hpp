#include <limits.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "matrix.hpp"

//Este archivo ha sido modificado para que funcione con la clase Matrix (Que he hecho yo)
//El código original es de GeeksforGeeks

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
inline int minDistance(int dist[], bool sptSet[], int V)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance array
inline void printSolution(int dist[], int n, int V, const std::string &map)
{
    printf("Vertex   Distance from Source\n");
    printf("%d \t\t %d\n", 3316, dist[3316]);
    
    if(map.size() != 0)
    {
        std::vector<int> a_distances{};
        for(int i{0}; i < map.size(); i++)
        {
            if(map[i] == 'a' || map[i] == 'S')
            {
                a_distances.push_back(dist[i]);
            }
        }
        std::sort(a_distances.begin(), a_distances.end());
        printf("Nearest a: \t\t %d\n", a_distances[0]);
    }
    
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
inline void dijkstra(Matrix adyacence_matrix, int src, const std::string &map = "")
{
    int V = adyacence_matrix.getRows();
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet, V);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && adyacence_matrix(u, v) && dist[u] != INT_MAX
                && dist[u] + adyacence_matrix(u, v) < dist[v])
                dist[v] = dist[u] + adyacence_matrix(u, v);
    }

    // print the constructed distance array
    printSolution(dist, V, V, map);
}

// driver program to test above function
inline void dijkstra_test()
{
    /* Let us create the example graph discussed above */
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 1);

}