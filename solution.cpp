/*
 * solution.cpp
 *
 *  Created on: Jan 28, 2018
 *      Author: Nic Falcione
 */

#include <iostream>
#include <vector>

using namespace std;

// Server compiler doesn't like initializer lists

//vector<string> oneToFourteen = {	"zero", "one" "two", "three", "four", "five",
//	"six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
//	"fourteen"};
//vector<string> teens = { "twen", "thir", "for", "fif", "six", "seven", "eigh",
//		"nine" };

string convert(unsigned long num) {
	vector<string>* oneToFourteen = new vector<string>();
	oneToFourteen->push_back("zero");
	oneToFourteen->push_back("one");
	oneToFourteen->push_back("two");
	oneToFourteen->push_back("three");
	oneToFourteen->push_back("four");
	oneToFourteen->push_back("five");
	oneToFourteen->push_back("six");
	oneToFourteen->push_back("seven");
	oneToFourteen->push_back("eight");
	oneToFourteen->push_back("nine");
	oneToFourteen->push_back("ten");
	oneToFourteen->push_back("eleven");
	oneToFourteen->push_back("twelve");
	oneToFourteen->push_back("thirteen");
	oneToFourteen->push_back("fourteen");

	vector<string>* teens = new vector<string>();
	teens->push_back("twen");
	teens->push_back("thir");
	teens->push_back("for");
	teens->push_back("fif");
	teens->push_back("six");
	teens->push_back("seven");
	teens->push_back("eigh");
	teens->push_back("nine");

	if (num < 15) {
		return (oneToFourteen->at(num));
	} else if (num < 20) {
		return (teens->at(num - 12) + "teen");
	} else if (num < 100) {
		unsigned long remainder = num - ((num / 10) * 10);
		string end = "";

		if (remainder == 0) {
			end = "ty";
		} else {
			end = "ty-" + convert(remainder);
		}

		return (teens->at((num / 10) - 2) + end);
	} else if (num < 1000) {
		unsigned long remainder = num - ((num / 100) * 100);
		string start = "";
		start = (oneToFourteen->at(num / 100) + " hundred");

		string end = convert(remainder);
		if (remainder == 0) {
			return start;
		}

		return start + " and " + end;
	} else if (num < 1000000) {
		unsigned long thousands = (num / 1000);
		unsigned long remainder = num - (thousands * 1000);
		if (remainder < 100 && remainder > 0) {
			return (convert(thousands) + " thousand and " + convert(remainder));
		} else if (remainder < 1) {
			return (convert(thousands) + " thousand");
		}
		return (convert(thousands) + " thousand, " + convert(remainder));
	} else if (num < 1000000000) {
		unsigned long millions = (num / 1000000);
		unsigned remainder = num - (millions * 1000000);
		if (remainder < 100 && remainder > 0) {
			return (convert(millions) + " million and " + convert(remainder));
		} else if (remainder < 1) {
			return (convert(millions) + " million");
		}
		return (convert(millions) + " million, " + convert(remainder));
	}
	return "";
}

vector<string>* process(vector<unsigned long>& input) {
	vector<string>* ret = new vector<string>();

	for (int i = 0; i < input.size(); i++) {
		unsigned long n = input.at(i);
		string s = convert(n);
		ret->push_back(s);

	}
	return ret;
}

