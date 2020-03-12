#include "card_deck.h"

#include <algorithm>
#include <random>

std::pair<Card::Rank, Card::Suit> Card::decode(uint8_t value) {
  Card::Suit suit = static_cast<Card::Suit>((value & 0xC0) >> 6);
  Card::Rank rank = static_cast<Card::Rank>(value & 0x3F);

  return std::make_pair(rank, suit);
}

uint8_t Card::encode(Card::Rank rank, Card::Suit suit) {
  return (suit << 6) + rank;
}

std::vector<Card> get_new_deck() {
  std::vector<Card> temp;

  temp.reserve(Card::Rank::rLast * Card::Suit::Last);

  for (uint8_t suit = Card::Suit::Hearts; suit < Card::Suit::Last; ++suit) {
    for (uint8_t rank = Card::Rank::rA; rank < Card::Rank::rLast; ++rank) {
      temp.emplace_back(static_cast<Card::Rank>(rank),
                        static_cast<Card::Suit>(suit));
    }
  }

  return temp;
}

void shuffle(std::vector<Card>& deck) {
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(deck.begin(), deck.end(), g);
}

bool isFlush(const std::vector<Card>& cards) {
  if (cards.size() == 0) return false;

  const std::pair<Card::Rank, Card::Suit> first = Card::decode(cards[0].data);

  for (std::size_t i = 1; i < cards.size(); ++i) {
    if (first.second != Card::decode(cards[i].data).second) return false;
  }

  return true;
}

bool isStraight(const std::vector<Card>& cards) {
  if (cards.size() == 0) return false;

  uint8_t min_rank = Card::Rank::rA;
  uint8_t max_rank = Card::Rank::rA;
  std::pair<Card::Rank, Card::Suit> temp;

  for (const auto& card : cards) {
    temp = Card::decode(card.data);
    if (temp.first < min_rank) {
      min_rank = temp.first;
    } else if (temp.first > max_rank) {
      max_rank = temp.first;
    }
  }

  return cards.size() == (max_rank - min_rank + 1);
}

std::ostream& operator<<(std::ostream& os, const Card::Rank& value) {
  switch (value) {
    case Card::Rank::r2:
      os << '2';
      break;
    case Card::Rank::r3:
      os << '3';
      break;
    case Card::Rank::r4:
      os << '4';
      break;
    case Card::Rank::r5:
      os << '5';
      break;
    case Card::Rank::r6:
      os << '6';
      break;
    case Card::Rank::r7:
      os << '7';
      break;
    case Card::Rank::r8:
      os << '8';
      break;
    case Card::Rank::r9:
      os << '9';
      break;
    case Card::Rank::r10:
      os << "10";
      break;
    case Card::Rank::rJ:
      os << 'J';
      break;
    case Card::Rank::rQ:
      os << 'Q';
      break;
    case Card::Rank::rK:
      os << 'K';
      break;
    case Card::Rank::rA:
      os << 'A';
      break;
    default:
      break;
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const Card::Suit& value) {
  switch (value) {
    case Card::Suit::Hearts:
      os << 'H';
      break;
    case Card::Suit::Diamonds:
      os << 'D';
      break;
    case Card::Suit::Clubs:
      os << 'C';
      break;
    case Card::Suit::Spades:
      os << 'S';
      break;
    default:
      break;
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
  std::pair<Card::Rank, Card::Suit> temp = Card::decode(card.data);
  os << temp.first << '-' << temp.second;
  return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<Card>& deck) {
  for (const auto& card : deck) os << card << ' ';
  return os;
}
