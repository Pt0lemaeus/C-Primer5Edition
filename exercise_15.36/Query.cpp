#include "stdafx.h"
#include <memory>
using std::make_shared;
#include <set>
using std::set;
#include <algorithm>
using std::set_intersection;
#include <iterator>
using std::inserter;
#include <cstddef>
using std::size_t;
#include "Query.h"

std::ostream &
operator<<(std::ostream &os, const Query &query)
{
    return os << query.rep();
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.cbegin(), end = result.cend();
    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz;++n)
    {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

QueryResult AndQuery::eval(const TextQuery &text) const
{
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.cbegin(), left.cend(), right.cbegin(), right.cend(),
        inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult OrQuery::eval(const TextQuery &text) const
{
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = make_shared<set<Query_base::line_no>>(left.cbegin(), left.cend());
    ret_lines->insert(right.cbegin(), right.cend());
    return QueryResult(rep(), ret_lines, left.get_file());
}
