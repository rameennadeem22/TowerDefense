# TowerDefense
A classic 2D Tower Defense game built using C++ and the SFML (Simple and Fast Multimedia Library). This project demonstrates core Object-Oriented Programming (OOP) principles through a wave-based strategy game.

## Key Features
Diverse Enemy Types: Includes Basic, Fast, Tank, Shielded, and Flying enemies, each with unique speed and health attributes.

Strategic Tower Variety: Five distinct tower types:

Cannon: Standard balanced defense.

Sniper: Long-range, high damage.

Machine Gun: Rapid-fire capabilities.

Slow Tower: Uses a timer-based debuff to reduce enemy velocity.

Bomb Tower: Implements Area of Effect (AoE) splash damage logic.

Grid-Based Placement: A tile-based system that prevents building on the path or overlapping towers.

Wave System: A structured 5-wave challenge with increasing difficulty.

Dynamic Interface: Real-time tracking of Gold, Lives, Wave count, and Tower selection.

## Technical Architecture
1. Object-Oriented Design
The project utilizes a robust class hierarchy to manage game entities:

Inheritance: A base Entity class provides coordinates and rendering logic. Enemy and Tower inherit from this, with specialized classes (like BombTower or FastEnemy) further extending functionality.

Polymorphism: Uses virtual functions and the override keyword to allow the Game engine to manage an array of different entity types through base-class pointers.

Encapsulation: Private data members with public getters/setters (e.g., getHp(), getX()) ensure data integrity.

2. Memory Management
Dynamic Allocation: Entities are managed via pointers and allocated using new.

Manual Cleanup: To prevent memory leaks, a dedicated cleanupDead() function handles object destruction and array shifting during gameplay, while the Game destructor ensures all remaining heap memory is freed on exit.

## Controls
[1] - [5]: Select different Tower types.

Left Click: Place the selected tower on the grid (requires sufficient Gold).

[Esc]: Exit the game.

## Installation & Setup
Prerequisites: * C++ Compiler (supporting C++11 or higher).

SFML Library installed and linked.

Assets: Ensure arial.ttf and required sprite images are in the project root directory.

Enjoy!
