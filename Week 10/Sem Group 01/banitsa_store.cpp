#include <bits/stdc++.h>
using namespace std;

struct Task
{
    int start;
    int timeTaken;
    int index;

    Task(int start, int timeTaken, int index) : start(start), timeTaken(timeTaken), index(index) {}

};

struct comparatorByStart
{
    bool operator()(const Task& left, const Task& right)
    {
        return left.start > right.start;
    }
};

struct comparatorByTimeTaken
{
    bool operator()(const Task& left, const Task& right)
    {
        if (left.timeTaken == right.timeTaken)
        {
            return left.index > right.index;
        }

        return left.timeTaken > right.timeTaken;
    }
};

priority_queue<Task, vector<Task>, comparatorByStart> tasks;
priority_queue<Task, vector<Task>, comparatorByTimeTaken> waiting;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int start, timeTaken;
    for (int i = 0; i < n; i++)
    {
        cin >> start >> timeTaken;
        Task t = Task(start, timeTaken, i);
        tasks.push(t);
    }

    long long time = 0;
    while (!tasks.empty() || !waiting.empty())
    {
        while (!tasks.empty() && tasks.top().start <= time)
        {
            Task curr = tasks.top();
            tasks.pop();
            waiting.push(curr);
        }

        if (waiting.empty() && !tasks.empty())
        {
            time = tasks.top().start;
            continue;
        }

        Task t = waiting.top();
        waiting.pop();

        cout << t.index << " ";
        time += t.timeTaken;
    }


    return 0;
}
