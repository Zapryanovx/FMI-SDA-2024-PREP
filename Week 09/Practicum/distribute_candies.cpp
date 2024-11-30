class Solution {
public:
    int distributeCandies(vector<int>& candyType) {

        size_t toEat = candyType.size() / 2;
        set<int> types(candyType.begin(), candyType.end());

        return min(toEat, types.size());
    }
};