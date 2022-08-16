#pragma once

namespace Core
{
	namespace Project
	{
		class _ProjectType {};
		
		namespace ProjectType
		{
			class _Unknown     : _ProjectType {};
			class _Programing  : _ProjectType {};
			class _Game        : _ProjectType {};
			class _Editing     : _ProjectType {};
			class _Music       : _ProjectType {};
			class _Movie       : _ProjectType {};
			class _ShortFilm   : _ProjectType {};
			class _ThreeD      : _ProjectType {};
			class _TwoD        : _ProjectType {};
			class _Compositing : _ProjectType {};

			namespace Programing
			{
				// Programing types
				class _Python     : _Programing {};
				class _Dart       : _Programing {};
				class _Java       : _Programing {};
				class _JavaScript : _Programing {};
				class _CSharp     : _Programing {};
				class _CPP        : _Programing {};
				class _C          : _Programing {};

				namespace Python
				{
					// Python
					class ConsoleApp  : _Python {};
					class PyGame      : _Python {};
					class PySimpleGUI : _Python {};
					class Kivy        : _Python {};
				}

				namespace Dart
				{
					// Dart
					class ConsoleApp : _Dart {};
					class _Flutter    : _Dart {};

					namespace Flutter
					{
						// Dart -> Flutter
						class FullMobileApp  : _Flutter {};
						class AndroidApp     : _Flutter {};
						class IOSApp         : _Flutter {};
						class WebApp         : _Flutter {};
						class FullDesktopApp : _Flutter {};
						class WindowsApp     : _Flutter {};
						class MacOSApp       : _Flutter {};
						class LinuxApp       : _Flutter {};
					}
				}

				namespace Java
				{
					// Java
					class ConsoleApp      : _Java {};
					class _MinecraftMod    : _Java {};
					class _MinecraftPlugin : _Java {};

					namespace MinecraftMod
					{
						// Java -> MinecraftMod
						class Fabric : _MinecraftMod {};
						class Forge  : _MinecraftMod {};
					}

					namespace MinecraftPlugin
					{
						// Java -> MinecraftPlugin
						class Bukkit : _MinecraftPlugin {};
						class Paper  : _MinecraftPlugin {};
					}
				}

				namespace JavaScript
				{
					// JavaScript
					class NodeJS      : _JavaScript {};
					class ReactJS     : _JavaScript {};
					class VueJS       : _JavaScript {};
					class AngularJS   : _JavaScript {};
					class ReactNative : _JavaScript {};
					class JustWebApp  : _JavaScript {};
				}

				namespace CSharp
				{
					// CSharp
					class ConsoleApp  : _CSharp {};
					class WPFApp      : _CSharp {};
					class WinFormsApp : _CSharp {};
				}

				namespace CPP
				{
					// CPP
					class ConsoleApp     : _CPP {};
					class StaticLibrary  : _CPP {};
					class DynamicLibrary : _CPP {};
					class Walnut         : _CPP {};
					class ImGui          : _CPP {};
				}

				namespace C
				{
					// C
					class ConsoleApp     : _C {};
					class ImGui          : _C {};
					class StaticLibrary  : _C {};
					class DynamicLibrary : _C {};
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
				class Godot     : _Game {};
				class Unreal    : _Game {};
				class Unity3D   : _Game {};
				class Unity2D   : _Game {};
				class _Minecraft : _Game {};

				namespace Minecraft
				{
					// Minecraft
					class ResourcePack : _Minecraft {};
					class DataPack     : _Minecraft {};
				}
			}

			namespace Editing
			{
				// Editing
				class Inkscape : _Editing {};
				class Gimp     : _Editing {};
				class Blender  : _Editing {};
				class Edius    : _Editing {};
				class Resolve  : _Editing {};
			}

			namespace Music
			{
				// Music
				class Audacity : _Music {};
				class FLStudio : _Music {};
				class Waveform : _Music {};
			}

			namespace ThreeD
			{
				// ThreeD
				class Blender : _ThreeD {};
			}

			namespace TwoD
			{
				// TwoD
				class Blender  : _TwoD {};
				class Inkscape : _TwoD {};
				class Gimp     : _TwoD {};
			}

			namespace Compositing
			{
				// Compositing
				class Blender : _Compositing {};
				class Resolve : _Compositing {};
			}
		}
	}
}