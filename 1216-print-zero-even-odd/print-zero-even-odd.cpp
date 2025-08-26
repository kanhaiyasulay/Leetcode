class ZeroEvenOdd {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    int len;
    int num;
    bool printZero;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        len = 0;
        num = 1;
        printZero = true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(len < 2*n)
        {
            std::unique_lock<std::mutex> lock(m);
            while(!printZero) 
            {
                cv.wait(lock);
            }
            if(num <= n) printNumber(0);
            len++;
            printZero = false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(len < 2*n && num <= n)
        {
            std::unique_lock<std::mutex> lock(m);
            while(num > n) cv.wait(lock);
            while(num%2 != 0 || printZero) cv.wait(lock);
            if(num%2 == 0 && num <= n)
            {
                printNumber(num);
                num++;
                len++;
                printZero = true;
                cv.notify_all();
            }
        }
    }

    void odd(function<void(int)> printNumber) {
        while(len < 2*n && num <= n)
        {
            std::unique_lock<std::mutex> lock(m);
            while(num > n) cv.wait(lock);
            while(num%2 == 0 || printZero) cv.wait(lock);
            if(num%2 != 0 && num <= n)
            {
                printNumber(num);
                num++;
                len++;
                printZero = true;
                cv.notify_all();
            }
        }
    }
};