#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	vector<string> paths;
	
	paths.push_back("helll");
	paths.push_back("world");
	
	for(auto path : paths){
		cout<<path<<endl;
	}
}
