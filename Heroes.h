#pragma once

#include <iostream>
#include <map>
#include <string>

#include "tinyxml2\tinyxml2.h"


class Heroes{
public:
	Heroes(std::string XMLPath);
	std::string getHero(int i){return hero[std::to_string((_Longlong)i)];};
	std::string getHero(std::string s){return hero[s];};
private:
	std::map<std::string,std::string> hero;
	void getHeroes(tinyxml2::XMLNode *n);
};