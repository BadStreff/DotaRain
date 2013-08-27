#include "SteamWebAPI.h"

std::string SteamWebAPI::getMatchHistory(std::string numMatches){
	//https://api.steampowered.com/IDOTA2Match_570/GetMatchHistory/V001/?format=XML&key=A2ABB033484CA4908799677CCC313B83&account_id=31856012
	std::string url = std::string("https://api.steampowered.com/IDOTA2Match_570/GetMatchHistory/V001/?format=XML");
	url.append(std::string("&key=").append(API_KEY));
	url.append(std::string("&account_id=").append(ACCOUNT_ID));
	url.append(std::string("&matches_requested=").append(numMatches));
	return getSteamXML(url, "DOTARAIN-MatchHistory.xml");
}

std::string SteamWebAPI::getMatchDetails(std::string matchID){
	std::string url = std::string("https://api.steampowered.com/IDOTA2Match_570/GetMatchDetails/V001/?format=XML");
	url.append(std::string("&key=").append(API_KEY));
	url.append(std::string("&match_id=").append(matchID));
	return getSteamXML(url, "DOTARAIN-MatchDetails");
}

std::string SteamWebAPI::getHeroes(){
	std::string url = std::string("https://api.steampowered.com/IEconDOTA2_570/GetHeroes/v0001/?format=XML");
	url.append(std::string("&key=").append(API_KEY));
	url.append("&language=en_us");
	return getSteamXML(url, "DOTARAIN-Heroes.xml");
}


/*Returns full path to file.
TODO: Check if the file is older than 5-10 minutes, if not just return file path
*/
std::string SteamWebAPI::getSteamXML(std::string URL, std::string filename){
	std::string path = std::string("C:\\Windows\\Temp\\").append(filename);
	
	//checking will go here

	HANDLE file = CreateFile(s2ws(path).c_str(),(GENERIC_READ | GENERIC_WRITE), 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	HINTERNET hOpen = InternetOpen(L"DotaRain", NULL, NULL, NULL, NULL);
	HINTERNET hURL = InternetOpenUrl(hOpen, s2ws(URL).c_str(), NULL, NULL, INTERNET_FLAG_RELOAD | INTERNET_FLAG_DONT_CACHE, NULL);


	DWORD dwBytesRead =0;
	DWORD dwBytesWritten = 0;
	do {
		char* lpBuffer = new char[2000];
		ZeroMemory(lpBuffer, 2000);
		InternetReadFile(hURL, (LPVOID)lpBuffer, 2000, &dwBytesRead);
		WriteFile(file, (LPVOID)lpBuffer, dwBytesRead, &dwBytesWritten, NULL);
		//std::cout << lpBuffer << std::endl;
		delete[] lpBuffer;
		lpBuffer = NULL;
	} while (dwBytesRead);

	InternetCloseHandle(hURL);
	InternetCloseHandle(hOpen);
	CloseHandle(file);
	return path;
}