#include "Queue.h"

template<typename T>
void Queue<T>::clear() {
    if(_size)
    {
        _begin.reset();
        _end.reset();
        _begin=std::make_shared<Node>();
        _end=_begin;
        _size=0;
    }
}
template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T> &_queue) {
    clear();
    _size=0;
    _begin=std::make_shared<Node>(Node());
    _end=_begin;
    auto it=_queue._begin;
    for(size_t i=0;i<_queue._size;i++)
    {
        push(it->data);
        it=it->next;
    }
    _size=_queue._size;
    return *this;
}
template<typename T>
Queue<T>& Queue<T>::operator=(Queue<T> &&_queue) noexcept {
    clear();
    _size=_queue._size;
    _begin=_queue._begin;
    _end=_queue._end;
    _queue._begin.reset();
    _queue._end.reset();
    _queue._size=0;
    return *this;
}
template<typename T>
void Queue<T>::swap(Queue<T> &_queue) {
    std::swap(_begin,_queue._begin);
    std::swap(_end,_queue._end);
    std::swap(_size,_queue._size);
}
template<typename T>
bool Queue<T>::empty() {
    return !_size;
}
template<typename T>
T& Queue<T>::front() {
    return _begin->data;
}
template<typename T>
T& Queue<T>::back() {
    return _end->data;
}
template<typename T>
void Queue<T>::pop() {
    if(_size>1)
    {
        _begin=_begin->next;
        _size--;
    }
    else if(_size==1)
    {
        _begin.reset();
        _end.reset();
        _begin=std::make_shared<Node>();
        _end=_begin;
        _size--;
    }
}
template<typename T>
void Queue<T>::push(const T &_data) {
    if(_size)
    {
        auto newNode = std::make_shared<Node>(_data);
        newNode->data=_data;
        newNode->prev=_end;
        _end->next=newNode;
        _end=newNode;
    }
    else
    {
        _begin->data=_data;
    }
    _size++;
}
template<typename T>
size_t Queue<T>::size() {
    return _size;
}
template<typename T>
Queue<T>::Queue(Queue<T> &&_queue) noexcept{
    _size=_queue._size;
    _begin=_queue._begin;
    _end=_queue._end;
    _queue._begin.reset();
    _queue._end.reset();
    _queue._size=0;
}
template<typename T>
Queue<T>::Queue(const Queue<T> &_queue) {
    _size=0;
    _begin=std::make_shared<Node>(Node());
    _end=_begin;
    auto it=_queue._begin;
    for(size_t i=0;i<_queue._size;i++)
    {
        push(it->data);
        it=it->next;
    }
    _size=_queue._size;
}
