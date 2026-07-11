// https://leetcode.com/problems/fizz-buzz-multithreaded/description/

import java.util.concurrent.Semaphore;
import java.util.function.IntConsumer;

public class LC_1195_FizzBuzzMultithreaded {
    private final int n;

    private final Semaphore mutex = new Semaphore(1);
    private final Semaphore f = new Semaphore(0);
    private final Semaphore b = new Semaphore(0);
    private final Semaphore fb = new Semaphore(0);

    public LC_1195_FizzBuzzMultithreaded(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 != 0) {
                f.acquire();

                printFizz.run();

                mutex.release();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            if (i % 5 == 0 && i % 3 != 0) {
                b.acquire();

                printBuzz.run();

                mutex.release();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                fb.acquire();

                printFizzBuzz.run();

                mutex.release();
            }
        }
    }

    // printNumber.accept(x) outputs "x".
    public void number(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            mutex.acquire();

            if (i % 15 == 0) {
                fb.release();
            } else if (i % 3 == 0) {
                f.release();
            } else if (i % 5 == 0) {
                b.release();
            } else {
                printNumber.accept(i);
                mutex.release();
            }
        }
    }
}
