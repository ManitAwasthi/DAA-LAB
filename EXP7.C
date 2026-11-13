#include <stdio.h>
#include <limits.h>

struct Edge {
    int source;
    int destination;
    int weight;
};

int main() {

    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    printf("Enter source destination weight:\n");

    for (int i = 0; i < E; i++)
        scanf("%d %d %d",
              &edges[i].source,
              &edges[i].destination,
              &edges[i].weight);

    int source;

    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    // Relax all edges V-1 times

    for (int i = 1; i <= V - 1; i++) {

        for (int j = 0; j < E; j++) {

            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;

            if (dist[u] != INT_MAX &&
                dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }
        }
    }

    // Check negative cycle

    for (int j = 0; j < E; j++) {

        int u = edges[j].source;
        int v = edges[j].destination;
        int w = edges[j].weight;

        if (dist[u] != INT_MAX &&
            dist[u] + w < dist[v]) {

            printf("Negative weight cycle detected.\n");
            return 0;
        }
    }

    printf("\nVertex\tDistance\n");

    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);

    return 0;
}
