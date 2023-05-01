//
//  Rap.cpp
//  cppTraining
//
//  Created by Mila ✨ on 26.01.2023.
//

#include "Rap.hpp"
#include <vector>
#include <string>

using namespace std;

Rap::Rap(){
    tag = "Rap";
}
Rap::~Rap(){
    
}

void Rap::set_beat(int new_beat){
    if (new_beat < 0){
        cout << "error";
        return;
        }
    beat = new_beat;
}

void Rap::set_speed_of_reading(int new_speed_of_reading){
    if (new_speed_of_reading < 0){
        cout << "error";
        return;
    }
    speed_of_reading = new_speed_of_reading;
}

int Rap::get_beat(){
    return beat;
}

int Rap::get_speed_of_reading(){
    return speed_of_reading;
}

void Rap::fill()
{
    Album::fill_in();
    string boof_string;
    int boof_int;
    cout << "the coolness of beat ( 0 to 100): ";
    getline(cin, boof_string);
    try {
        boof_int = stoi(boof_string);
    }
    catch (const exception& E) {
        cout << E.what() << endl;
        boof_int = 0;
    }
    set_beat(boof_int);
    cout << "the speed of reading (0 to 10): ";
    getline(cin, boof_string);
    try {
        boof_int = stoi(boof_string);
    }
    catch (const exception& E) {
        cout << E.what() << endl;
        boof_int = 0;
    }
    set_speed_of_reading(boof_int);
}

string Rap::to_string(){
    string result_string = Album::to_string();
    result_string += "The collness of beat: ";
    result_string += std::to_string(beat) + "\n";
    result_string += "Speed of reading: ";
    result_string += std::to_string(speed_of_reading) + "\n";
    return result_string;
}

void Rap::print(){
    cout << to_string();
}

void Rap::save_to_file(ofstream& File){
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
    File << std::to_string(beat) << endl;
    File << std::to_string(speed_of_reading) << endl;
    File << "</" + tag + ">\n";
}
int Rap::load_from_tokens(vector<string> tokens)
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
    set_beat(boof_int);
    i++;
    try {
        boof_int = stoi(tokens[i]);
    }
    catch (const exception& E) {
        cout << E.what() << endl;
        boof_int = 0;
    }
    set_speed_of_reading (boof_int);
    return i;
}

