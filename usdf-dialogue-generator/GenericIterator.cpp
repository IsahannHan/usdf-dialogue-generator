#include <string>
#include <list>
#include <iostream>

template <typename T>
const static std::string createMultipleItems(int nestedTabs, std::list<T>& list) {
    std::string items;

    std::cout << "TESTEEEEEEEEEE";

    for (auto p : list)
        items.append(p.tag(nestedTabs));

    return items;
}