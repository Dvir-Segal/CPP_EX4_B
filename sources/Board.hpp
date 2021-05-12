#pragma once 
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <climits>
#include <unordered_map>
#include <map>
#include <set>
#include <bits/stdc++.h>
#include <utility>
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic{
    class Board{
        protected:
            map<pandemic::City, set<pandemic::City>> connections;
            static map<string, pandemic::Color> mapColors;
            static map<string, pandemic::City> mapCities;
            map<City, pair<pandemic::Color, int>> cubesAndColors;
            set<pandemic::City> stations;
            set<pandemic::Color> cures;
         

        public:
            Board();
            int& operator[](pandemic::City c);
            friend ostream& operator<<(ostream& os, const pandemic::Board& input);
            bool is_clean();
            void remove_cures();
            void remove_stations(){stations.clear();}
            bool isNeighbor(City c1, City& c2){
                if (c1==c2){
                    return false;
                }
                return (find(connections[c1].begin(), connections[c1].end(), c2) != connections[c1].end());
            }
            bool hasStation(City& city){
                return (stations.find(city) != stations.end());
            }
            void addStation(City& city){
                stations.insert(city);
            }
            bool inCures(Color& color){
                return (cures.find(color) != cures.end());
            }
            void addCure(Color& color){
                cures.insert(color);
            }
            Color& colorByCity(City city){
                return cubesAndColors.at(city).first;
            }     
    };
}