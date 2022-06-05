// COS30008, Doubly-linked Nodes, Tutorial 9, 2022
#pragma once

template<typename T>
class DoublyLinkedList
{
private:
    T fPayload;
    DoublyLinkedList* fNext;
    DoublyLinkedList* fPrevious;

public:

    // l-value constructor and r-value constructor
    explicit DoublyLinkedList(const T& aPayload);
    explicit DoublyLinkedList(T&& aPayload);

    // link functions
    DoublyLinkedList& push_front(DoublyLinkedList& aNode);
    DoublyLinkedList& push_back(DoublyLinkedList& aNode);

    // unlink list node
    void isolate();

    // exchance payload positions of list nodes
    void swap(DoublyLinkedList& aNode);

    // getters
    const T& operator*() const;
    const T& getPayload() const;

    const DoublyLinkedList& getNext() const;
    const DoublyLinkedList& getPrevious() const;
};
