package queue;// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/

import java.util.ArrayDeque;
import java.util.Deque;

public class LC_1700_NumberOfStudentsUnableToEatLunch {
    public int countStudents(int[] students, int[] sandwiches) {
        Deque<Integer> sa = new ArrayDeque<>();
        Deque<Integer> st = new ArrayDeque<>();

        for (int i = 0; i < students.length; i++) {
            sa.addLast(sandwiches[i]);
            st.addLast(students[i]);
        }

        int unable = 0;
        while (!sa.isEmpty()) {
            if (st.peekFirst().equals(sa.peekFirst())) {
                st.pollFirst();
                sa.pollFirst();
                unable = 0;
            } else {
                st.addLast(st.pollFirst());
                unable++;
                if (unable == st.size()) {
                    return unable;
                }
            }
        }

        return 0;
    }
}
