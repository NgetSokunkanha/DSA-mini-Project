#include <iostream>
using namespace std;

const int MAX = 10;
const int INF = 10000;

int graph[MAX][MAX];      
int dist[MAX];            
bool visited[MAX];        
int previousBuilding[MAX]; 
int numberBuilding;       


void addEdge(int u, int v, int w) {
    graph[u][v] = w;
    graph[v][u] = w;
}


void dijkstra(int start) {
    for (int i = 0; i < numberBuilding; i++) {
        dist[i] = INF;
        visited[i] = false;
        previousBuilding[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < numberBuilding - 1; i++) {
        int u = -1;
        int minDist = INF;

        for (int j = 0; j < numberBuilding; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        visited[u] = true;

        for (int v = 0; v < numberBuilding; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                previousBuilding[v] = u;
            }
        }
    }
}

void printPath(int v) {
    if (v == -1)
        return;
    printPath(previousBuilding[v]);
    cout << v << " ";
}

void printDistance(int v) {
    cout << "\nTotal Distance: " << dist[v] << " meters.\n";
}



int main() {
    numberBuilding = 4;

    for (int i = 0; i < numberBuilding; i++)
        for (int j = 0; j < numberBuilding; j++)
            graph[i][j] = 0;


    addEdge(0, 1, 120); 
    addEdge(1, 2, 100); 
    addEdge(1, 3, 500); 
    addEdge(2, 3, 200); 


    cout << "Cambodia Academy of Digital Technology locations:\n";
    cout << "0. Motorcycle Parking\n";
    cout << "1. Institute of Digital Technology (IDT)\n";
    cout << "2. Institute of Digital Governance (IDG)\n";
    cout << "3. Institute of Digital Research and Innovation (IDRI)\n";

    return 0;
}
