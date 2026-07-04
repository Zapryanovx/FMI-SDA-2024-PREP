// https://leetcode.com/problems/find-the-highest-altitude/description/

public class P1732_FindTheHighestAltitude {
    public int largestAltitude(int[] gain) {
        int maxAltitude = 0;
        int sum = 0;
        for (int g : gain) {
            sum += g;
            maxAltitude = Math.max(maxAltitude, sum);
        }
        return maxAltitude;
    }
}
