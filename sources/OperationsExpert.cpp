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
#include "OperationsExpert.hpp"
using namespace std;

namespace pandemic{
        
    string pandemic::OperationsExpert::role(){
        return "OperationsExpert";
    }

    OperationsExpert& pandemic::OperationsExpert::build(){
        board.addStation(myCity);
        return *this;
    }
    
}

