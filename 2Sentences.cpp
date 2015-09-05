/*
 * 2Sentences.cpp
 *
 *  Created on: 1 Mar 2014
 *      Author: António Ribeiro
 */

#include <iostream>
#include <string.h>
#include <sstream>
#include <algorithm>
using namespace std;

string menu(string phrase1, string phrase2, char op){
	stringstream phraseConc;
	switch(op){
		case 'A': case 'a':
			phraseConc << phrase1;
			break;
		case 'B': case 'b':
			phraseConc << "Frase1: " << phrase1.size() << " Frase2: " << phrase2.size();
			break;
		case 'C': case 'c':
			if(phrase1.compare(phrase2)){
				phraseConc << "As frases são diferentes";
			} else {
				phraseConc << "As frases são iguais";
			}
			break;
		case 'D': case 'd':
			phraseConc << phrase1 << phrase2;
			break;
		case 'E': case 'e':{
			stringstream conc;
			string concString;
			char character;
			conc << phrase1 << phrase2;
			concString = conc.str();
			cin >> character;
			int times = 0;
			for(int i = 0; i<concString.length(); i++){
				if(concString[i] == character){
					times++;
				}
			}
			phraseConc << times;
		}
			break;
		case 'F': case 'f':{
			stringstream conc;
			string concString;
			char character;
			conc << phrase1 << phrase2;
			concString = conc.str();
			cin >> character;
			for(int i = 0; i<concString.length(); i++){
				if(concString[i] == character){
					for(int place = i; place<concString.length(); place++){
						concString[i] = concString[i+1];
					}
				}
			}
			phraseConc << concString;
		}
			break;
		case 'G': case 'g':{
			stringstream conc;
			string concString;
			char character;
			char characterSub;
			conc << phrase1 << phrase2;
			concString = conc.str();
			cin >> character;
			cin >> characterSub;
			for(int i = 0; i<concString.length(); i++){
				if(concString[i] == character){
					concString[i] = characterSub;
				}
			}
			phraseConc << concString;
		}
			break;
		default:
			break;
	}
 return phraseConc.str();
}

int main() {
	char op;
	string phrase1, phrase2;
	cout << "A - Copiar uma frase. (por exemplo a frase2 para dentro da frase1)\nB - Calcular o tamanho das frases.\nC - Comparar duas frases.\nD - Unir duas frases.\nE - Contar o numero de vezes que um caracter surge em cada frase.\nF - Retira uma letra das frases.\nG - Substituir uma letra das frases por outra.\n";
	cin >> op;
	getline(cin, phrase1);
	getline(cin, phrase1);
	getline(cin, phrase2);
	cout << menu(phrase1, phrase2, op);
	return 0;
}




