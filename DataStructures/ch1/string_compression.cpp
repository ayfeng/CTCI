#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;

string compress(string input) {
    string result;
    char prev = input.front();
    int count = 0;
    for (string::size_type i = 0; i != input.length(); ++i) {
        if(input[i] != prev) {
            result += prev+std::to_string(count);
            prev = input[i];
            count = 1;
        } else {
            ++count;
        }
    }
    result += prev+std::to_string(count);
    return (result.length() < input.length() ? result : input);
}

int main() {
    cout << compress("aabcccccaaa") << endl;
    cout << compress("abcdefg") << endl;
    return 0;
}

