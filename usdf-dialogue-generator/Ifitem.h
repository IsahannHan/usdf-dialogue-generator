#pragma once
#include "ItemAmountBase.h"
#include "Element.h"

class Ifitem :
    public Element,
    public ItemAmountBase
{
public:
    using ItemAmountBase::ItemAmountBase;
    Ifitem();

    std::string title = "IFITEM";

    std::string tag(int nestedTags, bool baseTag);
};

