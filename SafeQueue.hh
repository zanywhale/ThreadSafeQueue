#ifndef SAFE_QUEUE
#define SAFE_QUEUE

#include <iostream>
#include <queue>
#include <mutex>

namespace SafeQueue{
  template <typename T>
  class SafeQueue{
  public:
    SafeQueue();
    virtual ~SafeQueue();
    void Push( const T& t );
    void Pop();
    bool Empty();
  private:
    std::queue<T> queue;
  };

}

#endif // SAFE_QUEUE
