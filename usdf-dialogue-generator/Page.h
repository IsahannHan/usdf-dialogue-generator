#pragma once

#include <string>
#include <list>
#include "Ifitem.h"
#include "Choice.h"

class Page {
public:
    std::string title = "PAGE";

    std::string name;
    std::string panel;
    std::string voice;
    std::string dialog;
    int drop;
    int link;
    Ifitem ifitem;
    std::list<Choice> choice;

    std::string tag(int nestedTabs);
    std::string baseTag();
};
