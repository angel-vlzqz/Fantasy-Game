// Angel Velazquez
// CST-210
//#include "Character.h"
#pragma once

#include "GameAsset.h"
#include <string>

using namespace std;

class Weapon: public GameAsset
{
  private:
    int m_damage;
    string m_type;

  public:
    Weapon();
    Weapon(string, int);
    int GetDamage() const;
    void SetDamage(int);
    string GetType() const;
};
