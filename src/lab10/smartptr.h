#ifndef SMARTPTR_H
#define SMARTPTR_H

template <typename T>
class smart_ptr {
    T * obj;
public:
    smart_ptr(T *obj)
        : obj(obj){ }
    smart_ptr() : obj(nullptr){};
    ~smart_ptr() {
        delete obj;
    }
    T* operator->() { return obj; }
    T& operator* () { return *obj; }
};

#endif // SMARTPTR_H
