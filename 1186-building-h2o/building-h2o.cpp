class H2O {
    std::mutex m;
    std::condition_variable cv;
    int cntH;
public:
    H2O() 
    {
        cntH = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) 
    {
        std::unique_lock<std::mutex> lock(m);
        while(cntH == 2) 
        {
            cv.wait(lock);
        }
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        cntH++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) 
    {
        std::unique_lock<std::mutex> lock(m);
        while(cntH < 2)    
        {
            cv.wait(lock);
        }
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        cntH = 0;
        cv.notify_all();
    }
};