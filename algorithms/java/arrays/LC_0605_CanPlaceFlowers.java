// https://leetcode.com/problems/can-place-flowers/description

package arrays;

public class LC_0605_CanPlaceFlowers {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = 0;

        for (int i = 0; i < flowerbed.length; i++) {
            boolean currentEmpty = flowerbed[i] == 0;
            boolean leftEmpty = i == 0 || flowerbed[i - 1] == 0;
            boolean rightEmpty =
                    i == flowerbed.length - 1 || flowerbed[i + 1] == 0;

            if (currentEmpty && leftEmpty && rightEmpty) {
                flowerbed[i] = 1;
                count++;
            }
        }

        return count >= n;
    }
}
