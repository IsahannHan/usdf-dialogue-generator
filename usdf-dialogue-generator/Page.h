#pragma once
#include <string>

class Page
{
public:
    Page(std::string name,
        std::string panel,
        std::string voice,
        std::string dialog,
        int drop,
        int link);

    std::string name;
    std::string panel;
    std::string voice;
    std::string dialog;
    int drop;
    int link;

    std::string tag(int nestedTabs);
};

