#pragma once
#include <string>
class ItemAmountBase
{
public:
	ItemAmountBase(int item, int amount);
	ItemAmountBase();

	int item;
	int amount;

	std::string tag(int nestedTabs);
};

