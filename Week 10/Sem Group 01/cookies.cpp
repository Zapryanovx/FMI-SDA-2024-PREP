// C++ 14/20
int cookies(int k, vector<int> A) {

    priority_queue<int, vector<int>, greater<>>pq(A.begin(), A.end());
    int count = 0;

    while (pq.size())
    {
        if (pq.size() == 1 && pq.top() < k)
        {
            return -1;
        }

        else if (pq.top() >= k)
        {
            return count;
        }

        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();

        pq.push(f + 2 * s);
        count++;
    }

    return -1;
}