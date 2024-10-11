#include <iostream>

class Solution {
public:
    int numJewelsInStones(std::string jewels, std::string stones) {

        bool jewelsFound[26][2]{};

        for (int i = 0; i < jewels.size(); i++)
        {
            if (isupper(jewels[i]))
            {
                jewelsFound[jewels[i] - 'A'][0] = true;
                continue;
            }

            jewelsFound[jewels[i] - 'a'][1] = true;
        }

        int count = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            if (isupper(stones[i]))
            {
                if (jewelsFound[stones[i] - 'A'][0])
                {
                    count++;
                }
            }

            else
            {
                if (jewelsFound[stones[i] - 'a'][1])
                {
                    count++;
                }
            }
        }

        return count;

    }
};