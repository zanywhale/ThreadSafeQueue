#include "SafeQueue.hh"

int main(int argc, char *argv[]){

  SafeQueue::SafeQueue<std::string> sQ;
  std::string a{"Test SafeQueue!!"};
  std::cout << sQ.Empty() << std::endl;
  sQ.Push(a);
  std::cout << sQ.Empty() << std::endl;
  std::cout << sQ.Pop() << std::endl;
  std::cout << sQ.Empty() << std::endl;

  return 0;
}


