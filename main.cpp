#include <iostream>

template< class T >
struct BiList {
    T val;
    BiList< T >* next;
    BiList< T >* prev;
}; 

template< class T >
BiList< T >* add(BiList< T >* h, const T& d) {

};

template< class T >
BiList< T >* insert(BiList< T >* h, const T& d) {

};

template< class T >
BiList< T >* cut(BiList< T >* h) noexcept {

};

template< class T >
BiList< T >* erase(BiList< T >* h) noexcept {

};

template< class T >
BiList< T >* clear(BiList< T >* h, BiList< T >* e) noexcept {

};

template< class T, class F >
BiList< T >* erase(F f, BiList< T >* h, BiList< T >* e) noexcept {

};

int main() {

}