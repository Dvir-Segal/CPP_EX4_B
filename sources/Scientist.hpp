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
    class Scientist: public Player{
        
        int n;

        public:
            Scientist(Board& b, City c, int numCards): Player(b, c), n(numCards){};
            string role();
            void discover_cure(Color color);
    };
}

