class UnionFind
{
private:
    vector<size_t> parents;
    vector<size_t> sizes;

    size_t getParent(size_t vertex)
    {
        if (parents[vertex] == vertex)
        {
            return vertex;
        }

        return parents[vertex] = getParent(parents[vertex]);
    }

public:
    UnionFind(size_t vertices) : parents(vertices), sizes(vertices, 1)
    {
        for (int i = 0; i < vertices; i++)
        {
            parents[i] = i;
        }
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

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int nodesCount = isConnected.size();
        UnionFind uf(nodesCount);
        int numberOfComponents = nodesCount;
        for (int i = 0; i < nodesCount; i++)
        {
            for (int j = 0; j < nodesCount; j++)
            {
                if (isConnected[i][j] && !uf.areInOneSet(i, j))
                {
                    uf.unionVertices(i, j);
                    numberOfComponents--;

                    if (numberOfComponents == 1)
                    {
                        break;
                    }
                }
            }
        }

        return numberOfComponents;
    }
};