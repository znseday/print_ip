#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <memory>

// __FUNCSIG__ is for VS, but Qt (mingw) works with __PRETTY_FUNCTION__
#if (defined WIN32) || (defined WIN64)
//#define MY_P_FUNC __FUNCSIG__
#define MY_P_FUNC __PRETTY_FUNCTION__
#else
#define MY_P_FUNC __PRETTY_FUNCTION__
#endif

// I intentionally don't use "std::" because it's complicated code for fisrt TMP experience
using namespace std;


