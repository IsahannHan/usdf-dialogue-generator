#include <fstream>
#include <iostream>

#include "FileCreation.h"
#include "ElementCreation.h"

void FileCreation::dialogueCreation() {
	std::ofstream ofs_generated_file;
	ElementCreation creation;

	ofs_generated_file.open("generated_dialogue.txt", std::ios::out);

	ofs_generated_file << creation.baseFileCreation().tag(0, false) << std::endl;

	std::cout << "FILE GENERATED!" << std::endl;
}
