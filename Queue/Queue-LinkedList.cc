#include <iostream>
#include <list>

template <class T>
class Queue
{
private:
  std::list<T> data;

public:
  void Enqueue(T item)
  {
    data.push_back(item);
  }

  T Dequeue()
  {
    T item = data.front();
    data.pop_front();
    return item;
  }

  bool IsEmpty()
  {
    return data.size() == 0;
  }
};

main()
{
  Queue<int> x;
  
  for (int i = 0; i < 10; i++)
  {
    std::cout << "Enter number: ";
    int n;
    std::cin >> n;
    x.Enqueue(n);
  }
  
  while (!x.IsEmpty())
  {
    std::cout << x.Dequeue() << std::endl;
  }
}
