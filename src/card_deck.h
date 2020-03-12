#ifndef CARD_DECK_H_
#define CARD_DECK_H_

#include <iostream>
#include <utility>
#include <vector>

struct Card {
  enum Rank : uint8_t {
    rA,
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
    rLast
  };
  enum Suit : uint8_t { Hearts, Diamonds, Clubs, Spades, Last };
  uint8_t data;

  static uint8_t encode(Rank rank, Suit suit);

  static std::pair<Rank, Suit> decode(uint8_t value);

  Card(Rank rank, Suit suit) : data(Card::encode(rank, suit)) {}
};

std::vector<Card> get_new_deck();
void shuffle(std::vector<Card>& deck);
bool isFlush(const std::vector<Card>& cards);
bool isStraight(const std::vector<Card>& cards);

std::ostream& operator<<(std::ostream& os, const Card::Rank& value);
std::ostream& operator<<(std::ostream& os, const Card::Suit& value);
std::ostream& operator<<(std::ostream& os, const Card& card);
std::ostream& operator<<(std::ostream& os, const std::vector<Card>& deck);

#endif
