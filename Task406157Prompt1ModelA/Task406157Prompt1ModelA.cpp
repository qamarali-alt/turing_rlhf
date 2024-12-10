
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main() {
    // Ordered list of strings
    std::vector<std::string> ordered_strings = {
        "hello", "hello World", "help", "meaningless", "hi hello",
        "coffee", "chocolate", "coordinated",
    };

    // Substring to find
    std::string substring = "hello";

    // Helper function for case-insensitive comparison
    bool custom_compare(const std::string& lhs, const std::string& rhs) {
        return std::transform(lhs.begin(), lhs.end(), lhs.begin(), ::tolower) <
               std::transform(rhs.begin(), rhs.end(), rhs.begin(), ::tolower);
    }

    // Sort the input vector in case-insensitive manner
    std::sort(ordered_strings.begin(), ordered_strings.end(), custom_compare);

    // Find the range of the substring in the ordered list
    auto range = std::equal_range(
        ordered_strings.begin(), ordered_strings.end(), substring, custom_compare
    );

    // Display the occurrences
    if (range.first == range.second) {
        std::cout << "Substring \"" << substring << "\" not found.\n";
    } else {
        std::cout << "Substring \"" << substring << "\" found " << std::distance(range.first, range.second) << " times:\n";
        for (std::vector<std::string>::iterator it = range.first; it != range.second; ++it) {
            std::cout << *it << "\n";
        }
    }

    return 0;
}
 