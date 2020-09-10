 #include <string>
 #include <iostream>
 #include <sstream>

 #include "BaseFile.h"


 namespace FileCreation {
 	BaseFile _baseFile;
 	Conversation _conversation;
 	std::list<Page> _pagesList;

 	void choiceCreation(Page& page) {
 		std::list<Choice> _choicesList;
 		Choice _choice;
 		char satisfied{};
 		char anotherOne{};

 		while (toupper(anotherOne) != 'N') {
 			while (toupper(satisfied) != 'Y') {


 				std::cout << "---------------------------------------------------------------------------" << std::endl;
 				std::cout << "|                         CREATING CHOICE                                 |" << std::endl;
 				std::cout << "                        FOR PAGE " << page.name << "                       " << std::endl;
 				std::cout << "---------------------------------------------------------------------------" << std::endl;

 				std::cout << "Please type the \"TEXT\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"DISPLAYCOST\" attribute and press enter (true/false): ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"TEXT\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"TEXT\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"TEXT\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"TEXT\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"TEXT\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"TEXT\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"TEXT\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"TEXT\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);

 				std::cout << "Please type the \"AMOUNT\" attribute and press enter: ";
 				std::cin >> _ifItem.amount;


 			}
 		}
 	}

 	void ifItemCreation(Page& page) {
 		Ifitem _ifItem;
 		char satisfied{};

 		while (toupper(satisfied) != 'Y') {
 			std::cout << "---------------------------------------------------------------------------" << std::endl;
 			std::cout << "|                         CREATING IFITEM                                 |" << std::endl;
 			std::cout << "                        FOR PAGE " << page.name << "                       " << std::endl;
 			std::cout << "---------------------------------------------------------------------------" << std::endl;

 			std::cout << "Please type the \"ITEM\" attribute and press enter: ";
 			std::cin >> _ifItem.item;
 			std::cout << "Please type the \"AMOUNT\" attribute and press enter: ";
 			std::cin >> _ifItem.amount;

 			std::cout << "---------------------------------------------------------------------------" << std::endl;
 			std::cout << "|                           REVIEW IFITEM                                 |" << std::endl;
 			std::cout << "---------------------------------------------------------------------------" << std::endl;
 			std::cout << _ifItem.tag(0, true) << std::endl;

 			std::cout << "Does this looks good? Y to continue, N to recreate: ";
 			std::cin >> satisfied;

 			system("cls");
 		}

 		std::cout << "\"IFITEM\" element created! Linking it to the correspondent PAGE...";

 		page.ifitem = &_ifItem;

 		system("pause");
 	}

 	void pageCreation(Page& page) {
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
 			std::cout << "\n Proceeding to create \"IFITEM\" object for this PAGE..." << std::endl;

 			system("pause");

 			ifItemCreation(_page);

 			system("cls");

 			std::cout << "\n Proceeding to create multiple \"CHOICE\" objects for this PAGE..." << std::endl;

 			system("pause");

 			choiceCreation(_page);

 			//_page.ifitem = _ifItem;
 			//_page.choice = _choice;

 			std::cout << "\"PAGE\" element #" << _pagesList.size() << " fully created!";
 			std::cout << "Do you wish to create another \"PAGE\"? Y for yes, N for no: ";
 		}

 		std::cout << "Pages created!";

 		system("pause");
 	}

 	void conversationCreation(Conversation& conversation) {
 		// Create Conversation
 		char satisfied{};

 		while (toupper(satisfied) != 'Y') {
 			std::cout << "---------------------------------------------------------------------------" << std::endl;
 			std::cout << "|                         CREATING CONVERSATION                            |" << std::endl;
 			std::cout << "---------------------------------------------------------------------------" << std::endl;
 			std::cout << "Please type the \"ACTOR\" attribute and press enter: ";
 			std::getline(std::cin >> std::ws, conversation.actor);

 			std::cout << "---------------------------------------------------------------------------" << std::endl;
 			std::cout << "|                         REVIEW CONVERSATION                             |" << std::endl;
 			std::cout << "---------------------------------------------------------------------------" << std::endl;
 			std::cout << conversation.tag(0, true) << std::endl;

 			std::cout << "Does this looks good? Y to continue, N to recreate: ";
 			std::cin >> satisfied;

 			system("cls");
 		}

 		std::cout << "\"CONVERSATION\" created!";
 		std::cout << "\n Proceeding to create \"PAGE\" objects..." << std::endl;

 		system("pause");

 		pageCreation(conversation);

 		conversation.page = &_pagesList;
 	}

 	void baseFileCreation() {
 		// Create BaseFile
 		char satisfied{};
 		std::string nameSpace;
 		std::string include;
 		Conversation _conversation;

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

 		_baseFile.nameSpace = nameSpace;
 		_baseFile.include = include;

 		std::cout << "\"BASEFILE\" created!";
 		std::cout << "\n Proceeding to create \"CONVERSATION\" object..." << std::endl;

 		system("pause");

 		conversationCreation(_conversation);

 		_baseFile.conversation = &_conversation;
 	}

 	void dialogueCreation() {
 		baseFileCreation();
 	}
 }