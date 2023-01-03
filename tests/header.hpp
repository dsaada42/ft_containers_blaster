/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:36:57 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/03 15:12:17 by dsaada           ###   ########.fr       */
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

# define PRINT_FILE_LINE(){                                                             \
    std::cout << "(file: " << __FILE__ << ", line: " << __LINE__ << ")" << STD::endl;   \
}

# define CATCH_EXCEPTION(){                     \
    catch (...){                                \
        std::cout << "Exception not handled";   \
        PRINT_FILE_LINE();                      \
    }                                           \
}

template <class Iterator>
void print_range(Iterator first, Iterator last){    \
    for (Iterator it = first; it != last; ++it){    \
        std::cout << *it << " ";                    \
    }                                               \
    std::cout << std::endl;                         \
}

#endif