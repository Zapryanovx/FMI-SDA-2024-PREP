// https://leetcode.com/problems/print-in-order/description/

import java.util.concurrent.Semaphore;

public class LC_1114_PrintinOrder {
    private final Semaphore saf = new Semaphore(0);
    private final Semaphore tas = new Semaphore(0);

    public LC_1114_PrintinOrder() {
    }

    public void first(Runnable printFirst) throws InterruptedException {

        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();

        saf.release();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        saf.acquire();

        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();

        tas.release();
    }

    public void third(Runnable printThird) throws InterruptedException {
        tas.acquire();

        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
