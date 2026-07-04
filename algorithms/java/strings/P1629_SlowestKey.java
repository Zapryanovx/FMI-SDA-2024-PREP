// https://leetcode.com/problems/slowest-key/description/

public class P1629_SlowestKey {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        int maxDuration = Integer.MIN_VALUE;
        char slowestKey = 'a';

        for (int i = 0; i < releaseTimes.length; i++) {
            int duration = releaseTimes[i];
            if (i != 0) {
                duration -= releaseTimes[i - 1];
            }

            if (duration > maxDuration
                    || (duration == maxDuration && keysPressed.charAt(i) > slowestKey)) {
                maxDuration = duration;
                slowestKey = keysPressed.charAt(i);
            }
        }

        return slowestKey;
    }
}
