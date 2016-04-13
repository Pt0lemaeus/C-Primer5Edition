#pragma once
#include <string>
#include <iostream>
#include <memory>
#include"TextQuery.h"

class Query_base
{
    friend class Query;
protected:
    using line_no = TextQuery::line_No_type;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;

};

class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query& operator=(Query& rhs)
    {

    }
    Query(const std::string&);
    QueryResult eval(const TextQuery &t) const
    {
        return q->eval(t);
    }
    std::string rep() const 
    {
        //std::cout << "===================================== Query.rep() EXECUTE! ========================================" << std::endl;
        return q->rep();
    }
private:
    Query(/*std::shared_ptr<Query_base>*/ Query_base *query):q(query)
    {
        //std::cout << "========================= PRIVATE Query CONSTRUCTOR FUNCTION EXECUTE! =============================" << std::endl;
    }
    /*std::shared_ptr<Query_base>*/ Query_base *q;
};

std::ostream &
operator<<(std::ostream &, const Query &);

class WordQuery : public Query_base
{
    friend class Query;
    WordQuery(const std::string &s) :query_word(s)
    {
        //std::cout << "====================== PRIVATE WordQuery CONSTRUCTOR FUNCTION EXECUTE! ============================" << std::endl;
    }

    QueryResult eval (const TextQuery &t) const
    {
        return t.query(query_word);
    }

    std::string rep() const 
    { 
        //std::cout << "=================================== WordQuery.rep() EXECUTE! ======================================" << std::endl;
        return query_word; 
    }
    std::string query_word;
};

inline 
Query::Query(const std::string &s): q(new WordQuery(s)) 
{
    //std::cout << "========================= PUBLIC Query CONSTRUCTOR FUNCTION EXECUTE! ==============================" << std::endl;
}

class NotQuery:public Query_base
{
    friend Query operator~(const Query &);
    NotQuery(const Query &q):query(q)
    {
        //std::cout << "========================= PRIVATE NotQuery CONSTRUCTOR FUNCTION EXECUTE! ==========================" << std::endl;
    }

    std::string rep() const
    {
        //std::cout << "========================= PRIVATE NotQuery CONSTRUCTOR FUNCTION EXECUTE! ==========================" << std::endl;
        return "~(" + query.rep() + ")";
    }
    QueryResult eval(const TextQuery&) const;
    Query query;
};

inline Query operator~(const Query &operand)
{
    return new NotQuery(operand);
}

class BinaryQuery :public Query_base
{
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s):
        lhs(l),rhs(r),opSym(s)
    {
        //std::cout << "==================== PROTECTED BinaryQuery CONSTRUCTOR FUNCTION EXECUTE! ==========================" << std::endl;
    }
    std::string rep()const
    {
        //std::cout << "================================== BinaryQuery.rep() EXECUTE! =====================================" << std::endl;
        return "(" + lhs.rep() + " "
            + opSym + " "
            + rhs.rep() + ")";
    }
    Query lhs, rhs;
    std::string opSym;
};

class AndQuery :public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right) :
        BinaryQuery(left, right, "&")
    {
        //std::cout << "========================= PRIVATE AndQuery CONSTRUCTOR FUNCTION EXECUTE! ==========================" << std::endl;
    }
    QueryResult eval(const TextQuery&) const;
private:
    int kaka = 0;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return new AndQuery(lhs, rhs);
}

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right) :
        BinaryQuery(left, right, "|")
    {
        //std::cout << "========================= PRIVATE OrQuery CONSTRUCTOR FUNCTION EXECUTE! ===========================" << std::endl;
    }
    QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return new OrQuery(lhs, rhs);
}