/* SLinkedList.h
 * Authors: Goodrich, Tamassia and Mount (2011)
 * Description: Singly linked list class definitions
 * from code fragments 3.18 and 3.19
 */

#ifndef SLINKED_LIST_H
#define SLINKED_LIST_H

#include <cstdlib>

template <typename E> class SLinkedList; // allow forward references

template <typename E>
class SNode {						// singly linked list node
  private:
    E elem;							// element value
    SNode<E>* next;					// pointer links to next item in the list
    friend class SLinkedList<E>;	// allow SLinkedList to access members of SNode
  };  

template <typename E>
class SLinkedList {				// a singly linked list
  public:
    SLinkedList();				// empty list constructor
    ~SLinkedList();				// destructor
    bool empty() const;			// predicate: is list empty?
    const E& front() const;		// return front element
    void addFront(const E& e);	// add to front of list
    void removeFront();			// remove front item from list
  private:
    SNode<E>* head;				// head of the list
  };

#include "SLinkedList.cpp"		// need to include template function defintions
								// to allow instantiation with different types
#endif
