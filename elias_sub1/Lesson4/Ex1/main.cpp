#include <iostream>

#include <vector>

#include <assert.h>

using namespace std;

template <typename T>
vector<T> mergeContainers(vector<T> v1, vector<T> v2) {
    vector<T> target;

    for_each(v1.begin(), v1.end(), [&](const T elem) { target.push_back(elem); });
    for_each(v2.begin(), v2.end(), [&](const T elem) { target.push_back(elem); });
    return target;
}

int main() {
    vector<int> test = { 1, 2, 3, 4 };
    vector<int> test2 = { 5, 6, 7, 8 };
    auto testResult = mergeContainers(test, test2);

    vector<int> mustBe = { 1, 2, 3, 4, 5, 6, 7, 8 };
    assert(testResult == mustBe);
    cout << "Merge success." << endl;
    return 0;
}