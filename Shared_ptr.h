#ifndef QUEUE_SHARED_PTR_H
#define QUEUE_SHARED_PTR_H
#include <iostream>

template<typename T>
class Shared_ptr {
private:
    T* ptr;
    size_t* count;
    void _clean();
public:
    Shared_ptr():ptr(nullptr),count(nullptr){};
    Shared_ptr(T* _ptr):ptr(_ptr),count(new size_t(1)){};
    Shared_ptr(const Shared_ptr& _ptr);
    Shared_ptr& operator=(const Shared_ptr& _ptr);
    Shared_ptr(Shared_ptr&& _ptr) noexcept;
    Shared_ptr& operator=(Shared_ptr&& _ptr) noexcept;
    T* get() const;
    T& operator*();
    T* operator->();
    ~Shared_ptr();
};

#endif //QUEUE_SHARED_PTR_H
