#include "MatchDetails.h"

MatchDetails::MatchDetails(std::string XMLPath){
	tinyxml2::XMLDocument match_details;
	match_details.LoadFile(XMLPath.c_str());
	getDetails(match_details.FirstChildElement("result")->FirstChildElement("radiant_win"));

	tinyxml2::XMLNode *players = match_details.FirstChildElement("result")->FirstChildElement("players")->FirstChildElement("player");
	getPlayerDetails(players);
}

PlayerDetails MatchDetails::getPlayer(std::string id){
	for(unsigned int i = 0; i < pDetails.size(); i++)
		if(id == pDetails[i].getDetail("account_id"))
			return pDetails[i];
	return pDetails[0];
}


void MatchDetails::getDetails(tinyxml2::XMLNode *n){
	if(n == 0)
		return;
	else{
		details[n->ToElement()->Name()] += n->ToElement()->GetText();
		return getDetails(n->NextSibling());
	}
}

void MatchDetails::getPlayerDetails(tinyxml2::XMLNode *n){
	if (n==0)
		return;
	else{
		pDetails.push_back(PlayerDetails(n));
		return getPlayerDetails(n->NextSibling());
	}
}