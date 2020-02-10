// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER1_HPP_
#define INCLUDE_HEADER1_HPP_

#include <iostream>

template <typename T>
struct Element1{
    T value;
    Element1<T>* previous;
};
template <typename T>
class stack1
{
public:
    stack1(){
        _top = nullptr;
        count = 0;
    }
    ~stack1(){
        while (count) {
            Element1<T>* _local = _top->previous;
            delete _top->previous;
            _top = _local;
            --count;
        }
        delete _top;
    }
    void push(T&& value){
        Element1<T> new_elem;
        new_elem.previous = _top;
        new_elem.value = value;
        _top = &new_elem;
        ++count;
    }
    void push(const T& value){
        Element1<T> new_elem;
        new_elem.previous = _top;
        new_elem.value = value;
        _top = &new_elem;
        ++count;
    }
    void pop(){
        if (count) {
            Element1<T>* stakan;
            stakan = _top;
            std::cout << _top->value << std::endl;
            _top = _top->previous;
            --count;
        } else {
            std::cout << "stack is empty" << std::endl;
        }
    }
    const T& head() const{
        return _top->value;
    }
    Element1<T>* _top;
    unsigned count;
};

#endif //INCLUDE_HEADER1_HPP_
