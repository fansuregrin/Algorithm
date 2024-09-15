// 问题描述：
// 有 n 个城市，所有城市彼此是相邻的，它们各自向相邻的城市修建道路。
// 道路施工队每年前进一个单位，当两个城市的施工队相遇后，两个城市被修建的道路连通。
// 问最少需要多少年，所有城市能连通？
// 
// 输入格式：
// 第一行：一个整数 n，表示城市数量
// 接下来的 n 行，每一行有两个整数，表示城市的坐标
//
// 输出格式：
// 一个整数，表示连通所有城市的最少时间（向上取整）
// 
// 案例：
// 输入：
// 3
// 0 0
// 0 6
// 7 0
// 输出：
// 3
//
// 解题思路：
// 每一个城市看成无向图的顶点，城市之间的距离看成边的权值，建立加权的无向完全图
// 转化成最小生成树（连通加权无向图中一棵权值最小的生成树）问题
// 所需的时间（年数）由最小生成树中权值最大的那条边决定
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