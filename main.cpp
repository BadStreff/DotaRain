#include <Windows.h>
#include "API/RainmeterAPI.h"
#include <string>

//http://dev.dota2.com/showthread.php?t=47115 <- For info on the webAPI

struct Measure{
  std::wstring playerName;
	std::wstring heroName;
	int matchID;
	int duration;

	int *KDA;
	int *items;

	int GPM;
	int level;
	int gold;
	int last_hits;
	int denies;
	int xpPerMinute;
	int goldSpent;
	int totalDamge;
	int totalHealing;

	bool win;
	Measure() {}
};

PLUGIN_EXPORT void Initialize(void** data, void* rm){
	Measure* measure = new Measure;
	*data = measure;

	measure->playerName.assign(L"BadStreff");
	measure->heroName.assign(L"Axe");
	measure->matchID = 000001;
	measure->win = true;
}

PLUGIN_EXPORT void Reload(void* data, void* rm, double* maxValue){
	Measure* measure = (Measure*)data;
}

PLUGIN_EXPORT double Update(void* data){
	Measure* measure = (Measure*)data;
	return 0.0;
}

PLUGIN_EXPORT LPCWSTR GetString(void* data){
	Measure* measure = (Measure*)data;
	return L"";
}

//PLUGIN_EXPORT void ExecuteBang(void* data, LPCWSTR args)
//{
//	Measure* measure = (Measure*)data;
//}

PLUGIN_EXPORT void Finalize(void* data){
	Measure* measure = (Measure*)data;
	delete measure;
}
