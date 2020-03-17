#ifndef CARD_DECK_H_
#define CARD_DECK_H_

#include <iostream>
#include <vector>

struct Card {
  enum struct Rank : uint8_t {
    First = 1,
    rA = First,
    r2,
    r3,
    r4,
    r5,
    r6,
    r7,
    r8,
    r9,
    r10,
    rJ,
    rQ,
    rK,
    Last,
  };

  enum struct Suit : uint8_t {
    First = 0,
    Hearts = First,
    Diamonds,
    Clubs,
    Spades,
    Last,
  };

  uint8_t data;

  static uint8_t encode(Rank rank, Suit suit);

  Card(Rank rank, Suit suit) : data(Card::encode(rank, suit)) {}

  inline Rank rank() const;
  inline Suit suit() const;
};

std::vector<Card> get_new_deck();
void shuffle(std::vector<Card>& deck);
bool isFlush(const std::vector<Card>& cards);
bool isStraight(const std::vector<Card>& cards);

uint8_t operator-(const Card::Rank& lh, const Card::Rank& rh);
uint8_t operator+(const Card::Rank& lh, const Card::Rank& rh);

uint64_t operator*(uint64_t lh, const Card::Rank& rh);
uint64_t operator*(const Card::Rank& lh, uint64_t rh);

uint64_t operator+=(uint64_t& lh, const Card::Rank& rh);
uint64_t operator+(uint64_t lh, const Card::Rank& rh);

Card::Rank operator-(const Card::Rank& lh, uint64_t rh);

Card::Rank& operator++(Card::Rank& rank);
Card::Rank operator++(Card::Rank& rank, int);

uint8_t operator-(const Card::Suit& lh, const Card::Suit& rh);

Card::Suit& operator++(Card::Suit& suit);
Card::Suit operator++(Card::Suit& suit, int);

std::ostream& operator<<(std::ostream& os, const Card::Rank& value);
std::ostream& operator<<(std::ostream& os, const Card::Suit& value);
std::ostream& operator<<(std::ostream& os, const Card& card);
std::ostream& operator<<(std::ostream& os, const std::vector<Card>& deck);

#endif  // CARD_DECK_H_
