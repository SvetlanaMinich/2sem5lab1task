#include "Shared_ptr.h"

template<typename T>
Shared_ptr<T>::Shared_ptr(const Shared_ptr<T> &_ptr) {
    ptr=_ptr.ptr;
    count=_ptr.count;
    if(_ptr.ptr!=nullptr)
    {
        (*count)++;
    }
}

template<typename T>
Shared_ptr<T>::Shared_ptr(Shared_ptr<T> &&_ptr) noexcept{
    ptr=_ptr.ptr;
    count=_ptr.count;
    _ptr.ptr=nullptr;
    _ptr.count=nullptr;
}

template<typename T>
Shared_ptr<T>& Shared_ptr<T>::operator=(const Shared_ptr<T> &_ptr) {
    if(this!=_ptr)
    {
        _clean();
        ptr=_ptr.ptr;
        count=_ptr.count;
        if(_ptr.ptr!= nullptr)
        {
            (*count)++;
        }
    }
    return *this;
}

template<typename T>
Shared_ptr<T>& Shared_ptr<T>::operator=(Shared_ptr<T> &&_ptr) noexcept{
    _clean();
    ptr=_ptr.ptr;
    count=_ptr.count;
    _ptr.ptr= nullptr;
    _ptr.count=nullptr;
    return *this;
}

template<typename T>
T* Shared_ptr<T>::get() const {
    return ptr;
}

template<typename T>
T* Shared_ptr<T>::operator->() {
    return ptr;
}

template<typename T>
T& Shared_ptr<T>::operator*() {
    return *ptr;
}

template<typename T>
Shared_ptr<T>::~Shared_ptr() {
    _clean();
}

template<typename T>
void Shared_ptr<T>::_clean() {
    if(--(*count)==0)
    {
        delete ptr;
        delete count;
    }
}