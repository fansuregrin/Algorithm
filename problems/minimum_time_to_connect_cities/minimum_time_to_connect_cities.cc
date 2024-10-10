#if defined(__GNUC__)
#include <bits/stdc++.h>
#else
#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <cmath>
#endif

using namespace std;

// 并查集（合并-查找集合, Merge-Find Set）
// 使用不交集森林（Disjoint-set forest）实现
struct DSU {
    vector<int> pa; // 记录每个节点的双亲节点
    vector<int> sz; // 记录每个集合（每棵树的节点数量）的大小（秩）
    
    // 初始时，每个节点都是一个单独的集合（单独的一棵树）
    DSU(int n) : pa(n), sz(n, 1) {
        for (int i=0; i<n; ++i) {
            pa[i] = i;
        }
    }

    int find(int x) {
        while (pa[x] != x) {
            x = pa[x];
        }
        return x;
    }

    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (sz[a] > sz[b]) {
            swap(a, b);
        }
        pa[a] = b;
        sz[b] += sz[a];
        return true;
    }
};

int main() {
    int n = 0;
    cin >> n;
    vector<pair<int, int>> cities(n); // (x 坐标, y 坐标)
    for (int i=0; i<n; ++i) {
        cin >> cities[i].first >> cities[i].second;
    }

    vector<tuple<int, int, int>> edges(n*(n-1)/2); // (距离, 城市 a, 城市 b)
    auto it = edges.begin();
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            get<0>(*it) = abs(cities[i].first - cities[j].first) +
                abs(cities[i].second - cities[j].second);
            get<1>(*it) = i;
            get<2>(*it) = j;
            ++it;
        }
    }

    // Kruskal's algorithm
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int ans = 0;
    for (const auto &[w, a, b] : edges) {
        if (dsu.merge(a, b)) {
            ans = max(ans, w);
        }
    }

    cout << (ans/2 + (ans%2 ? 1 : 0)) << endl;
}