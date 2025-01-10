#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int from;
    int to;
    long long cost;
    long long profit;
    int index;

    bool operator<(const Edge& other) const
    {
        if (cost == other.cost)
        {
            return profit > other.profit;
        }

        return cost < other.cost;
    }
};

struct UnionFind
{
    vector<size_t> parents;
    vector<size_t> sizes;

    UnionFind(size_t vertices) : parents(vertices), sizes(vertices, 1)
    {
        iota(parents.begin(), parents.end(), 0);
    }

    int getParent(size_t vertex)
    {
        if (parents[vertex] == vertex)
        {
            return vertex;
        }

        return parents[vertex] = getParent(parents[vertex]);
    }

    bool areInOneSet(size_t first, size_t second)
    {
        return getParent(first) == getParent(second);
    }

    void unionVertices(size_t first, size_t second)
    {
        int parentOfFirst = getParent(first);
        int parentOfSecond = getParent(second);

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

    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost >> edges[i].profit;
        edges[i].index = i + 1;
    }

    sort(edges.begin(), edges.end());

    UnionFind uf(n + 1);
    int components = n;
    for (int i = 0; i < m; i++)
    {
        if (uf.areInOneSet(edges[i].from, edges[i].to))
        {
            continue;
        }

        uf.unionVertices(edges[i].from, edges[i].to);
        components--;
        cout << edges[i].index << endl;

        if (components == 1)
        {
            break;
        }
    }


    return 0;
}