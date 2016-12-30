#include <iostream>
#include <vector>


using namespace std;
using namespace std::chrono;

vector<string> generateVector() {
    vector<string> vec;
    for(int i = 0; i < 5500000; i++) {
        string str = "";
        for(int p = 0; p < 10; p++) {
            char c = (char)((rand() % 25) + 65);
            str += c;
        }
        if((rand() % 1500000) == 0) str += "foo";
        vec.push_back(str);
    }
    return vec;
}

inline bool ends_with(const string &str, const string &suffix)
{
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

int main() {
    vector<string> vec = generateVector();

    high_resolution_clock::time_point startTime = high_resolution_clock::now();
    vector<string>::iterator found = find_if(vec.begin(), vec.end(), [](string &str) {
        return ends_with(str, "foo");
    });
    high_resolution_clock::time_point endTime = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>( endTime - startTime ).count();

    std::cout << "Total execution time: " << duration << "." << std::endl;
    cout << "Found element: " << *found << endl;
    return 0;
}