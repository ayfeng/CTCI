#include <string>
#include <iostream>

using std::string;

bool isUniqueString(string str) {
    bool* unique_flags = new bool[128]; //map letters to uniqueness bools

    for (string::size_type i = 0; i != str.length(); ++i) {
        if (unique_flags[str[i]])
            return false;
        else
            unique_flags[str[i]] = true;
    }
    return true;
}

int main() {
    string test_strings[] = {"hi", "hello world", "", "abcdc", "aa", "19323"};

    for (int i = 0; i != sizeof(test_strings)/sizeof(test_strings[0]); ++i)
        std::cout << test_strings[i] << " is " << (isUniqueString(test_strings[i]) ? "" : "not ") << "unique." << std::endl;

    return 0;
}

