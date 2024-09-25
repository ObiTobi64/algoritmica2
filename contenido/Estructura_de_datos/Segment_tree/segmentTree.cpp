#include <bits/stdc++.h>
#define input freopen("inTrie.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

struct node
{
    char currentCharacter;
    bool endOfWord;
    node *children[10];
    node()
    {
        endOfWord = false;
        for (int i = 0; i < 10; i++)
        {
            children[i] = NULL;
        }
    }
};

bool isNumber, isCreated;
void insert(node *trie, string word)
{
    
    node *currentNode = trie;
    
    for (int i = 0; i < word.size(); i++)
    {
        int index = word[i] - '0';
        if (currentNode->children[index] == NULL)
        {
            isCreated = true;
            currentNode->children[index] = new node();
        }
        currentNode = currentNode->children[index];
        if(currentNode->endOfWord){
            isNumber = true;
        }
        currentNode->currentCharacter = word[i];
    }
    if(isCreated && !isNumber) {
        currentNode->endOfWord = true;
    }
    
}

bool search(node *trie, string word)
{
    node *currentNode = trie;
    for (int i = 0; i < word.size(); i++)
    {
        int index = word[i] - '0';
        if (currentNode->children[index] == NULL)
        {
            return false;
        }
        currentNode = currentNode->children[index];
    }
    return currentNode->endOfWord;
}

int main()
{
    // input;
    int wordsNumber;
    cin >> wordsNumber;

    node *trie = new node();

    while (wordsNumber--)
    {
        string word;
        cin >> word;
        isNumber = false;
        isCreated = false;
        insert(trie, word);
        cout<<isNumber<<" "<<isCreated<<endl;
    }
    
    if(search(trie,"1123")){
        cout<<"existe el 1123"<<endl;
    } else {
        cout<<"no existe el 1123"<<endl;
    }
    
    if(search(trie,"1")){
        cout<<"existe el 1"<<endl;
    } else {
        cout<<"no existe el 1"<<endl;
    }
    
    if(search(trie,"765179")){
        cout<<"existe el 765179"<<endl;
    } else {
        cout<<"no existe el 765179"<<endl;
    }

}