class Solution {
public:

    string generateBinary(int num, int n)
    {
        string binary = "";
        for (int i = 0; i < n; i++)
        {
            binary = (num & 1 ? "1" : "0") + binary;
            num >>= 1;
        }

        return binary;
    }

    string findDifferentBinaryString(vector<string>& nums) {

        unordered_set<string> s(nums.begin(), nums.end());

        int n = nums.size();
        int combinations = 1 << n;

        for (int i = 0; i < combinations; i++)
        {
            string curr = generateBinary(i, n);
            if (s.find(curr) == s.end())
            {
                return curr;
            }
        }

        return "";
    }
};