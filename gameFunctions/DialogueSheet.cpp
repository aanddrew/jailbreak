#include "DialogueSheet.h"

#include <iostream>

DialogueSheet::DialogueSheet(std::string fileName)
{
	std::ifstream inFile(fileName);
	std::string temp;
	std::vector<std::string> currentLines;
	while(std::getline(inFile, temp))
	{
		if (temp == "###")
		{
			table.push_back(currentLines);
			currentLines.clear();
		}
		else
		{
			currentLines.push_back(temp);
		}
	}
}
std::vector<std::vector<std::string>> DialogueSheet::getTable()
{
	return table;
}
std::vector<std::string> DialogueSheet::getRandLines()
{
	return table[rand()%table.size()];
}