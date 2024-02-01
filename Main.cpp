// Angel Velazquez
// CST-210
#include <string>
#include <vector>
#include <fstream>
#include "Battle.h"
#include "Character.h"
#include "Enemy.h"
#include "GameAsset.h"
#include "Player.h"
#include "RandomEnemy.h"
#include "Store.h"
#include "Weapon.h"

void Fight(Player &);
void WeaponShop(Player &, Store &);
void Recover(Player &);
void Menu(Player &);
void Save(Player &);

int main()
{
    bool quit = false;
    string userInput = "";

    // create new player
    Player player;
    cout << "Welcome to the BEST game ever created! (enter all values in lowercase ;)" << endl;
    cout << "Are you new here? (yes/no): ";
    cin >> userInput;
    cout << endl;

    if (tolower(userInput[0]) == 'y')
    {
        cout << "What do you name yourself, creature? ";
        cin >> userInput;
        cout << endl;
        player = Player(userInput);
    }
    else
    {
        fstream streamIn("Player.txt");
        streamIn >> player;
    }

    // create new store object
    Store store;

    while (!quit)
    {
        system("clear");
        userInput = "";
        cout << "What would you like to do, " << player.GetName() << "?" << endl;
        cout << "Battle"
             << "/Shop"
             << "/Recover"
             << "/Player"
             << "/Save"
             << "/Quit" << endl;

        cin >> userInput;

        if (tolower(userInput[0]) == 'b')
        {
            cout << endl;
            cout << endl;

            Fight(player);

            cout << endl;
            cout << endl;
        }
        else if (userInput == "Shop" || userInput == "shop")
        {
            cout << endl;
            cout << endl;

            WeaponShop(player, store);

            cout << endl;
            cout << endl;
        }
        else if (tolower(userInput[0] == 'r'))
        {
            cout << endl;
            cout << endl;

            Recover(player);

            cout << endl;
            cout << endl;
        }
        else if (tolower(userInput[0] == 'p'))
        {
            cout << endl;
            cout << endl;

            Menu(player);

            cout << endl;
            cout << endl;
        }
        else if (userInput == "Save" || userInput == "save")
        {
            cout << endl;
            cout << endl;

            Save(player);

            cout << endl;
            cout << endl;
        }
        else if (tolower(userInput[0]) == 'q')
        {
            userInput = "";
            cout << "Would you like to save first? Would be kinda dumb if you didn't to be honest. (yes/no) ";
            cin >> userInput;

            if (tolower(userInput[0] == 'y'))
            {
                Save(player);
            }

            quit = true;
        }
    }
}

