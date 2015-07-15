#include <string>
#include <iostream>
#include <iomanip>
using std::boolalpha;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int getCharValue(char c) {
    int capitalA = (int)'A';
    int capitalZ = (int)'Z';
    int lowercaseA = (int)'a';
    int lowercaseZ = (int)'z';
    int charVal = (int)c;

    if (capitalA <= charVal && charVal <= capitalZ)
        return charVal - capitalA;
    else if (lowercaseA <= charVal && charVal <= lowercaseZ)
        return charVal - lowercaseA;
    else
        return -1; //not found
}

int* getFrequencyMap(const string& a) {
    int* map = new int[(int)'z' - (int)'a'];
    for (string::const_iterator i = a.cbegin(); i != a.cend(); ++i) {
        map[getCharValue(*i)] = (map[getCharValue(*i)] ? 0 : 1);
    }
    return map;
}

bool checkPalindromePermutations(const string& a) {
    int* freqMap = getFrequencyMap(a);
    bool foundOdd = false;

    for (string::const_iterator i = a.cbegin(); i != a.cend(); ++i) {
        if (freqMap[getCharValue(*i)] == 0) { //odd number of times
            if (!foundOdd)
                foundOdd = true;
            else
                return false; //more than one letter that occurred an odd number of times
        }
    }
    return true;
}

int main() {
    string a;

    cout << "Enter word: ";
    cin >> a;

    cout << boolalpha << checkPalindromePermutations(a) << endl;
    
    return 0;
}
