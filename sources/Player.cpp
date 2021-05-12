#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <climits>
#include <unordered_map>
#include <map>
#include <set>
#include <bits/stdc++.h>
#include <utility>
#include "Player.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"
using namespace std;
using namespace pandemic;

    const int forCure = 5;
    Player& pandemic::Player::drive(pandemic::City city){
        if ( myCity != city && board.isNeighbor(myCity, city)){
            myCity = city;
            return *this;
        }
        throw out_of_range("Invalid drive");
        
    }

    Player& pandemic::Player::fly_direct(pandemic::City city){
        if (cards.find(city) != cards.end()){
            myCity = city;
            cards.erase(city);
            return *this;
        }        
        throw out_of_range("Invalid fly_direct");
    }

    Player& Player::fly_charter(City city){
        if (cards.find(myCity) == cards.end() || myCity==city){
            throw out_of_range("Invalid fly_charter");
        }   
        cards.erase(myCity);     
        myCity = city;
        return *this;
    }

    Player& pandemic::Player::fly_shuttle(pandemic::City city){
        if (!board.hasStation(myCity) || !board.hasStation(city) || myCity == city){
            throw out_of_range("Invalid fly_shuttle");
        }
        myCity = city;
        return *this;
    }

    Player& pandemic::Player::build(){
        if (board.hasStation(myCity)){
            return *this;
        }
        if (cards.count(myCity)==0){
            throw out_of_range("Invalid build");   
        }
        board.addStation(myCity);
        cards.erase(myCity);
        return *this;
    }

    void pandemic::Player::discover_cure(pandemic::Color color){
        if(board.inCures(color)){
            return;
        }
        if (!board.hasStation(myCity)){
            throw out_of_range("Invalid discover_cure");
        }
        const int num=5;
        if (numColors(color)<num){
            throw out_of_range("Invalid Operation");
        }
        throwCards(color, num);
        board.addCure(color);   
    }     

    Player& pandemic::Player::treat(pandemic::City city){
        if (myCity != city || board[city] == 0){
            throw out_of_range("Invalid treat");
        }
        if (board.inCures(board.colorByCity(city))){
            board[city] = 0;
        }
        else{
            board[city]--;
        }
        return *this;
    }

    Player& Player::take_card(pandemic::City city){
        cards.insert(city);
        return *this;
    }

    void Player::remove_cards(){
        cards.clear();
    }

    int Player::numColors(Color& color){
        int i=0;
        for (auto city: cards){
            if (board.colorByCity(city)==color){
                i++;
            }
        }
        return i;
    }

    void Player::throwCards(Color& color, int num){
        int i = 0;
        for (auto it = cards.begin(); it != cards.end();){
            if (board.colorByCity(*it)==color){
                cards.erase(it++);
                i++;
                if(i==num){
                    return;
                }
            }
            else{
                ++it;
            }
        }      
    }


