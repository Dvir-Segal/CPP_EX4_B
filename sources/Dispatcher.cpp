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
#include "Dispatcher.hpp"
using namespace std;

namespace pandemic{
    string pandemic::Dispatcher::role(){
        return "Dispatcher";
    }

    Dispatcher& pandemic::Dispatcher::fly_direct(City city){
        if(myCity==city){
            throw out_of_range("Invalid fly_direct");
        }
        if (board.hasStation(myCity)){
            myCity = city;
            return *this;
        }
        if (cards.find(city) != cards.end()){
            myCity = city;
            cards.erase(city);
            return *this;
        }        
        throw out_of_range("Invalid fly_direct");      
        
    }
}

