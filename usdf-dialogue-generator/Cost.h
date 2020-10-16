#pragma once
#include "ItemAmountBase.h"
class Cost :
    public Element,
    public ItemAmountBase
{
public:
    using ItemAmountBase::ItemAmountBase;

    std::string title = "COST";

    std::string tag(int nestedTabs, bool baseTag);
};

