#pragma once
#include <future>

template<class T>
class Singleton
{
public:
    static T* instance() {
        std::mutex mutex;

        mutex.lock();
        if ( nullptr == _st) {
            _st = new T;
        }
        mutex.unlock();

        return _st;
    }
protected:
    Singleton() {}
    virtual ~Singleton() {}

protected:
    static T* _st;
};

template<class T>
T* Singleton<T>::_st = nullptr;
