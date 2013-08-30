#include "MatchDetails.h"

MatchDetails::MatchDetails(std::string XMLPath){
	tinyxml2::XMLDocument match_details;
	match_details.LoadFile(XMLPath.c_str());
	getDetails(match_details.FirstChildElement("result")->FirstChildElement("radiant_win"));
}


void MatchDetails::getDetails(tinyxml2::XMLNode *n){
	if(n == 0)
		return;
	else{
		details[n->ToElement()->Name()] += n->ToElement()->GetText();
		return getDetails(n->NextSibling());
	}
}
