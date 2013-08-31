#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <Windows.h>

#include "tinyxml2\tinyxml2.h"
#include "SteamWebAPI.h"
#include "PlayerDetails.h"

class MatchDetails{
public:
	MatchDetails(std::string XMLPath);
	std::string getDetail(std::string s){return details[s];}
	PlayerDetails getPlayer(int i){return pDetails[i];}
private:
	std::map<std::string,std::string> details;
	std::vector<PlayerDetails> pDetails;
	void getDetails(tinyxml2::XMLNode *n);
	void getPlayerDetails(tinyxml2::XMLNode *n);
};