#include <iostream>
#include "CsvParser.h"
#include <string>

int main(int argc, char *argv[]) {
    CsvParser parser(std::string("data\\051037193158-20120323-2042.csv"));
    parser.Read();

    return 0;
}