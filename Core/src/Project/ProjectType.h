#pragma once

namespace Core
{
	namespace Project
	{
		class ProjectType {};
		
		namespace ProjectTypeNS
		{
			class Unknown     : ProjectType {};
			class Programing  : ProjectType {};
			class Game        : ProjectType {};
			class Editing     : ProjectType {};
			class Music       : ProjectType {};
			class Movie       : ProjectType {};
			class ShortFilm   : ProjectType {};
			class ThreeD      : ProjectType {};
			class TwoD        : ProjectType {};
			class Compositing : ProjectType {};

			namespace ProgramingNS
			{
				// Programing types
				class Python     : Programing {};
				class Dart       : Programing {};
				class Java       : Programing {};
				class JavaScript : Programing {};
				class CSharp     : Programing {};
				class CPP        : Programing {};
				class C          : Programing {};

				namespace PythonNS
				{
					// Python
					class ConsoleApp  : Python {};
					class PyGame      : Python {};
					class PySimpleGUI : Python {};
					class Kivy        : Python {};
				}

				namespace DartNS
				{
					// Dart
					class ConsoleApp : Dart {};
					class Flutter    : Dart {};

					namespace FlutterNS
					{
						// Dart -> Flutter
						class FullMobileApp  : Flutter {};
						class AndroidApp     : Flutter {};
						class IOSApp         : Flutter {};
						class WebApp         : Flutter {};
						class FullDesktopApp : Flutter {};
						class WindowsApp     : Flutter {};
						class MacOSApp       : Flutter {};
						class LinuxApp       : Flutter {};
					}
				}

				namespace JavaNS
				{
					// Java
					class ConsoleApp      : Java {};
					class MinecraftMod    : Java {};
					class MinecraftPlugin : Java {};

					namespace MinecraftModNS
					{
						// Java -> MinecraftMod
						class Fabric : MinecraftMod {};
						class Forge  : MinecraftMod {};
					}

					namespace MinecraftPluginNS
					{
						// Java -> MinecraftPlugin
						class Spigot : MinecraftPlugin {};
						class Paper  : MinecraftPlugin {};
					}
				}

				namespace JavaScriptNS
				{
					// JavaScript
					class NodeJS      : JavaScript {};
					class ReactJS     : JavaScript {};
					class VueJS       : JavaScript {};
					class AngularJS   : JavaScript {};
					class ReactNative : JavaScript {};
					class JustWebApp  : JavaScript {};
				}

				namespace CSharpNS
				{
					// CSharp
					class ConsoleApp  : CSharp {};
					class WPFApp      : CSharp {};
					class WinFormsApp : CSharp {};
				}

				namespace CppNS
				{
					// CPP
					class ConsoleApp     : CPP {};
					class StaticLibrary  : CPP {};
					class DynamicLibrary : CPP {};
					class Walnut         : CPP {};
					class ImGui          : CPP {};
				}

				namespace CNS
				{
					// C
					class ConsoleApp     : C {};
					class ImGui          : C {};
					class StaticLibrary  : C {};
					class DynamicLibrary : C {};
				}

				namespace Combinations
				{
					// Combinations
					class WPFwithCPP    : CSharpNS::WPFApp,     CppNS::DynamicLibrary {};
					class PythonWithC   : PythonNS::ConsoleApp, CNS  ::StaticLibrary  {};
					class PythonWithCPP : PythonNS::ConsoleApp, CppNS::StaticLibrary  {};
					class PyGameWithC   : PythonNS::PyGame,     CNS  ::StaticLibrary  {};
					class PyGameWithCPP : PythonNS::PyGame,     CppNS::StaticLibrary  {};
				}
			}

			namespace GameNS
			{
				// Game
				class Godot     : Game {};
				class Unreal    : Game {};
				class Unity3D   : Game {};
				class Unity2D   : Game {};
				class Minecraft : Game {};

				namespace MinecraftNS
				{
					// Minecraft
					class ResourcePack : Minecraft {};
					class DataPack     : Minecraft {};
				}
			}

			namespace EditingNS
			{
				// Editing
				class Inkscape : Editing {};
				class Gimp     : Editing {};
				class Blender  : Editing {};
				class Edius    : Editing {};
				class Resolve  : Editing {};
			}

			namespace MusicNS
			{
				// Music
				class Audacity : Music {};
				class FLStudio : Music {};
				class Waveform : Music {};
			}

			namespace ThreeDNS
			{
				// ThreeD
				class Blender : ThreeD {};
			}

			namespace TwoDNS
			{
				// TwoD
				class Blender  : TwoD {};
				class Inkscape : TwoD {};
				class Gimp     : TwoD {};
			}

			namespace CompositingNS
			{
				// Compositing
				class Blender : Compositing {};
				class Resolve : Compositing {};
			}
		}
	}
}