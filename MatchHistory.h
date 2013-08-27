#pragma once

#include <string>
#include <vector>

#include "SteamWebAPI.h"
#include "tinyxml2\tinyxml2.h"

class MatchHistory{
public:
	MatchHistory(std::string);
	std::string getMatch(int);
private:
	std::vector<std::string> matchIDs;
	void pullMatches(tinyxml2::XMLNode *n);
};