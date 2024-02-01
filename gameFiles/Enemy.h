// Angel Velazquez
// CST-210
#pragma once

#include "Character.h"
#include <random>

class Enemy: public Character
{
  private:
    int m_action;
    int m_currencyDropped;
    int m_xpDropped;
    int m_mdMin;
    int m_mdMax;
    int m_damage;

  public:
    Enemy();
    Enemy(string, int, int, int, int, int);
    void SetCurrencyDropped();
    int GetCurrencyDropped();
    int RandAction();
    string GetType() const;
    int GetXpDropped() const;
    int GetDamage();
    int Attack();
};
