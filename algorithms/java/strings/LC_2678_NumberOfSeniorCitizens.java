// https://leetcode.com/problems/number-of-senior-citizens/description/

public class LC_2678_NumberOfSeniorCitizens {
    public int countSeniors(String[] details) {
        int cnt = 0;

        for (String d: details) {
            if (Integer.parseInt(d.substring(11, 13)) > 60) {
                cnt++;
            }
        }

        return cnt;
    }
}
