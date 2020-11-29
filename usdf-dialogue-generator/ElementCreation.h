#pragma once

#include "BaseFile.h"
#include "Page.h"
#include "Conversation.h"
#include "Choice.h"

class ElementCreation {
public:

	BaseFile baseFileCreation();

	void conversationCreation(BaseFile* baseFile);

	void pageCreation(Conversation* conversation);

	void ifItemCreation(Page* page);

	void choiceCreation(Page* page);

	void costCreation(Choice* choice);
};