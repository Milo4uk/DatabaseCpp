//
//  Rock.cpp
//  cppTraining
//
//  Created by Mila ✨ on 20.01.2023.
//

#include "Rock.hpp"
#include <vector>
#include <string>

using namespace std;

Rock::Rock(){
    tag = "Rock";
}
Rock::~Rock(){
    
}

void Rock::set_riff(int new_riff){
    if (new_riff < 0){
        cout << "error";
        return;
        }
    riffs = new_riff;
}

void Rock::set_originality(int new_orig){
    if (new_orig < 0){
        cout << "error";
        return;
    }
    originality = new_orig;
}

int Rock::get_riff(){
    return riffs;
}

int Rock::get_originality(){
    return originality;
}

void Rock::fill()
{
    Album::fill_in();
    string boof_string;
    int boof_int;
    cout << "riffs: ";
    getline(cin, boof_string);
    try {
        boof_int = stoi(boof_string);
    }
    catch (const exception& E) {
        cout << E.what() << endl;
        boof_int = 0;
    }
    set_riff(boof_int);
    cout << "originality (0 to 100): ";
    getline(cin, boof_string);
    try {
        boof_int = stoi(boof_string);
    }
    catch (const exception& E) {
        cout << E.what() << endl;
        boof_int = 0;
    }
    set_originality(boof_int);
}

string Rock::to_string(){
    string result_string = Album::to_string();
    result_string += "Amount of nice riffs in the album: ";
    result_string += std::to_string(riffs) + "\n";
    result_string += "Originality (1 to 100): ";
    result_string += std::to_string(originality) + "\n";
    return result_string;
}

void Rock::print(){
    cout << to_string();
}

void Rock::save_to_file(ofstream& File){
    int i = 0;
    File << "<" + tag + ">\n";
    File << album_name << endl;
    File << "<Artists>\n";
    if (!artists.empty()) {
        for (Person artist : artists) {
            File << artist.Full_Name() << endl;
        }
    }
    File << "</Artists>\n";

//    File << "<Producers>\n";
//
//    if (!producers.empty()) {
//        for (Person producer : producers) {
//            File << producer.Full_Name() << endl;
//        }
////    }
//
//    File << "</Producers>\n";


    File << rating << endl;
    File << std::to_string(lenght_in_minutes) << endl;
    File << std::to_string(release_year) << endl;
    File << std::to_string(riffs) << endl;
    File << std::to_string(originality) << endl;
    File << "</" + tag + ">\n";
}
int Rock::load_from_tokens(vector<string> tokens)
{
    
    int i = Album::load_from_tokens(tokens);
    i++;
    int boof_int;
    try {
        boof_int = stoi(tokens[i]);
    }
    catch (const exception& E) {
        cout << E.what() << endl;
        boof_int = 0;
    }
    set_riff(boof_int);
    i++;
    try {
        boof_int = stoi(tokens[i]);
    }
    catch (const exception& E) {
        cout << E.what() << endl;
        boof_int = 0;
    }
    set_originality (boof_int);
    return i;
}

