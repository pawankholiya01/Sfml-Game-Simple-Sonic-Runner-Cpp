# Sfml Game - Simple Sonic Runner
 A Basic Game engine with features like state manager (adding deleting states ) , Asset manager implemented in c++ with SFM Llibrary  created in Visual Studio - 2017 . The game engine with itself binds a simple running sonic game that runs on both directions and jumps all animated with the help of a Sprite Sheets .
 This project is under Devlopment , Stay Tuned !!
 
 **To Run locally :** 
 First setup `SFML library` in your ide .
 Download and Extract the zip.
 Run the file `game.cpp`

 ### Running
 Character is capable of running in both the direction with A and D keys , as it moves in a direction the land sprites are actually moving in opposite direction to give running effect , character is animated using 2 Sprite Sheets One for Forward Motion and another for backward motion (same image Flipped!) . 
 
 ### Jump
 Character can jump upto a fixed height with W key and during jump it is animated with Sprites to give the effect , it can also move forward and Backward during jump and can also change direction of horizontal motion with A or D keys ! 
 
 ### Collision Detectiom
 Collision is detected using the intersection between two non-compatible objects area ,It is then the corresponding operation (`restricting movement`, `death`) is operation.
 `Running ground` is also applied in same manner .
 
 ### Refrences 
 Graphics Library used - [SFML](https://www.sfml-dev.org/)
 
