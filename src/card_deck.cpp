#include "card_deck.h"

#include <algorithm>
#include <random>

const std::vector<std::string> kSuitNames = {"\u2665", "\u2666", "\u2663",
                                             "\u2660"};
const std::vector<std::string> kRankNames = {"A", "2", "3",  "4", "5", "6", "7",
                                             "8", "9", "10", "J", "Q", "K"};

uint8_t Card::encode(Card::Rank rank, Card::Suit suit) {
  return (static_cast<uint8_t>(suit) << 6) + static_cast<uint8_t>(rank);
}

Card::Rank Card::rank() const { return static_cast<Card::Rank>(data & 0x3F); }

Card::Suit Card::suit() const {
  return static_cast<Card::Suit>((data & 0xC0) >> 6);
}

std::vector<Card> get_new_deck() {
  std::vector<Card> temp;

  temp.reserve((Card::Rank::Last - Card::Rank::First) *
               (Card::Suit::Last - Card::Suit::First));

  for (auto suit = Card::Suit::First; suit < Card::Suit::Last; ++suit)
    for (auto rank = Card::Rank::First; rank < Card::Rank::Last; ++rank)
      temp.emplace_back(rank, suit);

  return temp;
}

void shuffle(std::vector<Card>& deck) {
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(deck.begin(), deck.end(), g);
}

bool isFlush(const std::vector<Card>& cards) {
  if (cards.size() == 0) return false;

  const Card::Suit first_suit = cards[0].suit();
  for (const auto& card : cards)
    if (first_suit != card.suit()) return false;

  return true;
}

bool isStraight(const std::vector<Card>& cards) {
  if (cards.size() == 0) return false;

  Card::Rank min_rank = cards[0].rank();
  Card::Rank max_rank = cards[0].rank();

  for (const auto& card : cards) {
    if (card.rank() < min_rank) {
      min_rank = card.rank();
    } else if (card.rank() > max_rank) {
      max_rank = card.rank();
    }
  }

  if (max_rank == Card::Rank::rK && min_rank == Card::Rank::rA) return true;

  return cards.size() == (max_rank - min_rank + 1);
}

uint8_t operator-(const Card::Rank& lh, const Card::Rank& rh) {
  return static_cast<uint8_t>(lh) - static_cast<uint8_t>(rh);
}

uint8_t operator-(const Card::Suit& lh, const Card::Suit& rh) {
  return static_cast<uint8_t>(lh) - static_cast<uint8_t>(rh);
}

Card::Rank& operator++(Card::Rank& rank) {
  if (rank == Card::Rank::Last) return rank;
  rank = static_cast<Card::Rank>(static_cast<uint8_t>(rank) + 1);
  return rank;
}

Card::Rank operator++(Card::Rank& rank, int) {
  Card::Rank temp = rank;
  ++rank;
  return temp;
}

Card::Suit& operator++(Card::Suit& suit) {
  if (suit == Card::Suit::Last) return suit;
  suit = static_cast<Card::Suit>(static_cast<uint8_t>(suit) + 1);
  return suit;
}

Card::Suit operator++(Card::Suit& suit, int) {
  Card::Suit temp = suit;
  ++suit;
  return temp;
}

std::ostream& operator<<(std::ostream& os, const Card::Rank& value) {
  os << kRankNames[value - Card::Rank::First];
  return os;
}

std::ostream& operator<<(std::ostream& os, const Card::Suit& value) {
  os << kSuitNames[value - Card::Suit::First];
  return os;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
  os << card.rank() << card.suit();
  return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<Card>& deck) {
  for (const auto& card : deck) os << card << ' ';
  return os;
}
