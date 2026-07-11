// https://leetcode.com/problems/print-zero-even-odd/description/

import java.util.concurrent.Semaphore;
import java.util.function.IntConsumer;

public class LC_1116_PrintZeroEvenOdd {
    private final Semaphore z = new Semaphore(1);
    private final Semaphore otz = new Semaphore(0);
    private final Semaphore etz = new Semaphore(0);

    private final int n;

    public LC_1116_PrintZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            z.acquire();

            printNumber.accept(0);

            if (i % 2 == 0) {
                otz.release();
            } else {
                etz.release();
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            etz.acquire();

            printNumber.accept(i);

            z.release();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            otz.acquire();

            printNumber.accept(i);

            z.release();
        }
    }
}
