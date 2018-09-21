/* DLinkedList.cpp
 * Authors: Goodrich, Tamassia and Mount (2011)
 * Description: Doubly linked list member functions
 * from code fragments 3.24-27
 */

 // This file is included by "DLinkedList.h"

 // These are definitions of member functions for the template class
 // DLinkedList<E>, where E is the type of elements in the list.


template <typename E>
DLinkedList<E>::DLinkedList() {		// constructor
	header = new DNode<E>;			// create sentinels
	trailer = new DNode<E>;
	header->next = trailer;			// have them point to each other
	trailer->prev = header;
	header->prev = NULL;			// missing from Fragment 3.24
	trailer->next = NULL;
}

template <typename E>
DLinkedList<E>::~DLinkedList() {	// destructor
	while (!empty())				// remove all but sentinels
		removeFront();
	delete header;					// remove the sentinels
	delete trailer;
}

template <typename E>
bool DLinkedList<E>::empty() const		// is list empty?
{
	return (header->next == trailer);
}

template <typename E>
const E& DLinkedList<E>::front() const	// get front element
{
	return header->next->elem;
}

template <typename E>
const E& DLinkedList<E>::back() const	// get back element
{
	return trailer->prev->elem;
}

// insert new node before v
template <typename E>
void DLinkedList<E>::add(DNode<E>* v, const E& e) {
	DNode<E>* u = new DNode<E>;		// create a new node for e
	u->elem = e;
	u->next = v;					// link u in between v
	u->prev = v->prev;				// ...and v->prev
	v->prev->next = u;		// Fix bug in Fragment 3.26
	v->prev = u;			// must update v->prev->next before v->prev
	showScores();
	count++;
}

// add to front of list
template <typename E>
void DLinkedList<E>::addFront(const E& e)
{
	add(header->next, e);
}

// add to back of list
template <typename E>
void DLinkedList<E>::addBack(const E& e)
{
	add(trailer, e);
}

template <typename E>
bool DLinkedList<E>::addScore(const E& e) {
	//if the list is empty, add the first element to the front
	if (count == 0) {
		addFront(e);
		return true;
	}
	//loops through starting at first node (if the list isn't already full). If the value is greater than an existing value, it's added before it.
	DNode<E>* current = header->next;
	while (count != MAX_ENTRIES) {
		while (current != trailer) {
			if (e > (current->elem)) {
				add((current), e);
				return true;
			}
			current = current->next;
		}
		addBack(e);
		return true;
	}
	if (count == MAX_ENTRIES) {
		// if the list is already full, loop through to see if the new value is greater or equal to existing ones. If so, remove
		// the lowest value and insert the new one.
		if (e <= trailer->prev->elem) {
		cout << "The list is full and this score is not greater than the current top " << MAX_ENTRIES << "." << endl;
		return false;
		}
		current = (header->next);
		while (current != header) {
			if (e > current->elem) {
				removeBack();
				add(current, e);
				return true;
			}
			current = current->next;
		}
	}
	return false;
}

//Starts at the first node and loops through until it hits the trailer - printing each element as it goes
template <typename E>
void DLinkedList<E>::showScores() 
{
	DNode<E> *current = (header->next);
	cout << "High Scores: ";
	while (current != trailer) {
		cout << current->elem << " ";
		current = current->next;
	}
	cout << endl;
}

template <typename E>
void DLinkedList<E>::remove(DNode<E>* v) 
{
    DNode<E>* u = v->prev;		// predecessor
    DNode<E>* w = v->next;		// successor
    u->next = w;				// unlink v from list
    w->prev = u;
    delete v;
	count--;
}

// remove from front
template <typename E>
void DLinkedList<E>::removeFront()
    { remove(header->next); }

// remove from back
template <typename E>
  void DLinkedList<E>::removeBack()
    { remove(trailer->prev); }