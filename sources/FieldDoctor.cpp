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
#include "FieldDoctor.hpp"
using namespace std;

namespace pandemic{
    string pandemic::FieldDoctor::role(){
        return "FieldDoctor";
    }

    FieldDoctor& pandemic::FieldDoctor::treat(City city){
        if (board[city] == 0){
            throw out_of_range("Invalid treat");
        }
        if (myCity != city){
            if (!board.isNeighbor(myCity, city)){
                throw out_of_range("Invalid treat");
            }
        }
        if (board.inCures(board.colorByCity(city))){
            board[city] = 0;
        }
        else{
            board[city]--;
        }
        return *this;
    }
}

