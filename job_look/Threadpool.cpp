#include<memory>
#include<queue>
#include<thread>
#include<mutex>
#include<vector>
#include <condition_variable>
#include<future>
#include<iostream>
#include <chrono>


template<typename T>
class Safe_queue
{
    public:
    bool empty()
    {
        std::lock_guard<std::mutex> a(m_mutex);
        return m_queue.empty();
    }

    auto size()
    {
        std::lock_guard<std::mutex> a(m_mutex);
        return m_queue.size();
    }

    bool pop(T& t)
    {
        std::lock_guard<std::mutex> a(m_mutex);
        if(m_queue.empty()) return false;
        t=std::move(m_queue.front());
        m_queue.pop();
        return true;//忘打会“std::future_error: Broken promise”,就会拿走任务但不执行
    }

    void push(T& t)
    {
        std::lock_guard<std::mutex> a(m_mutex);
        m_queue.push(t);
    }

    private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
};


class Thread_pool
{
    public:
    class Worker
    {
        public:
        
        Worker(Thread_pool* _pool):pool(_pool){}

        void operator ()()
        {
            while(!pool->is_shut_down){
            {
                std::unique_lock<std::mutex> m_lock(pool->m_mutex);
                pool->m_cv.wait(m_lock,[this](){
                    return this->pool->is_shut_down||
                    !this->pool->m_queue.empty();
                }
                );
            }
            std::function<void()> func;
            bool flag=pool->m_queue.pop(func);
            if(flag) func();
            }
        }
        private:
        Thread_pool* pool;
        
    };

    template<typename F,typename... Args>
    auto submit(F&& f,Args&&... args)->std::future<decltype(f(args...))>{
        // std::function<decltype(f(args...))()> func=[&f,args...](){
        //     return f(args...);
        // };
        std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
        auto task_func=std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);
        std::function<void()> real_task=[task_func](){
            (*task_func) ();
        };
        m_queue.push(real_task);
        m_cv.notify_one();
        return task_func->get_future();        
    }

    Thread_pool(int n):threads(n),is_shut_down{false}{
        for(auto& i:threads){
            i=std::thread{Worker(this)};
        }
    };

    Thread_pool(const Thread_pool&)=delete;
    Thread_pool(Thread_pool&&)=delete;
    Thread_pool& operator = (const Thread_pool&)=delete;
    Thread_pool& operator = (Thread_pool&&)=delete;

    ~Thread_pool()
    {
        auto res=this->submit([](){});
        res.get();
        is_shut_down=true;
        m_cv.notify_all();
        for(auto& i:threads){
            if(i.joinable()) i.join();
        }
    }

    private:
    bool is_shut_down;
    Safe_queue<std::function<void()>> m_queue;
    std::vector<std::thread> threads;
    std::condition_variable m_cv;
    std::mutex m_mutex;
};


std::mutex _m;

int main()
{
    // auto begin = std::chrono::high_resolution_clock::now();
    Thread_pool pool(4);
    for (int i = 1; i <= 20; i++) {
        pool.submit([](int n) {
            {
                std::unique_lock<std::mutex> lk(_m);
                std::cout<<n<<"\n";
            }
         }, i);
    }
    // auto f=pool.submit([](){});
    // f.get();
    // auto end = std::chrono::high_resolution_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}
