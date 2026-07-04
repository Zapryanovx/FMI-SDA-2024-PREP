// https://leetcode.com/problems/transpose-matrix/description/

public class LC_0867_TransposeMatrix {
    public int[][] transpose(int[][] matrix) {
        int[][] transposed = new int[matrix[0].length][matrix.length];

        for (int row = 0; row < matrix.length; row++) {
            for (int col = 0; col < matrix[0].length; col++) {
                transposed[col][row] = matrix[row][col];
            }
        }
        return transposed;
    }
}
