#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include<bits/stdc++.h>

using namespace std;

long long poly_hash(string name,int buckets){
	long long x = 263;
	long long p = 1000000007;
	long long hash = 0;
	for(int i = 0 ; i < name.size() ; i++){
		hash = hash + (int)name[i]*pow(x,i);
	}
	hash = hash%p;
	return hash%buckets;
}

int main(){
	int buckets;
	cin >> buckets;
	int n;
	cin >> n;
	list<string> hash_table[buckets];
	for(int i = 0 ; i < n ; i++){
		string type;
		string str;
		cin >> type >> str;
		if(type == "check"){
			stringstream ss(str);
			int m;
			ss >> m;
			if(hash_table[m].empty()){
				cout << endl;
			}
			else{
			list<string>::iterator it;
			bool flag = true;
			for(it=hash_table[m].begin() ;it!=hash_table[m].end();it++){
				if(flag){
					cout << *it;
					flag = false;
				}
				else{
					cout << " " << *it;
				}
			}
			cout << endl;
			}	
		}
		else if(type == "add"){
			int m = poly_hash(str,buckets);
			list<string>::iterator it;
			if(hash_table[m].empty()){
				hash_table[m].push_front(str);
			}
			else{
				if(hash_table[m].end() == find(hash_table[m].begin(),hash_table[m].end(),str)){
					hash_table[m].push_front(str);
				}
			}	
		}
		else if(type == "find"){
			int m = poly_hash(str,buckets);
			list<string>::iterator it = hash_table[m].end();
			if(it != find(hash_table[m].begin(),hash_table[m].end(),str)){
				cout << "yes" << endl;
			}
			else{
				cout << "no" << endl;
			}
		}
		else if(type == "del"){
			int m = poly_hash(str,buckets);
			list<string>::iterator it;
			it = find(hash_table[m].begin(),hash_table[m].end(),str);
			if(it != hash_table[m].end()){
				hash_table[m].erase(it);
			}
		}
		
	}
	return 0 ;
}
