class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < score.size(); i++)
        {
            pq.push({ score[i], i });
        }

        vector<string> res(score.size());
        int place = 1;

        while (pq.size())
        {
            pair<int, int> points = pq.top();
            pq.pop();

            if (place == 1)
            {
                res[points.second] = "Gold Medal";
            }

            else if (place == 2)
            {
                res[points.second] = "Silver Medal";
            }

            else if (place == 3)
            {
                res[points.second] = "Bronze Medal";
            }

            else
            {
                res[points.second] = to_string(place);
            }

            place++;
        }

        return res;
    }
};