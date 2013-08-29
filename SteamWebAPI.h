#pragma once

#include <iostream>
#include <string>

#include <Windows.h>
#include <WinInet.h>

class SteamWebAPI{
public:
	SteamWebAPI(std::string k, std::string id, int t=10){ACCOUNT_ID=id;API_KEY=k;threshhold=t;};

	std::string getMatchHistory(std::string numMatches);
	std::string getMatchDetails(std::string matchID);
	std::string getHeroes();

	bool pastThreshold(HANDLE);
private:
	std::string ACCOUNT_ID;
	std::string API_KEY;
	int threshhold;
	
	std::wstring s2ws(std::string s){return std::wstring(s.begin(), s.end());}
	std::string getSteamXML(std::string URL, std::string filename);
};