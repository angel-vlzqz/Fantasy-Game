// Angel Velazquez
// CST-210
#pragma once

#include "Enemy.h"
#include <vector>

class RandomEnemy
{
  private:
    vector<Enemy> m_enemies =
    {
      Enemy("Goblin", 1, 0, 0, 0, 0),
      Enemy("Dreg", 5, 5, 1, 10, 1),
      Enemy("Captain", 10, 5, 5, 20, 2),
      Enemy("Hobgoblin", 8, 4, 11, 15, 2),
      Enemy("Vandal", 7, 2, 10, 15, 2),
      Enemy("Minotaur", 3, 1, 1, 3, 1),
      Enemy("Harpy", 10, 6, 7, 9, 2),
      Enemy("Hydra", 12, 6, 10, 15, 2),
      Enemy("Cyclops", 12, 10, 10, 15, 2),
      Enemy("Servitor", 15, 7, 20, 25, 3),
      Enemy("Thrall", 20, 10, 20, 25, 3),
      Enemy("Cursed Thrall", 30, 25, 30, 55, 4),
      Enemy("Acolyte", 30, 25, 30, 45, 4),
      Enemy("Knight", 25, 16, 45, 55, 4),
      Enemy("Ogre", 60, 30, 70, 80, 6),
      Enemy("Wizard", 35, 18, 25, 35, 4),
      Enemy("Ogre", 40, 22, 30, 39, 4),
      Enemy("Legionary", 20, 20, 25, 50, 1),
      Enemy("Centurion", 28, 20, 30, 60, 1),
      Enemy("Colossus", 60, 30, 75, 100, 3),
    };

  public:
    RandomEnemy();
    Enemy EasyEnemy();
    Enemy MediumEnemy();
    Enemy HardEnemy();
};
