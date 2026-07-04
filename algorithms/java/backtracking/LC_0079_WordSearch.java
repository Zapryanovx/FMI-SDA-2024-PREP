// https://leetcode.com/problems/word-search/description/

public class LC_0079_WordSearch {
    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (backtrack(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean backtrack(char[][] board, int i, int j, String word, int wordAt) {
        if (!isValid(board, i, j)) {
            return false;
        }

        if (board[i][j] == '#') {
            return false;
        }

        if (board[i][j] != word.charAt(wordAt)) {
            return false;
        }

        if (wordAt == word.length() - 1) {
            return true;
        }

        char temp = board[i][j];
        board[i][j] = '#';
        boolean found = backtrack(board, i - 1, j, word, wordAt + 1)
                || backtrack(board, i, j - 1, word, wordAt + 1)
                || backtrack(board, i, j + 1, word, wordAt + 1)
                || backtrack(board, i + 1, j, word, wordAt + 1);
        board[i][j] = temp;
        return found;
    }

    private boolean isValid(char[][] board, int i, int j) {
        if (i < 0 || i >= board.length) {
            return false;
        }
        return j >= 0 && j < board[0].length;
    }
}
