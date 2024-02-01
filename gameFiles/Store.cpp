// Angel Velazquez
// CST-210
#include "Store.h"
#include <iostream>

Store::Store()
{
  m_stock.push_back(Weapon("Rat King", 3));
  m_stock.push_back(Weapon("Bad Juju", 5));
  m_stock.push_back(Weapon("Crimson", 7));
  m_stock.push_back(Weapon("The Last Word", 10));
  m_stock.push_back(Weapon("Thorn", 12));
  m_stock.push_back(Weapon("The Chaperone", 15));
  m_stock.push_back(Weapon("Hawkmoon", 20));
  m_stock.push_back(Weapon("Ace of Spaces", 30));
  m_stock.push_back(Weapon("Vex Mythoclast", 38));
  m_stock.push_back(Weapon("Gjallarhorn", 75));

  m_price.push_back(10);
  m_price.push_back(12);
  m_price.push_back(16);
  m_price.push_back(22);
  m_price.push_back(26);
  m_price.push_back(30);
  m_price.push_back(36);
  m_price.push_back(45);
  m_price.push_back(60);
  m_price.push_back(400);
}

void Store::ShowStock()
{
  cout << "Xur: 'what do you want, bruh?'" << endl;
  for (auto cnt = 0; cnt < m_stock.size(); cnt++)
  {
    cout << cnt + 1 << ". " << m_stock[cnt].GetName() << " deals " << m_stock[cnt].GetDamage() << " damage for " << m_price[cnt] << " glimmer" << endl;
  }
}

Weapon Store::BuyWeapon(int index) const
{
  return m_stock[index];
}

int Store::GetPrice(int index)
{
  return m_price[index];
}
