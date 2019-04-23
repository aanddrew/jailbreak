#ifndef DIALOGUESHEET_H
#define DIALOGUESHEET_H

#include <string>
#include <vector>
#include <fstream>

class DialogueSheet
{
private:
	std::vector<std::vector<std::string>> table;
public:
	DialogueSheet(std::string fileName);
	std::vector<std::vector<std::string>> getTable();
	std::vector<std::string> getRandLines();
};

#endif