#include <fstream>
#include <iostream>
#include <string>

#include "FileCreation.h"

std::ofstream of_file;

 void intro() {
 	std::cout << "---------------------------------------------------------------------------" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|                     USDF DIALOGUE GENERATOR - v1.0.0                    |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|           Created by Isahann Hanacleto (github.com/IsahannHan)          |" << std::endl;
 	std::cout << "|        https://github.com/IsahannHan/usdf-zsdf-dialogue-generator       |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "---------------------------------------------------------------------------" << std::endl;
 	std::cout << "---------------------------------------------------------------------------" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|                          BASIC INFORMATION                              |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|          This program currently generates dialogues using the           |" << std::endl;
 	std::cout << "|          Universal Strife Dialog Format Specification (USDF).           |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|            github.com/rheit/zdoom/blob/master/specs/usdf.txt            |" << std::endl;
 	std::cout << "|              zdoom.org/wiki/Universal_Strife_Dialog_Format              |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "---------------------------------------------------------------------------" << std::endl;
 	system("pause");
 }

 void dialogueFields() {
 	std::cout << "---------------------------------------------------------------------------" << std::endl;
 	std::cout << "|                          DIALOGUE CREATION                              |" << std::endl;
 	std::cout << "---------------------------------------------------------------------------" << std::endl;
 	std::cout << "---------------------------------------------------------------------------" << std::endl;
 	std::cout << "|                              FIELDS                                     |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    CONVERSATION                                                         |" << std::endl;
 	std::cout << "|        -> Tag: 'conversation'                                           |" << std::endl;
 	std::cout << "|        -> Type: Conversation (Object with attributes)                   |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Attributes: ACTOR, PAGE                                       |" << std::endl;
 	std::cout << "|        -> Description: Starts a dialog.                                 |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    ACTOR                                                                |" << std::endl;
 	std::cout << "|        -> Tag: 'actor'                                                  |" << std::endl;
 	std::cout << "|        -> Type: Integer (Number)                                        |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: mobj for this conversation's actor.              |" << std::endl;
 	std::cout << "|                        If previously used, this will override           |" << std::endl;
 	std::cout << "|                        the previous conversation.                       |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    PAGE                                                                 |" << std::endl;
 	std::cout << "|        -> Tag: 'page'                                                   |" << std::endl;
 	std::cout << "|        -> Type: Page (Object with attributes)                           |" << std::endl;
 	std::cout << "|        -> Multiple: True                                                |" << std::endl;
 	std::cout << "|        -> Attributes: NAME, PANEL, VOICE, DIALOG DROP, LINK, IFITEM     |" << std::endl;
 	std::cout << "|                       CHOICE                                            |" << std::endl;
 	std::cout << "|        -> Description: Starts a new page.                               |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    NAME                                                                 |" << std::endl;
 	std::cout << "|        -> Tag: 'name'                                                   |" << std::endl;
 	std::cout << "|        -> Type: String (Text)                                           |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: Name that goes in the upper left hand corner.    |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    PANEL                                                                |" << std::endl;
 	std::cout << "|        -> Tag: 'panel'                                                  |" << std::endl;
 	std::cout << "|        -> Type: String (Text)                                           |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: Name of lump to render as the background.        |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    VOICE                                                                |" << std::endl;
 	std::cout << "|        -> Tag: 'voice'                                                  |" << std::endl;
 	std::cout << "|        -> Type: String (Text)                                           |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: Narration sound lump.                            |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    DIALOG                                                               |" << std::endl;
 	std::cout << "|        -> Tag: 'dialog'                                                 |" << std::endl;
 	std::cout << "|        -> Type: String (Text)                                           |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: Dialog of the page.                              |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    DROP                                                                 |" << std::endl;
 	std::cout << "|        -> Tag: 'drop'                                                   |" << std::endl;
 	std::cout << "|        -> Type: Integer (Number)                                        |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: mobj for the object to drop if the actor is      |" << std::endl;
 	std::cout << "|                        killed.                                          |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    LINK                                                                 |" << std::endl;
 	std::cout << "|        -> Tag: 'link'                                                   |" << std::endl;
 	std::cout << "|        -> Type: Integer (Number)                                        |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: Page to jump to if all ifitem conditions are     |" << std::endl;
 	std::cout << "|                        satisfied.                                       |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    IFITEM                                                               |" << std::endl;
 	std::cout << "|        -> Tag: 'ifitem'                                                 |" << std::endl;
 	std::cout << "|        -> Type: Ifitem (Object with attributes)                         |" << std::endl;
 	std::cout << "|        -> Multiple: True                                                |" << std::endl;
 	std::cout << "|        -> Attributes: ITEM, AMOUNT                                      |" << std::endl;
 	std::cout << "|        -> Description: Jumps to the specified page if the player        |" << std::endl;
 	std::cout << "|                        has the specified amount or more of item         |" << std::endl;
 	std::cout << "|                        in their inventory. This can be repeated as many |" << std::endl;
 	std::cout << "|                        times as the author wants, all conditions        |" << std::endl;
 	std::cout << "|                        must be met for the jump to occur.               |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    ITEM (Inside IFITEM)                                                 |" << std::endl;
 	std::cout << "|        -> Tag: 'item'                                                   |" << std::endl;
 	std::cout << "|        -> Type: Integer (Number)                                        |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: mobj of item to check.                           |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    AMOUNT (Inside IFITEM)                                               |" << std::endl;
 	std::cout << "|        -> Tag: 'amount'                                                 |" << std::endl;
 	std::cout << "|        -> Type: Integer (Number)                                        |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: Amount required to be in inventory.              |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    CHOICE                                                               |" << std::endl;
 	std::cout << "|        -> Tag: 'choice'                                                 |" << std::endl;
 	std::cout << "|        -> Type: Choice (Object with attributes)                         |" << std::endl;
 	std::cout << "|        -> Multiple: True                                                |" << std::endl;
 	std::cout << "|        -> Attributes: TEXT, COST, DISPLAYCOST, YESMESSAGE, NOMESSAGE,   |" << std::endl;
 	std::cout << "|                       LOG, GIVEITEM, SPECIAL, ARG0, ARG1, ARG2, ARG3,   |" << std::endl;
 	std::cout << "|                       ARG4, NEXTPAGE, CLOSEDIALOG                       |" << std::endl;
 	std::cout << "|        -> Description: Each dialog choices. Choices shall be            |" << std::endl;
 	std::cout << "|                        automatically numbered.                          |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    TEXT                                                                 |" << std::endl;
 	std::cout << "|        -> Tag: 'text'                                                   |" << std::endl;
 	std::cout << "|        -> Type: String (Text)                                           |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: Name of the choice.                              |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    COST                                                                 |" << std::endl;
 	std::cout << "|        -> Tag: 'cost'                                                   |" << std::endl;
 	std::cout << "|        -> Type: Cost (Object with attributes)                           |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Attributes: ITEM, AMOUNT                                      |" << std::endl;
 	std::cout << "|        -> Description: The amount of an item needed to successfully     |" << std::endl;
 	std::cout << "|                        pick this option. This can be repeated, but      |" << std::endl;
 	std::cout << "|                        only the first will be shown (provided           |" << std::endl;
 	std::cout << "|                        displaycost is true).  All costs must be         |" << std::endl;
 	std::cout << "|                        satisfied for success.                           |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    ITEM (Inside COST)                                                   |" << std::endl;
 	std::cout << "|        -> Tag: 'item'                                                   |" << std::endl;
 	std::cout << "|        -> Type: Integer (Number)                                        |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: Item that is required for this option.           |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    AMOUNT (Inside COST)                                                 |" << std::endl;
 	std::cout << "|        -> Tag: 'amount'                                                 |" << std::endl;
 	std::cout << "|        -> Type: Integer (Number)                                        |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: Minimum amount of the item needed.               |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    DISPLAYCOST                                                          |" << std::endl;
 	std::cout << "|        -> Tag: 'displaycost'                                            |" << std::endl;
 	std::cout << "|        -> Type: Boolean (True or False)                                 |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: Whether the cost should be displayed with        |" << std::endl;
 	std::cout << "|                        the option. If no cost is specified this should  |" << std::endl;
 	std::cout << "|                        be ignored.                                      |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    YESMESSAGE                                                           |" << std::endl;
 	std::cout << "|        -> Tag: 'yesmessage'                                             |" << std::endl;
 	std::cout << "|        -> Type: String (Text)                                           |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: Text to add to console when choice is accepted.  |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    NOMESSAGE                                                            |" << std::endl;
 	std::cout << "|        -> Tag: 'nomessage'                                              |" << std::endl;
 	std::cout << "|        -> Type: String (Text)                                           |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: Text to add to console when choice is denied.    |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    LOG                                                                  |" << std::endl;
 	std::cout << "|        -> Tag: 'log'                                                    |" << std::endl;
 	std::cout << "|        -> Type: String (Text)                                           |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: LOG entry to use on success.                     |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    GIVEITEM                                                             |" << std::endl;
 	std::cout << "|        -> Tag: 'giveitem'                                               |" << std::endl;
 	std::cout << "|        -> Type: Integer (Number)                                        |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: Gives the specified item upon success.           |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|     The following are the same as the special for linedefs in UDMF.     |" << std::endl;
 	std::cout << "|     They are executed on success.                                       |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    SPECIAL                                                              |" << std::endl;
 	std::cout << "|        -> Tag: 'special'                                                |" << std::endl;
 	std::cout << "|        -> Type: Integer (Number)                                        |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    ARG0 - ARG4                                                          |" << std::endl;
 	std::cout << "|        -> Tag: 'arg0 - arg4'                                            |" << std::endl;
 	std::cout << "|        -> Type: Integer (Number)                                        |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    NEXTPAGE                                                             |" << std::endl;
 	std::cout << "|        -> Tag: 'nextpage'                                               |" << std::endl;
 	std::cout << "|        -> Type: Integer (Number)                                        |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: Sets the next page.                              |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "|    CLOSEDIALOG                                                          |" << std::endl;
 	std::cout << "|        -> Tag: 'closedialog'                                            |" << std::endl;
 	std::cout << "|        -> Type: Boolean (True or False)                                 |" << std::endl;
 	std::cout << "|        -> Multiple: False                                               |" << std::endl;
 	std::cout << "|        -> Description: Should the dialog be closed upon selecting this  |" << std::endl;
 	std::cout << "|                        choice?                                          |" << std::endl;
 	std::cout << "|                                                                         |" << std::endl;
 	std::cout << "---------------------------------------------------------------------------" << std::endl;
 	system("pause");
 }

 void menu() {
 	int choice = -1;

 	while (choice != 0) {

 		system("cls");

 		std::cout << "---------------------------------------------------------------------------" << std::endl;
 		std::cout << "|                                                                         |" << std::endl;
 		std::cout << "|                                MENU                                     |" << std::endl;
 		std::cout << "|                                                                         |" << std::endl;
 		std::cout << "|  Type an option below and press ENTER:                                  |" << std::endl;
 		std::cout << "|      1 - Create new dialogue                                            |" << std::endl;
 		std::cout << "|      2 - Show USDF fields                                               |" << std::endl;
 		std::cout << "|      3 - About                                                          |" << std::endl;
 		std::cout << "|      0 - Exit                                                           |" << std::endl;
 		std::cout << "|                                                                         |" << std::endl;
 		std::cout << "---------------------------------------------------------------------------" << std::endl;

 		std::cin >> choice;

 		system("cls");

 		switch (choice) {
 		case 0:
 			std::cout << "---------------------------------------------------------------------------" << std::endl;
 			std::cout << "|                   Thanks for using this program!                        |" << std::endl;
 			std::cout << "---------------------------------------------------------------------------" << std::endl;
 			break;
 		case 1:
 			FileCreation::dialogueCreation();
 			break;
 		case 2:
 			dialogueFields();
 			break;
 		case 3:
 			intro();
 			break;
 		default:
 			std::cout << "---------------------------------------------------------------------------" << std::endl;
 			std::cout << "|                          INVALID CHOICE                                 |" << std::endl;
 			std::cout << "|                                                                         |" << std::endl;
 			std::cout << "|            Please pick any avaliable options from the menu.             |" << std::endl;
 			std::cout << "---------------------------------------------------------------------------" << std::endl;
 			system("pause");
 			break;
 		}
 	}
 }

