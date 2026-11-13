#include <stdio.h>
#include <limits.h>

#define V 5

int minDistance(int dist[], int visited[]) {

    int min = INT_MAX;
    int index = -1;

    for (int i = 0; i < V; i++) {

        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(int graph[V][V], int source) {

    int dist[V];
    int visited[V] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, visited);

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < V; v++) {

            if (!visited[v] &&
                graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance\n");

    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {

    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };

    int source;

    printf("Enter source vertex (0-4): ");
    scanf("%d", &source);

    dijkstra(graph, source);

    return 0;
}
