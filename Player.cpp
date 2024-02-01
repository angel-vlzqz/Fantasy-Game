// Angel Velazquez
// CST-210
#include "Player.h"

Player::Player()
  : m_level(1), m_experience(0), m_currency(100)
{
}

Player::Player(string name)
  : Character(name), m_level(1), m_experience(0), m_currency(100)
{
}

Player::Player(string name, int health, int remainingHealth, int level, int experience, int currency)
  : Character(name, health, remainingHealth), m_level(level), m_experience(experience), m_currency(currency)
{
}

int Player::GetLevel() const
{
  return m_level;
}

int Player::GetExperience() const
{
  return m_experience;
}

int Player::GetCurrency() const
{
  return m_currency;
}

void Player::SetLevel(int level)
{
  m_level = level;
}

void Player::SetExperience(int experience)
{
  m_experience = experience;
}

void Player::SetCurrency(int currency)
{
  m_currency = currency;
}

void Player::LevelUp()
{
  if (m_experience >= 15)
  {
    cout << "You have now leveled up!" << endl
      << endl;
    m_level++;
    SetHealth(12);
    SetRemainingHealth(12);
    m_experience = 0;
  }
}

string Player::GetType() const
{
  return "Player";
}

void Player::ShowPlayer()
{
  cout << m_name << endl;
  cout << "Level: " << m_level << "\tXP: " << m_experience << endl;
  cout << "Health: " << m_remainingHealth << "/" << m_health << endl;
  cout << "Glimmer: " << m_currency << endl;
}

// allows player to save their profile to a file
ostream &operator<<(ostream &out, const Player &save)
{
  out << save.m_name << "\n";
  out << save.m_health << "\n";
  out << save.m_remainingHealth << "\n";
  out << save.m_level << "\n";
  out << save.m_experience << "\n";
  out << save.m_currency << "\n";
  return out;
}

istream &operator>>(istream &in, Player &save)
{
  in >> save.m_name;
  in >> save.m_health;
  in >> save.m_remainingHealth;
  in >> save.m_level;
  in >> save.m_experience;
  in >> save.m_currency;
  return in;
}
