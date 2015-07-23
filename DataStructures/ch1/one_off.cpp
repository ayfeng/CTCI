#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

bool hasInsert(string first, string second) {
    if (first.length() != second.length()-1 && second.length() != first.length()-1)//one off on length indicates insertion or removal
        return false;

    string* shortString, *longString;
    if (first.length() > second.length())
        shortString = &second, longString = &first;
    else
        shortString = &first, longString = &second;

    bool foundMismatch = false;
    for (string::size_type i = 0, j = 0; i != shortString->length() && j != longString->length(); ++i, ++j) {
        if ((*shortString)[i] != (*longString)[j]) {
            if (foundMismatch) { //already found a mismatch before
                return false;
            } else {
                foundMismatch = true;
                ++j;
            }
        }
    }
    return true;
}

bool hasReplace(string first, string second) {
    if (first.length() != second.length())
        return false;

    bool foundMismatch = false;
    for (string::size_type i = 0; i != first.length(); ++i) {
        if (first[i] != second[i]) {
            if (foundMismatch) {
                return false;
            } else {
                foundMismatch = true;
            }
        }
    }
    return true;
}

bool oneOff(string first, string second) {
    return hasInsert(first, second) || hasReplace(first, second);
}


int main() {
    cout << oneOff("pale", "ple") << endl;
    cout << oneOff("pales", "pale") << endl;
    cout << oneOff("pale", "bale") << endl;
    cout << oneOff("pale", "bake") << endl;
}
