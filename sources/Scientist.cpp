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
#include "Scientist.hpp"
using namespace std;

namespace pandemic{
    string pandemic::Scientist::role(){           
        return "Scientist";
    }

    void pandemic::Scientist::discover_cure(Color color){
        if(board.inCures(color)){
            return;
        }
        if (numColors(color)<n || !board.hasStation(myCity)){
            throw out_of_range("Invalid Operation");
        }
        throwCards(color, n);   
        board.addCure(color);
    }
}

