#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void find_substring_occurrences(const std::vector<std::string>& ordered_list, const std::string& substring) {
    auto it = std::lower_bound(ordered_list.begin(), ordered_list.end(), substring);

    while (it != ordered_list.end() && it->find(substring) != std::string::npos) {
        std::cout << *it << '\n';
        ++it;
    }

    if (it == ordered_list.end()) {
        std::cout << "Substring \"" << substring << "\" not found.\n";
    }
}

int main() {
    std::vector<std::string> ordered_list = {
        "apple",
        "banana",
        "banana",
        "blueberry",
        "cherry",
        "grape",
        "grape",
        "grapes",
        "pineapple",
        "pineapple",
        "pineapple"
    };

    find_substring_occurrences(ordered_list, "gra");
    find_substring_occurrences(ordered_list, "pine");
    find_substring_occurrences(ordered_list, "peach");
    find_substring_occurrences(ordered_list, "ape");

    return 0;
}