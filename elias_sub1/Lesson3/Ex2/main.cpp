#include <iostream>

#include "pvector.h"
#include "pset.h"

using namespace std;

int main(int argc, char* argv[]) {
    string dict, txt;

    if(argc != 2) {
        cout << "Too few arguments given! Using default values.";

        dict = "dict.txt";
        txt = "text.txt";
    } else {
        dict = argv[1];
        txt = argv[2];
    }

    cout << dict << endl;

    pset<string> wordDict(dict);
    pvector<string> text(txt);
    pvector<string> corrected(txt + ".corrected");

    // Clear file contents (vector contents) and rewrite it with new input values
    corrected.clear();
    for_each(text.begin(), text.end(), [&] (string t) { corrected.push_back(t); });

    for(vector<string>::iterator it = corrected.begin(); it != corrected.end(); it++) {
        string word = *it;
        string replacement;
        if(wordDict.find(word) != wordDict.end()) continue;

        char cmd;
        bool ok = false;
        while(!ok) {
            cout << word << endl;
            cout << "(a)dd, (i)gnore, (r)eplace? ";

            cin >> cmd;
            ok = true;

            switch (cmd) {
                case 'i':
                    break;
                case 'a':
                    wordDict.insert(word);
                    break;
                case 'r':
                    cin >> replacement;
                    *it = replacement;
                    break;
                default:
                    cout << "Operation not allowed." << endl;
                    ok = false;
                    break;
            }
        }
    }
    return 0;
}
