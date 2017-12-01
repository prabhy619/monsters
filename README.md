# monsters
Basic Framework for a Turn-based combat simulation.

## Origin

It is based on the First generation of Pokemon games (Red & Blue/Green).
Many of the initial work has been adapted directly from their in-game mechanics as it is.
**Caution:** *It is based on my Highschool project which was originally written in C89. Some parts are still in need of being updated for C++11/C++14. The most recent working (and stripped) version is name EDITPKM-1.CPP. It can only be compiled by a C89 compiler with VGA graphics library linked at compile-time.*


## Reference for the mechanics

https://serebii.net/games/mechanics.shtml


## Current Status

The program is in **Alpha stage**, *ie; It doesn't function yet.*


## Prerequites
### 1. - Downloading the source
Latest source file is available at:
https://github.com/Danpar97/monsters.git

### 2. -  Compiling
* Use gcc/g++ on Mac/Linux (Unix-like OS)
* Use mingw on Microsoft Windows
**Note:** *Have to test compatibility with Visual C++.*


## Roadmap

The project is meant to be a basic framework for any game with similar mechanics and thus needs to be able to allow a more general approach than the current Pokemon based.
The Pokemon specific codes should continue to exist and evolve for referencing use cases for each and every function but in a seperate dev branch than the general one, called pkmn-dev.
If functions &/or mechanics can't be merged with the original one a new fork will be created to accomodate the new ones with adjusted base classes and functions
Please make a fork if you wish to adapt the framework for a game by combining it with some external (non-standard C/C++) library.


## Contributions

This project is open to contributions, feel free to signal errors with issues or directly correct the errors with pull-requests.
Contributions can be checked from:
https://github.com/Danpar97/monsters/contributors


## Questions

Feel free to ask any questions by adding issues or commenting sections.


## Disclaimer

Although I have mentioned adapting mechanics "as is" they are not representative of actual mechanics but rather supposition of observed behaviour in game.
This Project is in no way meant to be a game by itself and thus use of any copyrighted material is strictly forbidden.
