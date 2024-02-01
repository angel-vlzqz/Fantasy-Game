// Angel Velazquez
// CST-210
#include "Battle.h"

// default
Battle::Battle()
{
  m_player = Player("Billy");
  m_battleStatus = false;
}

// parameter for inserting a player
Battle::Battle(Player &player)
{
  m_player = player;
  m_enemy = Enemy("Slug", 5, 5, 1, 10, 1);
}

// parameters for player and enemy
Battle::Battle(Player &player, Enemy enemy)
  : m_player(player), m_enemy(enemy)
{
  m_battleStatus = false;
}

// returns player
Player Battle::GetPlayer() const
{
  return m_player;
}

// returns enemy
Enemy Battle::GetEnemy() const
{
  return m_enemy;
}

// set player
void Battle::SetPlayer(Player player)
{
  m_player = player;
}

void Battle::SetEnemy(Enemy enemy)
{
  m_enemy = enemy;
}

int Battle::Attack(string name, Character &character)
{
  srand(time(NULL));
  int chance = 0;
  int damage = 0;

  if (name == "Player")
  {
    chance = rand() % 10 + 1;

    if (chance <= 2)
    {
      cout << "You missed your attack" << endl;
      return damage;
    }
    else if (chance == 10)
    {
      damage = character.Attack() * 2;
      cout << character.GetName() << " dealt " << damage << " damage with a critical hit" << endl;
      return damage;
    }
    else
    {
      damage = character.Attack();
      cout << character.GetName() << " dealt " << damage << " hit points!" << endl;
      return damage;
    }
  }

  else if (name == "Enemy")
  {
    chance = rand() % 10 + 1;

    if (chance <= 2)
    {
      cout << character.GetName() << " missed their attack" << endl;
      return damage;
    }
    else if (chance == 10)
    {
      damage = character.Attack() * 2;
      cout << character.GetName() << " dealt " << damage << " damage with a critical hit, play better!" << endl;
      return damage;
    }
    else
    {
      damage = character.Attack();
      cout << character.GetName() << " dealt " << damage << " damage" << endl;
      return damage;
    }
  }
  return damage;
}

