#ifndef KOTORI_h
#define KOTORI_H
#include<iostream>
#include<map>
#include<cstring>
class Collection{
	std::string filename;
	std::multimap <std::string,std::string> collection;
	public:
		Collection(const std::string& f);
		std::string getbykey(std::string key);
		void update(std::string ask,std::string answer);
};
class Reply{
	public:
		void reply(std::string words,Collection* c);
};
class Learn{
	public:
		void learn(std::string words,Collection* c);
};
class Kotori{
	Reply* r;
	Learn* l;
	Collection* collection;
	public:
		Kotori(Collection* c,Reply* reply,Learn* learn){
			collection = c;
			r = reply;
			l = learn;
			std::cout<<"Begins"<<std::endl;
		}
	public:
		void reaction();
};
#endif//KOTORI_H
