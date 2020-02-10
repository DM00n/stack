//
// Created by dasta on 10.02.2020.
//

#ifndef LAB_05_STACK_HEADER2_HPP
#define LAB_05_STACK_HEADER2_HPP

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
    template <typename ... Args>
    void push_emplace(Args&&... value) {
        T _object(value ...);
        auto* new_elem = new Element<T>;
        new_elem->previous = _top;
        new_elem->value = _object;
        _top = new_elem;
        ++count;
    }
    void push(T&& value) {
        auto* new_elem = new Element<T>;
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
            Element<T>* _stakan;
            _stakan = _top;
            unsigned result = _top->value;
            _top = _top->previous;
            delete _stakan;
            --count;
            return result;
        } else {
            std::cout << "stack is empty" << std::endl;
            return -1;
        }
    }
    Element<T>* _top;
    unsigned count;
};

#endif //LAB_05_STACK_HEADER2_HPP
