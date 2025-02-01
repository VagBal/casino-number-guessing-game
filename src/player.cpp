#include "../inc/Player/Player.h"

Player::Player() : playerName("") {}

Player::Player(const std::string& newPlayerName) : playerName(newPlayerName) {}

void Player::setName(const std::string& newPlayerName)
{
    this->playerName = newPlayerName;
}

const std::string& Player::getName() const
{
    return playerName;
}