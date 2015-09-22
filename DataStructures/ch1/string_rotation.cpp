#include <string>
#include <iostream>

using namespace std;

bool isSubstring(string word, string substr) {
    return true; //assume that this function returns whether or not substr is a substr of word
}

bool isRotation(string first, string second) {
    if (first.length() != second.length()) {
        return false;
    } else {
        return isSubstring(first+first, second);
    }
}

int main() {
    string first, second;
    cin >> first >> second;

    cout << boolalpha << isRotation(first, second) << endl;
}

//assume there exists a function isSubstring(string, substr) that checks if one is a substring of the other
bool isSubstring(string word, string substr);
