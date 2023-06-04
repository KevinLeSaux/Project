#include <iostream>
#include <vector>
using namespace std;

// Sample adjacency list
vector<vector<int>> adj_list = {
    {1, 2},
    {0, 2},
    {0, 1, 3},
    {2}
};

int main() {
    // Determine the number of vertices in the graph
    int num_vertices = adj_list.size();

    // Create an n x n matrix initialized with zeros
    vector<vector<int>> adj_matrix(num_vertices, vector<int>(num_vertices, 0));

    // Iterate through each vertex and its neighbors, marking the corresponding entry in the matrix as 1
    for (int vertex = 0; vertex < num_vertices; vertex++) {
        for (int neighbor : adj_list[vertex]) {
            adj_matrix[vertex][neighbor] = 1;
        }
    }

    // Print the adjacency matrix
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
