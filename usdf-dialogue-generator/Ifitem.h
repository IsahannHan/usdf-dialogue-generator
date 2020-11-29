#pragma once
#include "ItemAmountBase.h"

class Ifitem : public ItemAmountBase {
public:
    using ItemAmountBase::ItemAmountBase;

    std::string title = "IFITEM";

    std::string tag(int nestedTabs);
    std::string baseTag();
};

