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
    class OperationsExpert: public Player{
        
        
        public:
            OperationsExpert(Board& b, City c): Player(b, c){}
            string role();
            OperationsExpert& build();
    };
}

