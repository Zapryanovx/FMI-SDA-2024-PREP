// https://leetcode.com/problems/day-of-the-year/description/

public class P1154_DayOfTheYear {
    public int dayOfYear(String date) {
        String[] args = date.split("-");
        int year = Integer.parseInt(args[0]);
        int month = Integer.parseInt(args[1]);
        int day = Integer.parseInt(args[2]);

        int[] months = new int[] {
                0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        };

        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            months[2]++;
        }

        int cnt = 0;
        for (int i = 1; i < month; i++) {
            cnt += months[i];
        }
        cnt += day;
        return cnt;
    }
}
