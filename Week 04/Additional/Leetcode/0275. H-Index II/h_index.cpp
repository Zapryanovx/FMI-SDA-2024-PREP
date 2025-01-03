class Solution {
public:
    int hIndex(vector<int>& citations) {

        int left = 0;
        int right = citations.size() - 1;

        int ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (citations.size() - mid <= citations[mid])
            {
                ans = citations.size() - mid;
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