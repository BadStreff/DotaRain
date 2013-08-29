#include "MatchHistory.h"

MatchHistory::MatchHistory(std::string file_path){
	tinyxml2::XMLDocument match_history;
	match_history.LoadFile(file_path.c_str());
	pullMatches(match_history.FirstChildElement("result")->FirstChildElement("matches")->FirstChildElement("match"));
}
std::string MatchHistory::getMatch(int n){
	if((unsigned int)n >= matchIDs.size())
		return 0;
	return matchIDs[n];
}

void MatchHistory::pullMatches(tinyxml2::XMLNode *n){
	if(n == 0)
		return;
	else{
		matchIDs.push_back(n->FirstChildElement("match_id")->GetText());
		pullMatches(n->NextSibling());
	}
}
