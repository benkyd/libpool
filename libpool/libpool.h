#ifndef LIBPOOL_LIBPOOL_H_
#define LIBPOOL_LIBPOOL_H_

#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>

class Pool {
public:
    Pool(int iNumThreads = 2);

    void resize(int iNumThreads);

    template<class F, class... Args>
    auto addToQueue(F&& f, Args&&... args) 
        -> std::future<typename std::result_of<F(Args...)>::type>;

private:
    std::vector<std::thread> m_vWorkers;
    std::queue<std::function<void()>> m_qTaskQueue;

    std::mutex m_mQueueMutex;
    std::condition_variable m_cCondition;
    bool m_bStop;

    int m_iThreads = 2;
};

#endif