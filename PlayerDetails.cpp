#include "PlayerDetails.h"


PlayerDetails::PlayerDetails(tinyxml2::XMLNode *n){
	getDetails(n->FirstChild());
}

void PlayerDetails::getDetails(tinyxml2::XMLNode *n){
	if(n==0)
		return;
	if(std::string(n->ToElement()->Name()) == "ability_upgrades")
		return getDetails(n->NextSibling());
	else
		details[n->ToElement()->Name()] += n->ToElement()->GetText();
	return getDetails(n->NextSibling());
}

PlayerDetails::~PlayerDetails(void){
}