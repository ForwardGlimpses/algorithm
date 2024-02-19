#include<bits/stdc++.h>
#define N 26
using namespace std;
struct TrieNode{
	struct TrieNode *children[N];
	int isEnd;
};
TrieNode *creatNode() {
	TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
	if (node) {
		node->isEnd = 0;
		for(int i = 0; i < N; i++){
			node->children[i] = NULL;
		}
	}
	return node;
}
void insert(TrieNode *root,char *word){
	TrieNode *curr = root;
	for(int i = 0; i < strlen(word); i++){
		int index = word[i] - 'a';
		if(curr->children[index] == NULL){
		   curr->children[index] = creatNode();
		}
		curr = curr->children[index];
	} 
	curr->isEnd = 1;
}
bool search(TrieNode *root, char *word){
	TrieNode *curr = root;
	for(int i = 0; i < strlen(word); i++){
		int index = word[i]-'a';
		if(curr->children[index] == NULL){
			return false;
		}
		curr = curr->children[index];
	}
	return (curr != NULL&& curr->isEnd);
}
void freeTrie(TrieNode *root){
	if(root){
		for(int i = 0; i < N ; i++){
			freeTrie(root->children[i]);
		}
		free(root);
	}
}
int main()
{
	int m,n;
	cin>>m>>n;
	TrieNode *root = creatNode();
	
	for(int i = 0; i<m; i++){
		char word[100];
		cin>>word;
		insert(root, word);
	}
	
	for(int i = 0; i < n; i++){
		char word[100];
		cin>>word;
		if(search(root, word)) {
			cout<<"true"<<endl;
		}else{
			cout<<"false"<<endl;
		}
	}
	freeTrie(root);
	
	return 0;
}