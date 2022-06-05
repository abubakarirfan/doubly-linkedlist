// COS30008, Doubly-linked Nodes, Tutorial 9, 2022

#pragma once

#include "DoublyLinkedList.h"

template<typename T>
class DoublyLinkedListIterator
{
private:
    enum class States { BEFORE, DATA, AFTER }; // 
    iterator states
        using Node = DoublyLinkedList<T>;
    
        // doubly-linked list
        const Node* fRoot;
        
        // iterator state
        States fState;
       
        // iterator position
        const Node* fCurrent;
       
public:

    using Iterator = DoublyLinkedListIterator<T>;
    DoublyLinkedListIterator(const Node* aRoot); // constructor
    const T& operator*() const;          // dereference
    
    // prefix increment
    Iterator& operator++();
    
    // postfix increment
    Iterator operator++(int);
    
    // prefix decrement
    Iterator& operator--();
    
    // postfix decrement
    Iterator operator--(int);
   
    bool operator==(const Iterator& aOtherIter) const; // equivalence
    bool operator!=(const Iterator& aOtherIter) const; // not equal
    
    // first element forward
    Iterator begin() const;
    
    // after last element forward
    Iterator end() const;
    
    // first element backwards
    Iterator rbegin() const;
    
    // before first element backwards
    Iterator rend() const;
};
