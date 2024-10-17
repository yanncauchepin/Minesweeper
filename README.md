# Minesweeper Game


This code implements a minesweeper game both in shell and with the graphical user interface ***wxWidgets***.

## Prerequisites

Before running this code, ensure you have the following :

- ***g++*** compiler installed on your system.

### Minesweeper

Before running this code, ensure you have the following :

- ***wxWidgets*** installed on your system.

To install ***wxWidgets*** on **Ubuntu** :
```bash
sudo apt-get install libwxgtk3.0-dev
```

## Usage

### Minesweeper

1. Navigate to the **minesweeper** directory.
```bash
cd minesweeper
```

2. Navigate to the **code** directory containing the source code and the ***Makefile*** file.
```bash
cd code
```
3. Compile the minesweeper game on both shell and graphical user interface by running ***make all***. Run ***make shellGame*** to just compile the minesweeper on shell. Run ***make wxGame*** to just compile the minesweeper on graphical user interface.
```bash
make all
```
```bash
make shellGame
```
```bash
make wxGame
```
4. The compiled program(s) ***shellGame*** or/and ***wxGame*** is/are now located in the parent repository.
```bash
cd ..
```
5. Execute the compiled game on shell by running ***./shellGame***. Execute the compiled game on graphical user interface by running ***./wxGame***.
```bash
./shellGame
```
```bash
./wxGame
```

*(Optional)* 5. Clean the repository by running ***make clean*** in the **code** directory.

```bash
cd code
make clean
```

## Monitor

### Minesweeper

#### ShellGame

To configure parameters for the minesweeper game in shell, the user have to inform some piece of information. In chronological order, the user have to provide :
- ***height*** : Integer value which indicates the height of the minesweeper game.
- ***width*** : Integer value which indicates the width of the minesweeper game.
- ***total number of mines*** : Integer value which indicates the total number of mines.

Then, the user enter in iterative monitor until the end of the game.

During the iterative monitor, the user have to iteratively insert :
- ***height*** : Integer value which indicates the height coordinate of the case.
- ***width*** : Integer value which indicates the width coordinate of the case.
- ***action*** : Boolean 0 or 1 to respectively indicate whether this action is to discover the case or flag it.

The end of the game comes either with a victory condition, a failure condition or by insert the value ***exit***, at any moment in the iterative monitor, to exit the game.

#### wxGame

This program run a ***wxWidgets Application*** with a initialized minesweeper game configured with a height of 10, a width of 10 and a total number of mines of 20.

To  play the game, the user have to click left on boxes to discover each one of them. Once a mine can be identified, the user could click right on a box to flag it. Therefore, this chosen box can no longer be discovered until the user click right again on this same box to remove the flag. An indicator of the amount of identified mines is indicated at the bottom of the application.

This program also handle victory and failure conditions.

Otherwise, the user can access to various menu such as :
- ***Game>Restart*** or *Crtl+R* to restart the minesweeper game with the same configuration.
- ***Game>initialized*** or *Crtl+I* to restart a minesweeper game by configure the height, the width and the total number of mines.
- ***Game>SetSpacing*** or *Crtl+S* to modify the display of the current minesweeper game by indicating the spacing desired between boxes in both height and width.
- ***Game>Quit*** or *Crtl+Q* to quit the minesweeper application.
- ***AI>Resolve*** or *Crtl+A* to bring help to the gamer and iteratively resolve the minesweeper game. Not implemented currently.
- ***Info>About*** to show a simple piece of information about this minesweeper game.

----

![](features_image.jpg)
