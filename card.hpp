// card.hpp file
#ifndef CARD_HPP
#define CARD_HPP

class Card
{
  public:
      Card();
      Card(int s, int n);
      void setSuit(int s);
      void setNum(int n);
      int getSuit() const;
      int getNum() const;
      void print() const;    
      bool operator < (const Card& card) const;
  private:
      int suit;
      int num;
};

#endif

