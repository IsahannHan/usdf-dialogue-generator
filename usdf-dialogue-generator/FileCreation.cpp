#include <fstream>
#include <iostream>

#include "FileCreation.h"
#include "ElementCreation.h"

void FileCreation::dialogueCreation() {
	std::ofstream ofs_generated_file;
	ElementCreation creation;

	ofs_generated_file.open("generated_dialogue.txt", std::ios::out);

	ofs_generated_file << creation.baseFileCreation().tag(0, false) << std::endl;

	system("cls");
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
	std::cout << "                             FILE GENERATED!                                   " << std::endl;
	std::cout << "    The dialogue file can be found at the same directory with this program.    " << std::endl;
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
	system("pause");
}

