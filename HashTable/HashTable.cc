#include <iostream>
#include <array>
#include <list>
#include <algorithm>
#include <stdexcept>

template <class K, class V>
struct KeyVal
{
  K key;
  V val;
};

template <class K, class V>
class HashTable
{
public:
  void add(K key, V val)
  {
    auto location = hashKey(key);
    this->table[location].push_back({.key = key,
                                     .val = val});
  }

  V &findItem(K key)
  {
    auto location = hashKey(key);
    auto findIter = std::find_if(
        this->table[location].begin(),
        this->table[location].end(),
        [key](const KeyVal<K, V> &obj)
        {
          return key == obj.key;
        });

    if (findIter == this->table[location].end())
      throw std::runtime_error("Item Doesn't Exists");
    return findIter->val;
  }

  V &operator[](K key)
  {
    try
    {
      return this->findItem(key);
    }
    catch (std::exception e)
    {
      this->add(key, 0);
      return this->findItem(key);
    }
  }

private:
  inline constexpr auto hashKey(K &key)
  {
    return std::hash<K>()(key) % this->table.size();
  }

private:
  std::array<std::list<KeyVal<K, V>>, 100> table;
};

int main()
{
  HashTable<std::string, int> h;

  h["HI"] = 15;
  h["See"] = 15;
  h["LV"] = 15;

  std::cout << h["HI"] << std::endl;
}
