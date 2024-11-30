class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> m;

        for (int i = 0; i < arr.size(); i++)
        {
            if (m.find(arr[i] * 2) != m.end()
                || (arr[i] % 2 == 0 && m.find(arr[i] / 2) != m.end()))
            {
                return true;
            }

            m[arr[i]] = i;
        }

        return false;
    }
};
