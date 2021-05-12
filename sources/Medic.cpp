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
#include "Medic.hpp"
using namespace std;

namespace pandemic{
    string pandemic::Medic::role(){
        return "Medic";
    }

    Medic& pandemic::Medic::drive(City city){
        if (board.isNeighbor(myCity, city)){
            myCity = city;
            if(board.inCures((board.colorByCity(myCity)))){
                board[myCity] = 0;
            }
            return *this;
        }
        throw out_of_range("Invalid drive");
    }

    Medic& pandemic::Medic::fly_direct(City city){
        if (cards.find(city) != cards.end()){
            myCity = city;
            if(board.inCures((board.colorByCity(myCity)))){
                board[myCity] = 0;
            }
            cards.erase(city);
            return *this;
        }        
        throw out_of_range("Invalid fly_direct");
    }

    Medic& pandemic::Medic::fly_charter(City city){
        if (cards.find(myCity) != cards.end()){
            myCity = city;
            if(board.inCures((board.colorByCity(myCity)))){
                board[myCity] = 0;
            }
            cards.erase(myCity);
            return *this;
        }        
        throw out_of_range("Invalid fly_charter");
    }

    Medic& pandemic::Medic::fly_shuttle(City city){
        if (board.hasStation(city)){
            myCity = city;
            if(board.inCures((board.colorByCity(myCity)))){
                board[myCity] = 0;
            }
            return *this;
        }
        throw out_of_range("Invalid fly_shuttle");
    }

    Medic& pandemic::Medic::treat(City city){
        if (myCity != city || board[city] == 0){
            throw out_of_range("Invalid treat");
        }
        board[city] = 0;
        return *this;
    }
}

