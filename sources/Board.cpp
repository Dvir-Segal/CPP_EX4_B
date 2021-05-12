#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <climits>
#include <unordered_map>
#include <map>
#include <bits/stdc++.h>
#include <utility>
#include <queue>
#include "Board.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic{
    map<string, pandemic::Color> Board::mapColors;
    map<string, pandemic::City> Board::mapCities;

    pandemic::Board::Board(){
        mapColors["Red"] = Color::Red;
        mapColors["Yellow"] = Color::Yellow;
        mapColors["Blue"] = Color::Blue;
        mapColors["Black"] = Color::Black;

        mapCities["Algiers"] = City::Algiers;
        mapCities["Atlanta"] = City::Atlanta;
        mapCities["Baghdad"] = City::Baghdad;
        mapCities["Bangkok"] = City::Bangkok;
        mapCities["Beijing"] = City::Beijing;
        mapCities["Bogota"] = City::Bogota;
        mapCities["BuenosAires"] = City::BuenosAires;
        mapCities["Cairo"] = City::Cairo;
        mapCities["Chennai"] = City::Chennai;
        mapCities["Chicago"] = City::Chicago;
        mapCities["Delhi"] = City::Delhi;
        mapCities["Essen"] = City::Essen;
        mapCities["HoChiMinhCity"] = City::HoChiMinhCity;
        mapCities["HongKong"] = City::HongKong;
        mapCities["Istanbul"] = City::Istanbul;
        mapCities["Jakarta"] = City::Jakarta;
        mapCities["Johannesburg"] = City::Johannesburg;
        mapCities["Karachi"] = City::Karachi;
        mapCities["Khartoum"] = City::Khartoum;
        mapCities["Kinshasa"] = City::Kinshasa;
        mapCities["Kolkata"] = City::Kolkata;
        mapCities["Lagos"] = City::Lagos;
        mapCities["Lima"] = City::Lima;
        mapCities["London"] = City::London;
        mapCities["LosAngeles"] = City::LosAngeles;
        mapCities["Madrid"] = City::Madrid;
        mapCities["Manila"] = City::Manila;
        mapCities["MexicoCity"] = City::MexicoCity;
        mapCities["Miami"] = City::Miami;
        mapCities["Milan"] = City::Milan;
        mapCities["Montreal"] = City::Montreal;
        mapCities["Moscow"] = City::Moscow;
        mapCities["Mumbai"] = City::Mumbai;
        mapCities["NewYork"] = City::NewYork;
        mapCities["Osaka"] = City::Osaka;
        mapCities["Paris"] = City::Paris;
        mapCities["Riyadh"] = City::Riyadh;
        mapCities["SanFrancisco"] = City::SanFrancisco;
        mapCities["Santiago"] = City::Santiago;
        mapCities["SaoPaulo"] = City::SaoPaulo;
        mapCities["Seoul"] = City::Seoul;
        mapCities["Shanghai"] = City::Shanghai;
        mapCities["StPetersburg"] = City::StPetersburg;
        mapCities["Sydney"] = City::Sydney;
        mapCities["Taipei"] = City::Taipei;
        mapCities["Tehran"] = City::Tehran;
        mapCities["Tokyo"] = City::Tokyo;
        mapCities["Washington"] = City::Washington;

        ifstream cities_map{"cities_map.txt"};
        ifstream& file = cities_map;
        string line;
        string city;
        string neighbor;
        string color;
        while (getline(file, line)){
            istringstream istr(line);
            // city = line.substr(0,line.find_first_of(' '));
            // line = line.substr(line.find_first_of(' ')+1);
            // color = line.substr(0,line.find_first_of(' '));
            // cubesAndColors[mapCities[city]].first = mapColors[color];
            // cubesAndColors[mapCities[city]].second = 0;
            // line = line.substr(line.find_first_of(' ')+1);
            // while (line.find(' ') != std::string::npos){
            //     neighbor = line.substr(0,line.find_first_of(' '));
            //     connections[mapCities[city]].insert(mapCities[neighbor]);
            //     line = line.substr(line.find_first_of(' ')+1);
            // }
            
            istr >> city;
            istr >> color;
            cubesAndColors[mapCities[city]].first = mapColors[color];
            cubesAndColors[mapCities[city]].second = 0;
            while (istr >> neighbor){
                connections[mapCities[city]].insert(mapCities[neighbor]);
            } 
        }
    }
    
    int& pandemic::Board::operator[](pandemic::City city){
        return this->cubesAndColors.at(city).second;
    }

    bool pandemic::Board::is_clean(){
        for (auto i = cubesAndColors.begin(); i != cubesAndColors.end(); i++){
            if ((i->second).second != 0){
                return false;
            }
        }
        return true;
    }
    ostream& operator<<(ostream& os, const pandemic::Board& input){
        return os;
    }

    void pandemic::Board::remove_cures(){
        for (auto i = Board::cubesAndColors.begin(); i != Board::cubesAndColors.end(); i++){
            (i->second).second = 0;
        }
        cures.clear();
    }
}

