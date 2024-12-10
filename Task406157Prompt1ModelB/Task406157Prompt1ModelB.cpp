#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> ordered_list = {
        "apple",
        "banana",
        "banana",
        "blueberry",
        "cherry",
        "grape",
        "grape",
        "grape",
        "pineapple",
        "pineapple",
        "pineapple"
    };

    std::string substring_to_find = "grape";

    auto range = std::equal_range(ordered_list.begin(), ordered_list.end(), substring_to_find);

    if (range.first == ordered_list.end()) {
        std::cout << "Substring \"" << substring_to_find << "\" not found.\n";
    } else {
        std::cout << "Substring \"" << substring_to_find << "\" found "
                  << std::distance(range.first, range.second) << " time(s):\n";
        for (auto it = range.first; it != range.second; ++it) {
            std::cout << *it << '\n';
        }
    }

    return 0;
}