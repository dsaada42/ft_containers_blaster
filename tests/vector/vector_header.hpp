/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_header.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:19:53 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/03 15:04:20 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HEADER_HPP
# define VECTOR_HEADER_HPP

#include "../header.hpp"
#include "vector.hpp"
#include <vector>

#define PRINT_VECTOR(vector){                                       \
    std::cout << "********* VECTOR *********\n";                    \
    std::cout << " size     = " << vector.size() << "\n";           \
    std::cout << " capacity = " << vector.capacity() << "\n";       \
    std::cout << "___ Elements ___\n";                              \
    print_range(vector.begin(), vector.end());                      \
}

//----- Penser a remplacer par un track allocator -----
typedef NAMESPACE::vector<std::string, std::allocator<std::string> > strvector;
typedef NAMESPACE::vector<int, std::allocator<int> > intvector;
typedef NAMESPACE::vector<long, std::allocator<long> > longvector;
typedef NAMESPACE::vector<double, std::allocator<double> > doublevector;
typedef NAMESPACE::vector<char, std::allocator<char> > charvector;

#endif