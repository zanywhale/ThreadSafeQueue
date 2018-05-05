#include "SafeQueue.hh"

namespace SafeQueue{
  template <typename T>
  SafeQueue<T>::SafeQueue(){}

  template <typename T>
  SafeQueue<T>::~SafeQueue(){}

  template <typename T>
  void SafeQueue<T>::Push( const T& t){
    std::lock_guard<std::mutex> lock(q_mutex);
    queue.push(t);
    q_cond.notify_one();
  }

  template <typename T>
  T& SafeQueue<T>::Pop(){
    std::unique_lock<std::mutex> lock(q_mutex);
    while(queue.empty())
    {
      q_cond.wait(lock);
    }
    T &val = queue.front();
    queue.pop();
    return val;
  }

  template <typename T>
  bool SafeQueue<T>::Empty(){
    return queue.empty()? true : false;
  }
}

