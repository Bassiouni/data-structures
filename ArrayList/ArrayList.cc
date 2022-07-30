#include <iostream>

template <typename T>
class ArrayList
{
public:
  ArrayList() : m_size(0), m_indexer(0), m_data_array(nullptr) {}
  ArrayList(size_t size) : m_size(size), m_indexer(0), m_data_array(nullptr) {}

  inline void push_back(T value)
  {
    if (this->m_indexer == this->m_size)
      this->regrow();

    std::cout << "pushing value " << value << "; with index " << this->m_indexer << std::endl;
    this->m_data_array[this->m_indexer++] = value;
  }

  inline T &operator[](size_t index) const
  {
    return this->m_data_array[index];
  }

  inline void deleteAt(size_t index)
  {
    for (auto i = index; i < this->m_size; i++)
    {
      this->m_data_array[i] = this->m_data_array[i + 1];
    }
    this->m_indexer--;
  }

  inline size_t size() const { return this->m_indexer; }

  ~ArrayList()
  {
    if (this->m_data_array)
    {
      delete[] this->m_data_array;
      this->m_data_array = nullptr;
    }
  }

private:
  void regrow()
  {
    uint32_t new_size = this->m_size + 10;
    T *new_array = new T[new_size];
    for (int i = 0; i < this->m_size; i++)
    {
      new_array[i] = this->m_data_array[i];
    }
    delete[] this->m_data_array;
    this->m_data_array = new_array;
    this->m_size = new_size;

    std::cout << "Regrowing -- new size: " << this->m_size << std::endl;
  }

private:
  T *m_data_array;
  uint32_t m_size, m_indexer;
};

int main()
{
  ArrayList<int> l;

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(4);
  l.push_back(5);
  l.deleteAt(1);

  for (size_t i = 0; i < l.size(); i++)
  {
    std::cout << l[i] << std::endl;
  }
}
