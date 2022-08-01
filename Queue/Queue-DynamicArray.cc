#include <iostream>
#include <vector>

template <typename T>
class Queue : private std::vector<T>
{
public:
  Queue() = default;

  inline void enqueue(T elm)
  {
    this->insert(this->begin(), elm);
  }

  T dequeue()
  {
    T r = this->back();
    this->pop_back();
    return r;
  }

  inline bool isEmpty()
  {
    return this->size() == 0;
  }
};
