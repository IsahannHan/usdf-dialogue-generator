#include <fstream>
#include <iostream>

using namespace std;

ofstream of_file;

void beginConversation(){
  of_file << "conversation\n{";
}

int main(void){
    string _namespace; 

   
    of_file.open("generated_file.txt", ios::out);

    cout << "--------------------STRIFE FILE GENERATOR--------------------\n\n";
    cout << "*BEGGINING CREATION*\n";
    cout << "Namespace? ";
    getline(cin, _namespace);
    cout << "Namespace: " << _namespace << endl;

    of_file << "namespace = "<< "\"" << _namespace << "\"" << "\n" << endl;

    beginConversation();
}


