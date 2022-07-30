#include <iostream>

template <typename T>
struct Node
{
  T data;
  Node<T> *next;
};

template <typename T>
class LinkedList
{
public:
  LinkedList() : head(nullptr) {}

  void insert(T value)
  {
    Node<T> *temp = new Node<T>;
    temp->data = value;

    if (!this->head)
    {
      head = temp;
      return;
    }

    temp->next = this->head;
    this->head = temp;
  }

  void printAll()
  {
    Node<T> *temp = this->head;

    while (temp)
    {
      std::cout << temp->data << " -> ";
      temp = temp->next;
    }

    std::cout << "null" << std::endl;
  }

  ~LinkedList()
  {
    Node<T> *temp;
    while (head)
    {
      temp = head->next;
      std::cout << "deleting " << head->data << std::endl;
      delete head;
      head = temp;
    }
  }

private:
  Node<T> *head;
};

int main()
{
  LinkedList<int> l;

  l.insert(1);
  l.insert(2);
  l.insert(3);
  l.insert(4);

  l.printAll();
}
