#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_VERTICES = 20;
const int INF = INT_MAX;

class Edge {
public:
    int u, v, weight;
    Edge(int u, int v, int w) : u(u), v(v), weight(w) {}
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

class Graph {
private:
    int numVertices;
    vector<pair<int, int>> adjList[MAX_VERTICES]; // (vertex, weight)
    vector<Edge> edges; // for Kruskal

public:
    Graph(int vertices) {
        if (vertices > MAX_VERTICES || vertices < 1) {
            cout << "Invalid number of vertices. Setting to maximum (" << MAX_VERTICES << ")." << endl;
            numVertices = MAX_VERTICES;
        } else {
            numVertices = vertices;
        }
    }

    void addEdge(int u, int v, int w) {
        if (isValidVertex(u) && isValidVertex(v) && w >= 0) {
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w}); // undirected
            edges.push_back(Edge(u, v, w));
            cout << "Edge added between " << u << " and " << v << " with weight " << w << ".\n";
        } else {
            cout << "Invalid vertices or weight. Please try again.\n";
        }
    }

    void displayGraph() {
        cout << "\nAdjacency List (vertex -> (neighbour, weight)):\n";
        for (int i = 0; i < numVertices; i++) {
            cout << i << " -> ";
            for (auto &nbr : adjList[i]) {
                cout << "(" << nbr.first << ", " << nbr.second << ") ";
            }
            cout << endl;
        }
    }

    void primsMST() {
        cout << "\nPrim's Algorithm - Minimum Spanning Tree\n";
        vector<bool> selected(numVertices, false);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        selected[0] = true;
        for (auto &nbr : adjList[0]) {
            pq.push({nbr.second, {0, nbr.first}});
        }

        int mstWeight = 0;
        while (!pq.empty()) {
            auto [weight, nodes] = pq.top();
            pq.pop();
            int u = nodes.first, v = nodes.second;

            if (selected[v]) continue;

            cout << u << " - " << v << " (weight " << weight << ")\n";
            mstWeight += weight;
            selected[v] = true;

            for (auto &nbr : adjList[v]) {
                if (!selected[nbr.first]) {
                    pq.push({nbr.second, {v, nbr.first}});
                }
            }
        }
        cout << "Total weight of MST: " << mstWeight << endl;
    }

    void kruskalsMST() {
        cout << "\nKruskal's Algorithm - Minimum Spanning Tree\n";
        vector<int> parent(numVertices);
        for (int i = 0; i < numVertices; i++) parent[i] = i;

        auto findParent = [&](int v) {
            while (v != parent[v])
                v = parent[v];
            return v;
        };

        auto unionSets = [&](int a, int b) {
            parent[findParent(a)] = findParent(b);
        };

        sort(edges.begin(), edges.end(), compareEdges);

        int mstWeight = 0;
        for (auto &edge : edges) {
            int pu = findParent(edge.u);
            int pv = findParent(edge.v);

            if (pu != pv) {
                cout << edge.u << " - " << edge.v << " (weight " << edge.weight << ")\n";
                mstWeight += edge.weight;
                unionSets(pu, pv);
            }
        }
        cout << "Total weight of MST: " << mstWeight << endl;
    }

    void dijkstra(int src) {
        cout << "\nDijkstra's Algorithm - Single Source Shortest Path\n";
        if (!isValidVertex(src)) {
            cout << "Invalid source vertex.\n";
            return;
        }

        vector<int> dist(numVertices, INF);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [currentDist, u] = pq.top();
            pq.pop();

            for (auto &nbr : adjList[u]) {
                int v = nbr.first;
                int weight = nbr.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from vertex " << src << ":\n";
        for (int i = 0; i < numVertices; i++) {
            if (dist[i] == INF)
                cout << i << " -> INF\n";
            else
                cout << i << " -> " << dist[i] << "\n";
        }
    }

private:
    bool isValidVertex(int v) {
        return v >= 0 && v < numVertices;
    }
};

int main() {
    int vertices;
    cout << "Enter the number of vertices in the graph (max " << MAX_VERTICES << "): ";
    cin >> vertices;

    Graph graph(vertices);

    int choice;
    do {
        cout << "\nGraph Menu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Prim's MST\n";
        cout << "4. Kruskal's MST\n";
        cout << "5. Dijkstra's Algorithm\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int u, v, w;
                cout << "Enter start vertex: ";
                cin >> u;
                cout << "Enter end vertex: ";
                cin >> v;
                cout << "Enter weight: ";
                cin >> w;
                graph.addEdge(u, v, w);
                break;
            }

            case 2:
                graph.displayGraph();
                break;

            case 3:
                graph.primsMST();
                break;

            case 4:
                graph.kruskalsMST();
                break;

            case 5: {
                int src;
                cout << "Enter source vertex: ";
                cin >> src;
                graph.dijkstra(src);
                break;
            }

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please select between 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}
