// Angel Velazquez
// CST-210
#pragma once

#include "Character.h"
#include <vector>
#include <iostream>

class Player : public Character
{
  private:
    int m_level;
    int m_experience;
    int m_currency;

  public:
    Player();
    Player(string);
    Player(string, int, int, int, int, int);
    int GetLevel() const;
    int GetExperience() const;
    int GetCurrency() const;
    void SetLevel(int);
    void SetExperience(int);
    void SetCurrency(int);
    void LevelUp();
    string GetType() const;
    void ShowPlayer();
    friend ostream &operator<<(ostream &, const Player &);
    friend istream &operator>>(istream &, Player &);
};
