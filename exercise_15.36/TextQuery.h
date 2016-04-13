#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cctype>
#include "StrVec.h"
//void low_case_all(std::string&);
//void delete_symbol(std::string&);

class QueryResult;

class TextQuery
{
public:
    using line_No_type = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<StrVec> text;
    std::map<std::string, std::shared_ptr<std::set<line_No_type>>> result;
};





class QueryResult
{
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    using line_No_type = std::vector<std::string>::size_type;
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_No_type>> p,
                std::shared_ptr<StrVec> f):sought(s), lines(p), file(f) {};
    const std::set<line_No_type>::iterator cbegin();
    const std::set<line_No_type>::iterator cend();
    std::shared_ptr<StrVec> get_file();
private:
    std::string sought;
    std::shared_ptr<StrVec> file;
    std::shared_ptr<std::set<line_No_type>> lines;
};

std::ostream& print(std::ostream& out, const QueryResult &qr);
void low_case_all(std::string& word);
void delete_symbol(std::string& word);


