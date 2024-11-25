class Solution {
public:
    int tribonacci(int n, vector<int>& cache)
    {
        if (n == 0)
        {
            return cache[0] = 0;
        }

        if (n == 1)
        {
            return cache[1] = 1;
        }

        if (n == 2)
        {
            return cache[2] = 1;
        }

        if (cache[n] != -1)
        {
            return cache[n];
        }

        return cache[n] = tribonacci(n - 1, cache) + tribonacci(n - 2, cache) + tribonacci(n - 3, cache);
    }

    int tribonacci(int n) {
        vector<int> cache(n + 1, -1);
        return tribonacci(n, cache);
    }
};