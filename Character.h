// Angel Velazquez
// CST-210
#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Weapon.h"

using namespace std;

class Character
{
  protected:
    string m_name;
    int m_health;
    int m_remainingHealth;

  private:
    vector<Weapon> m_weapons;
    Weapon m_currentWeapon;
    bool m_holdingItem;
    bool m_dead;

  public:
    Character();
    Character(string);
    Character(string, int);
    Character(string, int, int);
    string GetName() const;
    int GetHealth() const;
    int GetRemainingHealth() const;
    bool IsDead() const;
    string GetWeaponName() const;
    void SetName(string);
    void SetHealth(int);
    void SetRemainingHealth(int);
    void SetCurrentWeapon();
    void SetDeath(bool);
    void IsHoldingItem();
    virtual int Attack();
    void CheckHealth();
    void ShowWeapons() const;
    void ObtainWeapon(const Weapon);
    // virtual string GetType() const = 0;
};
