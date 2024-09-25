#include <bits/stdc++.h>
#define input freopen("inTrie.txt,"r",stdin)
#define output freopen("outTrie.txt","w",stdout)
using namespace std;

struct node {
    char currentCharacter;
    bool endOfWord;
    node * children [26];

    node (){
        endOfWord = false ; // Ponemos al nodo como falso
        for (int i =0; i<26;i++){
            children[i] = NULL; //En cada posición pondra que es nulo [null,null,null,null]
        }
    }   
};

void insert(node *trie,string word){
    node *currentNode = trie; //Estamos mandando el puntero 
    for(int i = 0 ; i < word.size();i++){
        int index = word[i] - 'a'; // 98 - a = 1
        if(currentNode->children[index]==NULL){ //Esto obtendra el valor de la casa Paul
            currentNode -> children[index] = new node(); //Hasta ahora no nos hemos movido
        } 
        currentNode = currentNode->children[index]; //Ahora si nos estamos moviendo 
        currentNode->currentCharacter = word[i];
    }
    currentNode->endOfWord = true; //Con esto estamos diciendo que es una palabra, ya que el puntero esta al final, si halla acabado el for 
} 

bool search(node *trie, string word){ //estamos mandando el puntero y la palabra 
    node *currentNode = trie;
    for(int i = 0; i<word.size();i++){
        int index = word[i] - 'a';
        if (currentNode->children[index] == NULL){ //NOs preguntamos si existe la palabra, en este caso no
            return false;
        }
        currentNode = currentNode->children[index];
    }
    return currentNode->endOfWord;
}

// bool deleted(node *trie, string word){
//     node *currentNode = trie;
//     for(int i=0; i<word.size;i++){

//     }
// }

int main (){
    int wordNumber;
    cin >> wordNumber;
    node * trie = new node();//Va a crear a otro nodo en null para esta palabra y lo pondra en falso     
    while(wordNumber--){
        string word;
        cin >> word;
        insert(trie,word);
    }
    if(search(trie,"appli")){
        cout<<"existe la palabra appli"<<endl;
    }else{
        cout<<"No existe la palabra appli"<<endl;
    }
}