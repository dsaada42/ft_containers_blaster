/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_header.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:14:45 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 10:04:38 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HEADER_HPP
# define SET_HEADER_HPP

# include "../header.hpp"
# include "set.hpp"
# include <set>

#define PRINT_SET(set){                                           \
    std::cout << "==================== VECTOR ====================\n";  \
    std::cout << " size     = " << set.size() << "\n";               \
    std::cout << "___ Elements ___\n";                                  \
    print_range(set.begin(), set.end());                          \
}

#define CHECK_TYPEDEF(type)                                                                        \
    {                                                                                              \
        NAMESPACE::set<int>::type a = NAMESPACE::set<int>::type();                                 \
        (void)a;                                                                                   \
    }
    
#define PRINT_ALL(set)                                                                             \
    {                                                                                              \
        PRINT_FILE_LINE();                                                                         \
        PRINT_SET(set);                                                                            \
    }

#define PRINT_BOUND(b, end)                                                                        \
    {                                                                                              \
        if (b != end) {                                                                            \
            PRINT_LINE("Value:", *b);                                                              \
        } else {                                                                                   \
            PRINT_MSG("End iterator");                                                             \
        }                                                                                          \
        std::cout << std::endl;                                                                    \
    }

#define PRINT_EQ_RANGE(p, end)                                                                     \
    {                                                                                              \
        std::cout << "--------------------------------\n";                                         \
        PRINT_BOUND(p.first, end);                                                                 \
        PRINT_BOUND(p.second, end);                                                                \
    }

#define PRINT_IT_PTR(it)                                                                           \
    {                                                                                              \
        PRINT_LINE("It:", *(it));                                                                  \
    }


typedef NAMESPACE::set<int, std::less<int>, track_allocator<int> > intset;
typedef NAMESPACE::set<std::string, std::less<std::string>, track_allocator<std::string> > strset;


#endif


