# Project Time
## created by ShakedKod

## Content table
* [What is Project Time?](#what-is-project-time)
* [Introduction](#Watch-the-introduction)
* [How to install](#How-to-install-Project-Time)
* [tweak the project](#How-to-tweak-this-project-for-your-own-uses)

## What is Project Time?

This is Project Time, the project manager for the people that don't have time.
Project Time supports:
* a lot of programs and platforms, like:
    * [Blender](https://blender.org)
    * [Resolve](https://www.blackmagicdesign.com/products/davinciresolve)
    * [Edius](https://www.edius.net)
    * C/C++ console apps
    * C/C++ to dynamic library(dll)
    * C++ with [ImGui](https://github.com/ocornut/imgui) and [Walnut](https://github.com/TheCherno/Walnut)
    * c# console apps
    * [.NET](https://dotnet.microsoft.com) apps
    * [WPF](https://docs.microsoft.com/en-us/visualstudio/designers/getting-started-with-wpf) Projects
    * C++ backend with C# WPF frontend
    * [Python](https://python.org) console apps
    * Python games with [Pygame](https://www.pygame.org)
    * Python apps with [Kivy](https://kivy.org)
    * JavaScript of all kinds: React, Angular, Node and more
    * [Dart](https://dart.dev) console apps
    * [Flutter](https://flutter.dev) apps
    * [Flutter](https://flutter.dev) web apps
    * regular web app (with html, css, and javascript)
    * Java console apps
    * [Minecraft](https://www.minecraft.net) [Forge](files.minecraftforge.net/) mod
    * [Minecraft](https://www.minecraft.net) [Fabric](https://fabricmc.net) mod
    * [Minecraft](https://www.minecraft.net) Plugins
    * [Minecraft](https://www.minecraft.net) resource pack
    * [Minecraft](https://www.minecraft.net) data pack
    * [Unreal Engine](https://www.unrealengine.com) games and apps
    * [Unity](https://unity.com) 2D games and apps
    * [Unity](https://unity.com) 3D games and apps
    * and more
* integration with git
* powerful interface
* timeline
* create projects right from the interface
* and more

## Watch the introduction
<a href="https://youtube.com/NotExsistsYet" target="_blank">
    <img src="imageSoon" alt="Watch The Introduction" width="240" height="180" border="10"/>
</a>

## How to install Project Time

The easiest way to install is:

1. go to the [Project Time Website](https://OrtStudios.github.io/Programing/Time/ProjectTime)
2. click on the download button and wait
3. follow the steps in the installer
4. use Project Time

if you steel don't understand, you can watch [this](https://youtube.com/NotExsistsYet) youtube video.

## How to tweak this project for your own uses

1. clone the project from the [repository](https://OrtStudios.github.io/ProjectTime.git)
2. open the project in your IDE, preferably [Visual Studio Code](https://code.visualstudio.com)
3. you can change the code in two diffrent locations:
    * `Core/src` - the source code of the backhand of the project(the core)
    * `ProjectTime/lib` - the source code of the project UI and main app
4. when you are done, you can build the project with the `build.bat <platform>` file
    * the project should work on all desktop platforms like Windows, Linux, and Mac.
5. go to the `/ProjectTime/build/windows/runner/Release/`
6. open the file named <span style="color: #0094B1">project_time.exe</span> with [Resource Hacker](http://www.angusj.com/resourcehacker/#download)
7. change the icon to the icon at: `/ProjectTime/assets/images/logoIcon.ico` with the command from the menu `Action` called `Replace Icon ...` or use the shortcut `Ctrl + R`
8. delete the `project_time.exe` file, and change the name of the newly created file `project_time_original.exe` to `ProjectTime.exe`.
9. create a new folder in `/ProjectTime/build/windows/runner/Release/` called `assets` and move the [Core](https://github.com/OrtStudios/PTCore/) dll to there. (<span style="color: red">To be automated</span>)
10. use your version of Project Time ;)