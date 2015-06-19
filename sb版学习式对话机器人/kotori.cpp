#include"kotori.h"
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<map>
#include<ctime>
using namespace std;
Collection::Collection(const std::string& f){
	filename = f;
	ifstream fin(f.c_str());
	string temp[100000];
	string temp1,temp2;
	int i = 0;
	while(fin>>temp[i]){
		i++;
	}
	for(int j = 0;j < i;j++){
		if(j%2 == 0){
			temp1 = temp[j];
		}else if(j%2 == 1){
			temp2 = temp[j];
			collection.insert(pair<string,string>(temp1,temp2));
		}
	} 
	fin.close();
}
string Collection::getbykey(string key){
	multimap <string,string>::iterator it;
	int num = collection.count(key);
	it = collection.find(key);
	int ram = 0;
	srand((unsigned)time(NULL));
	if(num == 0){
		return "";
	}
	else{
		ram = rand()%num;
		for(int i = 0;i < num;i++){
		if(i == ram){
			return (*it).second;
		}
			it++;
		}
	}
}
void Collection::update(string ask,string answer){
	collection.insert(pair<string,string>(ask,answer));
	ofstream fout;
	fout.open(filename.c_str(),ios::app);
	string output = ask+" "+answer+"\n";
	fout<<output;
	fout.close();
}
void Reply::reply(string words,Collection* c){
	if(c->getbykey(words) == ""){
		cout<<"No Reply"<<endl;
	}else{
		cout<<c->getbykey(words)<<endl;
	}
}
void Learn::learn(string words,Collection* c){
	string ask = "",answer = "";
	int firstspace = 0,secondspace = 0;
	int l = words.length();
	for(int i = 0;i < l;i++){
		if(words[i] == ' '){
			if(firstspace == 0){
				firstspace = i;
			}
			else{
				secondspace = i;
				break; 
			} 
		}
	}
	for(int i = firstspace + 1;i < secondspace;i++){
		ask += words[i];
	}
	for(int i = secondspace + 1;i < l;i++){
		answer += words[i];
	} 
	c->update(ask,answer);
	cout<<"Learned Successfully!"<<endl;
}
void Kotori::reaction(){
	string words;
	getline(cin,words,'\n');
	if(words[0] == '@'){
		l->learn(words,collection);
	}
	else{
		r->reply(words,collection);
	}
}
