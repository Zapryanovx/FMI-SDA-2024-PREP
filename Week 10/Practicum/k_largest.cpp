class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    int target;

    KthLargest(int k, vector<int>& nums) {
        target = k;
        for (int num : nums)
        {
            add(num);
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > target)
        {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
