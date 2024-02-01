# Fantasy-Game
This is a fantasy game written completely in C++.

The game works by entering your response directly into the terminal.

As far as testing goes, this game ONLY runs on UNIX systems due to the
clear command used to clear the terminal.

The program utilizes the 'auto' variable so the compiler needs to be set to
version 11 or greater of C++.

To compile the game, run this command into your terminal.
```
g++ -o main Battle.cpp GameAsset.cpp Player.cpp RandomEnemy.cpp Enemy.cpp Weapon.cpp Character.cpp Main.cpp Store.cpp -std=c++11
```

To run the game, run this command into your terminal.
```
./main
```

If you look at the Player.txt file, you may see that I have a character already
saved.

Keep in mind that there is no auto save feature, so you will have to save
your progress manually!
