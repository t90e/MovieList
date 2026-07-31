#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "header.h"
using namespace std;


class Movie {       // The class
public:             // Access specifier
    string name;    // Attribute
    bool seen;      // Attribute 
    Movie(string x, bool y) { // Constructor with parameters
        name = x;
        seen = y;
    }
};