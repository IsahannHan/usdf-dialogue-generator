#include <string>
#include <iostream>
#include <sstream>

#include "BaseFile.h"
#include "FileCreationHelper.cpp"

 namespace FileCreation {

 	void choiceCreation(Page& page) {
 		char satisfied{};
 		char anotherOne{};

 		std::list<Choice> _choicesList;

 		while (toupper(anotherOne) != 'N') {
 		    Choice _choice;

 			while (toupper(satisfied) != 'Y') {
 				std::cout << "---------------------------------------------------------------------------" << std::endl;
 				std::cout << "|                         CREATING CHOICE                                 |" << std::endl;
 				std::cout << "                        FOR PAGE " << page.name << "                       " << std::endl;
 				std::cout << "---------------------------------------------------------------------------" << std::endl;

                //ElementTypes::BOOL

 				std::cout << "Please type the \"TEXT\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"DISPLAYCOST\" attribute and press enter (true/false): ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"YESMESSAGE\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"NOMESSAGE\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"LOG\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"GIVEITEM\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"SPECIAL\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);
 				std::cout << "Please type the \"ARG0\" attribute and press enter: ";
 				std::getline(std::cin >> std::ws, _choice.text);
                std::cout << "Please type the \"ARG1\" attribute and press enter: ";
                std::getline(std::cin >> std::ws, _choice.text);
                std::cout << "Please type the \"ARG2\" attribute and press enter: ";
                std::getline(std::cin >> std::ws, _choice.text);
                std::cout << "Please type the \"ARG3\" attribute and press enter: ";
                std::getline(std::cin >> std::ws, _choice.text);
                std::cout << "Please type the \"ARG4\" attribute and press enter: ";
                std::getline(std::cin >> std::ws, _choice.text);
                std::cout << "Please type the \"NEXTPAGE\" attribute and press enter: ";
                std::getline(std::cin >> std::ws, _choice.text);
                std::cout << "Please type the \"CLOSEDIALOG\" attribute and press enter: ";
                std::getline(std::cin >> std::ws, _choice.text);


                std::cout << "Does this looks good? Y to continue, N to recreate: ";
                std::cin >> satisfied;

                system("cls");
 			}

            // Add page element

            _choicesList.push_back(_choice);

            std::cout << "\"CHOICE\" element #" << _choicesList.size() << " fully created!";
            std::cout << "Do you wish to create another \"CHOICE\"? Y for yes, N for no: ";
 		}


        page.choice = &_choicesList;
 	}

 	void ifItemCreation(Page& page) {
 		char satisfied{};
 		Ifitem _ifItem;

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

        std::cout << "\"IFITEM\" element linked!";

 		system("pause");
 	}

 	void pageCreation(Conversation& conversation) {
 		// Create MULTIPLE pages
        std::list<Page> _pagesList;
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

 		while (toupper(anotherOne) != 'N') {
            Page _page;

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

 			std::cout << "Base \"PAGE\" element #" << _pagesList.size() << " created!";

 			std::cout << "\n Proceeding to create \"IFITEM\" object for this PAGE..." << std::endl;

 			system("pause");

 			ifItemCreation(_page);

 			system("cls");

 			std::cout << "\n Proceeding to create multiple \"CHOICE\" objects for this PAGE..." << std::endl;

 			system("pause");

 			choiceCreation(_page);

            system("cls");

            // Add page element

            _pagesList.push_back(_page);

 			std::cout << "\"PAGE\" element #" << _pagesList.size() << " fully created!";
 			std::cout << "Do you wish to create another \"PAGE\"? Y for yes, N for no: ";
 		}

 		std::cout << "Pages created!";

 		system("pause");

        conversation.page = &_pagesList;
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
 	}

 	void dialogueCreation() {
 		baseFileCreation();
 	}
 }