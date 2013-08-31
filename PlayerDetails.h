#pragma once

#include <iostream>
#include <map>
#include <string>

#include "tinyxml2\tinyxml2.h"

class PlayerDetails
{
public:
	PlayerDetails(tinyxml2::XMLNode *n);
	std::string getDetail(std::string s){return details[s];};
	~PlayerDetails(void);
private:
	void getDetails(tinyxml2::XMLNode *n);
	std::map<std::string,std::string> details;
};