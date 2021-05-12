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
#include "GeneSplicer.hpp"
using namespace std;

namespace pandemic{
   string pandemic::GeneSplicer::role(){
        return "GeneSplicer";
    }
    
    void pandemic::GeneSplicer::discover_cure(Color color){
            if(board.inCures(color)){
            return;
        }
        const int num=5;
        if (cards.size()<num || !board.hasStation(myCity)){
            throw out_of_range("Invalid Operation");
        }
        int i = 0;
        for (auto it = cards.begin(); it != cards.end();){
            cards.erase(it++);
            i++;
            if(i==num){
                return;
            }
            ++it;
        }
        board.addCure(color);   
    }
}

