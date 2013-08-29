#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <Windows.h>

#include "tinyxml2\tinyxml2.h"
#include "SteamWebAPI.h"

class MatchDetails{
public:
	MatchDetails(std::string XMLPath);
private:
	std::vector< std::map<std::string,std::string> > playerDetails; //refactor into an object
	std::map<std::string,std::string> matchResults;
};