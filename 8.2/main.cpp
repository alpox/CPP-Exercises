#include <iostream>

#include <fstream>

#include <string>
#include <vector>
#include <set>
#include <regex>

using namespace std;

void get_words(string filename, vector<string> &words) {

    ifstream ifs(filename);
    std::string s( (std::istreambuf_iterator<char>(ifs) ),
                   (std::istreambuf_iterator<char>()    ) );

    std::regex words_regex("(\\w+)");
    auto reg = sregex_iterator(s.begin(), s.end(), words_regex);
    auto regend = sregex_iterator();
    
    for(auto i = reg; i != regend; ++i) {
        words.push_back((*i).str());
    }
}

void get_dict(string filename, vector<regex> &dict) {
    ifstream ifs(filename);
    while(true) {
        string s;
        ifs >> s;
        dict.push_back(regex(s));
        if(!ifs.good()) break;
    }
}

int main(int argc, char* argv[]) {
    vector<string> text;
    vector<regex> dict;

    get_words("text.txt", text);
    get_dict("dict.txt", dict);

    for(vector<string>::iterator it = text.begin(); it != text.end(); it++) {
        string word = *it;
        bool ok = false;
        
        for(vector<regex>::iterator dit = dict.begin(); dit != dict.end(); dit++)
            if(regex_match(word, *dit)) ok = true;

        if(!ok)
            cout << "'" << word << "' is not correct!" << endl;
    }
    
    return 0;
}
