#include <fstream>
#include <iostream>
#include "classes/conversation.cpp"

using namespace std;

ofstream of_file;

int main(void){
    Conversation conversation;
    conversation.actor = "Antonio Flags";

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


