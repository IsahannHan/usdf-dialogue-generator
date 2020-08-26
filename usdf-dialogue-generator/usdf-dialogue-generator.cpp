#include <fstream>
#include <iostream>
#include "Conversation.h"

using namespace std;

ofstream of_file;

int main(void) {
    Page page("teste", "t", "foda-se", "caralho", 2, 355);

    Conversation conversation("Antonio pirocas", &page);

    // cout << "ACTOR: " << conversation.actor << "TAG: \n" << conversation.tag();

    // string _namespace;

    of_file.open("generated_dialogue.txt", ios::out);

    // cout << "--------------------STRIFE FILE GENERATOR--------------------\n\n";
    // cout << "*BEGGINING CREATION*\n";
    // cout << "Namespace? ";
    // getline(cin, _namespace);
    // cout << "Namespace: " << _namespace << endl;

    of_file << conversation.tag(0) << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
