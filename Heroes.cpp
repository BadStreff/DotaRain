#include "Heroes.h"

Heroes::Heroes(std::string XMLPath){
	tinyxml2::XMLDocument hero_details;
	hero_details.LoadFile(XMLPath.c_str());

	tinyxml2::XMLNode *h = hero_details.FirstChildElement("result")->FirstChildElement("heroes")->FirstChildElement("hero");
	getHeroes(h);
}

void Heroes::getHeroes(tinyxml2::XMLNode *n){
	if(n == 0)
		return;
	else{
		//pretty hackish way of doing this
		//required to format them this way for images
		std::string snip = n->FirstChildElement("name")->GetText();
		hero[n->FirstChildElement("id")->GetText()] +=  std::string(snip.begin()+14,snip.end());
		return getHeroes(n->NextSibling());
	}
}