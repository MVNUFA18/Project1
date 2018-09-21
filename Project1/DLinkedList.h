/* DLinkedList.h
 * Authors: Goodrich, Tamassia and Mount (2011)
 * Description: Doubly linked list class definitions
 * from code fragments 3.22 and 3.23
 */
#pragma once

#ifndef DLINKED_LIST_H
#define DLINKED_LIST_H

#include <cstdlib>
#include <iostream>

using namespace std;

template <typename E> class DLinkedList; // allow forward reference

template <typename E>
class DNode {					// doubly linked list node
  private:
    E elem;						// node element value
    DNode<E>* prev;				// previous node in list
    DNode<E>* next;				// next node in list
    friend class DLinkedList<E>;	// allow DLinkedList access
};

template <typename E>
class DLinkedList {				// doubly linked list
  public:
    DLinkedList();				// constructor
    ~DLinkedList();				// destructor
    bool empty() const;				// is list empty?
    const E& front() const;			// get front element
    const E& back() const;			// get back element
    void addFront(const E& e);		// add to front of list
    void addBack(const E& e);		// add to back of list
	bool addScore(const E& score);  // add score in order
	void showScores();				// Print a line displaying scores in decreasing order
    void removeFront();				// remove from front
    void removeBack();				// remove from back
  private:
    DNode<E>* header;				// list sentinels
    DNode<E>* trailer;
	const int MAX_ENTRIES = 10;
	int count = 0;
  protected:						// local utilities
    void add(DNode<E>* v, const E& e);	// insert new node before v
    void remove(DNode<E>* v);			// remove node v
};

#include "DLinkedList.cpp"		// need to include template function defintions
								// to allow instantiation with different types
#endif
