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
    friend class QueryResult;
public:
    TextQuery(std::ifstream &);
    std::string& query(std::string&);
private:
    std::shared_ptr<std::vector<std::string>> text;
    std::shared_ptr<std::map<std::string, std::set<size_t>>> result;
};

TextQuery::TextQuery(std::ifstream &infile)
{
    std::string word, line;
    text = std::make_shared<std::vector<std::string>>();
    result = std::make_shared<std::map<std::string, std::set<size_t>>>();
    size_t line_No = 0;
    while (std::getline(infile, line))
    {
        text->push_back(line);
    }
}

std::string& TextQuery::query(std::string& s)
{
    low_case_all(s);
    size_t line_No = 0;
    std::string word;
    if (text->size() == 0)
        throw std::runtime_error("Query in a null file!");
    if (result->find(s)== result->end())
    {
        for (const auto &line : *text)
        {
            std::istringstream is(line);
            while (is >> word)
            {
                low_case_all(word);
                delete_symbol(word);
                if (word == s)
                    result->operator[](word).insert(line_No);
            }
            ++line_No;
        }
    }

    return s;
}

class QueryResult
{
public:
    QueryResult(TextQuery& tq) { text = tq.text; result = tq.result; };
    std::ostream& print(std::ostream&, std::string&);
private:
    std::shared_ptr<std::vector<std::string>> text;
    std::shared_ptr<std::map<std::string, std::set<size_t>>> result;
};

std::ostream& QueryResult::print(std::ostream& out, std::string& word)
{
    auto ret = result->find(word);
    if (ret != result->end())
    {
            out << ret->first << " occurs " << ret->second.size() << " time"<<((ret->second.size()>1)?"s.":".") << std::endl;
            for (auto c : ret->second)
            {
                out << "(line" << c << ")" << text->operator[](c) << std::endl;
            }
    }
    else
    {
        out << word << " occurs 0 time." << std::endl;
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