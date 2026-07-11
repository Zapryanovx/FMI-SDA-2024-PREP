// https://leetcode.com/problems/the-dining-philosophers/description/

import java.util.concurrent.Semaphore;

public class LC_1226_TheDiningPhilosophers {
    private final Semaphore[] forks = new Semaphore[5];
    private final Semaphore table = new Semaphore(4, true);

    public LC_1226_TheDiningPhilosophers() {
        for (int i = 0; i < 5; i++) {
            forks[i] = new Semaphore(1, true);
        }
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {

        int left = philosopher;
        int right = (philosopher + 1) % 5;

        table.acquire();

        forks[left].acquire();
        forks[right].acquire();

        pickLeftFork.run();
        pickRightFork.run();

        eat.run();

        putLeftFork.run();
        putRightFork.run();

        forks[left].release();
        forks[right].release();

        table.release();
    }
}
