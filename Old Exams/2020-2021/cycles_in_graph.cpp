#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int from;
    int to;
    int weight;
    
    bool operator<(const Edge& other) const
    {
        return weight > other.weight;
    }
};

struct UnionFind
{
    vector<size_t> parents;
    vector<size_t> sizes;
    
    UnionFind(size_t vertices): parents(vertices), sizes(vertices, 1)
    {
        iota(parents.begin(), parents.end(), 0);
    }
    
    int getParent(size_t vertex)
    {
        if(parents[vertex] == vertex)
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
        
        if(parentOfFirst == parentOfSecond)
        {
            return;
        }
        
        if(sizes[parentOfFirst] < sizes[parentOfSecond])
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
    vector<Edge> edges;
    for(int i = 0; i < m; i++)
    {
        int f, t, w;
        cin >> f >> t >> w;
        
        edges.push_back({f, t, w});
    }
    
    sort(edges.begin(), edges.end());
    
    UnionFind uf(n + 1);
    long long total = 0;
    for(int i = 0; i < m; i++)
    {
        if(uf.areInOneSet(edges[i].from, edges[i].to))
        {
            total += edges[i].weight;
            continue;
        }
        
        uf.unionVertices(edges[i].from, edges[i].to);
    }
    
    cout << total;
    
    
    return 0;
}
