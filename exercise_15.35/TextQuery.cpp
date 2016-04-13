#include "stdafx.h"
#include "TextQuery.h"

TextQuery::TextQuery(std::ifstream &infile) :text(new StrVec())
{
    std::string line;
    //result = std::make_shared<std::map<std::string, std::set<size_t>>>();

    while (std::getline(infile, line))
    {
        text->push_back(line);
        size_t line_No = text->size() - 1;
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

std::ostream& print(std::ostream& out, const QueryResult &qr)
{

    out << qr.sought << " occurs " << qr.lines->size() << " time" << ((qr.lines->size()>1) ? "s." : ".") << std::endl;
    for (auto c : *qr.lines)
    {
        out << "\t(line" << c + 1 << ")" << *(qr.file->begin() + c) << std::endl;
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