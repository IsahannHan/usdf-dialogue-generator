#pragma once
#include "ItemAmountBase.h"
#include "Cost.h"

#include <string>

class Choice {
public:
	std::string text;
	Cost cost;
	bool displaycost;
	std::string yesmessage;
	std::string nomessage;
	std::string log;
	int giveitem;
	int special;
	int arg0;
	int arg1;
	int arg2;
	int arg3;
	int arg4;
	int nextpage;
	bool closedialog;

	std::string title = "CHOICE";

	std::string tag(int nestedTabs);
	std::string baseTag();
};

