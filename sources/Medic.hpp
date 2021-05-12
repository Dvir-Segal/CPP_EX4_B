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
#include <queue>
#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace std;

namespace pandemic{
    class Medic: public Player{
        
        
        public:
            Medic(Board& b, City c): Player(b, c){};
            string role();
            Medic& drive(City city);
            Medic& fly_direct(City city);
            Medic& fly_charter(City city);
            Medic& fly_shuttle(City city);
            Medic& treat(City city);
    };
}

