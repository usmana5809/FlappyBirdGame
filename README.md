# Flappy Bird Game
This project is an implementation of the classic Flappy Bird game in C++.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [How to Play](#how-to-play)
- [Instructions](#instructions)
- [Registered Users](#registered-users)
- [Screenshots](#screenshots)
- [Contributing](#contributing)
- [License](#license)

## Introduction
This project simulates the famous Flappy Bird game using basic C++ console graphics. It includes features for user registration, gameplay mechanics, and basic user interface.

## Features
- User registration with username input.
- Flappy Bird gameplay with obstacles.
- Score tracking and game-over functionality.
- Instructions for playing the game.
- Viewing previously registered users.


## Installation
1. Clone the repository:
    ```sh
    git clone https://github.com/your-username/FlappyBirdGame.git
    ```
2. Navigate to the project directory:
    ```sh
    cd FlappyBirdGame
    ```
3. Compile the code using a C++ compiler:
Compile the C++ files using your preferred compiler (e.g., g++)
    ```sh
    g++ main.cpp -o flappybird
    ```

## How to Play
# 1.Run the executable:
 ```sh
    ./flappybird
  ```
# 2.Follow the on-screen menu:
- Register your username.
- Start the game and use the spacebar to make the bird fly.
- Avoid obstacles to increase your score.
- Press any key to go back to the main menu after game over.
  
## Game Output
# 1.Main Menu Output
When you run the program, it starts with a main menu where users can choose different options:

 -------------------------- 
 |      Flappy Bird       | 
 --------------------------
1. Register your User Name
2. Start Game
3. Instructions
4. Registered Users
5. Exit
Select option:


# 2.Registration Process
If you choose option 1 (Register your User Name), the output will prompt you to enter your username:

 -------------------------- 
 |      Flappy Bird       | 
 --------------------------
Please Register your Name: [user enters their name]

- After entering your name, it will display the main menu again.


## 3.Starting the Game
If the user selects option 2 to start the game:

 -------------------------- 
 |      Flappy Bird       | 
 --------------------------
FLAPPY BIRD
----------
Control 
-------- 
 Spacebar = jump
Press any key to start



## 4.Gameplay
During gameplay, the console screen resembles:
 -------------------------- [Border]
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 |                         |
 -------------------------- [Border]
Score: 0

- The bird (o) starts at a fixed position (6) within the console window.
- Pipes (***) start to generate from the right side and move leftward across the screen.
- Score is displayed on the right side, starting from 0.



# 5.Gameplay Mechanics
- Bird Movement
**Flying:** Pressing the spacebar allows the bird (o) to fly upwards, adjusting its position to avoid obstacles (***).
- Scoring
**Score Display:** During gameplay, the current score is displayed on the right side of the console:
- Score: 0
**Increment:** Each time the bird successfully passes through a pair of obstacles (***), the score increments by 1.

- Obstacles (Pipes)
**Generation:** Pipes (***) are generated at random heights with a gap ( ) between them for the bird to pass through.
**Movement:** Pipes move from right to left across the screen at a constant speed.

- Collision Detection
**Criteria:** If the bird collides with the top or bottom of a pipe (***), the game ends.

  

# 6. Game Over
When the game ends due to a collision or if the user decides to exit (Esc), the following message is displayed:

Thank you For Playing our game
 --------------------------
-------- Game Over -------
--------------------------
----------Score: 5--------

Press any key to go back to menu.


## Expected Output
- Users will interact with the system via a command-line interface.
- Menus will guide the user to perform various operations.
- Success and error messages will be displayed accordingly.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new Pull Request.

## Contact
For any questions or suggestions, please contact [usmanazulfiqar2001@gmail.com](mailto:usmanazulfiqar2001@gmail.com).




