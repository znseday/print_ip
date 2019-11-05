#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <utility>
#include <iomanip>

// __FUNCSIG__ is for VS, but Qt (mingw) works with __PRETTY_FUNCTION__ as well
#if (defined WIN32) || (defined WIN64)
//#define MY_P_FUNC __FUNCSIG__
#define MY_P_FUNC __PRETTY_FUNCTION__
#else
#define MY_P_FUNC __PRETTY_FUNCTION__
#endif

// I intentionally don't use "std::" because it's complicated code for fisrt TMP experience
using namespace std;

//template<typename T>
//void MyPrintIp(T ip) // it's general function, but things aren't so easy(
//{
//    throw invalid_argument("ip has incompatible type");
//}

//template<class T>
//typename enable_if<is_integral<T>::value, T> void
//    MyPrintIp(T t)
//{
//    std::cout << "integral" << endl;
//}

//template <typename T>
//enable_if_t<is_integral_v<T>, void> MyPrintIp(const T ip)
//{
//   cout << ip << endl;
//}

template<class T> // such an idea about unsued parameter is taken from cppreference
void MyPrintIp(T ip, typename enable_if<is_integral<T>::value>::type* = 0)
{
    //cout << dec << ip << endl;           // for debugging
    //unsigned decltype(ip) mask = 0xff;   // it's logical, but doesn't work (((
    typename make_unsigned<T>::type mask = 0xff; // this monster works
    //cout << "mask = " << hex << mask << endl;                 // for debugging
    //cout << "sizeof(mask) = " << dec << sizeof(mask) << endl; // for debugging

    for (int i = (sizeof(ip)-1)*8; i >= 0; i -= 8)
        cout << ((ip>>i) & mask) << ((i>0)? "." : "\n");
}

//template<class T>
//void MyPrintIp(const string &ip, typename enable_if<is_class<T>::value>::type* = 0)
//{
//    cout << ip << endl;
//}

void MyPrintIp(const string &ip)
{
    cout << ip << endl;
}

//template<class T, class V> // doesn't work for T, but works for 'const vector<V> &ip' (((
//void MyPrintIp(const vector<V> &ip, typename enable_if<is_class<T>::value>::type* = 0)
//{
//    //copy(ip.cbegin(), ip.cend(), ostream_iterator<V>(cout, ".")); // adds extra point at the end (((
//    for (auto it = ip.cbegin(); it != ip.cend(); ++it)
//        cout << *it << ((it < (ip.cend()-1))? "." : "\n");
//}

template<class T, class = typename enable_if<is_class<T>::value>::type >
void MyPrintIp(T ip)
{
    for (auto it = ip.cbegin(); it != ip.cend(); )
    {
        cout << *it++;
        if (it != ip.cend())
            cout << ".";
    }
    cout << endl;
}

//template<typename T>  // "error: function template partial specialization is not allowed" ((( !!!!!
//void MyPrintIp<string>(const string &ip)
//{   // "error: function template partial specialization is not allowed" ((( !!!!!
//    cout << ip << endl;
//}


template<int P, typename ...Args>
void HelperPrintIp(tuple<Args...> &t)
{
    cout << get<P>(t);

    if constexpr (P < tuple_size<tuple<Args...>>::value-1)
    {
        //    static_assert (   // doesn't work (((
        //     is_same_v<tuple_element<P, typename remove_reference<decltype(t)>::type>::type,
        //               tuple_element<P+1, typename remove_reference<decltype(t)>::type>::type>
        //     , "q");

         static_assert (
             is_same_v<typename tuple_element<P, tuple<Args...>>::type ,
                       typename tuple_element<P+1, tuple<Args...>>::type >
             , "!!! Incompatible types !!!");

        cout << ".";
        HelperPrintIp<P+1>(t);
    }
    else
        cout << endl;
}

template<typename ...Args>
void MyPrintIp(tuple<Args...> &t)
{
//    cout << MY_P_FUNC << endl;
//    cout << "It's tuple" << endl;

    HelperPrintIp<0>(t);
}














