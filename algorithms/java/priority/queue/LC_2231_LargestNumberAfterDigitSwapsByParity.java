// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/description/

package priority.queue;

import java.util.Comparator;
import java.util.PriorityQueue;

public class LC_2231_LargestNumberAfterDigitSwapsByParity {
    public int largestInteger(int num) {
        PriorityQueue<Character> even = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Character> odd = new PriorityQueue<>(Comparator.reverseOrder());

        String numStr = String.valueOf(num);
        for (char d: numStr.toCharArray()) {
            if ((d - '0') % 2 == 0) {
                even.add(d);
            } else {
                odd.add(d);
            }
        }

        int mul = (int) Math.pow(10, numStr.length() - 1);
        int largest = 0;
        for (char d: numStr.toCharArray()) {
            if ((d - '0') % 2 == 0) {
                largest += mul * (even.remove() - '0');
            } else {
                largest += mul * (odd.remove() - '0');
            }
            mul /= 10;
        }
        return largest;
    }
}
