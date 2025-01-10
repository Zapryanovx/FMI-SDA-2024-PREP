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

    int from, to;
    int n;
    cin >> n;

    UnionFind uf(n + 1);
    int components = n;
    while (cin >> from >> to)
    {
        if (uf.areInOneSet(from, to))
        {
            cout << components << " CYCLE FORMED!" << endl;
            continue;
        }

        components--;
        uf.unionVertices(from, to);

        cout << components << endl;
    }

    return 0;
}
