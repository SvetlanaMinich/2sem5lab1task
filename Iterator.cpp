#include "Iterator.h"

template<class T>
Iterator<T>::Iterator() {
    it= nullptr;
}
template<class T>
Iterator<T>::Iterator(T *iter) {
    it=iter;
}
template<class T>
Iterator<T>::Iterator(const Iterator<T> &another) {
    it=another.it;
}
template<class T>
Iterator<T>& Iterator<T>::operator++() {
    it++;
    return *this;
}
template<class T>
Iterator<T>& Iterator<T>::operator--() {
    it--;
    return *this;
}
template<class T>
bool Iterator<T>::operator<(Iterator<T> i) {
    return it<i.it;
}
template<class T>
bool Iterator<T>::operator>(Iterator<T> i) {
    return it>i.it;
}
template<class T>
bool Iterator<T>::operator==(Iterator<T> i) {
    return it==i.it;
}
template<class T>
bool Iterator<T>::operator!=(Iterator<T> i) {
    return it!=i.it;
}
template<class T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T> &i) {
    if(this==i){
        return *this;
    }
    it=i.it;
    return *this;
}
template<class T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T> *i) {
    it=i->it;
    return *this;
}
template<class T>
Iterator<T> Iterator<T>::operator+(int n) {
    it+=n;
    return *this;
}
template<class T>
Iterator<T> Iterator<T>::operator-(int n) {
    it-=n;
    return *this;
}
template<class T>
T* Iterator<T>::operator->() {
    return it;
}
template<class T>
T* Iterator<T>::getPoiner() const {
    return it;
}
template<class T>
T& Iterator<T>::operator*() {
    return *it;
}
template<class T>
size_t Iterator<T>::operator-(Iterator<T> i) {
    return it-i.it;
}