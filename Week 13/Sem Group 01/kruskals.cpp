#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
};

class UnionFind
{
private:
    vector<int> parents;
    vector<int> sizes;

    int getParent(int vertex)
    {
        if (parents[vertex] == vertex)
        {
            return vertex;
        }

        return parents[vertex] = getParent(parents[vertex]);
    }

public:
    UnionFind(int vertices) : parents(vertices), sizes(vertices)
    {
        for (int i = 0; i < vertices; i++)
        {
            parents[i] = i;
            sizes[i] = 1;
        }
    }

    bool areInOneSet(int first, int second)
    {
        return getParent(first) == getParent(second);
    }

    void unionVertices(int first, int second)
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

int kruskals(int v, vector<Edge>& edges) {

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
        });

    UnionFind uf(v);
    vector<Edge> mstEdges;
    int totalWeight = 0;

    for (size_t i = 0; i < edges.size(); i++)
    {
        if (uf.areInOneSet(edges[i].from, edges[i].to))
        {
            continue;
        }

        totalWeight += edges[i].weight;
        uf.unionVertices(edges[i].from, edges[i].to);
        mstEdges.push_back(edges[i]);
        if (mstEdges.size() == v - 1)
        {
            break;
        }
    }

    return totalWeight;
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<Edge> edges(e);
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    cout << kruskals(v, edges);
}