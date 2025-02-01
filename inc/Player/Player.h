#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
public:
    Player();
    Player(const std::string& newPlayerName);

    void setName(const std::string& newPlayerName);
    const std::string& getName() const;
private:
    std::string playerName;
};

#endif