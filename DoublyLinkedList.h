#pragma once

template <typename T>
struct DoublyLinkedList
{
private:
    T fPayload;
    DoublyLinkedList* fNext;
    DoublyLinkedList* fPrevious;

public:

    explicit DoublyLinkedList(const T& aPayload) : 
        fPayload(aPayload),
        fNext(this),
        fPrevious(this)
    {}
    
    explicit DoublyLinkedList(T&& aPayload) : 
        fPayload(move(aPayload)),
        fNext(this),
        fPrevious(this)
    {}

    DoublyLinkedList& push_front(DoublyLinkedList& aNode)
    {
        aNode.fNext = this;
        aNode.fPrevious = fPrevious;
        fPrevious->fNext = &aNode;
        fPrevious = &aNode;

        return aNode;
    }

    DoublyLinkedList& push_back(DoublyLinkedList& aNode)
    {
        aNode.fPrevious = this;
        aNode.fNext = fNext;
        fNext->fPrevious = &aNode;
        fNext = &aNode;

        return aNode;
    }

    void isolate()
    {
        fPrevious->fNext = fNext;
        fNext->fPrevious = fPrevious;
        fPrevious = this;
        fNext = this;
    }


    void swap(DoublyLinkedList& aNode)
    {
        std::swap(fPayload, aNode.fPayload);
    }


    const T& operator*() const
    {
        return getPayload();
    }

    const T& getPayload() const
    {
        return fPayload;
    }

    const DoublyLinkedList& getNext() const
    {
        return *fNext;
    }

    const DoublyLinkedList& getPrevious() const
    {
        return *fPrevious;
    }

};