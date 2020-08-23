#include <fstream>
#include <iostream>
#include "classes/conversation.h"

using namespace std;

ofstream of_file;

int main(void){
    Conversation conversation;

    cout << conversation.actor;

    string _namespace; 


    of_file.open("generated_dialogue.txt", ios::out);

    cout << "--------------------STRIFE FILE GENERATOR--------------------\n\n";
    cout << "*BEGGINING CREATION*\n";
    cout << "Namespace? ";
    getline(cin, _namespace);
    cout << "Namespace: " << _namespace << endl;

    of_file << "namespace = "<< "\"" << _namespace << "\"" << "\n" << endl;

}


