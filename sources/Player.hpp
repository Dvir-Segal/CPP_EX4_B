#pragma once 
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
#include <set>
#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"
using namespace std;

namespace pandemic{
    class Player{
        protected:
            Board& board;
            City myCity;
            set<City> cards;
            

        public:
            Player(Board& b, City c): board(b), myCity(c){}
            virtual Player& drive(City city);
            virtual Player& fly_direct(City city);
            virtual Player& fly_charter(City city);
            virtual Player& fly_shuttle(City city);
            virtual Player& build();
            virtual void discover_cure(Color color);
            virtual Player& treat(City city);
            virtual string role() = 0;
            virtual Player& take_card(City city);   
            virtual void remove_cards();
            int numColors(Color& color);
            void throwCards(Color& color, int num);
    };
}
