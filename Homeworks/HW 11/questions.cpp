#include <bits/stdc++.h>
using namespace std;

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
        sizes[parentOfFirst] += parentOfSecond;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    UnionFind uf(n + 1);
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        uf.unionVertices(from, to);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int type, from, to;
        cin >> type >> from >> to;

        if (type == 1)
        {
            cout << uf.areInOneSet(from, to);
        }

        else
        {
            uf.unionVertices(from, to);
        }
    }

    return 0;
}
