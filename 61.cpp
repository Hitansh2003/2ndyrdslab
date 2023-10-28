#include <iostream>
#include <vector>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjList;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }

    void addEdge(int source, int destination) {
        if (source >= 0 && source < numVertices && destination >= 0 && destination < numVertices) {
            adjList[source].push_back(destination);
            adjList[destination].push_back(source); // For an undirected graph
        } else {
            std::cerr << "Invalid vertex index." << std::endl;
        }
    }

    void printGraph() {
        for (int v = 0; v < numVertices; v++) {
            std::cout << "Vertex " << v << " is connected to:";
            for (const int &neighbor : adjList[v]) {
                std::cout << " " << neighbor;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int numVertices = 5;
    Graph graph(numVertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);

    std::cout << "Graph representation (adjacency list):" << std::endl;
    graph.printGraph();

    return 0;
}
