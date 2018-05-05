#ifndef SAFE_QUEUE
#define SAFE_QUEUE

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>

namespace SafeQueue{
  template <typename T>
  class SafeQueue{
  public:
    SafeQueue();
    virtual ~SafeQueue();
    void Push( const T& t );
    T& Pop();
    bool Empty();
  private:
    std::queue<T> queue;
    mutable std::mutex q_mutex;
    mutable std::condition_variable q_cond;
  };

}

#endif // SAFE_QUEUE
