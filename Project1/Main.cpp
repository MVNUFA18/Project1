/*
 * Author: Dante Cherubini
 * Description: DlinkedList Main
 * Date: 9/16/2018
 * Gathers user input until a negative score is entered and puts the score into the 'high scores'
 * if it is greater than any current scores OR the high scores list is not yet full.
 */

#include <iostream>
#include "DLinkedList.h"

using namespace std;

int main() {
	DLinkedList<int> List;

	int score = 0;
	// Infinite loop - exits only when a negative score is entered
	while (true) {
		cout << "Enter a new score : ";
		cin >> score;
		if (score < 0) {
			cout << "A negative score was entered.";
			return 0;
		}
		List.addScore(score);
	}
	return 0;
}