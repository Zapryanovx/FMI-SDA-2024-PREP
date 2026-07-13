// https://leetcode.com/problems/flood-fill/description/

package dfs;

public class LC_0733_FloodFill {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        return fill(image, sr, sc, color, image[sr][sc]);
    }

    private int[][] fill(int[][] image, int sr, int sc, int color, int startingColor) {
        if (sr < 0 || sr >= image.length
            || sc < 0 || sc >= image[0].length
            || image[sr][sc] != startingColor || image[sr][sc] == color) {
            return image;
        }

        image[sr][sc] = color;
        fill(image, sr - 1, sc, color, startingColor);
        fill(image, sr, sc - 1, color, startingColor);
        fill(image, sr, sc + 1, color, startingColor);
        fill(image, sr + 1, sc, color, startingColor);
        return image;
    }

}
