#include "Card.h"

Suit Card::suit() const noexcept {
    return m_suit;
}

Value Card::value() const noexcept {
    return m_value;
}

unsigned int Card::card_index() const noexcept {
    return index;
}

Card::Card(Suit suit, Value value) : m_suit(suit), m_value(value) {
    index = 4 * static_cast<int>(value) + static_cast<int>(suit);
};

bool Card::operator==(const Card& other) const noexcept {
    return m_value == other.m_value;
}

bool Card::operator!=(const Card& other) const noexcept {
    return !(*this == other);
}

bool Card::operator<(const Card& other) const noexcept {
    return m_value < other.m_value;
}

bool Card::operator>(const Card& other) const noexcept {
    return m_value > other.m_value;
}

bool Card::operator<=(const Card& other) const noexcept {
    return m_value <= other.m_value;
}

bool Card::operator>=(const Card& other) const noexcept {
    return m_value >= other.m_value;
}

bool Card::operator==(const Value& other) const noexcept {
    return m_value == other;
}

bool Card::operator!=(const Value& other) const noexcept {
    return m_value != other;
}

bool Card::operator<(const Value& other) const noexcept {
    return m_value < other;
}

bool Card::operator>(const Value& other) const noexcept {
    return m_value > other;
}

bool Card::operator<=(const Value& other) const noexcept {
    return m_value <= other;
}

bool Card::operator>=(const Value& other) const noexcept {
    return m_value >= other;
}

std::string Card::to_string() const noexcept {
    std::string repr;
    switch(m_value) {
        case Value::Two:
            repr += "2";
            break;
        case Value::Three:
            repr += "3";
            break;
        case Value::Four:
            repr += "4";
            break;
        case Value::Five:
            repr += "5";
            break;
        case Value::Six:
            repr += "6";
            break;
        case Value::Seven:
            repr += "7";
            break;
        case Value::Eight:
            repr += "8";
            break;
        case Value::Nine:
            repr += "9";
            break;
        case Value::Ten:
            repr += "10";
            break;
        case Value::Jack:
            repr += "J";
            break;
        case Value::Queen:
            repr += "Q";
            break;
        case Value::King:
            repr += "K";
            break;
        case Value::Ace:
            repr += "A";
            break;
    }
    switch(m_suit) {
        case Suit::Hearts:
            repr += "h";
            break;
        case Suit::Diamonds:
            repr += "d";
            break;
        case Suit::Clubs:
            repr += "c";
            break;
        case Suit::Spades:
            repr += "s";
            break;
    }
    return repr;
}
