// Group 10 - Daniel Ye, Abdullah Shahid, Kevin Li
#include <iostream>
#include<cstdlib>
#include <time.h>
#include <vector>
#include <bits/stdc++.h>
#include "card.hpp"

using namespace std;

/*
  C - 0 - Clubs
  D - 1 - Diamonds
  H - 2 - Hearts
  S - 3 - Spades
  
  2
  3
  4
  5
  6
  7
  8
  9
  10
  11 - Jack 
  12 - Queen 
  13 - King
  14 - Ace
*/

const int MAX_DECK_SIZE = 52;
const int NUM_SUITS = 4;
const int NUM_RANKS = 13;

int randomNum(int, int);
Card getRandomCard(vector<Card>);
bool isPulled(Card, vector<Card>);
int isFlush(vector<Card>);
int isStraight(vector<Card>);
int isStraightFlush(vector<Card>);
bool isRoyalFlush(vector<Card>);
bool isFullHouse(vector<Card>);
int isFourOfaKind(vector<Card>);
int isThreeOfaKind(vector<Card>);
int isPair(vector<Card>);
int isTwoPair(vector<Card>);
int isHighCard(vector<Card>);
void testHand(vector<Card>);

int main() {

  /* Generate a random seed. */
  srand(time(NULL));

  vector<Card> hand;
  cout << "Generating Hand:" << endl;
  for(int i = 0; i<2; i++)
  {
    Card card = getRandomCard(hand);
    hand.push_back(card);
    card.print();
  }
  cout << "Generating Flop:" << endl;
  for(int i = 0; i<3; i++)
  {
    Card card = getRandomCard(hand);
    hand.push_back(card);
    card.print();
  }
  
  testHand(hand);
  cout << "Adding one card:" << endl;
  Card extraCard1 = getRandomCard(hand);
  hand.push_back(extraCard1);
  extraCard1.print();
  testHand(hand);

  cout << "Adding one more card:" << endl;
  Card extraCard2 = getRandomCard(hand);
  hand.push_back(extraCard2);
  extraCard2.print();
  testHand(hand);
  
  //Test Straight
  vector<Card> handStraight;

  handStraight.push_back(Card(1, 2));
  handStraight.push_back(Card(1, 3));
  handStraight.push_back(Card(2, 3));
  handStraight.push_back(Card(0, 4));
  handStraight.push_back(Card(2, 5));
  handStraight.push_back(Card(3, 10));
  handStraight.push_back(Card(1, 14));

  cout << "Straight Hand:" << endl;
  for (auto i = handStraight.begin(); i != handStraight.end(); ++i) {
    i->print();
  }
  testHand(handStraight);

 //Test 4 of kind
  // vector<Card> handFourKind;

  // handFourKind.push_back(Card(0, 14));
  // handFourKind.push_back(Card(3, 14));
  // handFourKind.push_back(Card(2, 14));
  // handFourKind.push_back(Card(1, 14));
  // handFourKind.push_back(Card(1, 2));

  // cout << "4 of a Kind Hand:" << endl;
  // for (auto i = handFourKind.begin(); i != handFourKind.end(); ++i) {
  //   i->print();
  // }
  // testHand(handFourKind);
  // Expected output: Four of a Kind of Ace

  //Test Full House
  // vector<Card> handFullHouse;

  // handFullHouse.push_back(Card(3, 2));
  // handFullHouse.push_back(Card(0, 2));
  // handFullHouse.push_back(Card(2, 4));
  // handFullHouse.push_back(Card(3, 4));
  // handFullHouse.push_back(Card(3, 14));
  // handFullHouse.push_back(Card(2, 14));
  // handFullHouse.push_back(Card(1, 14));

  // cout << "Full House Hand:" << endl;
  // for (auto i = handFullHouse.begin(); i != handFullHouse.end(); ++i) {
  //   i->print();
  // }
  // testHand(handFullHouse);
  // Expected output: Full House with three of Ace and two of 4

  //Test Royal Flush
  // vector<Card> handRoyalFlush;
  
  // handRoyalFlush.push_back(Card(2, 9));

  // for(int i = 0; i<5; i++)
  // {
  //   handRoyalFlush.push_back(Card(0, 10 + i));
  // }

  // cout << "Royal Flush Hand:" << endl;
  // for (auto i = handRoyalFlush.begin(); i != handRoyalFlush.end(); ++i) {
  //   i->print();
  // }
  // testHand(handRoyalFlush);
  // Expected output: Royal Flush with suit: Clubs

  //Test Straight flush
  // vector<Card> handStraightFlush;

  // handStraightFlush.push_back(Card(3, 2));
  // handStraightFlush.push_back(Card(3, 14));
  // handStraightFlush.push_back(Card(3, 4));
  // handStraightFlush.push_back(Card(3, 3));
  // handStraightFlush.push_back(Card(3, 6));
  // handStraightFlush.push_back(Card(3, 5));

  // cout << "Straight Flush Hand:" << endl;
  // for (auto i = handStraightFlush.begin(); i != handStraightFlush.end(); ++i) {
  //   i->print();
  // }
  // testHand(handStraightFlush);
  // Expected output: Straight Flush with high card: 6 and suit: Spades

}

