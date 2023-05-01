//
//  Rap.hpp
//  cppTraining
//
//  Created by Mila ✨ on 26.01.2023.
//
#ifndef Rap_hpp
#define Rap_hpp

#include <iostream>
#include <vector>
#include <string>
#include "AlbumHeader.h"

#pragma once

using namespace std;

class Rap : public Album{
public:
    Rap();
    ~Rap();
    int get_beat();
    int get_speed_of_reading();
    void set_beat(int new_riff);
    void set_speed_of_reading(int new_orig);
    void fill();
    string to_string();
    void print();
    void save_to_file(ofstream& File);
    int load_from_tokens(vector <string> tokens);

private:
    int beat;
    int speed_of_reading;
    string riff_name;
};



#endif
