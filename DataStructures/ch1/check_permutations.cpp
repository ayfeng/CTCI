#include <string> //string
#include <iostream> //cout, endl
#include "hash_map.hpp" //HashMap

using std::string;

//brute force
bool checkPermutations1(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    for (string::size_type i = 0; i != s1.length(); ++i) {
        bool found = false;
        for (string::size_type j = 0; j != s2.length(); ++j) {
            if (s1[i] == s2[j]) {
                found = true;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

bool checkPermutations2(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    HashMap<char, int> map = HashMap<char, int>();
    for (string::size_type i = 0; i != s1.size(); ++i) {
        map.insert(s1[i], 1);
    }

    for (string::size_type j = 0; j != s2.size(); ++j) {
        if(map[s2[j]] == -1)
            return false;
    }
    return true;
}

int main() {
    string test_strings[] = {"one", "oen", "oek", "oek", "one"};
    for (int i = 0; i != sizeof(test_strings)/sizeof(test_strings[0])-1; ++i) {
        std::cout << "CHECKING " << test_strings[i] << " " << test_strings[i+1] << std::endl;
        std::cout << checkPermutations2(test_strings[i], test_strings[i+1]) << std::endl;
    }
    return 0;
}
