/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:44:59 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/11/30 20:45:02 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft {

template <bool IsIntegral, class T>
struct value {
  static const bool val = IsIntegral;
};

template <class T>
struct is_integral_value : public value<false, T> {};

template <>
struct is_integral_value<bool> : public value<true, bool> {};

template <>
struct is_integral_value<char> : public value<true, char> {};

template <>
struct is_integral_value<signed char> : public value<true, signed char> {};

template <>
struct is_integral_value<unsigned char> : public value<true, unsigned char> {};

template <>
struct is_integral_value<wchar_t> : public value<true, wchar_t> {};

template <>
struct is_integral_value<char16_t> : public value<true, char16_t> {};

template <>
struct is_integral_value<char32_t> : public value<true, char32_t> {};

template <>
struct is_integral_value<short> : public value<true, short> {};

template <>
struct is_integral_value<unsigned short> : public value<true, unsigned short> {
};

template <>
struct is_integral_value<int> : public value<true, int> {};

template <>
struct is_integral_value<unsigned int> : public value<true, unsigned int> {};

template <>
struct is_integral_value<long> : public value<true, long> {};

template <>
struct is_integral_value<unsigned long> : public value<true, unsigned long> {};

template <>
struct is_integral_value<long long> : public value<true, long long> {};

template <>
struct is_integral_value<unsigned long long>
    : public value<true, unsigned long long> {};

template <class T>
struct is_integral : public is_integral_value<T> {};
}  // namespace ft

#endif
