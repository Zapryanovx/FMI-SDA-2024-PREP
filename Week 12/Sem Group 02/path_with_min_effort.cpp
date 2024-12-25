struct Node
{
    int x;
    int y;
    int price;

    bool operator<(const Node& other) const
    {
        return price > other.price;
    }
};

vector<vector<int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
bool isValid(int x, int y, int m, int n)
{
    return 0 <= x && x < m && 0 <= y && y < n;
}


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> prices(m, vector<int>(n, INT_MAX));
        prices[0][0] = 0;

        priority_queue<Node> nextToProcess;
        nextToProcess.push({ 0, 0, 0 });

        while (!nextToProcess.empty())
        {
            auto current = nextToProcess.top();
            nextToProcess.pop();

            if (prices[current.x][current.y] < current.price)
            {
                continue;
            }

            if (current.x == m - 1 && current.y == n - 1)
            {
                return current.price;
            }

            for (int i = 0; i < 4; i++)
            {
                int newX = current.x + directions[i][0];
                int newY = current.y + directions[i][1];

                if (isValid(newX, newY, m, n))
                {
                    int newPrice = max(current.price,
                        abs(heights[current.x][current.y] - heights[newX][newY]));
                    if (prices[newX][newY] > newPrice)
                    {
                        prices[newX][newY] = newPrice;
                        nextToProcess.push({ newX, newY, newPrice });
                    }
                }
            }
        }

        return 0;
    }
};