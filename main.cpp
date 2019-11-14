#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

#include "my_aux.h"

using namespace std;

/**
    @brief This main function shows how MyPrintIp works
*/
int main()
{
#if (defined WIN32) || (defined WIN64)
    cout << "Homework print_ip" << endl << endl;  // for debugging
    //cout << MY_P_FUNC << endl;                  // for debugging
#else
    // something
#endif

//    MyPrintIp<char>(-1); // this commented block works as well
//    MyPrintIp<short>(0);
//    MyPrintIp<int>(2130706433);
//    MyPrintIp<__int64>(8875824491850138409);

//    MyPrintIp(2130706433ul); // additional test for unsigned type

    MyPrintIp((char)-1); // this commented block works as well
    MyPrintIp((short)0);
    MyPrintIp((int)2130706433);
    MyPrintIp((long long)8875824491850138409);

    string s = "255.255.127.0";
    //MyPrintIp<string>(s);
    MyPrintIp(s);

    vector<int> v = {250, 200, 150, 100};
    //MyPrintIp<vector<int>>(v);
    MyPrintIp(v);

    list<int> l = {200, 150, 100, 50};
    //MyPrintIp<list<int>>(l);
    MyPrintIp(l);

    //auto t = make_tuple(150, 100, 50, '0', 200ul); // causes "Incompatible types" as it's supposed to do
    auto t = make_tuple(150, 100, 50, 0, 1);
    MyPrintIp(t);

    return 0;
}
