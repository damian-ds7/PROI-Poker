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

std::string Card::get_file_path() const noexcept{
    std::string file_name = ":/resources/Deck/";
    switch(m_suit){
        case Suit::Hearts:
            file_name += "hearts_";
            break;
        case Suit::Diamonds:
            file_name += "diamonds_";
            break;
        case Suit::Clubs:
            file_name += "clubs_";
            break;
        case Suit::Spades:
            file_name += "spades_";
            break;
    }
    switch(m_value){
        case Value::Two:
            file_name += "two";
            break;
        case Value::Three:
            file_name += "three";
            break;
        case Value::Four:
            file_name += "four";
            break;
        case Value::Five:
            file_name += "five";
            break;
        case Value::Six:
            file_name += "six";
            break;
        case Value::Seven:
            file_name += "seven";
            break;
        case Value::Eight:
            file_name += "eight";
            break;
        case Value::Nine:
            file_name += "nine";
            break;
        case Value::Ten:
            file_name += "ten";
            break;
        case Value::Jack:
            file_name += "jack";
            break;
        case Value::Queen:
            file_name += "queen";
            break;
        case Value::King:
            file_name += "king";
            break;
        case Value::Ace:
            file_name += "ace";
            break;
    }
    file_name += ".png";
    return file_name;
}
