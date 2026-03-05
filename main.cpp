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
  BiList< T >* newNode = new BiList< T >{d, h, h->prev};
  h->prev->next = newNode;
  h->prev = newNode;
  return newNode;
};

template< class T >
BiList< T >* insert(BiList< T >* h, const T& d)
{
  BiList< T >* newNode = new BiList< T >{d, h->next, h};
  h->next->prev = newNode;
  h->next = newNode;
  return newNode;
};

template< class T >
BiList< T >* cut(BiList< T >* h) noexcept
{
  if (h->next == h) 
  {
    delete h;
    return nullptr;
  }
  BiList< T >* newHead = h->next;
  h->prev->next = h->next;
  h->next->prev = h->prev;
  delete h;
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
    delete h;
    return nullptr;
  }
  BiList< T >* current = h;
  BiList< T >* next = nullptr;
  while (current != e)
  {
    next = nurrent->next;
    delete current;
    current = next;
  }
  delete e;
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

int main()
{

}