// Angel Velazquez
// CST-210
#include "RandomEnemy.h"

RandomEnemy::RandomEnemy()
{
}

// enemies for new users
Enemy RandomEnemy::EasyEnemy()
{
  srand(time(NULL));
  int index = rand() % 5 + 1;
  return m_enemies[index];
}

// enemies for decent users
Enemy RandomEnemy::MediumEnemy()
{
  srand(time(NULL));
  int index = rand() % 9 + 7;
  return m_enemies[index];
}

// enemies for pro users
Enemy RandomEnemy::HardEnemy()
{
  srand(time(NULL));
  int index = rand() % 20 + 10;
  return m_enemies[index];
}
