// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description

package arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LC_1431_KidsWithTheGreatestNumberOfCandies {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        List<Boolean> result = new ArrayList<>();
        int max = Arrays.stream(candies).max().getAsInt();

        for (int c: candies) {
            result.add(c + extraCandies >= max ? true : false);
        }

        return result;
    }
}
