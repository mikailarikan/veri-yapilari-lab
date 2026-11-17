#include <stdio.h>
#include <stdlib.h>

#define NUM_CITIES 5

char* cities[] = {"Istanbul", "Ankara", "Izmir", "Bursa", "Antalya"};

//Adjacency Matrix
int graph[NUM_CITIES][NUM_CITIES] = {
    {0, 1, 0, 1, 0}, 
    {1, 0, 1, 0, 1},
    {0, 1, 0, 0, 0}, 
    {1, 0, 0, 0, 1}, 
    {0, 1, 0, 1, 0}  
};

int visited_dfs[NUM_CITIES] = {0, 0, 0, 0, 0};

void DFS(int node) {
    visited_dfs[node] = 1;
    printf("%s ", cities[node]);

    for (int i = 0; i < NUM_CITIES; i++) {
        if (graph[node][i] == 1 && !visited_dfs[i]) {
            DFS(i);
        }
    }
}

void BFS(int startNode) {
    int visited_bfs[NUM_CITIES] = {0, 0, 0, 0, 0};
    int queue[NUM_CITIES];
    int front = 0, rear = 0;

    visited_bfs[startNode] = 1;
    //Önce atama sonra arttırma işlemi yapar
    queue[rear++] = startNode;

    while (front < rear) {
        //Önce atama sonra arttırma işlemi yapar 
        int currentNode = queue[front++];
        printf("%s ", cities[currentNode]);

        for (int i = 0; i < NUM_CITIES; i++) {
            if (graph[currentNode][i] == 1 && !visited_bfs[i]) {
                visited_bfs[i] = 1;      
                queue[rear++] = i;       
            }
        }
    }
}

int main() {

    int start_node = 0;

    printf("2. BFS (Breadth-First Search) Dolasimi:\n");
    BFS(start_node);
    printf("\n\n");

    printf("3. DFS (Depth-First Search) Dolasimi:\n");
    DFS(start_node);
    printf("\n");

    return 0;
}