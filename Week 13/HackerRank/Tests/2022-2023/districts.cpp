#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
    vector<size_t> parents;
    vector<size_t> sizes;

    UnionFind(size_t vertices) : parents(vertices), sizes(vertices, 1)
    {
        iota(parents.begin(), parents.end(), 0);
    }

    size_t getParent(size_t vertex)
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
        size_t parentOfFirst = getParent(first);
        size_t parentOfSecond = getParent(second);

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

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        UnionFind uf(x);
        int components = x;

        for (int i = 0; i < y; i++)
        {
            int f, t;
            cin >> f >> t;

            if (!uf.areInOneSet(f, t))
            {
                components--;
                uf.unionVertices(f, t);
            }
        }

        cout << components << " ";
    }

    return 0;
}
