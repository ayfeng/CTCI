#include <iostream>
#include <string>

using std::string;

//brute force - O(n), n = length of str
string urlify(string str, int input) {
    string result;
    for (string::size_type i = 0; i != str.length(); ++i) {
        if (str[i]==' ')
            result += "%20";
        else
            result.push_back(str[i]);
    }
    return result;
}

//TODO implementation using char arrays

int main() {
    std::cout << urlify("Mr John Smith", 13) << std::endl;
    return 0;
}
