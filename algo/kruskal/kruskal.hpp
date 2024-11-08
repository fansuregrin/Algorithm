#ifndef ALGO_KRUSKAL_HPP
#define ALGO_KRUSKAL_HPP
#include <algorithm>
#include "../../ds/disjoint_set_union/DSU.hpp"

int kruskal(const std::vector<std::vector<std::pair<int,int>>> &g);
int kruskal(std::vector<std::vector<int>> &edges, int n);

/**
 * @brief 最小生成树 Kruskal 算法
 * @param g 邻接表表示的图，结点中顶点序号在前、权值在后。
 * @return 最小生成树的边权和
 */
int kruskal(const std::vector<std::vector<std::pair<int,int>>> &g) {  
    std::vector<std::vector<int>> edges;
    int n = g.size();
    for (int i=0; i<n; ++i) {
        for (const auto &adj: g[i]) {
            // edge = {权值, 顶点1, 顶点2}
            edges.push_back({adj.second, i, adj.first});
        }
    }
    return kruskal(edges, n);
}

/**
 * @brief 最小生成树 Kruskal 算法
 * @param edges 图的所有边，边 = {权值, 顶点u，顶点v}
 * @param n 图的顶点总数
 * @return 最小生成树的边权和
 */
int kruskal(std::vector<std::vector<int>> &edges, int n) {
    // 把图中的所有边按权值升序排序
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    int num_conn = 0, w = 0;
    for (const auto &e : edges) {
        if (dsu.merge(e[1], e[2])) {
            ++num_conn;
            w += e[0];
        }
        if (num_conn >= n-1) {
            break;
        }
    }
    return w;
}

#endif // ALGO_KRUSKAL_HPP