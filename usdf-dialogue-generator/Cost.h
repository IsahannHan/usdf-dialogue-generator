#pragma once
#include "ItemAmountBase.h"
class Cost :
    public ItemAmountBase
{
public:
    using ItemAmountBase::ItemAmountBase;

    std::string tag(int nestedTabs);
};

