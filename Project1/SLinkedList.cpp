/* SLinkedList.cpp
 * Authors: Goodrich, Tamassia and Mount (2011)
 * Description: Singly linked list member functions
 * from code fragment 3.20
 */

// This file is included by "SLinkedList.h"

// These are definitions of member functions for the template class
// SLinkedList<E>, where E is the type of elements in the list.

template <typename E>
SLinkedList<E>::SLinkedList()				// constructor
    : head(NULL) { }						// initializer list may be given 
											// between : and {
template <typename E>
bool SLinkedList<E>::empty() const			// predicate: is list empty?
    { return head == NULL; }

template <typename E>
const E& SLinkedList<E>::front() const		// return front element
    { return head->elem; }

template <typename E>
SLinkedList<E>::~SLinkedList()				// destructor
    { while (!empty()) removeFront(); }

template <typename E>
void SLinkedList<E>::addFront(const E& e) {		// add element to front of list
    SNode<E>* v = new SNode<E>;		// create new node
    v->elem = e;					// store data
    v->next = head;					// head now follows v
    head = v;						// v is now the head
}

/* DEMONSTRATION IN CLASS: adding a new function
 * with a loop to scan the chain of nodes
 */
/*
template <typename E>
void SLinkedList<E>::addRear(const E& e) {		// add element to rear of list
	SNode<E>* v = new SNode<E>;		// create new node
	v->elem = e;					// store data
	v->next = NULL;					// 
	SNode<E> *current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = v;
}
*/

template <typename E>
void SLinkedList<E>::removeFront() {	// remove front item from list
    SNode<E>* old = head;			// save current head
    head = old->next;				// skip over old head
    delete old;						// delete the old head
}
