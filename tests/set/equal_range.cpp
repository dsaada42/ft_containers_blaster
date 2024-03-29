/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_range.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:31:40 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 09:31:52 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

int main (void) {
    SETUP_ARRAYS();

    {
        intset m(s_int, s_int + s_size);

        m.insert(34);
        m.insert(3468);
        m.insert(96533);
        m.insert(1954894589);
        m.insert(7754322);
        m.insert(3632);
        m.insert(3);
        m.insert(4);
        m.insert(-873487);
        m.insert(-95763433);
        m.insert(453834782);
        m.insert(19458942);
        m.insert(1245689793);

        NAMESPACE::pair<intset::iterator, intset::iterator> eq = m.equal_range(98583944);

        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(209485948);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(19458942);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(19458941);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(19458943);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(-1);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(3);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(4);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(5);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(0);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(std::numeric_limits<int>::max());
        PRINT_EQ_RANGE(eq, m.end());
        m.insert(std::numeric_limits<int>::max());
        eq = m.equal_range(std::numeric_limits<int>::max());
        PRINT_EQ_RANGE(eq, m.end());
    }

    {
        intset temp(s_int, s_int + s_size);

        temp.insert(34);
        temp.insert(3468);
        temp.insert(96533);
        temp.insert(1954894584);
        temp.insert(7754322);
        temp.insert(3632);
        temp.insert(3);
        temp.insert(4);
        temp.insert(-873487);
        temp.insert(-95763433);
        temp.insert(453834782);
        temp.insert(19458942);
        temp.insert(1245689793);

        const intset m(temp);

        NAMESPACE::pair<intset::const_iterator, intset::const_iterator> eq =
            m.equal_range(98583944);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(209485948);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(19458942);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(19458941);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(19458943);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(-1);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(3);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(4);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(5);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(0);
        PRINT_EQ_RANGE(eq, m.end());
        eq = m.equal_range(std::numeric_limits<int>::max());
        PRINT_EQ_RANGE(eq, m.end());
    }
    {
        const intset m;

        NAMESPACE::pair<intset::const_iterator, intset::const_iterator> eq =
            m.equal_range(std::numeric_limits<int>::max());
        PRINT_EQ_RANGE(eq, m.end());
    }
    leak_checker::check_all();
}