void Fight(Player &playerInFight)
{
    RandomEnemy randomEnemy;
    Enemy enemy = randomEnemy.EasyEnemy();
    enemy.SetRemainingHealth(enemy.GetHealth());

    Battle battle(playerInFight, enemy);
    string userInput = "";

    bool fighting = true;
    string characterType = "";
    int damage = 0;
    int xpDropped = 0;
    int currencyDropped;
    bool battleBool = false;

    while (!battleBool)
    {
        system("clear");
        int enemyAction = enemy.RandAction();

        // player's round
        string playerInput = "";
        cout << playerInFight.GetName() << " HP: " << playerInFight.GetRemainingHealth() << "/" << playerInFight.GetHealth() << "\t\t" << enemy.GetName() << " HP: " << enemy.GetRemainingHealth() << "/" << enemy.GetHealth() << endl;
        cout << "So, what do you wanna do? (Fight/Nothing): ";
        cin >> playerInput;

        if (tolower(playerInput[0] == 'f'))
        {
            // damage is updated based on player's weapon
            cout << endl;
            damage = battle.Attack(playerInFight.GetType(), playerInFight);

            if (damage != 0)
            {
                enemy.SetRemainingHealth(enemy.GetRemainingHealth() - damage);
                cout << enemy.GetName() << " took " << damage << " hit points!" << endl;
            }
        }

        else if (tolower(playerInput[0]) == 'n')
        {
            cout << endl;
            cout << "You did nothing" << endl;
            fighting = false;
        }

        // check enemy status
        enemy.CheckHealth();
        if (enemy.IsDead())
        {
            enemy.SetCurrencyDropped();
            xpDropped = enemy.GetXpDropped();
            currencyDropped = enemy.GetCurrencyDropped();

            cout << enemy.GetName() << " has perished" << endl;
            cout << "You gained " << xpDropped << " XP" << endl;
            playerInFight.SetExperience(playerInFight.GetExperience() + xpDropped);
            cout << "You gained " << currencyDropped << " Glimmer" << endl;
            playerInFight.SetCurrency(playerInFight.GetCurrency() + currencyDropped);
            battleBool = true;

            cout << endl;
            playerInFight.LevelUp();
            cout << endl;
        }

        // enemy's round
        else if (fighting)
        {
            if (enemyAction <= 5)
            {
                damage = battle.Attack(enemy.GetType(), enemy);

                if (damage != 0)
                {
                    playerInFight.SetRemainingHealth(playerInFight.GetRemainingHealth() - damage);
                    cout << "You took " << damage << " hit points!" << endl;
                }
            }
            else if (enemyAction > 5)
            {
                cout << enemy.GetName() << " is just staring at you. Menacingly." << endl;
            }

            cout << endl;
        }

        // check player status
        playerInFight.CheckHealth();
        if (playerInFight.IsDead())
        {
            cout << playerInFight.GetName() << " has died! *you suck*" << endl;
            battleBool = true;
            cout << endl;
            cout << "Game Over :(" << endl;
            exit(1);
        }

        cout << endl;
        cout << "Enter any letter to continue: " << endl;
        cin >> userInput;
    }

    // restoring objects
    battleBool = false;
    auto level = playerInFight.GetLevel();
    if (level < 2)
    {
        enemy = randomEnemy.EasyEnemy();
    }
    else if (level >= 2 && level < 4)
    {
        enemy = randomEnemy.MediumEnemy();
    }
    else if (level >= 4)
    {
        enemy = randomEnemy.HardEnemy();
    }

    enemy.SetDeath(false);
    enemy.SetRemainingHealth(enemy.GetHealth());
}

void WeaponShop(Player &playerInStore, Store &store)
{
    system("clear");
    string userInput = "";
    int index = 0;

    cout << "You have " << playerInStore.GetCurrency() << " Glimmer" << endl;
    cout << endl;
    store.ShowStock();

    cout << "Xur: Enter the number of which weapon you'd like to purchase, If your Glimmer is insufficient, enter 0 and come back with more Glimmer. ";
    cin >> index;

    if (index == 0)
    {
        cout << "Get out of here." << endl;
    }
    else if (playerInStore.GetCurrency() >= store.GetPrice(--index))
    {
        playerInStore.ObtainWeapon(store.BuyWeapon(index));
        playerInStore.SetCurrency(playerInStore.GetCurrency() - store.GetPrice(--index));
    }
    else
    {
        cout << "Xur: lol, you can't buy that" << endl;
    }

    cout << endl;
    cout << "Do you want to continue? *say yes* " << endl;
    getline(cin, userInput);
}

void Recover(Player &playerRecovering)
{
    system("clear");
    string input = "";

    cout << "Добро пожаловать в дом твоей мамы. 'that means welcome home :)'" << endl;
    cout << "you gotta pay 4 Glimmer to stay here. I don't make the rules, srry. *i literally made the rules* (yes/no): ";
    cin >> input;

    if (tolower(input[0]) == 'y')
    {
        cout << "YUHHHHH you made a good choice. Get some sleep." << endl;
        cout << "You have recovered all of your health.";
        playerRecovering.SetCurrency(playerRecovering.GetCurrency() - 4);
        playerRecovering.SetRemainingHealth(playerRecovering.GetHealth());
    }
    else
    {
        cout << "get 0ut";
    }

    cout << endl;
    cout << "Enter any key to continue: ";
    cin >> input;
}

void Menu(Player &playerInMenu)
{
    system("clear");
    string input = "";
    playerInMenu.ShowPlayer();
    cout << "Current weapon: " << playerInMenu.GetWeaponName() << endl;

    cout << "Do you wanna change gunz?? (yes/no) ";
    cin >> input;

    if (tolower(input[0]) == 'y')
    {
        playerInMenu.SetCurrentWeapon();
    }

    cout << endl;
    cout << "Enter any key to continue (don't be a smartass) ";
    cin >> input;
}

void Save(Player &playerSave)
{
    string input = "";
    cout << "Game saved!" << endl;
    fstream streamOut("Player.txt");
    streamOut << playerSave;

    cout << endl;
    cout << "Do you want to continue? (yes/no) ";
    cin >> input;
}