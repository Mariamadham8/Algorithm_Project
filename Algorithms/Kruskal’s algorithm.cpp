#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    int* parent;
    int* rank;
public:
    DisjointSet(int size) {
        parent = new int[size];
        rank = new int[size];

        for (int i = 0; i < size; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int findSet(int node) {
        if (parent[node] == -1)
            return node;
        return parent[node] = findSet(parent[node]);
    }
    void unionSets(int node1, int node2) {
        int root1 = findSet(node1);
        int root2 = findSet(node2);

        if (root1 != root2) {
            if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else {
                parent[root2] = root1;
                rank[root1] += 1;
            }
        }
    }
};

class Graph {
    vector<vector<int>> edges;
    int vertices;

public:
    Graph(int verticesCount) { vertices = verticesCount; }
    void addEdge(int src, int dest, int weight) {
        edges.push_back({weight, src, dest});
    }

    void computeMST() {
        sort(edges.begin(), edges.end());
        DisjointSet disjointSet(vertices);
        int totalWeight = 0;
        int edgeCount = 0;

        cout << "Edges in the MST:" << endl;
        for (auto edge : edges) {
            int weight = edge[0];
            int src = edge[1];
            int dest = edge[2];

            if (disjointSet.findSet(src) != disjointSet.findSet(dest)) {
                disjointSet.unionSets(src, dest);
                totalWeight += weight;
                cout << src << " -- " << dest << " == " << weight << endl;
                edgeCount++;
            }

            if (edgeCount == vertices - 1) {
                break;
            }
        }
        cout << "Total Weight of MST: " << totalWeight << endl;
    }
};
int main() {
    Graph graph(5);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);

    graph.computeMST();

    return 0;
}
