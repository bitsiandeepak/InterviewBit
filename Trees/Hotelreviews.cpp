#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct trieNode
{
	struct trieNode* children[26];
	bool isEndOfWord;
};

struct trieNode* getNode()
{
	struct trieNode *temp = new trieNode();
	temp->isEndOfWord = false;
	for(int i = 0; i<26;i++)
	{
		temp->children[i] = NULL;
	}
	return temp; 
}

void insert(string str, struct trieNode *head)
{
	struct trieNode *temp = head;
	for(int i = 0; i<str.size(); i++)
	{
		int index = str[i] - 'a';
		if(temp->children[index] != NULL)
			temp = temp->children[index];
		else
		{
			temp->children[index] = getNode();
			temp = head->children[index];
		}
		temp->isEndOfWord = true;
	}
}

bool search(string str, struct trieNode *head)
{
	struct trieNode *temp = head;
	for(int i = 0; i<str.size(); i++)
	{
		int index = str[i] - 'a';
		if(head->children[index] == NULL)
			return false;
		head = head->children[index];
	}
	return head!=NULL && head->isEndOfWord == true;
}

vector<string> tokenize(string str)
{
	int i=0;
	string temp;
	vector<string> res;
	while( i < str.size())
	{
		if(str[i] == '_')
		{
			res.push_back(temp);
			temp.clear();
			i++;
			continue;
		}
		temp = temp + str[i];
		i++;
	}
	if(temp.size()!=0)
		res.push_back(temp);
	return res;
}

int main() {
	// your code goes here
	string str = "hello_how_are_you";
	vector<string> result = tokenize(str);
	for(int i = 0; i<result.size();i++)
	{
		cout<<result[i]<<endl;
	}
	trieNode *head = getNode();
	for(int i = 0; i<=result.size(); i++)
	{
		insert(result[i], head);
	}
	vector<string> testString = {"water_is_cool", "cold_ice_drink", "cool_wifi_speed"};
	for(int i=0 ; i<testString.size(); i++)
	{
		vector<string> splitString = tokenize(testString[i]);
		int count= 0;
		for(int j= 0; j<splitString.size(); j++)
		{
			if(search(splitString[j],head))
				count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
