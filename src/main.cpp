#include <algorithm>
#include <iostream>
#include <vector>

#include "card_deck.h"
int main(int argc, char **argv) {
  std::vector<Card> deck = get_new_deck();
  std::vector<Card> cards;

  const std::size_t kTestCase1CardCount = 5;

  cards.reserve(kTestCase1CardCount);

  std::copy_n(deck.cbegin(), kTestCase1CardCount, std::back_inserter(cards));

  std::cout << "Cards: " << cards << std::endl;
  std::cout << "is flush: " << isFlush(cards) << std::endl;
  std::cout << "is staight: " << isStraight(cards) << std::endl;
  std::cout << std::endl;

  shuffle(deck);
  cards.clear();
  std::copy_n(deck.cbegin(), kTestCase1CardCount, std::back_inserter(cards));

  std::cout << "Cards: " << cards << std::endl;
  std::cout << "is flush: " << isFlush(cards) << std::endl;
  std::cout << "is staight: " << isStraight(cards) << std::endl;
  std::cout << std::endl;

  cards.clear();
  cards = {
      Card(Card::Rank::rA, Card::Suit::Hearts),
      Card(Card::Rank::r5, Card::Suit::Hearts),
      Card(Card::Rank::r2, Card::Suit::Hearts),
      Card(Card::Rank::r3, Card::Suit::Hearts),
      Card(Card::Rank::r4, Card::Suit::Hearts),
  };
  std::cout << "Cards: " << cards << std::endl;
  std::cout << "is staight: " << isStraight(cards) << std::endl;
  std::cout << std::endl;

  cards.clear();
  cards = {
      Card(Card::Rank::rA, Card::Suit::Hearts),
      Card(Card::Rank::r5, Card::Suit::Hearts),
      Card(Card::Rank::r3, Card::Suit::Hearts),
      Card(Card::Rank::r4, Card::Suit::Hearts),
      Card(Card::Rank::r6, Card::Suit::Hearts),
  };
  std::cout << "Cards: " << cards << std::endl;
  std::cout << "is staight: " << isStraight(cards) << std::endl;
  std::cout << std::endl;

  return 0;
}
