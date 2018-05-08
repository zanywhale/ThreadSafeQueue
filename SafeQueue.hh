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
    SafeQueue() = default;
    virtual ~SafeQueue(){};
    void Push( const T& t );
    T Pop();
    T Front();
    T Back();
    T Size();
    bool Empty();
  private:
    std::queue<T> queue;
    mutable std::mutex q_mutex;
    mutable std::condition_variable q_cond;
  };

  template <typename T>
  void SafeQueue<T>::Push( const T& t ){
    std::lock_guard<std::mutex> lock(q_mutex);
    queue.push(t);
    q_cond.notify_one();
  }

  template <typename T>
  T SafeQueue<T>::Pop(){
    std::unique_lock<std::mutex> lock(q_mutex);
    while(queue.empty()){
      q_cond.wait(lock);
    }
    T value = queue.front();
    queue.pop();
    return value;
  }

  template <typename T>
  T SafeQueue<T>::Front(){
    return queue.front();
  }

  template <typename T>
  T SafeQueue<T>::Back(){
    return queue.back();
  }

  template <typename T>
  T SafeQueue<T>::Size(){
    return queue.size();
  }

  template <typename T>
  bool SafeQueue<T>::Empty(){
    return queue.empty() ? true : false;
  }

}

#endif // SAFE_QUEUE
