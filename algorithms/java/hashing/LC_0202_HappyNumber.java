// https://leetcode.com/problems/happy-number/description/
package hashing;

import java.util.HashSet;
import java.util.Set;

public class LC_0202_HappyNumber {
    public boolean isHappy(int n) {
        Set<Integer> unique = new HashSet<>();

        while (n != 1) {
            if (unique.contains(n)) {
                return false;
            }
            unique.add(n);
            n = sumOfSquaresOfDigits(n);
        }

        return true;
    }

    private int sumOfSquaresOfDigits(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
}
