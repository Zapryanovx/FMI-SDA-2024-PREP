#include <bits/stdc++.h>
using namespace std;

static bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first < b.first;
}

int getBadFriendSeat(vector<vector<int>>& times, int targetFriend) {

    int n = times.size();

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({ times[i][0], i + 1 });
        v.push_back({ times[i][1], -(i + 1) });
    }

    sort(v.begin(), v.end(), compare);
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(i);
    }

    unordered_map<int, int> friendOnChair;
    for (auto& p : v)
    {
        int time = p.first;
        int idx = abs(p.second);

        if (p.second < 0)
        {
            int chair = friendOnChair[idx];
            pq.push(chair);
        }

        else
        {
            int chair = pq.top();
            pq.pop();
            friendOnChair[idx] = chair;

            if (idx - 1 == targetFriend)
            {
                return chair;
            }
        }
    }

    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> times;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        int in, out;
        cin >> in >> out;

        temp.push_back(in);
        temp.push_back(out);
        times.push_back(temp);
    }

    int target;
    cin >> target;

    cout << getBadFriendSeat(times, target);


    return 0;
}
