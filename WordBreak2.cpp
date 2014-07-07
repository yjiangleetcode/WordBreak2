// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

void buildResult(vector<string> &out, vector<vector<string> > &sens, int cur, vector<string> &curSen)
{
	if (cur==0){
		string temp;
		for (int i=curSen.size()-1; i>=0; --i){
			temp+=curSen[i];
			if(i!=0){
				temp+=" ";
			}
		}
		out.push_back(temp);
		return;
	}
	for (int i=0; i<sens[cur].size(); ++i){
		curSen.push_back(sens[cur][i]);
		buildResult(out, sens, cur - sens[cur][i].length(), curSen);
		curSen.pop_back();
	}
}
vector<string> wordBreak(string s, unordered_set<string> &dict)
{
	vector<string> temp;
	vector<vector<string>> sens(s.length()+1, temp);
	sens[0].push_back("a");
	cout<<sens[0][0]<<endl;
	cout<<sens.size()<<endl;
	for (int i=0; i<s.length(); ++i){
		if (!sens.size()){
			continue;
		}
		for (string word : dict){
			if (s.substr(i,word.length())==word){
				sens[i+word.length()].push_back(word);
			}
		}
	}
	vector<string> out;
	vector<string> curSen;
	if (sens[s.length()].size()){
		buildResult(out, sens, s.length(),curSen);
	}
	return out;
}



int _tmain(int argc, _TCHAR* argv[])
{
	string s = "catsanddog";
	unordered_set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	vector<string> out = wordBreak(s,dict);
	for ( string word : out){
		std::cout << "'"<< word << "'"<< "	";
	}
	return 0;
}

