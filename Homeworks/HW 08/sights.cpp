#include <bits/stdc++.h>
using namespace std;

struct Point
{
    long long x = 0;
    long long y = 0;
    long long dist = 0;

    Point() = default;
    Point(long long x, long long y, long long dist) : x(x), y(y), dist(dist) {}

};

struct Comparator
{
    bool operator()(const Point& lhs, const Point& rhs)
    {
        if (lhs.dist == rhs.dist)
        {
            if (lhs.x == rhs.x)
            {
                return lhs.y > rhs.y;
            }

            return lhs.x > rhs.x;
        }

        return lhs.dist > rhs.dist;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long  startX, startY, n, k;
    cin >> startX >> startY >> n >> k;

    priority_queue<Point, vector<Point>, Comparator> pq;
    for (long long i = 0; i < n; i++)
    {
        long long x, y, dist;
        cin >> x >> y;
        dist = pow(startX - x, 2) + pow(startY - y, 2);

        Point p = Point(x, y, dist);
        pq.push(p);
    }

    while (k--)
    {
        cout << pq.top().x << " " << pq.top().y << endl;
        pq.pop();
    }

    return 0;
}