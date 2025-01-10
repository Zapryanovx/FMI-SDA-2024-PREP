#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int from;
    int to;
    int speed;

    bool operator<(const Edge& other)
    {
        return speed < other.speed;
    }
};

struct UnionFind
{
    vector<size_t> parents;
    vector<size_t> sizes;

    UnionFind(int vertices) : parents(vertices), sizes(vertices, 1)
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

    bool areInOneSet(size_t first, size_t second)
    {
        return getParent(first) == getParent(second);
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
        int f, t, s;
        cin >> f >> t >> s;
        edges[i] = { f, t, s };
    }

    sort(edges.begin(), edges.end());

    int minS = 0;
    int maxS = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        UnionFind uf(n + 1);
        int currMax = 0;
        int count = 0;

        for (int j = i; j < m; j++)
        {
            if (uf.areInOneSet(edges[j].from, edges[j].to))
            {
                continue;
            }

            uf.unionVertices(edges[j].from, edges[j].to);
            currMax = max(currMax, edges[j].speed);
            count++;

            if (count == n - 1)
            {
                break;
            }
        }

        if (count == n - 1 && currMax - edges[i].speed < maxS - minS)
        {
            minS = edges[i].speed;
            maxS = currMax;
        }
    }

    cout << minS << ' ' << maxS;

    return 0;
}
