#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include <Windows.h>
#include <WinInet.h>

class SteamWebAPI{
public:
	SteamWebAPI(std::string k, std::string id){ACCOUNT_ID=id;API_KEY=k;};

	std::string getMatchHistory(std::string numMatches);
	std::string getMatchDetails(std::string matchID);
	std::string getHeroes();
private:
	std::string ACCOUNT_ID;
	std::string API_KEY;
	
	std::wstring s2ws(std::string s){return std::wstring(s.begin(), s.end());}
	std::string getSteamXML(std::string URL, std::string filename);
};