class Solution {

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {


        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (int i = 0; i < arr.size(); i++)
        {
            pq.push({ abs(arr[i] - x), arr[i] });
        }

        vector<int> res;
        while (k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        sort(res.begin(), res.end());
        return res;
    }
};