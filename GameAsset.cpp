// Angel Velazquez
// CST-210
#include "GameAsset.h"

GameAsset::GameAsset()
{
  m_name = "";
}

GameAsset::GameAsset(string name)
  : m_name(name)
{
}

string GameAsset::GetName() const
{
  return m_name;
}

void GameAsset::SetName(string name)
{
  m_name = name;
}
