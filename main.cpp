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

    cout << "\nTotal Distance: " << dist[v] << " meters\n";
}

int checkIDTRoom() {
    int room;
    cout << "\nEnter IDT room number: ";
    cin >> room;

    int firstDigit = room / 100;

    if (firstDigit == 0) {
        cout << "Ground Floor (30m)\n";
        return 30;
    }
    else if (firstDigit == 1) {
        cout << "First Floor (50m)\n";
        return 50;
    }
    else if (firstDigit == 2) {
        cout << "Second Floor (70m)\n";
        return 70;
    }
    else {
        cout << "Invalid room number\n";
        return 0;
    }
}


int checkIDGRoom() {
    int choice;
    cout << "\nSelect IDG location:\n";
    cout << "1. Canteen (50m)\n";
    cout << "2. IDG Hall (80m)\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Destination: IDG Canteen\n";
        return 50;
    }
    else if (choice == 2) {
        cout << "Destination: IDG Hall\n";
        return 80;
    }
    else {
        cout << "Invalid choice\n";
        return 0;
    }
}


int checkIDRIRoom() {
    int choice;
    cout << "\nSelect IDRI room:\n";
    cout << "1. Angel Room (40m)\n";
    cout << "2. Jupiter Room (60m)\n";
    cout << "3. Cosmos Hall (100m)\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Destination: Angel Room\n";
        return 40;
    }
    else if (choice == 2) {
        cout << "Destination: Jupiter Room\n";
        return 60;
    }
    else if (choice == 3) {
        cout << "Destination: Cosmos Hall\n";
        return 100;
    }
    else {
        cout << "Invalid choice\n";
        return 0;
    }
}


// User input
void inputUser() {
    int start, end;
    int startExtraDistance = 0;
    int destinationExtraDistance = 0;

    cout << "\nEnter start location number: ";
    cin >> start;

    if (start == 1) {
        cout << "\nStarting from IDT\n";
        startExtraDistance = checkIDTRoom();
    }
    else if (start == 2) {
        cout << "\nStarting from IDG\n";
        startExtraDistance = checkIDGRoom();
    }
    else if (start == 3) {
        cout << "\nStarting from IDRI\n";
        startExtraDistance = checkIDRIRoom();
    }

    cout << "\nEnter destination number: ";
    cin >> end;

    dijkstra(start);

    cout << "\nShortest Path: ";
    printPath(end);

    if (end == 1) {
        cout << "\nDestination: IDT\n";
        destinationExtraDistance = checkIDTRoom();
    }
    else if (end == 2) {
        cout << "\nDestination: IDG\n";
        destinationExtraDistance = checkIDGRoom();
    }
    else if (end == 3) {
        cout << "\nDestination: IDRI\n";
        destinationExtraDistance = checkIDRIRoom();
    }

    cout << "\nTotal Distance: "
         << dist[end] + startExtraDistance + destinationExtraDistance
         << " meters\n";
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

    inputUser();

    return 0;
}
