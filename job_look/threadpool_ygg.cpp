#include <iostream>
#include<thread>
#include<mutex>
#include <chrono>
#include<time.h>
#include<vector>
#include<queue>
#include<future>
#include <mutex>
#include <queue>
#include <functional>
#include <future>
#include <thread>
#include <utility>
#include <vector>
#include <condition_variable>
#include<string>
using namespace std;

template<typename T>
struct safe_queue{
    queue<T>que;
    mutex _m;
    bool empty() {
        lock_guard<mutex> lc(_m);
        return que.empty();
    }
    auto size() {
        lock_guard<mutex> lc(_m);
        return que.size();
    }
    void push(T& t) {
        lock_guard<mutex> lc(_m);
        que.push(t);
    }
    bool pop(T & t) {
        if (empty())return false;
        lock_guard<mutex> lc(_m);
        t = move(que.front());
        que.pop();
        return true;
    }
};
class ThreadPool {
   private:
    class worker {
     public:
        ThreadPool* pool; 
        worker(ThreadPool* _pool) :  pool{ _pool } {}
        void operator ()() {
            while (!pool->is_shut_down) {
                {
                    unique_lock<mutex> lock(pool->_m);
                    pool->cv.wait(lock, [this]() {
                        return this->pool->is_shut_down ||
                            !this->pool->que.empty();
                        });
                }
                function<void()>func;
                bool flag = pool->que.pop(func);
                if (flag) {
                    func();
                }
            }
        }
    };
public:
    bool is_shut_down;
    safe_queue<std::function<void()>> que; 
    vector<std::thread>threads; 
    mutex _m; 
    condition_variable cv;
    ThreadPool(int n) : threads(n), is_shut_down{ false } {
        for (auto& t : threads)t = thread{ worker(this) };
    }
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool(ThreadPool&&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;
    ThreadPool& operator=(ThreadPool&&) = delete;

    template <typename F, typename... Args>
    auto submit(F&& f, Args &&...args) -> std::future<decltype(f(args...))> {
        function<decltype(f(args...))()> func = [&f, args...]() {return f(args...); };
        auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);
        std::function<void()> warpper_func = [task_ptr](){
            (*task_ptr)();
        };
        que.push(warpper_func);
        cv.notify_one();
        return task_ptr->get_future();
    }
    ~ThreadPool() {
        auto f = submit([]() {});
        f.get();
        is_shut_down = true;
        cv.notify_all(); // 通知，唤醒所有工作线程
        for (auto& t : threads) {
          if(t.joinable()) t.join();
        }
    }
};
mutex _m;

int main()
{
    ThreadPool pool(4);
    for (int i = 1; i <= 20; i++) {
        pool.submit([](int n) {
            if (n % 2 == 1) {
                this_thread::sleep_for(0.1s);
            }
            {
                unique_lock<mutex> lk(_m);
                cout<<"id :"<< n << endl;
            }
         }, i);
    }
}
