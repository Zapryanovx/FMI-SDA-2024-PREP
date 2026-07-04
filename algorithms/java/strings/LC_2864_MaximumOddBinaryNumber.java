// https://leetcode.com/problems/maximum-odd-binary-number/description/

public class LC_2864_MaximumOddBinaryNumber {
    public String maximumOddBinaryNumber(String s) {
        int cntOnes = 0;

        for (char d: s.toCharArray()) {
            if (d == '1') {
                cntOnes++;
            }
        }

        return String.valueOf('1').repeat(cntOnes - 1) + String.valueOf('0').repeat(s.length() - cntOnes) + '1';
    }
}
