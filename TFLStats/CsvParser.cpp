#include "CsvParser.h"
#include <sstream>

using namespace std;

CsvParser::CsvParser(std::string& filename) :
    _filename(filename)
{
    if (!OpenFile()) throw exception("Cannot open file for reading.\n");
}


CsvParser::~CsvParser(void)
{
}

void CsvParser::Read() {
    string line;
    string sub = "";
    vector<string> strings;
    vector<vector<string>> stringStrings;

    while (getline(_file, line)) {
        auto size = line.size();
        int i = 0;

        for (auto it = line.begin(); it != line.end(); it++, i++) {
            if (*it != ',' || it == line.end()-1) {
                if (it == line.end()-1) {
                    i = ClearLine(sub, it, strings, i);

                }
                else
                    sub.push_back(*it);
            }
            else {
                i = ClearLine(sub, it, strings, i);
                //strings.push_back(sub);
                //sub = "";
                //i = 0;
            }
        }
        
        /*for (auto i = 0; i < line.size(); i++) {
            if (line[i] != ',' && line[i] != '\n' && i < line.size()) {
                sub.push_back(line[i]);
            }
            else if (i == line.size()){
                strings.push_back(sub);
                sub == "";
                break;
            }
            else {
                strings.push_back(sub); 
                sub = "";
            }
        }*/
    }
}

bool CsvParser::OpenFile() {
    _file.open(_filename);

    if (!_file) {
        cerr << "Cannot open file.\n";
        return false;
    }

    return true;
}

int CsvParser::ClearLine(string &sub, string::iterator it, vector<string> &strings, int i )
{
    sub.push_back(*it);
    strings.push_back(sub);
    sub = "";
    i = 0;	
    return i;
}


