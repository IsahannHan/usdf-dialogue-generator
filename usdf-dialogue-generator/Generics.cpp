#include <string>
#include <list>
#include <iostream>

template <typename T>
const static std::string createSingleItem(int nestedTabs, T& item, bool baseTag){
    return item.tag(nestedTabs, baseTag);
}

template <typename T>
const static std::string createMultipleItems(int nestedTabs, std::list<T>& list, bool baseTag) {
    std::string items;

    for (auto i : list)
        items.append(createSingleItem(nestedTabs, i, baseTag));

    return items;
}