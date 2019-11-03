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

template<class T>
void MyPrintIp(const string &ip, typename enable_if<is_class<T>::value>::type* = 0)
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
//      cout << *it << ((it < (ip.cend()-1))? "." : "\n"); // 'it-1' doesn't work for list (((
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

// something for tuple there...
















