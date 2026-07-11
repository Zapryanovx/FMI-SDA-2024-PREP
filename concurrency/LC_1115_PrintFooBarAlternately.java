// https://leetcode.com/problems/print-foobar-alternately/description/

import java.util.concurrent.Semaphore;

public class LC_1115_PrintFooBarAlternately {
    private final Semaphore ftb = new Semaphore(1);
    private final Semaphore btf = new Semaphore(0);

    private final int n;

    public LC_1115_PrintFooBarAlternately(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            ftb.acquire();

            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();

            btf.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            btf.acquire();

            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();

            ftb.release();
        }
    }
}
