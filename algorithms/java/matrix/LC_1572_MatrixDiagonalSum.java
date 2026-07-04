// https://leetcode.com/problems/matrix-diagonal-sum/description/

public class LC_1572_MatrixDiagonalSum {
    public int diagonalSum(int[][] mat) {
        int sum = 0;
        for (int row = 0; row < mat.length; row++) {
            sum += mat[row][row];
            if (row != mat.length - row - 1) {
                sum += mat[row][mat.length - row - 1];
            }
        }
        return sum;
    }
}
