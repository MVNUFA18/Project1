/* ListDemo.cpp
 * Author: Bob Kasper
 * Description: demonstrate SLinkedList and DLinkedList classes
 * which are described by Goodrich, Tamassia and Mount (2011), section 3.2
 */

#include "SLinkedList.h"
#include "DLinkedList.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	SLinkedList<string> wordList;
	DLinkedList<int> numList;
	string word;

	// input a sequence of words until STOP is entered
	cout << "Enter a message followed by STOP:" << endl;
	cin >> word;
	while (word != "STOP") {
		wordList.addFront(word);
		cin >> word;
	}

	// display the list
	while (!wordList.empty()) {
		cout << wordList.front() << ' ';
		wordList.removeFront();
	}
	cout << endl;

	// input a sequence of integers until 0 is entered
	int num;
	cout << "Enter a list of integers followed by 0:" << endl;
	cin >> num;
	while (num != 0) {
		numList.addBack(num); // add to end of list, instead of front
		cin >> num;
	}

	// display the list
	while (!numList.empty()) {
		cout << numList.front() << ' ';
		numList.removeFront();
	}
	cout << endl;
}
