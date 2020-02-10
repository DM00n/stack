// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER1_HPP
#define INCLUDE_HEADER1_HPP

#include <iostream>

template <typename T>
struct Element{
    T value;
    Element<T>* previous;
};
template <typename T>
class stack
{
public:
    stack(){
        _top = nullptr;
        count = 0;
    }
    ~stack(){
        while (count) {
            Element<T>* _local = _top->previous;
            delete _top->previous;
            --count;
        }
        delete _top;
    }
    void push(T&& value){
        auto* new_elem = new Element<T>;
        new_elem->previous = _top;
        new_elem->value = value;
        _top = new_elem;
        ++count;
    }
    void push(const T& value){
        auto* new_elem = new Element<T>;
        new_elem->previous = _top;
        new_elem->value = value;
        _top = new_elem;
        ++count;
    }
    void pop(){
        if (count) {
            Element<T>* stakan;
            stakan = _top;
            std::cout << _top->value << std::endl;
            _top = _top->previous;
            delete stakan;
            --count;
        } else {
            std::cout << "stack is empty" << std::endl;
        }
    }
    const T& head() const{
        return _top->value;
    }
    Element<T>* _top;
    unsigned count;
};

#endif //INCLUDE_HEADER1_HPP
