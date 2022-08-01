#include <list>
#include <iostream>

template <class T>
class Stack
{
public:
  Stack() = default;

  inline void push(T item)
  {
    this->l.push_back(item);
  }

  inline T pop()
  {
    T r = this->l.back();
    this->l.pop_back();
    return r;
  }

  inline bool isEmpty()
  {
    return this->l.size() == 0;
  }

private:
  std::list<T> l;
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
