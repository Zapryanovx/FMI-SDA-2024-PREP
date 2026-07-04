// https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/

public class P1582_SpecialPositionsInABinaryMatrix {
    public int numSpecial(int[][] mat) {
        int[] onesInRows = new int[mat.length];
        int[] onesInCols = new int[mat[0].length];

        for (int row = 0; row < mat.length; row++) {
            for (int col = 0; col < mat[0].length; col++) {
                if (mat[row][col] == 1) {
                    onesInRows[row]++;
                    onesInCols[col]++;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                if (mat[i][j] == 1 && onesInRows[i] == 1 && onesInCols[j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
