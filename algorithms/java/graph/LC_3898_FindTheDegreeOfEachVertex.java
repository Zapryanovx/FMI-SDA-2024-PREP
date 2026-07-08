// https://leetcode.com/problems/find-the-degree-of-each-vertex/
package graph;

class LC_3898_FindTheDegreeOfEachVertex {
    public int[] findDegrees(int[][] matrix) {
        int[] degrees = new int[matrix.length];
        for (int vertex = 0; vertex < matrix.length; vertex++) {
            int cnt = 0;
            for (int edge = 0; edge < matrix[vertex].length; edge++) {
                if (matrix[vertex][edge] == 1) {
                    cnt++;
                }
            }
            degrees[vertex] = cnt;
        }
        return degrees;
    }
}
