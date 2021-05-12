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
#include "Researcher.hpp"
using namespace std;

namespace pandemic{
    string pandemic::Researcher::role(){
        return "Researcher";
    }

    void pandemic::Researcher::discover_cure(Color color){
        if(board.inCures(color)){
            return;
        }
        const int num=5;
        if (numColors(color)<num){
            throw out_of_range("Invalid Operation");
        }
        throwCards(color, num);   
        board.addCure(color);
    }        
}

