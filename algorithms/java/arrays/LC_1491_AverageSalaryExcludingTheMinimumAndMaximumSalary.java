// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/
package arrays;

public class LC_1491_AverageSalaryExcludingTheMinimumAndMaximumSalary {
    public double average(int[] salary) {
        int min = salary[0];
        int max = salary[0];
        long sum = 0L;

        for (int s: salary) {
            min = Math.min(min, s);
            max = Math.max(max, s);
            sum += s;
        }
        return (double)(sum - min - max) / (salary.length - 2);
    }
}

