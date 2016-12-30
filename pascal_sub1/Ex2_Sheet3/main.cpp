#include <iostream>
#include <string>
#include <sstream>
#include "pset.h"

using namespace std;

void spellchecker(pset<string> input, pset<string> dictionary){
    int checker;
    char var;
    string command;
    string correct;
    for(typename set<string>::iterator it = input.get_set().begin(); it!=input.get_set().end(); ++it){
        checker = 0;
        for(typename set<string>::iterator dictIt = dictionary.get_set().begin(); dictIt!=dictionary.get_set().end(); ++dictIt){
            if((*dictIt).compare(*it)==0){
                checker = 1;
            }
        }
        if(checker == 0){
            cout << *it << endl << "(a)dd, (i)gnore, (r)replace" << endl;
            getline(cin,command);
            istringstream is(command);
            is >> var;
            if(var == 'a'){
                dictionary.get_set().insert(*it);
            }
            if(var == 'i'){

            }
            if(var == 'r'){
                input.remove(*it);
                cout << "Type the correct word:";
                getline(cin,correct);
                input.get_set().insert(correct);
                for(typename set<string>::iterator Iter=dictionary.get_set().begin(); Iter!=dictionary.get_set().end(); ++Iter){
                    if(correct.compare(*Iter)==0){
                        dictionary.get_set().insert(correct);
                    }
                }
            }
        }
    }
}


int main() {
    pset<string> dictionary("dictionary.txt");
    pset<string> input("input_file.txt");
    //spellchecker(input, dictionary);
    cout << dictionary.get_set().size();
}