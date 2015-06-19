#include"kotori.h"
#include<iostream>
#include<map>
#include<cstring>
using namespace std;
/*For system result, the code is written in English*/
int main(){
	string filename;
	cin >> filename;
	Collection collection(filename);
	Collection* c = &collection;
	Reply* r = new Reply;
	Learn* l = new Learn;
	Kotori kotori(c,r,l);
	getchar();
	while(1){
		kotori.reaction();
	}
	return 0;
}
