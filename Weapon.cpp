// Angel Velazquez
// CST-210
#include "Weapon.h"

Weapon::Weapon()
  : GameAsset()
{
  m_damage = 0;
}

Weapon::Weapon(string name, int damage)
  : GameAsset(name)
{
  m_damage = damage;
}

int Weapon::GetDamage() const
{
  return m_damage;
}

void Weapon::SetDamage(int damage)
{
  m_damage = damage;
}

