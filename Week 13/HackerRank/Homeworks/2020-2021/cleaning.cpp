#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct UnionFind {
    vector<int> parents;
    vector<int> sizes;

    UnionFind(int vertices) : parents(vertices), sizes(vertices, 1)
    {
        for (int i = 0; i < vertices; i++)
        {
            parents[i] = i;
        }
    }

    int getParent(int x)
    {
        if (parents[x] == x)
        {
            return x;
        }

        return parents[x] = getParent(parents[x]);
    }

    bool areInOneSet(int x, int y)
    {
        return getParent(x) == getParent(y);
    }

    void unionVertices(int x, int y)
    {
        int parentOfFirst = getParent(x);
        int parentOfSecond = getParent(y);

        if (parentOfFirst == parentOfSecond)
        {
            return;
        }

        if (sizes[parentOfFirst] < sizes[parentOfSecond])
        {
            swap(parentOfFirst, parentOfSecond);
        }

        parents[parentOfSecond] = parentOfFirst;
        sizes[parentOfFirst] += sizes[parentOfSecond];
    }
};


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;

    if (v == 1)
    {
        cout << 0;
        return 0;
    }

    std::vector<pair<int, int>> edges;

    for (int i = 0; i < e; i++)
    {
        int from, to;
        cin >> from >> to;
        edges.push_back({ from, to });
    }

    int res = 0;
    int connected = 1;
    UnionFind uf(v + 1);

    for (size_t i = 0; i < edges.size(); i++)
    {
        res++;

        if (uf.areInOneSet(edges[i].first, edges[i].second))
        {
            continue;
        }

        uf.unionVertices(edges[i].first, edges[i].second);
        connected++;

        if (connected == v)
        {
            cout << res << endl;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
