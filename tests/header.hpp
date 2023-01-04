/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:36:57 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/04 16:38:57 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

# include <cstdlib>
# include <cstddef>
# include <memory>
# include <string>
# include <iostream>
# include <sstream>
# include "../srcs/allocator_tracker.hpp"
# include "../srcs/leak_checker.hpp"

# define PRINT_FILE_LINE(){                                                             \
    std::cout << "(file: " << __FILE__ << ", line: " << __LINE__ << ")" << std::endl;   \
}

# define PRINT_LINE(str, val){          \
    std::cout << str << " " << (val);   \
    PRINT_FILE_LINE();                  \
}

# define CATCH_EXCEPTION()                      \
    catch (...){                                \
        std::cout << "Exception not handled";   \
        PRINT_FILE_LINE();                      \
    }                                           \

template <class Iterator>
void print_range(Iterator first, Iterator last){    \
    for (Iterator it = first; it != last; ++it){    \
        std::cout << *it << " ";                    \
    }                                               \
    std::cout << std::endl;                         \
}

template <typename ForwardIt, typename T>
void iota(ForwardIt first, ForwardIt last, T value = T())
{
    while (first != last) {
        *first++ = value;
        ++value;
    }
}

#endif