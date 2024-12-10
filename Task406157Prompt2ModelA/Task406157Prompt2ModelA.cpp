#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> find_substring_occurrences(const vector<string>& ordered_list, const string& substring_to_find)
{
   vector<int> result;

    if (substring_to_find.empty()) {
        return result; // Return empty vector for empty substring
    }

    for (size_t i = 0; i < ordered_list.size(); ++i)
    {
        const string& str = ordered_list[i];
        if (str.find(substring_to_find) != string::npos)
        {
            result.push_back(i);
        }
    }
    return result;
}
int main()
{
    std::vector<std::string> ordered_list = {
        "apple", "banana", "banana_split", "blueberry", "cherry",
        "grape", "grapefruit", "pineapple", "pineappled_daiquiri"
    };

    std::string substring_to_find = "na";
    
    auto indices = find_substring_occurrences(ordered_list, substring_to_find);

    if (indices.empty()) {
        std::cout << "Substring \"" << substring_to_find << "\" not found.\n";
    } else {
        std::cout << "Substring \"" << substring_to_find << "\" found "
                  << indices.size() << " time(s):\n";
        for (auto index : indices) {
            std::cout << ordered_list[index] << '\n';
        }
    }

    return 0;
}
