#include <iostream>

template< class T >
struct BiList
{
  T val;
  BiList< T >* next;
  BiList< T >* prev;
}; 

template< class T >
BiList< T >* add(BiList< T >* h, const T& d)
{
  BiList< T >* newNode = new BiList< T >{d, h, h->prev}; //T(const T&)
  h->prev->next = newNode;
  h->prev = newNode;
  return newNode;
};

template< class T >
BiList< T >* insert(BiList< T >* h, const T& d)
{
  BiList< T >* newNode = new BiList< T >{d, h->next, h}; //T(const T&)
  h->next->prev = newNode;
  h->next = newNode;
  return newNode;
};

template< class T >
BiList< T >* cut(BiList< T >* h) noexcept
{
  if (h->next == h) 
  {
    delete h; //~T()
    return nullptr;
  }
  BiList< T >* newHead = h->next;
  h->prev->next = h->next;
  h->next->prev = h->prev;
  delete h; //~T()
  return newHead;
};

template< class T >
BiList< T >* erase(BiList< T >* h) noexcept
{
  if (h->next == h)
  {
    return h;
  }
  BiList< T >* toDelete = h->next;
  h->next = toDelete->next;
  toDelete->next->prev = h;
  delete toDelete;
  return h;
};

template< class T >
BiList< T >* clear(BiList< T >* h, BiList< T >* e) noexcept
{
  if (h == e)
  {
    delete h; //~T()
    return nullptr;
  }
  BiList< T >* current = h;
  BiList< T >* next = nullptr;
  while (current != e)
  {
    next = current->next;
    delete current;
    current = next;
  }
  delete e; //~T()
  return nullptr;
};

template< class T, class F >
F traverse(F f, BiList< T >* h, BiList< T >* e) noexcept
{
  BiList< T >* current = h;
  if (e == nullptr)
  {
    while (true)
    {
      f(current->val);
      current = current->next;
      if (current == h) break;
    }
  } else {
    while (true) 
    {
      f(current->val);
      if (current == e) break;
      current = current->next;
    }
  }
  return f;
};

template< class T >
size_t sizeCount(BiList< T >* h) {
  if (h == nullptr){
    return 0;
  }
  size_t count = 1;
  BiList< T >* current = h->next;
  while (current != h) {
    ++count;
    current = current->next;
  }
  return count;
};

template< class T >
BiList< T >* makeBiList(const T& d) {
    BiList< T >* newNode = new BiList< T >{d, nullptr, nullptr}; //T(const T&)
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
};

template< class T >
void print(BiList< T >* h) {
    if (h == nullptr) {
        std::cout << "\n";
        return;
    }
    std::cout << h->val << " ";
    
    BiList< T >* current = h->next;
    while (current != h)
    {
      std::cout << current->val << " ";
      current = current->next;
    }
    std::cout << "\n";
}

int main()
{
  size_t size = 7;
  int* array = new int[size]{3, 5, 8, 12, 30, 18, 7};
  BiList<int>* h = nullptr;
  try {
    h = makeBiList(array[0]);
  } catch(...) {
    delete[] array;
    return 1;
  }
  try{
    for (size_t i = 1; i < size; ++i) {
      h = insert(h->prev,  array[i]);
  }
  } catch(...) {
    if (h != nullptr)
    {
      clear(h, h->prev);
    }
    delete[] array;
    return 1;
  }
  print(h);
  if (h != nullptr) {
    clear(h, h->prev);
  }
  delete[] array;
  return 0;
}