#pragma once
#include "ItemAmountBase.h"
class Ifitem :
    public ItemAmountBase
{
public:
    using ItemAmountBase::ItemAmountBase;
    Ifitem();

    std::string tag(int nestedTags, bool baseTag);
};

