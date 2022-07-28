#pragma once

namespace Core
{
	class BaseProjectType {};
	
	namespace ProjectType
	{
		class Unknown     : BaseProjectType {};
		class programing  : BaseProjectType {};
		class game        : BaseProjectType {};
		class Editing     : BaseProjectType {};
		class Music       : BaseProjectType {};
		class Movie       : BaseProjectType {};
		class ShortFilm   : BaseProjectType {};
		class ThreeD      : BaseProjectType {};
		class TwoD        : BaseProjectType {};
		class Compositing : BaseProjectType {};

		namespace Programing
		{
			// Programing types
			class python     : programing {};
			class dart       : programing {};
			class java       : programing {};
			class javaScript : programing {};
			class cSharp     : programing {};
			class cPP        : programing {};
			class c          : programing {};

			namespace Python
			{
				// Python
				class ConsoleApp  : python {};
				class PyGame      : python {};
				class PySimpleGUI : python {};
				class Kivy        : python {};
			}

			namespace Dart
			{
				// Dart
				class ConsoleApp : dart {};
				class flutter    : dart {};

				namespace Flutter
				{
					// Dart -> Flutter
					class FullMobileApp  : flutter {};
					class AndroidApp     : flutter {};
					class IOSApp         : flutter {};
					class WebApp         : flutter {};
					class FullDesktopApp : flutter {};
					class WindowsApp     : flutter {};
					class MacOSApp       : flutter {};
					class LinuxApp       : flutter {};
				}
			}

			namespace Java
			{
				// Java
				class ConsoleApp      : java {};
				class minecraftMod    : java {};
				class minecraftPlugin : java {};

				namespace MinecraftMod
				{
					// Java -> MinecraftMod
					class Fabric : minecraftMod {};
					class Forge  : minecraftMod {};
				}

				namespace MinecraftPlugin
				{
					// Java -> MinecraftPlugin
					class Bukkit : minecraftPlugin {};
					class Paper  : minecraftPlugin {};
				}
			}

			namespace JavaScript
			{
				// JavaScript
				class NodeJS      : javaScript {};
				class ReactJS     : javaScript {};
				class VueJS       : javaScript {};
				class AngularJS   : javaScript {};
				class ReactNative : javaScript {};
				class JustWebApp  : javaScript {};
			}

			namespace CSharp
			{
				// CSharp
				class ConsoleApp  : cSharp {};
				class WPFApp      : cSharp {};
				class WinFormsApp : cSharp {};
			}

			namespace CPP
			{
				// CPP
				class ConsoleApp     : cPP {};
				class StaticLibrery  : cPP {};
				class DynamicLibrary : cPP {};
				class Walnut         : cPP {};
				class ImGui          : cPP {};
			}

			namespace C
			{
				// C
				class ConsoleApp     : c {};
				class ImGui          : c {};
				class StaticLibrery  : c {};
				class DynamicLibrary : c {};
			}

			namespace Combinations
			{
				// Combinations
				class WPFwithCPP : CSharp::WPFApp, CPP::DynamicLibrary {};
				class PythonWithC : Python::ConsoleApp, C::StaticLibrery {};
				class PythonWithCPP : Python::ConsoleApp, CPP::StaticLibrery {};
				class PyGameWithC : Python::PyGame, C::StaticLibrery {};
				class PyGameWithCPP : Python::PyGame, CPP::StaticLibrery {};
			}
		}

		namespace Game
		{
			// Game
			class Godot : game {};
			class Unreal : game {};
			class Unity3D : game {};
			class Unity2D : game {};
		}

		// Editing
		class Inkscape : Editing {};
		class Gimp : Editing {};
		class EditingBlender : Editing {};
		class Edius : Editing {};
		class EditingResolve : Editing {};

		// Music
		class Audacity : Music {};
		class FLStudio : Music {};
		class Waveform : Music {};

		// ThreeD
		class Blender3D : ThreeD {};

		// TwoD
		class Blender2D : TwoD {};

		// Compositing
		class BlenderCompositing : Compositing {};
		class ResolveCompositing : Compositing {};
	}
}