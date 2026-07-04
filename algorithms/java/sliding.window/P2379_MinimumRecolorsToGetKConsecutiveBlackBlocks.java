// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/

public class P2379_MinimumRecolorsToGetKConsecutiveBlackBlocks {
    public int minimumRecolors(String blocks, int k) {
        int whites = 0;
        for (int i = 0; i < k; i++) {
            if (blocks.charAt(i) == 'W') whites++;
        }

        int min = whites;
        for (int i = k; i < blocks.length(); i++) {
            if (blocks.charAt(i) == 'W') whites++;
            if (blocks.charAt(i - k) == 'W') whites--;
            min = Math.min(min, whites);
        }
        return min;
    }
}