int main(void)
{
	intro();
	menu();

	//std::list<Choice> choices;
	//std::list<Page> pages;

	//Cost cost(5, 10);
	//Ifitem ifitem(2, 993);

	//Choice choice("Name of the choice", &cost, true, "Yes message.", "No message", "Yoooooo", 5, 2, 1111, 22, 5, 7, 3, 99, false);
	//Choice choice1("WEEE HOO", &cost, true, "Yes.", "sage", "num sei", 5, 2, 3, 44, 5, 7, 8, 99, true);
	//Choice choice2("Name of the choiceSSSSSSSS", &cost, true, "SIMmessage.", "No", "Yoooooo", 5, 2, 111, 4, 5, 7, 8, 66, false);

	//choices.push_back(choice);
	//choices.push_back(choice1);
	//choices.push_back(choice2);

	//Page page("PAGE 1", "Panel test", "Voice oooof", "Test dialog", 1, 2, &ifitem, &choices);
	//Page page1("PAGE 2222", "SAM CEHOICES test", "Voice urgh", "Test testteste", 4, 6666, &ifitem, &choices);

	//pages.push_back(page);
	//pages.push_back(page1);

	//Conversation conversation("ednaldo pereira", &pages);

	//of_file.open("generated_dialogue.txt", std::ios::out);
	//of_file << conversation.tag(0, false) << std::endl;
	////getline(cin, _namespace);

	std::cout << "Press any key to continue" << std::endl;
	std::cin.get();

	return 0;
}
