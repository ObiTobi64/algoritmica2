#include <bits/stdc++.h>
#define input freopen("inCellphones.txt,"r",stdin)
#define output freopen("outCellphones.txt","w",stdout)
using namespace std;

struct node {
    char currentCharacter;
    bool endOfWord;
    node * children [10];

    node (){
        endOfWord = false ; // Ponemos al nodo como falso
        for (int i =0; i<10;i++){
            children[i] = NULL; //En cada posición pondra que es nulo [null,null,null,null]
        }
    }   
};

bool isNumber, isCreated;

void insert(node *trie,string word){
    node *currentNode = trie; //Estamos mandando el puntero 
    
    for(int i = 0 ; i < word.size();i++){
        int index = word[i] - '0'; // 98 - a = 1
        if(currentNode->children[index]==NULL){ //Esto obtendra el valor de la casa Paul
            isCreated = true;
            currentNode -> children[index] = new node(); //Hasta ahora no nos hemos movido
        } 
        currentNode = currentNode->children[index]; //Ahora si nos estamos moviendo 
        if(currentNode->endOfWord){
            isNumber = true;
        }
        currentNode->currentCharacter = word[i];
    }
    if(isCreated && !isNumber){
        currentNode->endOfWord = true;
    }
    currentNode->endOfWord = true; //Con esto estamos diciendo que es una palabra, ya que el puntero esta al final, si halla acabado el for 

} 

bool search(node *trie, string word){ //estamos mandando el puntero y la palabra 
    node *currentNode = trie;
    for(int i = 0; i<word.size();i++){
        int index = word[i] - '0';
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
        isNumber = false;
        isCreated = false;
        insert(trie,word);
        cout<<isNumber<<" "<<isCreated<<endl;
    }
    if(search(trie,"76517826")){
        cout<< "Existe el numero"<<endl;
    }
        cout<<"No existe el numero"<<endl;
}