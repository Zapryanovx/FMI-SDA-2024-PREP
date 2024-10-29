class Solution {

    bool check(vector<int>& quantities, long long mid, int n)
    {
        int currShops = 0;
        for (size_t i = 0; i < quantities.size(); i++)
        {
            currShops += quantities[i] / mid;
            if (quantities[i] % mid != 0)
            {
                currShops++;
            }
        }

        return currShops <= n;
    }

public:
    int minimizedMaximum(int n, vector<int>& quantities) {

        long long left = 1;
        long long right = 0;
        for (size_t i = 0; i < quantities.size(); i++)
        {
            right += quantities[i];
        }

        long long ans = INT_MAX;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            if (check(quantities, mid, n))
            {
                ans = mid;
                right = mid - 1;
            }

            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};