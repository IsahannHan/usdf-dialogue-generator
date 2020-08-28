#include <string>
#include <list>
#include <iostream>

template <typename T>
const static std::string createSingleItem(int nestedTabs, T& item){
    return item.tag(nestedTabs);
}

template <typename T>
const static std::string createMultipleItems(int nestedTabs, std::list<T>& list) {
    std::string items;

    for (auto i : list)
        items.append(createSingleItem(nestedTabs, i));

    return items;
}