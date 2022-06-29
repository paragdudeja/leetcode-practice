// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(int node, int color, int n, bool graph[101][101], vector<int> &colors) {
    for(int i = 0; i < n; i++) {
        if(graph[node][i] && colors[i] == color)
            return false;
    }
    return true;
}

bool colorNode(int node, int n, int m, bool graph[101][101], vector<int> &colors) {
    if(node == n)
        return true;
    
    for(int color = 1; color <= m; color++) {
        if(isSafe(node, color, n, graph, colors)) {
            colors[node] = color;
            if(colorNode(node+1, n, m, graph, colors))
                return true;
            colors[node] = 0;
        }
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> colors(n);
    
    return colorNode(0, n, m, graph, colors);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends