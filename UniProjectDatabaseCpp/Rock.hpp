//
//  Rock.hpp
//  cppTraining
//
//  Created by Mila ✨ on 20.01.2023.
//

#ifndef Rock_hpp
#define Rock_hpp

#include <iostream>
#include <vector>
#include <string>
#include "AlbumHeader.h"

#pragma once

using namespace std;

class Rock : public Album{
public:
    Rock();
    ~Rock();
    int get_riff();
    int get_originality();
    void set_riff(int new_riff);
    void set_originality(int new_orig);
    void fill();
    string to_string();
    void print();
    void save_to_file(ofstream& File);
    int load_from_tokens(vector <string> tokens);

private:
    int riffs;
    int originality;
    string riff_name;
};



#endif
