#include <algorithm>
#include <iostream>
#include <vector>

#include "card_deck.h"
int main() {
  std::vector<Card> deck = get_new_deck();
  std::vector<Card> cards;

  const std::size_t kTestCase1CardCount = 5;

  cards.reserve(kTestCase1CardCount);

  std::copy_n(deck.cbegin(), cards.capacity(), std::back_inserter(cards));

  std::cout << "Cards: " << cards << std::endl;
  std::cout << "is flush: " << isFlush(cards) << std::endl;
  std::cout << "is staight: " << isStraight(cards) << std::endl;
  std::cout << std::endl;

  shuffle(deck);
  cards.clear();
  std::copy_n(deck.cbegin(), cards.capacity(), std::back_inserter(cards));

  std::cout << "Cards: " << cards << std::endl;
  std::cout << "is flush: " << isFlush(cards) << std::endl;
  std::cout << "is staight: " << isStraight(cards) << std::endl;
  std::cout << std::endl;

  cards.clear();
  cards = {
      Card(Card::Rank::rA, Card::Suit::Hearts),
      Card(Card::Rank::r5, Card::Suit::Diamonds),
      Card(Card::Rank::r2, Card::Suit::Clubs),
      Card(Card::Rank::r3, Card::Suit::Spades),
      Card(Card::Rank::r4, Card::Suit::Hearts),
  };
  std::cout << "Cards: " << cards << std::endl;
  std::cout << "is staight: " << isStraight(cards) << std::endl;
  std::cout << std::endl;

  cards.clear();
  cards = {
      Card(Card::Rank::rA, Card::Suit::Hearts),
      Card(Card::Rank::r5, Card::Suit::Diamonds),
      Card(Card::Rank::r3, Card::Suit::Clubs),
      Card(Card::Rank::r4, Card::Suit::Spades),
      Card(Card::Rank::r6, Card::Suit::Hearts),
  };
  std::cout << "Cards: " << cards << std::endl;
  std::cout << "is staight: " << isStraight(cards) << std::endl;
  std::cout << std::endl;

  cards.clear();
  cards = {
      Card(Card::Rank::r6, Card::Suit::Hearts),
      Card(Card::Rank::r7, Card::Suit::Diamonds),
      Card(Card::Rank::r10, Card::Suit::Clubs),
      Card(Card::Rank::r9, Card::Suit::Spades),
      Card(Card::Rank::r8, Card::Suit::Hearts),
  };
  std::cout << "Cards: " << cards << std::endl;
  std::cout << "is staight: " << isStraight(cards) << std::endl;
  std::cout << std::endl;

  cards.clear();
  cards = {
      Card(Card::Rank::r10, Card::Suit::Hearts),
      Card(Card::Rank::rK, Card::Suit::Diamonds),
      Card(Card::Rank::rA, Card::Suit::Clubs),
      Card(Card::Rank::rJ, Card::Suit::Spades),
      Card(Card::Rank::rQ, Card::Suit::Hearts),
  };
  std::cout << "Cards: " << cards << std::endl;
  std::cout << "is staight: " << isStraight(cards) << std::endl;
  std::cout << std::endl;

  cards.clear();
  cards = {
      Card(Card::Rank::r8, Card::Suit::Hearts),
      Card(Card::Rank::rK, Card::Suit::Diamonds),
      Card(Card::Rank::rA, Card::Suit::Clubs),
      Card(Card::Rank::rJ, Card::Suit::Spades),
      Card(Card::Rank::rQ, Card::Suit::Hearts),
  };
  std::cout << "Cards: " << cards << std::endl;
  std::cout << "is staight: " << isStraight(cards) << std::endl;
  std::cout << std::endl;

  return 0;
}
