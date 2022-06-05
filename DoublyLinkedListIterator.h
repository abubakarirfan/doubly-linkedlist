#pragma once

#include "DoublyLinkedList.h"

template<typename T>
class DoublyLinkedListIterator
{
private:
    enum class States { BEFORE, DATA, AFTER }; // iterator states
    
    using Node = DoublyLinkedList<T>;

    // doubly-linked list
    const Node* fRoot;

    // iterator state
    States fState;

    // iterator position
    const Node* fCurrent;

public:
    using Iterator = DoublyLinkedListIterator<T>;

    DoublyLinkedListIterator(const Node* aRoot) : fRoot(aRoot), fCurrent(aRoot)
    {
        if (fCurrent != nullptr)
        {
            fState = States::DATA;
        }
        else
        {
            fState = States::AFTER;
        }
    }

    const T& operator*() const
    {
        return **fCurrent;
    }


    Iterator& operator++()
    {
        switch (fState)
        {
        case States::BEFORE:
            fCurrent = fRoot;

            if (fCurrent == nullptr)
            {
                fState = States::AFTER;
            }
            else
            {
                fState = States::DATA;
            }

            break;

        case States::DATA:
            if (fCurrent == &fRoot->getPrevious())
            {
                fCurrent = nullptr;
                fState = States::AFTER;
            }
            else
            {
                fCurrent = &fCurrent->getNext();
            }

            break;
        default:
            break;
        
        }
        return *this;
    }

    Iterator operator++(int)
    {
        Iterator temp = *this;

        ++(*this);

        return temp;
    }

    Iterator& operator--()
    {
        switch (fState)
        {
        case States::AFTER:

            fCurrent = fRoot;

            if (fCurrent == nullptr)
            {
                fState = States::BEFORE;
            }
            else
            {
                fCurrent = &fCurrent->getPrevious(); 
                fState = States::DATA;
            }

            break;
        case States::DATA:
           
            if (fCurrent == fRoot)
            {
                fCurrent = nullptr;
                fState = States::BEFORE;
            }
            else
            {
                fCurrent = &fCurrent->getPrevious();
            }
            break;

        default:

            break;
        }

        return *this;
    }

    Iterator operator--(int)
    {
        Iterator temp = *this;

        --(*this);

        return temp;
    }

    bool operator==(const Iterator& aOtherIter) const
    {
        return
            fRoot == aOtherIter.fRoot &&
            fCurrent == aOtherIter.fCurrent &&
            fState == aOtherIter.fState;
    }

    bool operator!=(const Iterator& aOtherIter) const
    {
        return !(*this == aOtherIter);
    }

    Iterator begin() const
    {
        return ++(rend());
    }

    Iterator end() const
    {
        Iterator iter = *this;

        iter.fCurrent = nullptr;
        iter.fState = States::AFTER;

        return iter;
    }

    Iterator rbegin() const
    {
        return --(end());
    }

    Iterator rend() const
    {
        Iterator iter = *this;

        iter.fCurrent = nullptr;
        iter.fState = States::BEFORE;

        return iter;
    }

};