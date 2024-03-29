/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:36:53 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 11:02:14 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_header.hpp"

int main(void) {
    SETUP_MAP_ARRAYS();

    {
        intmap m(intstr_arr, intstr_arr + intstr_size);
        intmap::size_type c = m.count(64);
        PRINT_LINE("Count:", c);
        c = m.count(145);
        PRINT_LINE("Count:", c);
        c = m.count(11);
        PRINT_LINE("Count:", c);
        m.insert(NAMESPACE::make_pair(34, "seiurhg8347wo83twerw"));
        m.insert(NAMESPACE::make_pair(2, "dsghesrzarherheat43"));
        m.insert(NAMESPACE::make_pair(9, "awgfawe4t3A4YSDFGAS"));
        m.insert(NAMESPACE::make_pair(3, "dzfg45yrthsdfgshju"));
        m.insert(NAMESPACE::make_pair(22, "j564wedfshgj6ee5yegrs"));
        m.insert(NAMESPACE::make_pair(10, "cfngcvcx56;oiliuee"));
        c = m.count(34);
        PRINT_LINE("Count:", c);
        c = m.count(2);
        PRINT_LINE("Count:", c);
        c = m.count(9);
        PRINT_LINE("Count:", c);
        m.erase(9);
        c = m.count(9);
        PRINT_LINE("Count:", c);
        c = m.count(10);
        PRINT_LINE("Count:", c);
        c = m.count(22);
        PRINT_LINE("Count:", c);
    }    
    leak_checker::check_all();
}