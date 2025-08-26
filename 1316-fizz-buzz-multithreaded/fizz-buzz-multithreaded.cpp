class FizzBuzz {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    int tempN = 1;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(tempN <= n)
        {
            std::unique_lock<std::mutex> lock(m);
            while(tempN <= n && !(tempN%3 == 0 && tempN%5 != 0))
            {
                cv.wait(lock);
            }
            if(tempN <= n)
            {
                printFizz();
                tempN++;
            }
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(tempN <= n)
        {
            std::unique_lock<std::mutex> lock(m);
            while(tempN <= n && !(tempN%3 != 0 && tempN%5 == 0))
            {
                cv.wait(lock);
            }
            if(tempN <= n)
            {                
                printBuzz();
                tempN++;
            }
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(tempN <= n)
        {
            std::unique_lock<std::mutex> lock(m);
            while(tempN <= n && !(tempN%3 == 0 && tempN%5 == 0))
            {
                cv.wait(lock);
            }
            if(tempN <= n)
            {
                printFizzBuzz();
                tempN++;
            }
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(tempN <= n)
        {
            std::unique_lock<std::mutex> lock(m);
            while(tempN <= n && !(tempN%3 != 0 && tempN%5 != 0))
            {
                cv.wait(lock);
            }
            if(tempN <= n) 
            {
                printNumber(tempN);
                tempN++;
            }
            cv.notify_all();
        }
    }
};