// card.cpp file
#include<cstring>
#include<iostream>
#include "card.hpp"

Card::Card() {
  suit = 0;
  num = 0;
}

Card::Card(int s, int n) {
  suit = s;
  num = n;
}

void Card::setSuit(int s) {
  suit = s; 
}

void Card::setNum(int n) {
  num = n;
}

int Card::getSuit() const {
  return suit;
}

int Card::getNum() const {
  return num;
}

void Card::print() const {
  std::string suitNames [4] = {"C", "D", "H", "S"};
  std::string rankNames [13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
  std::cout << suitNames[suit] << " " << rankNames[num-2] << std::endl;
}

bool Card::operator < (const Card& card) const
{
    return (num < card.num);
}