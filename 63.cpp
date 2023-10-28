#include <iostream>
#include <vector>
#include <stack>

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
        } else {
            std::cerr << "Invalid vertex index." << std::endl;
        }
    }

    void dfs(int startVertex) {
        if (startVertex < 0 || startVertex >= numVertices) {
            std::cerr << "Invalid starting vertex." << std::endl;
            return;
        }

        std::vector<bool> visited(numVertices, false);
        std::stack<int> s;

        s.push(startVertex);

        std::cout << "Depth-First Search starting from vertex " << startVertex << ": ";
        while (!s.empty()) {
            int currentVertex = s.top();
            s.pop();

            if (!visited[currentVertex]) {
                std::cout << currentVertex << " ";
                visited[currentVertex] = true;
            }

            for (int neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    int numVertices = 7;
    Graph graph(numVertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);

    int startVertex = 0;
    graph.dfs(startVertex);

    return 0;
}
