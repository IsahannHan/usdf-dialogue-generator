#include <string>
#include <iostream>
#include <sstream>

#include "BaseFile.h"


namespace FileCreation {
	BaseFile _baseFile;
	Conversation _conversation;
	std::list<Page> _pagesList;

	void ifItemCreation(Page& page) {

	}

	void pageCreation() {
		// Create MULTIPLE pages
		Page _page;
		char satisfied{};
		char anotherOne{}; // DJ KHALED

		/*Page(std::string name,
			std::string panel,
			std::string voice,
			std::string dialog,
			int drop,
			int link,
			Ifitem * ifitem,
			std::list<Choice> * choice);*/

		while (toupper(anotherOne) != 'N')
		{
			while (toupper(satisfied) != 'Y') {
				std::cout << "---------------------------------------------------------------------------" << std::endl;
				std::cout << "|                         CREATING PAGE                                   |" << std::endl;
				std::cout << "---------------------------------------------------------------------------" << std::endl;

				std::cout << "Please type the \"NAME\" attribute and press enter: ";
				std::getline(std::cin >> std::ws, _page.name);
				std::cout << "Please type the \"PANEL\" attribute and press enter: ";
				std::getline(std::cin >> std::ws, _page.panel);
				std::cout << "Please type the \"VOICE\" attribute and press enter: ";
				std::getline(std::cin >> std::ws, _page.voice);
				std::cout << "Please type the \"DIALOG\" attribute and press enter: ";
				std::getline(std::cin >> std::ws, _page.dialog);
				std::cout << "Please type the \"DROP\" attribute and press enter: ";
				std::cin >> _page.drop;
				std::cout << "Please type the \"LINK\" attribute and press enter: ";
				std::cin >> _page.link;

				std::cout << "---------------------------------------------------------------------------" << std::endl;
				std::cout << "|                           REVIEW PAGE                                   |" << std::endl;
				std::cout << "---------------------------------------------------------------------------" << std::endl;
				std::cout << _page.tag(0, true) << std::endl;

				std::cout << "Does this looks good? Y to continue, N to recreate: ";
				std::cin >> satisfied;

				system("cls");
			}

			_pagesList.push_back(_page);

			std::cout << "Base \"PAGE\" element #" << _pagesList.size() << " created!";
			std::cout << "\n Proceeding to create \"IFITEM\" and \"CHOICE\" objects..." << std::endl;

			// here

			std::cout << "\"PAGE\" element #" << _pagesList.size() << " fully created!";
			std::cout << "Do you wish to create another \"PAGE\"? Y for yes, N for no: ";
		}

		std::cout << "Pages created!";
		std::cout << "\n Proceeding to create \"IFITEM\" and \"CHOICE\" objects..." << std::endl;

		system("pause");
	}

	void conversationCreation() {
		// Create Conversation
		char satisfied{};

		while (toupper(satisfied) != 'Y') {
			std::cout << "---------------------------------------------------------------------------" << std::endl;
			std::cout << "|                         CREATING CONVERSATION                            |" << std::endl;
			std::cout << "---------------------------------------------------------------------------" << std::endl;
			std::cout << "Please type the \"ACTOR\" attribute and press enter: ";
			std::getline(std::cin >> std::ws, _conversation.actor);

			std::cout << "---------------------------------------------------------------------------" << std::endl;
			std::cout << "|                         REVIEW CONVERSATION                             |" << std::endl;
			std::cout << "---------------------------------------------------------------------------" << std::endl;
			std::cout << _conversation.tag(0, true) << std::endl;

			std::cout << "Does this looks good? Y to continue, N to recreate: ";
			std::cin >> satisfied;

			system("cls");
		}

		std::cout << "\"CONVERSATION\" created!";
		std::cout << "\n Proceeding to create \"PAGE\" objects..." << std::endl;

		system("pause");

		pageCreation();
	}

	void baseFileCreation() {
		// Create BaseFile
		char satisfied{};
		std::string nameSpace;
		std::string include;

		while (toupper(satisfied) != 'Y') {
			std::cout << "---------------------------------------------------------------------------" << std::endl;
			std::cout << "|                         CREATING FILE BASE                              |" << std::endl;
			std::cout << "---------------------------------------------------------------------------" << std::endl;
			std::cout << "Please type the \"namespace\" and press enter: ";
			std::getline(std::cin >> std::ws, _baseFile.nameSpace);

			std::cout << "Please type the \"include\" and press enter: ";
			std::getline(std::cin >> std::ws, _baseFile.include);

			std::cout << "---------------------------------------------------------------------------" << std::endl;
			std::cout << "|                         REVIEW FILE BASE                                |" << std::endl;
			std::cout << "---------------------------------------------------------------------------" << std::endl;
			std::cout << _baseFile.tag(true) << std::endl;

			std::cout << "Does this looks good? Y to continue, N to recreate: ";
			std::cin >> satisfied;

			system("cls");
		}

		std::cout << "\"BASEFILE\" created!";
		std::cout << "\n Proceeding to create \"CONVERSATION\" object..." << std::endl;

		system("pause");

		conversationCreation();
	}

	void dialogueCreation() {
		baseFileCreation();
	}
}