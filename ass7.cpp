#include <iostream>
using namespace std;

#define MAX 10

class CityMap {
    string cityNames[MAX];
    int adjMatrix[MAX][MAX];
    int adjList[MAX][MAX];
    int listSize[MAX];
    int n;

public:
    CityMap(int cities) {
        n = cities;
        for (int i = 0; i < n; i++) {
            listSize[i] = 0;
            for (int j = 0; j < n; j++)
                adjMatrix[i][j] = 0;
        }
    }

    void setCityName(int index, string name) {
        cityNames[index] = name;
    }

    void addRoad(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        adjList[u][listSize[u]++] = v;
        adjList[v][listSize[v]++] = u;
    }

    void displayAdjMatrix() {
        cout << "\nAdjacency Matrix (Road Connections):\n";
        cout << "     ";
        for (int i = 0; i < n; i++)
            cout << cityNames[i][0] << " ";
        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << cityNames[i][0] << "  : ";
            for (int j = 0; j < n; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    void displayAdjList() {
        cout << "\nAdjacency List (City Connections):\n";
        for (int i = 0; i < n; i++) {
            cout << cityNames[i] << " -> ";
            for (int j = 0; j < listSize[i]; j++)
                cout << cityNames[adjList[i][j]] << " ";
            cout << endl;
        }
    }

    void DFS(int start) {
        int visited[MAX] = {0};
        int stack[MAX];
        int top = -1;
        cout << "\nDFS Route starting from " << cityNames[start] << ": ";
        stack[++top] = start;
        while (top != -1) {
            int node = stack[top--];
            if (!visited[node]) {
                cout << cityNames[node] << " ";
                visited[node] = 1;
                for (int i = listSize[node] - 1; i >= 0; i--) {
                    int adjNode = adjList[node][i];
                    if (!visited[adjNode])
                        stack[++top] = adjNode;
                }
            }
        }
        cout << endl;
    }

    void BFS(int start) {
        int visited[MAX] = {0};
        int queue[MAX];
        int front = 0, rear = 0;
        cout << "\nBFS Route starting from " << cityNames[start] << ": ";
        visited[start] = 1;
        queue[rear++] = start;
        while (front < rear) {
            int node = queue[front++];
            cout << cityNames[node] << " ";
            for (int i = 0; i < listSize[node]; i++) {
                int adjNode = adjList[node][i];
                if (!visited[adjNode]) {
                    visited[adjNode] = 1;
                    queue[rear++] = adjNode;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    CityMap map(5);
    map.setCityName(0, "Delhi");
    map.setCityName(1, "Mumbai");
    map.setCityName(2, "Chennai");
    map.setCityName(3, "Kolkata");
    map.setCityName(4, "Bangalore");
    map.addRoad(0, 1);
    map.addRoad(0, 2);
    map.addRoad(1, 3);
    map.addRoad(2, 4);
    cout << "\n=== City Map Navigation System ===\n";
    map.displayAdjMatrix();
    map.displayAdjList();
    map.DFS(0);
    map.BFS(0);
    return 0;
}
// *********OUTPUT***********
// PS C:\Users\SHRINIVAS\myfolder\DSA> cd "c:\Users\SHRINIVAS\myfolder\DSA\" ; if ($?) { g++ ass7.cpp -o ass7 } ; if ($?) { .\ass7 }

// === City Map Navigation System ===

// Adjacency Matrix (Road Connections):
//      D M C K B 
// D  : 0 1 1 0 0 
// M  : 1 0 0 1 0 
// C  : 1 0 0 0 1 
// K  : 0 1 0 0 0 
// B  : 0 0 1 0 0

// Adjacency List (City Connections):
// Delhi -> Mumbai Chennai
// Mumbai -> Delhi Kolkata
// Chennai -> Delhi Bangalore
// Kolkata -> Mumbai
// Bangalore -> Chennai

// DFS Route starting from Delhi: Delhi Mumbai Kolkata Chennai Bangalore

// BFS Route starting from Delhi: Delhi Mumbai Chennai Kolkata Bangalore