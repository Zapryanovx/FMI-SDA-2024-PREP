// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/
package greedy;

import java.util.Arrays;

public class LC_2037_MinimumNumberOfMovesToSeatEveryone {
    public int minMovesToSeat(int[] seats, int[] students) {
        Arrays.sort(seats);
        Arrays.sort(students);

        int moves = 0;
        for (int i = 0; i < seats.length; i++) {
            moves += Math.abs(seats[i] - students[i]);
        }
        return moves;
    }
}
