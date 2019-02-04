/*
    * File Name : AccountPtrArray.h -> BoundCheckPtrArray.h
    * Version : 0.2
    * Update Date : 2019. 01 .30.
*/

#ifndef __BOUND_CHECK_PTR_ARRAY_H__
#define __BOUND_CHECK_PTR_ARRAY_H__

template <typename T>
class BoundCheckPtrArray
{
private:
    T** arr;
    int arrlen;
    BoundCheckPtrArray(const BoundCheckPtrArray& copy) {}
    BoundCheckPtrArray& operator= (const BoundCheckPtrArray& copy) {}
public:
    BoundCheckPtrArray(int arrlen = 100);
    T*& operator[] (int index);
    T* operator[] (int index) const;
    int length() const;
    ~BoundCheckPtrArray();
};

template <typename T>
BoundCheckPtrArray<T>::BoundCheckPtrArray(int arrlen)
    : arrlen(arrlen) {
    this->arr = new T*[this->arrlen];
}

template <typename T>
T*& BoundCheckPtrArray<T>::operator[] (int index) {
    if(index < 0 || index >= this->arrlen) {
        cout << "index range out of exception" << endl;
        exit(1);
    }
    return this->arr[index];
}

template <typename T>
T* BoundCheckPtrArray<T>::operator[] (int index) const {
    if(index < 0 || index >= this->arrlen) {
        cout << "index range out of exception" << endl;
        exit(1);
    }
    return this->arr[index];
}

template <typename T>
int BoundCheckPtrArray<T>::length() const {
    return this->arrlen;
}

template <typename T>
BoundCheckPtrArray<T>::~BoundCheckPtrArray() {
    delete []arr;
}

#endif
