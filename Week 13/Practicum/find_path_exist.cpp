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

    void unionSet(int x, int y)
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
        parentOfFirst = parentOfSecond;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        UnionFind uf(n);
        for (auto& edge : edges)
        {
            uf.unionSet(edge[0], edge[1]);
        }

        return uf.areInOneSet(source, destination);
    }
};