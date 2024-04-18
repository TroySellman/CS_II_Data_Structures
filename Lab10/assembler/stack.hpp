//
// File: stack.hpp
//
// Programmer:
// Date:        Spring 2024
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//
#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_

#include <new>
#include <cassert>
#include "../string/string.hpp"

// bonus, use map
// std::map<std::string, int> myMap;

template<typename T> 
class Node {
public:
	Node(T data) : data(data) {};
	T data;
	Node<T>* next;
};


// CLASS INV:
//
template <typename T>
class stack {
public:
              stack     () : tos(nullptr) {};
              stack     (const stack<T>&);
              ~stack    ();
    void      swap      (stack<T>&);
    stack<T>& operator= (stack<T> rhs) { swap (rhs); return *this; };
    
	bool      empty     () const { return tos == nullptr; };
	bool      full      () const;
	T         top       () const { if (!empty()) return tos->data; };
	T         pop       ();
	void      push      (const T&);

private:
	Node<T>   *tos;
};


//REQUIRES: tos -> x1 -> x2 -> ... -> xn -> 0
//ENSURES: tos -> item -> x1 -> x2 -> ... -> xn -> 0
template <typename T>
void stack<T>::push(const T& item) {
    assert(!full());
    Node<T> *temp = new Node<T>(item);
    temp->next = tos;
    tos = temp;
}

//REQUIRES: tos -> x1 -> x2 -> ... -> xn -> 0 && tos != 0
//ENSURES: tos -> item -> x2 -> ... -> xn -> 0
template <typename T>
T stack<T>::pop() {
    assert(!empty());
    T result = tos -> data;
    Node<T> *temp = tos;
    tos = tos -> next;
    delete temp;
    return result;
}

template<typename T>
stack<T>::~stack() {
    Node<T> *temp;
    while (tos != nullptr) {
        temp = tos;
        tos = tos -> next;
        delete temp;
    }
}

template <typename T>
stack<T>::stack(const stack<T>& actual) {
    Node<T> *temp = actual.tos;
    Node<T> *bottom = nullptr;
    tos = 0;
    while (temp != nullptr) {
        if (tos == nullptr) {
            tos = new Node<T>(temp -> data);
            bottom = tos;
        } else {
            bottom -> next = new Node<T>(temp -> data);
            bottom = bottom -> next;
        }
        temp = temp -> next;
    }
}

template <typename T>
void stack<T>::swap(stack<T>& rhs) {
    Node<T> *temp = tos;
    tos = rhs.tos;
    rhs.tos = temp;
}

template <typename T>
bool stack<T>::full() const {
    // Node<T> *temp = new(std::nothrow) Node<T>();
    // if (temp == 0) // No memory remaining
    //     return true;
    // delete temp;
    return false;
}


#endif