// Function used to test the ranking of each hands by first sorting them
void testHand(vector<Card> hand) {
  sort(hand.begin(), hand.end());
  string suitNames [4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
  string rankNames [13] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
  
  if(isRoyalFlush(hand) == true) {
    cout << "Royal Flush with suit: " << suitNames[isFlush(hand)] << endl;
  }
  else if(isStraightFlush(hand) != -1) {
    cout << "Straight Flush with high card: " << rankNames[isStraightFlush(hand)-2] 
    << " and suit: " << suitNames[isFlush(hand)] << endl;
  }
  else if(isFourOfaKind(hand) != -1) {
    cout << "Four of a Kind of " << rankNames[isFourOfaKind(hand)-2] << endl;
  }
  else if(isFullHouse(hand) == true) {
    if(isTwoPair(hand) == -1)
      cout << "Full House with three of " << rankNames[isThreeOfaKind(hand)-2] 
      << " and two of " << rankNames[isPair(hand)-2] << endl;
    else 
      cout << "Full House with three of " << rankNames[isThreeOfaKind(hand)-2] 
      << " and two of " << rankNames[isTwoPair(hand)-2] << endl;
  }
  else if( isFlush(hand) != -1) {
    cout << "Flush with suit: " << suitNames[isFlush(hand)] << endl;
  }
  else if(isStraight(hand) != -1) {
    cout << "Straight with high card: " << rankNames[isStraight(hand)-2] << endl; 
  }
  else if(isThreeOfaKind(hand) != -1) {
    cout << "Three of a kind of " << rankNames[isThreeOfaKind(hand)-2] << endl;
  }
  else if(isTwoPair(hand) != -1) {
    cout << "Two Pair of " << rankNames[isPair(hand)-2] << " and " << rankNames[isTwoPair(hand)-2] << endl; 
  }
  else if(isPair(hand) != -1) {
    cout << "One Pair of " << rankNames[isPair(hand)-2] << endl;
  }
  else if(isHighCard(hand) != -1) {
    cout << "High card is: " << rankNames[isHighCard(hand)-2] << endl;
  }
  cout << endl;
}

/* Returns a random integer between a minumum number and maximum number, exclusive of the maximum number */
int randomNum(int minNum, int maxNum) {
  return rand() % maxNum + minNum;
}

/* Returns a random card with a suit and rank that is not already in the given hand */
Card getRandomCard(vector<Card> hand) {
  Card card;
  do {
    /* minNum 0 corresponds to rank 2 of suit 0, the clubs suit */
    
    int randNum = randomNum(0, MAX_DECK_SIZE);
    int suit = randNum / NUM_RANKS;
    int rank = (randNum % NUM_RANKS) + 2;
    card = Card(suit, rank);

  } while (isPulled(card,hand));

  return card;
}

/* Returns a boolean condition indicating whether the card has already been pulled into the given hand, comparing the 
suit and rank of the card with the suits and ranks of the cards already in the hand. */
bool isPulled(Card card, vector<Card> hand) {
  for (auto i = hand.begin(); i != hand.end(); ++i) {
    if(i->getNum() == card.getNum() && i->getSuit() == card.getSuit()) {
      return true;
    }
  }

  return false;
}

/* The isFlush function returns the suit that makes up the flush, and -1 if no flush exists */
int isFlush(vector<Card> hand) {
    int suits [4] = {0};
    for(auto i = hand.begin(); i != hand.end(); ++i) {
      suits[i->getSuit()]++;
    }

    for(int i = 0; i<4; i++) {
      if(suits[i]>=5) {
        return i;
      }
    }
    
    return -1;
}

/* Returns the highest rank card of a straight if it exists in the hand, if no straight exits, return -1 */
int isStraight(vector<Card> hand) {
  int lastRankOfStraight = -1;
  int counter = 1;
  for(auto i = hand.begin(); i != hand.end()-1; ++i)
  { 
    if(i->getNum() != (i+1)->getNum() && i->getNum()+1 != (i+1)->getNum()) {
      counter = 1;
    }
    else if (i->getNum() != (i+1)->getNum()) {
      counter++;
      if(counter == 4 && (i+1)->getNum() == 5 && hand[hand.size()-1].getNum() == 14) {
        counter++;
      }

      if(counter >= 5) {
        lastRankOfStraight = (i+1)->getNum();
      }
    }
  }
  return lastRankOfStraight;
}

/* Uses the isFlush function to determine if a flush exists and if so, records the suit of the flush. A subset of 
   the hand is which contains only the cards that have the same suit as the flush is created. The function checks
   if a straight exists in the flushed hand by passing it into the isStraight function. The isStraight function
   returns the highest rank card. The highest rank card of the straight flush is then returned. If no straight 
   flush exists, -1 is returned. */
int isStraightFlush(vector<Card> hand) {
  int suit = isFlush(hand);
  if(suit == -1) {
    return -1;
  }

  vector<Card> flushHand;
  for(auto i = hand.begin(); i != hand.end(); ++i) {
    if(i->getSuit()==suit) {
      flushHand.push_back(*i);
    }
  }

  return isStraight(flushHand);
}

// This function determines if the hand is a Royal Flush. It initially checks if the hand is a flush
// then checks if the hand contains an Ace, King, Queen, Jack, and 10 all of the same suit.
bool isRoyalFlush(vector<Card> hand) {
  
  if (isStraightFlush(hand) == 14) {
    return true;
  }
  else {
    return false;
  }
}

// This function checks if the hand contains a full house by checking if the hand
// contains both a pair and a three of a kind simultaneously, which would mean it 
// contains a full house.
bool isFullHouse(vector<Card> hand) {
  if (isThreeOfaKind(hand) != -1 && isPair(hand) != -1)
    return true;
  else
    return false;
}

// This function checks if the hand contains 4 cards of the same value. Since the hand has already 
// been sorted, the function checks if the 1st and 3rd element are equivalent, the 2nd and 4th element
// are equivalent, etc.
int isFourOfaKind(vector<Card> hand) {
  if (hand.size() == 5) {
    if (hand[0].getNum() == hand[3].getNum() || hand[1].getNum() == hand[4].getNum()) {
      return hand[2].getNum();
    }
  }

  if (hand.size() == 6) {
    if (hand[0].getNum() == hand[3].getNum() || hand[1].getNum() == hand[4].getNum() ||
    hand[2].getNum() == hand[5].getNum()) {
      return hand[3].getNum();return hand[3].getNum();
    }
  }

  if (hand.size() == 7) {
    if (hand[0].getNum() == hand[3].getNum() || hand[1].getNum() == hand[4].getNum() || 
    hand[2].getNum() == hand[5].getNum() || hand[3].getNum() == hand[6].getNum()) {
      return hand[3].getNum();
    }
  }
    
  return -1;
}

// This function checks if the hand contains 3 cards of the same value, and will return that value
// if it exists, otherwise it will return -1
int isThreeOfaKind(vector<Card> hand) {
  for (auto i = hand.begin(); i != hand.end()-2; ++i) {
    if (i->getNum() == (i+1)->getNum() && i->getNum() == (i+2)->getNum())
      return i->getNum();
  }
  return -1;
}

// This funtion checks if the hand contains a pair. It also does a check to ensure
// that the pair is not contained within a three of a kind. It returns the value of
// the pair, otherwise it returns -1.
int isPair(vector<Card> hand) {
  int tripleCheck = 0;
  tripleCheck = isThreeOfaKind(hand);
  
  for(auto i = hand.begin(); i != hand.end()-1; ++i){
    if (i->getNum() == (i+1)->getNum() && i->getNum() != tripleCheck)
      return i->getNum();
  }

  return -1;
}

// This function checks if the hand contains two pairs. It initially checks if the 
// hand contains a singular pair, and then finds another pair that does not have the
// the same value as the first pair. It returns the value of the second pair, otherwise
// the function returns -1.
int isTwoPair(vector<Card> hand) {
  int tripleCheck = isThreeOfaKind(hand);
  int pairCheck = isPair(hand);

  if (pairCheck == -1)
    return -1;

  for(auto i = hand.begin(); i != hand.end()-1; ++i){
    if (i->getNum() == (i+1)->getNum() && i->getNum() != tripleCheck && i->getNum() != pairCheck)
      return i->getNum();
  }

  return -1;
}

// This function iterates through the hand to find the highest value card
// and returns its value.
int isHighCard(vector<Card> hand) {
  int highCard = hand[0].getNum();
  
  for (auto i = hand.begin(); i!= hand.end()-1; ++i){
    if ((i+1)->getNum() > i->getNum())
      highCard = (i+1)->getNum(); 
  }

  return highCard;
}


