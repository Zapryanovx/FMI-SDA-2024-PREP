#include <bits/stdc++.h>
using namespace std;

struct Tunnel
{
    long long to;
    long long kg;
    long long battery;
};

using pll = pair<long long, long long>;

long long djikstra(vector<vector<Tunnel>>& graph, int start, int end, int maxWeight)
{
    vector<long long> distances(graph.size(), LLONG_MAX);
    distances[start] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({ 0, start });

    unordered_set<int> visited;
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        long long currNode = curr.second;
        long long currWeight = curr.first;

        if (visited.count(currNode))
        {
            continue;
        }

        visited.insert(currNode);

        for (auto& t : graph[currNode])
        {
            if (t.kg > maxWeight)
            {
                continue;
            }

            long long nextNode = t.to;
            long long total = currWeight + t.battery;

            if (distances[nextNode] > total)
            {
                distances[nextNode] = total;
                pq.push({ total, nextNode });
            }
        }
    }

    return distances[end];
}

long long binarySearch(long long minWeight, long long maxWeight, long long maxBattery, long long n, vector<vector<Tunnel>>& graph)
{
    long long left = minWeight;
    long long right = maxWeight;
    long long res = -1;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long currDist = djikstra(graph, 1, n, mid);
        if (currDist <= maxBattery)
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return res;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, k;
    cin >> n >> m >> k;

    vector<vector<Tunnel>> graph(n + 1);
    long long maxWeight = 0;
    for (long long i = 0; i < m; i++)
    {
        long long from, to, kg, battery;
        cin >> from >> to >> kg >> battery;

        maxWeight = max(maxWeight, kg);
        graph[from].push_back({ to, kg, battery });

    }

    cout << binarySearch(1, maxWeight, k, n, graph);


    return 0;
}
