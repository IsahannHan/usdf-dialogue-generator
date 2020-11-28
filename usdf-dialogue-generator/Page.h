#pragma once

#include <string>
#include <list>
#include "Ifitem.h"
#include "Choice.h"
#include "Element.h"

class Page : public Element
{
public:
    Page(std::string name,
        std::string panel,
        std::string voice,
        std::string dialog,
        int drop,
        int link,
        Ifitem ifitem,
        std::list<Choice> choice);

    Page();

    std::string name;
    std::string panel;
    std::string voice;
    std::string dialog;
    int drop;
    int link;
    Ifitem ifitem;
    std::list<Choice> choice;

    std::string title = "PAGE";

    std::string tag(int nestedTabs, bool baseTag);
};
