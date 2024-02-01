// Angel Velazquez
// CST-210
#pragma once

#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <string>
#include <random>
#include <vector>

using namespace std;

class Battle
{
  private:
    Player m_player;
    Enemy m_enemy;
    bool m_battleStatus;

  public:
    Battle();
    Battle(Player &);
    Battle(Player &, Enemy);
    Player GetPlayer() const;
    Enemy GetEnemy() const;
    void SetPlayer(Player);
    void SetEnemy(Enemy);
    int Attack(string, Character &);
};
