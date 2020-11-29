#pragma once
#include "ItemAmountBase.h"

class Cost : public ItemAmountBase
{
public:
    using ItemAmountBase::ItemAmountBase;

    std::string title = "COST";

	std::string tag(int nestedTabs);
	std::string baseTag();
};

