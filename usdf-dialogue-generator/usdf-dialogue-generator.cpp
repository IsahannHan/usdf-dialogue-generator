#include <fstream>
#include <iostream>

#include "Conversation.h"
#include "Choice.h"

std::ofstream of_file;

int main(void) {
    std::list<Choice> choices;
    std::list<Page> pages;

    Cost cost(5, 10);
    Ifitem ifitem(2, 993);

    Choice choice("Name of the choice", &cost, true, "Yes message.", "No message", "Yoooooo", 5, 2, 1111, 22, 5, 7, 3, 99, false);
    Choice choice1("WEEE HOO", &cost, true, "Yes.", "sage", "num sei", 5, 2, 3, 44, 5, 7, 8, 99, true);
    Choice choice2("Name of the choiceSSSSSSSS", &cost, true, "SIMmessage.", "No", "Yoooooo", 5, 2, 111, 4, 5, 7, 8, 66, false);

    choices.push_back(choice);
    choices.push_back(choice1);
    choices.push_back(choice2);

    Page page("PAGE 1", "Panel test", "Voice oooof", "Test dialog", 1, 2, &ifitem, &choices);
    Page page1("PAGE 2222", "SAM CEHOICES test", "Voice urgh", "Test testteste", 4, 6666, &ifitem, &choices);

    pages.push_back(page);
    pages.push_back(page1);

    Conversation conversation("ednaldo pereira", &pages);

    // cout << "ACTOR: " << conversation.actor << "TAG: \n" << conversation.tag();

    // string _namespace;

    of_file.open("generated_dialogue.txt", std::ios::out);

    // cout << "--------------------STRIFE FILE GENERATOR--------------------\n\n";
    // cout << "*BEGGINING CREATION*\n";
    // cout << "Namespace? ";
    // getline(cin, _namespace);
    // cout << "Namespace: " << _namespace << endl;

    of_file << conversation.tag(0) << std::endl;

    return 0;
}
