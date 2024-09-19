#include <iostream>
#include <vector>


using namespace std; 

struct node {
    char currentCharacter;       
    bool isWord;
   //  int priority = 0;            
    struct node * children[27];  // [null,null,null,......,null] 
    node() {
        isWord = false;
    }
}*trie; 

// Inicializar 

void init() {
    trie = new node();  // Instanciar el objeto trie
}
//Crear una palabra 
void insertWord(string word) {   // alba 
    node * currentNode =  trie;  //Crea otro nodo 
    for (int i = 0; i< word.length(); i++) { // alba
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
            currentNode->children[character] = new node(); //Si esta vacio que la letra donde sera otro nodo 
           // currentNode->isWord = false;
        }
      //   currentNode = max(currentNode->priority,priority);
        currentNode = currentNode->children[character];
        currentNode->currentCharacter = word[i]; //Y si no esta vacio, recorre la palabra hasta que..
    }
    currentNode->isWord = true; //Llegue al fin de palabra 
}
//Busqueda de palabras
bool searchWord(string word) {   // alto 
    node * currentNode =  trie;  
    for (int i = 0; i < word.length(); i++) {
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
            return false; //Si no encuentra la palabra retorna falso
        }
        currentNode = currentNode->children[character]; //Pero si la encuentra, el nodo principal va al nodo hijo
    }
    cout<<currentNode->currentCharacter<<endl;
    return currentNode->isWord;
}

// Eliminar una palabra (deshabilitarla) en el trie
void deleteWord(string word) {
    node *currentNode = trie;
    for (int i = 0; i < word.length(); i++) {
        int character = word[i] - 'a';
        if (currentNode->children[character] == NULL) {
            cout << "La palabra '" << word << "' no existe en el trie." << endl;
            return;
        }
        currentNode = currentNode->children[character];
    }
    if (currentNode->isWord) {
        currentNode->isWord = false;
        cout << "Palabra '" << word << "' eliminada." << endl;
    } else {
        cout << "La palabra '" << word << "' no existe en el trie." << endl;
    }
}

void isThereWord(string word) {
    if(searchWord(word)) {
        cout<<"si existe : "<<word<<" en el trie"<<endl;
    } else {
        cout<<"No Existe :P"<<endl;
    }
}

int main() {

    // Inicializar Trie
    init();  
    string word = "auto";
    insertWord(word);
    isThereWord(word);
    word = "automovil";   
    insertWord(word);
    isThereWord("auto");
    isThereWord(word);

    // Eliminar palabra
    cout << "\nEliminando 'auto':" << endl;
    deleteWord("auto");
    isThereWord("auto");
    isThereWord("automovil");

    cout << "\nEliminando 'automovil':" << endl;
    deleteWord("automovil");
    isThereWord("automovil");
    return 0;
}