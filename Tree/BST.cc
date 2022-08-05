#include <iostream>
#include <stdexcept>
#include <queue>

template <typename T>
class Node
{
public:
  T data;
  Node<T> *left;
  Node<T> *right;

  Node(T data) : data(data), left(nullptr), right(nullptr) {}
};

template <class T>
class BST
{
public:
  BST() : root(nullptr) {}

  ~BST()
  {
    std::queue<Node<T> *> q;
    if (this->root)
      q.push(this->root);

    while (!q.empty())
    {
      if (q.front()->left)
        q.push(q.front()->left);

      if (q.front()->right)
        q.push(q.front()->right);

      delete q.front();
      q.pop();
    }
  }

  void add(T elm)
  {
    Node<T> *temp = root;
    if (!temp)
    {
      root = new Node(elm);
      return;
    }

    while (temp)
    {
      if (this->root->data == elm)
        throw std::runtime_error("Element Exists!");

      if (elm > temp->data)
      {
        if (!temp->right)
        {
          temp->right = new Node(elm);
          break;
        }
        temp = temp->right;
      }
      else
      {
        if (!temp->left)
        {
          temp->left = new Node(elm);
          break;
        }
        temp = temp->left;
      }
    }
  }

  bool exists(T elm)
  {
    Node<T> *temp = this->root;

    while (temp)
    {
      if (temp->data == elm)
        return true;
      else if (temp->data > elm)
        temp = temp->left;
      else
        temp = temp->right;
    }
    return false;
  }

private:
  Node<T> *root;
};

int main()
{
  BST<int> b;
  b.add(3);
  b.add(2);
  b.add(4);
  b.add(15);

  std::cout << b.exists(5) << std::endl;
}
