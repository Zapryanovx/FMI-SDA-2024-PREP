class Solution {
public:
    int trap(vector<int>& height) {

        deque<pair<int, int>> blocks;
        int trappedWater = 0;

        for (int i = 0; i < height.size(); i++)
        {
            while (blocks.size() && blocks.back().first < height[i])
            {
                auto block = blocks.back();
                blocks.pop_back();
                if (blocks.empty())
                {
                    continue;
                }

                int waterBlocks = min(height[i], blocks.front().first) - block.first;
                int interval = block.second - blocks.back().second;
                trappedWater += waterBlocks * interval;
            }

            blocks.push_back({ height[i], i });
        }

        return trappedWater;

    }
};