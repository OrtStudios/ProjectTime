#pragma once

namespace Core
{
	class ProjectType {};
	
	namespace ProjectType
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

		namespace Programing
		{
			// Programing types
			class Python     : Programing {};
			class Dart       : Programing {};
			class Java       : Programing {};
			class JavaScript : Programing {};
			class CSharp     : Programing {};
			class CPP        : Programing {};
			class C          : Programing {};

			namespace Python
			{
				// Python
				class ConsoleApp  : Python {};
				class PyGame      : Python {};
				class PySimpleGUI : Python {};
				class Kivy        : Python {};
			}

			namespace Dart
			{
				// Dart
				class ConsoleApp : Dart {};
				class Flutter    : Dart {};

				namespace Flutter
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

			namespace Java
			{
				// Java
				class ConsoleApp      : Java {};
				class MinecraftMod    : Java {};
				class MinecraftPlugin : Java {};

				namespace MinecraftMod
				{
					// Java -> MinecraftMod
					class Fabric : MinecraftMod {};
					class Forge  : MinecraftMod {};
				}

				namespace MinecraftPlugin
				{
					// Java -> MinecraftPlugin
					class Bukkit : MinecraftPlugin {};
					class Paper  : MinecraftPlugin {};
				}
			}

			namespace JavaScript
			{
				// JavaScript
				class NodeJS      : JavaScript {};
				class ReactJS     : JavaScript {};
				class VueJS       : JavaScript {};
				class AngularJS   : JavaScript {};
				class ReactNative : JavaScript {};
				class JustWebApp  : JavaScript {};
			}

			namespace CSharp
			{
				// CSharp
				class ConsoleApp  : CSharp {};
				class WPFApp      : CSharp {};
				class WinFormsApp : CSharp {};
			}

			namespace CPP
			{
				// CPP
				class ConsoleApp     : CPP {};
				class StaticLibrary  : CPP {};
				class DynamicLibrary : CPP {};
				class Walnut         : CPP {};
				class ImGui          : CPP {};
			}

			namespace C
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
				class WPFwithCPP    : CSharp::WPFApp,     CPP::DynamicLibrary {};
				class PythonWithC   : Python::ConsoleApp, C::StaticLibrary    {};
				class PythonWithCPP : Python::ConsoleApp, CPP::StaticLibrary  {};
				class PyGameWithC   : Python::PyGame,     C::StaticLibrary    {};
				class PyGameWithCPP : Python::PyGame,     CPP::StaticLibrary  {};
			}
		}

		namespace Game
		{
			// Game
			class Godot   : Game {};
			class Unreal  : Game {};
			class Unity3D : Game {};
			class Unity2D : Game {};
		}

		namespace Editing
		{
			// Editing
			class Inkscape : Editing {};
			class Gimp     : Editing {};
			class Blender  : Editing {};
			class Edius    : Editing {};
			class Resolve  : Editing {};
		}

		namespace Music
		{
			// Music
			class Audacity : Music {};
			class FLStudio : Music {};
			class Waveform : Music {};
		}

		namespace ThreeD
		{
			// ThreeD
			class Blender : ThreeD {};
		}

		namespace TwoD
		{
			// TwoD
			class Blender  : TwoD {};
			class Inkscape : TwoD {};
			class Gimp     : TwoD {};
		}

		namespace Compositing
		{
			// Compositing
			class Blender : Compositing {};
			class Resolve : Compositing {};
		}
	}
}