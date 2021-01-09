#include <iostream>
#include <list>
#include <string.h>
#include <bits/stdc++.h>
#include "syllable.h"
#include "syllable.cpp"
SeparatorOfSyllables libsilaba;
using namespace std;
void separarPalabras(string);
void chemsificar(string);
bool verifyPalabra(string);
list<string> lista;
int numsilabas;
string opc = "s";
string texto;
int *posiciones;
int main(){
	do{
		texto = "";
		cout<<"------------------------------------------------------"<<endl;
		cout<<"Texto a chemsificar: ";
		fflush(stdin);
		getline(cin,texto);
		cout<<endl;
		separarPalabras(texto);
		while (!lista.empty()){
			chemsificar(lista.front());
			lista.pop_front();
		}
		cout<<endl;
		cout<<"------------------------------------------------------"<<endl;
		cout<<"Desea chemsificar mas texto? (s/n):  ";
		cin>>opc;
	}while (opc != "n");
	
	return 0;
}

void separarPalabras(string str)
{
   // Used to split string around spaces.
    istringstream ss(str);
 
    string word; // for storing each word
 
    // Traverse through all words
    // while loop till we get 
    // strings to store in string word
    while (ss >> word) 
    {
        // print the read word
        lista.push_back(word);
    }
}
void chemsificar(string palabra){
	posiciones = libsilaba.SyllablePositions(palabra.c_str());
	numsilabas = libsilaba.NumberOfSyllables(palabra.c_str());
	for (int i=1; i<numsilabas; i++){
		palabra.insert(posiciones[i],"m");
	};
	cout<<palabra;
	if(verifyPalabra(palabra))
		cout<<"m";
	cout<<" ";
}
bool verifyPalabra (string palabra){
	if(palabra.find("\"") == string::npos && palabra.find("?") == string::npos && palabra.find(":") == string::npos && palabra.find(".") == string::npos && palabra.find(",") == string::npos && palabra.find(";") == string::npos)
		return true;
	return false;
}
