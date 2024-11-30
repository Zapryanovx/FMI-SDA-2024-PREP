#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const long long BASE = 31;

long long modPow(long long base, long long at, long long mod)
{
    long long result = 1;
    while (at > 0)
    {
        if (at % 2 == 1)
        {
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        at /= 2;
    }
    return result;
}

unordered_set<long long> computeHashes(const string& s, int len)
{
    unordered_set<long long> hashes;
    if (len == 0)
    {
        return hashes;
    }

    long long hash1 = 0, hash2 = 0;
    long long basePower1 = modPow(BASE, len - 1, MOD1);
    long long basePower2 = modPow(BASE, len - 1, MOD2);

    for (int i = 0; i < len; i++) {
        hash1 = (hash1 * BASE + s[i]) % MOD1;
        hash2 = (hash2 * BASE + s[i]) % MOD2;
    }

    hashes.insert(hash1 * MOD2 + hash2);

    for (int i = len; i < s.size(); i++)
    {
        hash1 = (hash1 - (s[i - len] * basePower1) % MOD1 + MOD1) % MOD1;
        hash1 = (hash1 * BASE + s[i]) % MOD1;

        hash2 = (hash2 - (s[i - len] * basePower2) % MOD2 + MOD2) % MOD2;
        hash2 = (hash2 * BASE + s[i]) % MOD2;

        hashes.insert(hash1 * MOD2 + hash2);
    }

    return hashes;
}

bool hasCommonSubstring(const string& s1, const string& s2, int len)
{
    auto hashes1 = computeHashes(s1, len);
    auto hashes2 = computeHashes(s2, len);

    for (const auto& h : hashes2)
    {
        if (hashes1.count(h))
        {
            return true;
        }
    }
    return false;
}

int longestCommonSubstring(const string& s1, const string& s2)
{
    int left = 1, right = min(s1.size(), s2.size());
    int result = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (hasCommonSubstring(s1, s2, mid))
        {
            result = mid;
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }

    return result;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << longestCommonSubstring(s1, s2) << endl;
    return 0;
}
