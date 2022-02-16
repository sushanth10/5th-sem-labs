#include<stdio.h>
#include<stdlib.h>
#define INF 999

struct Edge{
    int src;
    int dest;
    int weight;
};

int bellman_ford(struct Edge * edge, int src, int num_edges, int num_vertices, int dist[num_vertices]){
    
    int i, j, u, v, w;
    
    int cycle=0;
    
    // default distance to all nodes to be infinity
    for(i=0; i<num_vertices; i++){
        dist[i]=INF;
    }

    dist[src] = 0;

    // relaxation to be done |V|-1 times
    for(i=0; i<num_vertices-1; i++){

        for(j=0; j<num_edges; j++){
            u = edge[j].src;
            v = edge[j].dest;
            w = edge[j].weight;

            // relaxation to be done when the distance is lesser than value found
            if(dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
            }
        }
    }

    // check it one more time and if the value changes, it has a negative cycle
    for(j=0; j<num_edges; j++){
        u = edge[j].src;
        v = edge[j].dest;
        w = edge[j].weight;

        if(dist[v]>dist[u]+w) cycle=1;
    }
    return cycle;
}


int main(int argc, char const *argv[])
{
    printf("-----BELLMAN FORD ALGORITHM-----\n");

    int num_vertices, num_edges;

    printf("Enter number of vertices : ");    
    scanf("%d", &num_vertices);

    printf("Enter number of edges : ");
    scanf("%d", &num_edges);
    
    printf("\n----------\n");

    int dist[num_vertices];

    
    struct Edge * edge = (struct Edge *)malloc(num_edges*(sizeof(struct Edge)));

    for(int i=0; i<num_edges; i++){
        printf("Enter source node for edge %d : ", (i+1));
        scanf("%d", &edge[i].src);
        
        printf("Enter destination node for edge %d : ", (i+1));
        scanf("%d", &edge[i].dest);
        
        printf("Enter weight of edge %d (0 if no path exists): ", (i+1));
        scanf("%d", &edge[i].weight);
        if(edge[i].weight==0) edge[i].weight=INF;
    }

    printf("\n----------\n");
    int src;
    printf("Enter source node : ");
    scanf("%d", &src);

    printf("\n----------\n");

    // returns 1 if there is a negative cycle, or zero if there is not
    int cycle = bellman_ford(edge, src, num_edges, num_vertices, dist);

    if(cycle){
        printf("There is a negative weighted cycle\n");
    }else{
        for(int i=0; i<num_vertices; i++){
            printf("Shortest path from %d to %d is %d\n", src, i, dist[i]);
        }
    }
    
    printf("-----END OF PROGRAM-----\n");
    return 0;
}
