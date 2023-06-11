#pragma once

#include <iostream>
#include <list>
#include <exception>
#include "Dog.h"

struct MyComparator {
    template<typename T>
    bool operator()(const T& a, const T& b) const {
        return  (b - a) < 0;
    }
};

template<typename T, typename Comparator = MyComparator>
class PriorityQueue {
public:
    void push(const T& t) {
        typename std::list<T>::iterator it = elements.begin();
        while (it != elements.end() && Comparator()(t, *it)) {
            ++it;
        }
        elements.insert(it, t);
    }

    T poll() {
        if (elements.empty()) {
            throw std::runtime_error("PriorityQueue is empty.");
        }
        T front = elements.front();
        elements.pop_front();
        return front;
    }

private:
    std::list<T> elements;
};
