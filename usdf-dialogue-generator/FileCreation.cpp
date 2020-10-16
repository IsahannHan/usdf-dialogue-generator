#include <fstream>
#include <iostream>

#include "ElementCreation.cpp"
using namespace utils_element_creation;

std::ofstream ofs_generated_file;

 namespace FileCreation {

 	void dialogueCreation() {
        ofs_generated_file.open("generated_dialogue.txt", std::ios::out);

 		ofs_generated_file << baseFileCreation().tag(0, false) << std::endl;

        std::cout << "FILE GENERATED!" << std::endl;
 	}
 }