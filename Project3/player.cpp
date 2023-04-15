#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include "player.h"

void Player::addCards(vector<Card> winningCards) // add winning cards to the end of the cards at hand
{
    for (int i = 0; i < winningCards.size(); i++)
    {
        cards.push_back(winningCards[i]);
    }
}

void Player::print() // print cards in player's hand
{
    for (int i = 0; i < cards.size(); i++)
    {
        cards[i].print();
    }
}

void Player::dropCards() // drop THREE cards from the front of cards at hand
{
    for (int i = 0; i < 3; i++)
    {
        cards.pop_front();
    }
}

void Player::play_a_card() // play one card from the front of cards at hand
{
    cards.pop_front();
}

void Player::getNumCards() // return how many cards player holds currently
{
    return cards.size();
}

