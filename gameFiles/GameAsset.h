// Angel Velazquez
// CST-210
#pragma once

#include <string>

using namespace std;

class GameAsset
{
  protected:
    string m_name;

  public:
    GameAsset();
    GameAsset(string);
    string GetName() const;
    void SetName(string);
};
