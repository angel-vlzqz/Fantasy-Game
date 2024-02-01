// Angel Velazquez
// CST-210
#pragma once

#include "Weapon.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Store
{
  private:
    vector<Weapon> m_stock;
    vector<int> m_price;

  public:
    Store();
    void ShowStock();
    Weapon BuyWeapon(int) const;
    int GetPrice(int);
};
