Clean Engine: 2D Game Engine
==========

_Note:_ Their will be a compact website soon containing all the info below along with an embedding guide, downloads, tutorials and all the other resources you need to get started with the CleanEngine.

Clean Engine is a Game Engine to develop 2D Games fast and easy. It is written in C++. The goal is to allow very fast development, which is often needed in prototyping. Thanks to the many embedded opensource libraries we can provide you with all the features you might need. Keep in mind that we aim for a miniamlistic and compact game engine.


## Features

  * Deploy games on Windows
  * Develop quick prototypes or advanced 2D Games
  * A component system to boost code reusability and improve code organisation
  * Crossplatform input support via [SDL2](http://www.libsdl.org/) 
  * Better code organisation via scenes and objects
  * Develop games in C++
  * Multithreading support to keep your games performant
  * Garbage Collection system to manage your memory
  * Boost integration for containers and other small things
  * Application: Generate an empty game project or start from a template

## Project Setup
  * Download [SDL2](https://github.com/libsdl-org/SDL/releases) and [SDL2-Image](https://github.com/libsdl-org/SDL_image/releases) (Make Sure you get the devel VC version of both files)
  * Extract them in a System folder (Mine as example: C:/Dev/SDL2)
  * Paste the SDL2.dll and SDL2-Image.dll on your main folder and where your engine.exe is located
  * Go to Project->Properties->C/C++->General and on Additional Include Directories put your SDL2 adn SDL2-image include folder
  
  ![Additional Include Directories](https://i.imgur.com/riRi7kA.png)
  * Go to Project->Properties->Linker->General and on Additional Library Directories put your SDL2 adn SDL2-image lib folder
  
  ![Additional Library Directories](https://i.imgur.com/PMiwVbq.png)
  * Go to Project->Properties->Linker->Input and on Additional Dependencies include SDL2.lib, SDL2main.lib and SDL2_image.lib

  ![Additional Library Directories](https://i.imgur.com/9srJSoU.png)
  * You should be able to run the Engine
