// Angel Velazquez
// CST-210
#include "Enemy.h"

Enemy::Enemy()
{
  m_xpDropped = 1;
  m_action = 0;
}

Enemy::Enemy(string name, int health, int xp, int minCurrency, int maxCurrency, int damage)
  : Character(name, health)
{
  m_mdMin = minCurrency;
  m_mdMax = maxCurrency;
  m_xpDropped = xp;
  m_damage = damage;
  m_action = 0;
}

void Enemy::SetCurrencyDropped()
{
  srand(time(NULL));
  m_currencyDropped = rand() % m_mdMin + m_mdMax;
}

int Enemy::GetCurrencyDropped()
{
  return m_currencyDropped;
}

int Enemy::RandAction()
{
  srand(time(NULL));
  m_action = rand() % 10 + 1;
  return m_action;
}

string Enemy::GetType() const
{
  return "Enemy";
}

int Enemy::GetXpDropped() const
{
  return m_xpDropped;
}

int Enemy::GetDamage()
{
  return m_damage;
}

int Enemy::Attack()
{
  return m_damage;
}
