#include<stdio.h>
#include<stdlib.h>
#define INFINITY 999

void dijkstra(int n, int src, int cost[100][100], int dist[100]){
    int u, w, visited[100], count, min;

    // set all visited vertices to zero.
    // default distance values will be equal to distance from the source node
    for(int i=1; i<=n; i++){
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    count = 2;
    while(count<=n){
        min = 99;

        // find the least distance for the vertex
        for(w=1; w<=n; w++){
            if(dist[w]<min && !visited[w]){
                min = dist[w];
                u=w;
            }
        }

        // set that vertex as visited
        visited[u]=1;
        count++;

        // update values of distance vertex, if path through any visited vertex to a final vertex is lesser than the value in distance matrix
        for(w=1; w<=n; w++){
            if(dist[w]>dist[u]+cost[u][w] && !visited[w]){
                dist[w] = dist[u]+cost[u][w];
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, cost[100][100], dist[100], src;
    
    printf("-----DIJKSTRA'S SHORTEST PATH ALGORITHM-----");

    printf("\nEnter number of nodes : ");
    scanf("%d", &n);
    printf("\nEnter cost matrix : \n");

    // input the cost matrix
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            printf("Distance from node %d to node %d (if no path, enter 0) = ", i, j);
            scanf("%d", &cost[i][j]);
            if(cost[i][j]==0) 
                cost[i][j]=INFINITY;
            
            cost[j][i] = cost[i][j];
        }
    }

    printf("\n----------\nEnter source node : ");
    scanf("%d", &src);


    dijkstra(n, src, cost, dist);

    printf("\n----------\n");
    printf("The shortest distances are : \n");
    for(int i=1; i<=n; i++){
        if(i!=src){
            printf("%d -> %d = %d\n", src, i, dist[i]);
        }
    }

    printf("----------\n");
    return 0;
}
