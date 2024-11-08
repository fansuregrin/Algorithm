#include <iostream>
#include "kruskal.hpp"

using namespace std;

int main() {
    // 7
    // 0 1 7
    // 0 3 5
    // 1 2 8
    // 1 3 9
    // 1 4 7
    // 2 4 5
    // 3 4 15
    // 3 5 6
    // 4 5 8
    // 4 6 9
    // 5 6 11
    int n{0};
    cin >> n;
    vector<vector<pair<int,int>>> g(n, vector<pair<int,int>>());
    int u, v, w;
    while (cin >> u >> v >> w) {
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    cout << "minimum edge weight sum: " << kruskal(g) << endl;
}