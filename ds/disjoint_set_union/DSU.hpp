#ifndef ALGO_DSU_HPP
#define ALGO_DSU_HPP
#include <vector>
#include <algorithm>

struct DSU {
    std::vector<int> par, rank;
    
    DSU(int n) : par(n), rank(n, 1) {
        for (int i=0; i<n; ++i) {
            par[i] = i;
        }
    }

    int find(int x) {
        while (x != par[x]) {
            x = par[x];
        }
        return x;
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        if (rank[x] < rank[y]) {
            std::swap(x, y);
        }
        par[y] = x;
        rank[x] += rank[y];
        return true;
    }
};

#endif // ALGO_DSU_HPP