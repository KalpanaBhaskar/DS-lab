#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_VERTICES = 10;

class Graph {
private:
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

public:
    Graph(int vertices) {
        if (vertices > MAX_VERTICES || vertices < 1) {
            cout << "Invalid number of vertices. Setting to maximum (" << MAX_VERTICES << ")." << endl;
            numVertices = MAX_VERTICES;
        } else {
            numVertices = vertices;
        }

        // Initialize the adjacency matrix to 0
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void insertEdge(int start, int end) {
        if (isValidVertex(start) && isValidVertex(end)) {
            adjMatrix[start][end] = 1;
            adjMatrix[end][start] = 1; // For undirected graph
            cout << "Edge inserted between " << start << " and " << end << "." << endl;
        } else {
            cout << "Invalid vertices. Please try again." << endl;
        }
    }

    void deleteEdge(int start, int end) {
        if (isValidVertex(start) && isValidVertex(end)) {
            if (adjMatrix[start][end] == 1) {
                adjMatrix[start][end] = 0;
                adjMatrix[end][start] = 0; // For undirected graph
                cout << "Edge deleted between " << start << " and " << end << "." << endl;
            } else {
                cout << "No edge exists between " << start << " and " << end << "." << endl;
            }
        } else {
            cout << "Invalid vertices. Please try again." << endl;
        }
    }

    void searchEdge(int start, int end) {
        if (isValidVertex(start) && isValidVertex(end)) {
            if (adjMatrix[start][end] == 1) {
                cout << "Edge exists between " << start << " and " << end << "." << endl;
            } else {
                cout << "No edge exists between " << start << " and " << end << "." << endl;
            }
        } else {
            cout << "Invalid vertices. Please try again." << endl;
        }
    }

    void displayGraph() {
        cout << "\nAdjacency Matrix:\n";
        cout << setw(4) << " ";
        for (int i = 0; i < numVertices; i++) {
            cout << setw(4) << i;
        }
        cout << "\n";

        for (int i = 0; i < numVertices; i++) {
            cout << setw(4) << i;
            for (int j = 0; j < numVertices; j++) {
                cout << setw(4) << adjMatrix[i][j];
            }
            cout << "\n";
        }
    }

private:
    bool isValidVertex(int v) {
        return (v >= 0 && v < numVertices);
    }
};

int main() {
    int vertices;
    cout << "Enter the number of vertices in the graph (max " << MAX_VERTICES << "): ";
    cin >> vertices;

    Graph graph(vertices);

    int choice, start, end;

    do {
        cout << "\nGraph Menu:\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display Graph\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter start vertex: ";
                cin >> start;
                cout << "Enter end vertex: ";
                cin >> end;
                graph.insertEdge(start, end);
                break;

            case 2:
                cout << "Enter start vertex: ";
                cin >> start;
                cout << "Enter end vertex: ";
                cin >> end;
                graph.deleteEdge(start, end);
                break;

            case 3:
                cout << "Enter start vertex: ";
                cin >> start;
                cout << "Enter end vertex: ";
                cin >> end;
                graph.searchEdge(start, end);
                break;

            case 4:
                graph.displayGraph();
                break;

            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
