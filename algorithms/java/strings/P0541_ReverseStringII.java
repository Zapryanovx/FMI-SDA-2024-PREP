// https://leetcode.com/problems/reverse-string-ii/description/

public class P0541_ReverseStringII {
    public String reverseStr(String s, int k) {
        char[] ch = s.toCharArray();
        for (int i = 0; i < ch.length; i += 2 * k) {
            reverse(ch, i, Math.min(i + k - 1, ch.length - 1));
        }
        return String.valueOf(ch);
    }

    private void reverse(char[] ch, int from, int to) {
        while(from < to) {
            char temp = ch[from];
            ch[from] = ch[to];
            ch[to] = temp;

            from++;
            to--;
        }
    }
}
