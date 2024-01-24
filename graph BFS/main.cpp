#include <iostream>
#include <list>
#include <stack>
#include "queue"

using namespace std;

class graph {
private:
    int vertice;
    list<int>* adjList;
    bool* visited;

public:
    graph(int vertices) {
        vertice = vertices;
        adjList = new list<int>[vertices];
        visited = new bool[vertices];
    }

    void addEdge(int src, int dst) {
        adjList[src].push_back(dst);
        adjList[dst].push_back(src);
    }

    void BFS(int startVertice) {
        for (int i = 0; i < vertice; ++i) {
            visited[i] = false;
        }

        queue<int> q;

        q.push(startVertice);
        visited[startVertice] = true;

        list<int>::iterator i;

        while (!q.empty()) {
            int currentVertice = q.front();
            q.pop();
            cout << "Visited vertice: " << currentVertice << endl;

            for (i = adjList[currentVertice].begin(); i != adjList[currentVertice].end(); i++) {
                if (!visited[*i]) {
                    q.push(*i);
                    visited[*i] = true;
                }
            }
        }
    }

    void DFS(int startVertice) {
        for (int i = 0; i < vertice; ++i) {
            visited[i] = false;
        }

        stack<int> s;
        s.push(startVertice);
        visited[startVertice]=true;

        while (!s.empty()) {
            int currentVertice = s.top();
            s.pop();
                cout << "Visited vertice: " << currentVertice << endl;
            for (int neighbor : adjList[currentVertice]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                    visited[neighbor]=true;
                }
            }
        }
    }
};

int main() {
    graph g(5);
    g.addEdge(0, 2);
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);


    cout << "BFS starting from vertex 2:" << endl;
    g.BFS(0);

    cout << "\nDFS starting from vertex 2:" << endl;
    g.DFS(0);

    return 0;
}
