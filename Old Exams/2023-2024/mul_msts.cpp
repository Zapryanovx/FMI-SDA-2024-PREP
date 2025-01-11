#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int from;
    int to;
    int weight;

    bool operator<(const Edge& other)
    {
        return weight < other.weight;
    }
};

struct UnionFind
{
    vector<size_t> parents;
    vector<size_t> sizes;
    vector<long long> sums;

    UnionFind(size_t vertices) : parents(vertices), sizes(vertices, 1), sums(vertices)
    {
        for (int i = 0; i < vertices; i++)
        {
            parents[i] = i;
        }
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

    void unionVertices(size_t first, size_t second, long long weight)
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
        sums[parentOfFirst] += (sums[parentOfSecond] + weight);
        sizes[parentOfFirst] += sizes[parentOfSecond];
    }
};

long long kruskal(vector<Edge>& edges, int k, int n)
{
    UnionFind uf(n);
    for (auto& edge : edges)
    {
        if (uf.areInOneSet(edge.from, edge.to))
        {
            continue;
        }

        uf.unionVertices(edge.from, edge.to, edge.weight);
    }

    unordered_set<int> visited;
    long long totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (uf.sizes[uf.getParent(i)] % k == 0)
        {
            if (!visited.count(uf.getParent(i)))
            {
                visited.insert(uf.getParent(i));
                totalSum += uf.sums[uf.getParent(i)];
            }
        }
    }

    return totalSum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    cin >> q;
    while (q--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        UnionFind uf(n);

        vector<Edge> edges;
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({ u, v, w });
        }
        sort(edges.begin(), edges.end());

        cout << kruskal(edges, k, n) << endl;
    }

    return 0;
}
