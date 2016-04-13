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

void low_case_all(std::string&);
void delete_symbol(std::string&);

class QueryResult;

class TextQuery
{
public:
    using line_No_type = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(std::string&);
private:
    std::shared_ptr<std::vector<std::string>> text;
    std::map<std::string, std::shared_ptr<std::set<line_No_type>>> result;
};

TextQuery::TextQuery(std::ifstream &infile):text(new std::vector<std::string>)
{
    std::string line;
    //result = std::make_shared<std::map<std::string, std::set<size_t>>>();

    while (std::getline(infile, line))
    {
        text->push_back(line);
        size_t line_No = text->size()-1;
        std::istringstream is(line);
        std::string word;
        while (is >> word)
        {
            low_case_all(word);
            delete_symbol(word);
            auto &lines = result[word];
            if (!lines)
                lines.reset(new std::set<line_No_type>);
            lines->insert(line_No);
        }
    }
}



class QueryResult
{
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    using line_No_type = std::vector<std::string>::size_type;
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_No_type>> p,
                std::shared_ptr<std::vector<std::string>> f):sought(s), lines(p), file(f) {};
private:
    std::string sought;
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::set<line_No_type>> lines;
};

std::ostream& print(std::ostream& out, const QueryResult &qr)
{

            out << qr.sought << " occurs " << qr.lines->size() << " time"<<((qr.lines->size()>1)?"s.":".") << std::endl;
            for (auto c : *qr.lines)
            {
                out << "\t(line" << c + 1<< ")" << *(qr.file->begin()+c) << std::endl;
            }
    return out;
}

void low_case_all(std::string& word)
{
    for (auto &c : word)
    {
        c = std::tolower(c);
    }
}

void delete_symbol(std::string& word)
{
    const static std::set<char> exclude_char = { '.','|',',','?','!',':','(',')' };
    for (auto i = word.begin(); i != word.end(); ++i)
    {
        if (exclude_char.find(*i) != exclude_char.end())
            i = word.erase(i);
        if (i == word.end())
            break;
    }
}

QueryResult TextQuery::query(std::string& s)
{
    static std::shared_ptr<std::set<line_No_type>> nodata(new std::set < line_No_type>);
    low_case_all(s);
    size_t line_No = 0;
    std::string word;
    if (text->size() == 0)
        throw std::runtime_error("Query in a null file!");
    auto loc = result.find(s);
    if (loc == result.end())
        return QueryResult(s, nodata, text);
    else
        return QueryResult(s, loc->second, text);
}
