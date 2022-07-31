#include <iostream>

template <typename T>
struct Node
{
  T data;
  Node<T> *next;

  Node() = default;
  Node(T &val) : data(val), next(nullptr) {}
  Node(T &&val) : Node(val) {}
};

template <typename T>
class LinkedList
{
public:
  LinkedList() : head(nullptr) {}

  void insert(T value)
  {
    Node<T> *temp = new Node<T>(value);

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

    std::cout << ((temp) ? "[" : "Empty!");

    while (temp)
    {
      std::cout << temp->data << "]";
      temp = temp->next;
      if (temp)
        std::cout << " -> [";
    }

    std::cout << std::endl;
  }

  void remove(T val)
  {
    Node<T> *prevptr = this->head;
    Node<T> *currptr = prevptr;

    if (currptr->data == val)
    {
      prevptr = currptr->next;
      delete currptr;
      this->head = prevptr;
      return;
    }
    currptr = currptr->next;
    while (currptr)
    {
      if (currptr->data == val)
      {
        prevptr->next = currptr->next;
        delete currptr;
        break;
      }
      currptr = currptr->next;
      prevptr = prevptr->next;
    }
  }

  ~LinkedList()
  {
    Node<T> *temp;
    while (this->head)
    {
      temp = this->head->next;
      std::cout << "deleting node " << this->head->data << std::endl;
      delete this->head;
      this->head = temp;
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

  l.remove(5); // Testing with non-existing values to check for Seg Faults.
  l.printAll();

  l.reverse();
  l.printAll();

  l.remove(1);
  l.printAll();
}
