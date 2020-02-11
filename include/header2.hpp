// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER2_HPP_
#define INCLUDE_HEADER2_HPP_
#define STACK_END -1
#include <iostream>

template <typename T>
struct Element2{
    T value;
    Element2<T>* previous;
};

template <typename T>
class stack2
{
public:
    stack2(){
        _top = nullptr;
        count = 0;
    }
    ~stack2(){
        while (count) {
            Element2<T>* _local = _top->previous;
            delete _top;
            --count;
            _top = _local;
        }
        delete _top;
    }
    template <typename ... Args>
    void push_emplace(Args&&... value) {
        T _object(value ...);
        auto* new_elem = new Element2<T>;
        new_elem->previous = _top;
        new_elem->value = _object;
        _top = new_elem;
        ++count;
    }
    void push(T&& value) {
        auto* new_elem = new Element2<T>;
        new_elem->previous = _top;
        new_elem->value = value;
        _top = new_elem;
        ++count;
    }
    const T& head() const {
        return _top->value;
    }
    T pop() {
        if (count) {
            Element2<T>* _stakan;
            _stakan = _top;
            T result = _top->value;
            _top = _top->previous;
            delete _stakan;
            --count;
            return result;
        } else {
            std::cout << "stack is empty" << std::endl;
            exit(STACK_END);
        }
    }
    Element2<T>* _top;
    unsigned count;
};

#endif //INCLUDE_HEADER2_HPP_
