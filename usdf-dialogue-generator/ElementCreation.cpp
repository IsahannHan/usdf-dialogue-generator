#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "ElementCreation.h"
#include "ElementCreationHelper.h"

BaseFile ElementCreation::baseFileCreation() {
	BaseFile _baseFile = BaseFile();

	do {
		system("cls");

		ElementCreationHelper::creatingElementTitle(_baseFile.title);

		_baseFile.nameSpace = ElementCreationHelper::createElementString("NAMESPACE");
		_baseFile.include = ElementCreationHelper::createElementString("INCLUDE");

	} while (!ElementCreationHelper::satisfiedWithElement(_baseFile.title, _baseFile.tag(0, true)));

	conversationCreation(_baseFile); // Next: CONVERSATION

	return _baseFile;
}

void ElementCreation::conversationCreation(BaseFile& baseFile) {
	// Create conversation, and link it to the current baseFile

	Conversation _conversation = Conversation();

	do {
		system("cls");

		ElementCreationHelper::creatingElementTitle(_conversation.title);

		_conversation.actor = ElementCreationHelper::createElementString("ACTOR");

	} while (!ElementCreationHelper::satisfiedWithElement(_conversation.title, _conversation.tag(0, true)));

	pageCreation(_conversation); // Next: PAGE

	// Link to parent

	baseFile.conversation = &_conversation;
}

void ElementCreation::pageCreation(Conversation& conversation) {
	// Create pages, and link it to the current conversation

	std::list<Page> _pagesList;
	Page _page;

	do {
		_page = Page();

		do {
			system("cls");

			ElementCreationHelper::creatingElementTitle(_page.title);

			_page.name = ElementCreationHelper::createElementString("NAME");
			_page.panel = ElementCreationHelper::createElementString("PANEL");
			_page.voice = ElementCreationHelper::createElementString("VOICE");
			_page.dialog = ElementCreationHelper::createElementString("DIALOG");
			_page.drop = ElementCreationHelper::createElementInteger("DROP");
			_page.link = ElementCreationHelper::createElementInteger("LINK");

		} while (!ElementCreationHelper::satisfiedWithElement(_page.title, _page.tag(0, true)));


		ifItemCreation(_page);
		choiceCreation(_page); // Next element: IFITEM and CHOICE 

		_pagesList.push_back(_page);

	} while (ElementCreationHelper::anotherElementRequested(_page.title, _pagesList.size()));

	conversation.page = &_pagesList;
}

void ElementCreation::ifItemCreation(Page& page) {
	// Create ifitem, and link it to the current page

	Ifitem _ifItem = Ifitem();

	do {
		system("cls");

		ElementCreationHelper::creatingElementTitle(_ifItem.title);

		_ifItem.item = ElementCreationHelper::createElementInteger("ITEM");
		_ifItem.amount = ElementCreationHelper::createElementInteger("AMOUNT");

	} while (!ElementCreationHelper::satisfiedWithElement(_ifItem.title, _ifItem.tag(0, true)));

	page.ifitem = &_ifItem;
}

void ElementCreation::choiceCreation(Page& page) {

	std::list<Choice> _choicesList;
	Choice _choice;

	do {
		_choice = Choice();

		do {
			system("cls");

			ElementCreationHelper::creatingElementTitle(_choice.title);

			_choice.text = ElementCreationHelper::createElementString("TEXT");
			_choice.displaycost = ElementCreationHelper::createElementBoolean("DISPLAYCOST");
			_choice.yesmessage = ElementCreationHelper::createElementString("YESMESSAGE");
			_choice.nomessage = ElementCreationHelper::createElementString("NOMESSAGE");
			_choice.log = ElementCreationHelper::createElementString("LOG");
			_choice.giveitem = ElementCreationHelper::createElementInteger("GIVEITEM");
			_choice.special = ElementCreationHelper::createElementInteger("SPECIAL");
			_choice.arg0 = ElementCreationHelper::createElementInteger("ARG0");
			_choice.arg1 = ElementCreationHelper::createElementInteger("ARG1");
			_choice.arg2 = ElementCreationHelper::createElementInteger("ARG2");
			_choice.arg3 = ElementCreationHelper::createElementInteger("ARG3");
			_choice.arg4 = ElementCreationHelper::createElementInteger("ARG4");
			_choice.nextpage = ElementCreationHelper::createElementInteger("NEXTPAGE");
			_choice.closedialog = ElementCreationHelper::createElementBoolean("CLOSEDIALOG");

		} while (!ElementCreationHelper::satisfiedWithElement(_choice.title, _choice.tag(0, true)));


		costCreation(_choice); // Next element: COST 

		_choicesList.push_back(_choice);

	} while (ElementCreationHelper::anotherElementRequested(_choice.title, _choicesList.size()));

	page.choice = &_choicesList;
}

void ElementCreation::costCreation(Choice& choice) {
	// Create cost, and link it to the current choice

	Cost _cost = Cost();

	do {
		system("cls");

		ElementCreationHelper::creatingElementTitle(_cost.title);

		_cost.item = ElementCreationHelper::createElementInteger("ITEM");
		_cost.amount = ElementCreationHelper::createElementInteger("AMOUNT");

	} while (!ElementCreationHelper::satisfiedWithElement(_cost.title, _cost.tag(0, true)));

	choice.cost = &_cost;
}

// Utils

void ElementCreation::proceedNestedElementCreation(Element& currentElement) {

}

