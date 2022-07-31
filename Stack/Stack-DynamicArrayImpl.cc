#include <iostream>
#include <vector>

template <class T>
class Stack : private std::vector<T>
{
public:
  void push(T elem)
  {
    this->push_back(elem);
  }

  T pop()
  {
    T elm = this->back();
    this->pop_back();
    return elm;
  }

  bool isEmpty() { return this->size() == 0; }
};

int main()
{
  Stack<int> s;

  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);

  while (!s.isEmpty())
  {
    std::cout << s.pop() << std::endl;
  }
}
