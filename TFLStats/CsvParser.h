#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <iostream>

class CsvParser
{
public:
    CsvParser(std::string& filename);
    ~CsvParser(void);

    void Read();

    int ClearLine(std::string &sub, std::string::iterator it, std::vector<std::string> &strings, int i );

    void Append(std::string& text);

private:
    bool OpenFile();
    bool CloseFile();

private:
    struct CsvRecord {
        int _balance;
        int _credit;
        int _charge;
        double _startTime;
        double _endTime;
        std::string _date;
        std::string _actionType;
        std::string _note;
    };
    
    typedef std::shared_ptr<CsvRecord> CsvRecordPtr;

private:
    std::string _filename;
    std::vector<CsvRecordPtr> _records;
    std::ifstream _file;
};

#endif
