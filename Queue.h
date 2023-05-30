#pragma once
#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include <iostream>
#include <memory>

template<typename T>
class Queue {
private:
    struct Node
    {
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;
        T data;
        Node():next(nullptr),prev(next),data(T()){}
        explicit Node(const T& _data):data(_data),next(nullptr),prev(next){}
        ~Node()=default;
    };
    std::shared_ptr<Node> _begin;
    std::shared_ptr<Node> _end;
    size_t _size;
public:
    Queue():_size(0){
        _begin=std::make_shared<Node>();
        _end=_begin;
    }
    Queue(const Queue<T>& _queue);
    Queue(Queue<T>&& _queue) noexcept;
    Queue<T>& operator=(const Queue<T>& _queue);
    Queue<T>& operator=(Queue<T>&& _queue) noexcept;
    size_t size();
    void push(const T& _data);
    void pop();
    T& back();
    T& front();
    bool empty();
    void swap(Queue<T>& _queue);
    void clear();
};


#endif //QUEUE_QUEUE_H
