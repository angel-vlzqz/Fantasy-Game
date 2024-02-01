// Angel Velazquez
// CST-210
#include "Character.h"

Character::Character()
  : m_name(""), m_health(10), m_remainingHealth(10)
{
  m_weapons.push_back(Weapon("Bare Hands", 1));
  m_currentWeapon = m_weapons[0];
}

Character::Character(string name)
  : m_name(name), m_health(10), m_remainingHealth(10)
{
  m_weapons.push_back(Weapon("Bare Hands", 1));
  m_currentWeapon = m_weapons[0];
}

Character::Character(string name, int health)
  : m_name(name), m_health(health), m_remainingHealth(health)
{
  m_weapons.push_back(Weapon("Bare Hands", 1));
  m_currentWeapon = m_weapons[0];
}

Character::Character(string name, int health, int remainingHealth)
  : m_name(name), m_health(health), m_remainingHealth(remainingHealth)
{
  m_weapons.push_back(Weapon("Bare Hands", 1));
  m_currentWeapon = m_weapons[0];
}

string Character::GetName() const
{
  return m_name;
}

int Character::GetHealth() const
{
  return m_health;
}

int Character::GetRemainingHealth() const
{
  return m_remainingHealth;
}

bool Character::IsDead() const
{
  return m_dead;
}

string Character::GetWeaponName() const
{
  return m_currentWeapon.GetName();
}

void Character::SetName(string name)
{
  m_name = name;
}

void Character::SetHealth(int health)
{
  m_health = health;
}

void Character::SetRemainingHealth(int remainingHealth)
{
  m_remainingHealth = remainingHealth;
}

void Character::SetCurrentWeapon()
{
  cout << m_currentWeapon.GetName() << " is currently being used" << endl;
  int selectedWeapon = 0;
  ShowWeapons();

  cout << "select a weapon: ";
  cin >> selectedWeapon;

  m_currentWeapon = m_weapons[--selectedWeapon];
  cout << m_currentWeapon.GetName() << " is now equipped" << endl;

  if (m_currentWeapon.GetName() == "Bare Hands")
  {
    m_holdingItem = false;
  }
  else
  {
    m_holdingItem = true;
  }
}

void Character::SetDeath(bool status)
{
  m_dead = status;
}

void Character::IsHoldingItem()
{
  if (m_holdingItem)
  {
    cout << "Yeah" << endl;
  }
  else
  {
    cout << "Nahh" << endl;
  }
}

int Character::Attack()
{
  int damage{};

  if (m_holdingItem)
  {
    damage = m_currentWeapon.GetDamage();
  }
  else
  {
    damage = 1;
  }

  return damage;
}

void Character::CheckHealth()
{
  if (m_remainingHealth <= 0)
  {
    m_remainingHealth = 0;
    m_dead = true;
  }
  else
  {
    m_dead = false;
  }
}

void Character::ShowWeapons() const
{
  for (auto cnt = 0; cnt < m_weapons.size(); cnt++)
  {
    cout << cnt + 1 << ". " << m_weapons[cnt].GetName() << " deals " << m_weapons[cnt].GetDamage() << " hit points" << endl;
  }
}

void Character::ObtainWeapon(const Weapon weapon)
{
  cout << m_name << " has earned " << weapon.GetName() << " that deals " << weapon.GetDamage() << " hit points" << endl
    << endl;
  m_weapons.push_back(weapon);
}

//string Character::GetType() const
//{
  // WIP
  //return m_weapons[0].GetType();
//}

//string Character::GetType() const
//{
  // WIP
  //return m_type;
//}
