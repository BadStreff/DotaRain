#include "MatchHistory.h"

MatchHistory::MatchHistory(std::string file_path){
	tinyxml2::XMLDocument match_history;
	match_history.LoadFile(file_path.c_str());
	match_history.Print();
}
std::string MatchHistory::getMatch(int n){
	return matchIDs[n];
}

void MatchHistory::pullMatches(tinyxml2::XMLNode *n){
}
