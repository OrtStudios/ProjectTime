#pragma once

namespace Core
{
	namespace ProjectNS
	{
		class ProjectType 
		{
		public:
			std::string ToString() const { return "Unknown"; }
		};
		
		namespace ProjectTypeNS
		{
			class Unknown : ProjectType {
			public:
				std::string ToString() const { return "Unknown"; }
			};

			class Programing : ProjectType {
			public:
				std::string ToString() const { return "Programing"; }
			};

			class Game : ProjectType {
			public:
				std::string ToString() const  { return "Game"; }
			};

			class Editing : ProjectType {
			public:
				std::string ToString() const { return "Editing"; }
			};

			class Music : ProjectType {
			public:
				std::string ToString() const { return "Music"; }
			};

			class Movie : ProjectType {
			public:
				std::string ToString() const { return "Movie"; }
			};

			class ShortFilm : ProjectType {
			public:
				std::string ToString() const { return "ShortFilm"; }
			};

			class ThreeD : ProjectType {
			public:
				std::string ToString() const { return "ThreeD"; }
			};

			class TwoD : ProjectType {
			public:
				std::string ToString() const { return "TwoD"; }
			};

			class Compositing : ProjectType {
			public:
				std::string ToString() const { return "Compositing"; }
			};

			namespace ProgramingNS
			{
				// Programing types
				class Python : Programing {
				public:
					std::string ToString() const { return "Python"; }
				};

				class Dart : Programing {
				public:
					std::string ToString() const { return "Dart"; }
				};

				class Java : Programing {
				public:
					std::string ToString() const { return "Java"; }
				};

				class JavaScript : Programing {
				public:
					std::string ToString() const { return "JavaScript"; }
				};

				class CSharp : Programing {
				public:
					std::string ToString() const { return "CSharp"; }
				};

				class CPP : Programing {
				public:
					std::string ToString() const { return "CPP"; }
				};

				class C : Programing {
				public:
					std::string ToString() const { return "C"; }
				};

				namespace PythonNS
				{
					// Python
					class ConsoleApp : Python {
					public:
						std::string ToString() const { return "Py_ConsoleApp"; }
					};
					
					class PyGame : Python {
					public:
						std::string ToString() const { return "Py_PyGame"; }
					};
					
					class PySimpleGUI : Python {
					public:
						std::string ToString() const { return "Py_PySimpleGUI"; }
					};
					
					class Kivy : Python {
					public:
						std::string ToString() const { return "Py_Kivy"; }
					};
				}

				namespace DartNS
				{
					// Dart
					class ConsoleApp : Dart {
					public:
						std::string ToString() const { return "Dart_ConsoleApp"; }
					};

					class Flutter : Dart {
					public:
						std::string ToString() const { return "Dart_Flutter"; }
					};

					namespace FlutterNS
					{
						// Dart -> Flutter
						class FullMobileApp : Flutter {
						public:
							std::string ToString() const { return "Flutter_FullMobileApp"; }
						};
						
						class AndroidApp : FullMobileApp {
						public:
							std::string ToString() const { return "Flutter_AndroidApp"; }
						};
						
						class IOSApp : FullMobileApp {
						public:
							std::string ToString() const { return "Flutter_IOSApp"; }
						};
						
						class WebApp : Flutter {
						public:
							std::string ToString() const { return "Flutter_WebApp"; }
						};
						
						class FullDesktopApp : Flutter {
						public:
							std::string ToString() const { return "Flutter_FullDesktopApp"; }
						};
						
						class WindowsApp : FullDesktopApp {
						public:
							std::string ToString() const { return "Flutter_WindowsApp"; }
						};
						
						class MacOSApp : FullDesktopApp {
						public:
							std::string ToString() const { return "Flutter_MacOSApp"; }
						};
						
						class LinuxApp : FullDesktopApp {
						public:
							std::string ToString() const { return "Flutter_LinuxApp"; }
						};
					}
				}

				namespace JavaNS
				{
					// Java
					class ConsoleApp : Java {
					public:
						std::string ToString() const { return "Java_ConsoleApp"; }
					};
					
					class MinecraftMod : Java {
					public:
						std::string ToString() const { return "Java_MinecraftMod"; }
					};
					
					class MinecraftPlugin : Java {
					public:
						std::string ToString() const { return "Java_MinecraftPlugin"; }
					};

					namespace MinecraftModNS
					{
						// Java -> MinecraftMod
						class Fabric : MinecraftMod {
						public:
							std::string ToString() const { return "MCM_Fabric"; }
						};

						class Forge : MinecraftMod {
						public:
							std::string ToString() const { return "MCM_Forge"; }
						};
					}

					namespace MinecraftPluginNS
					{
						// Java -> MinecraftPlugin
						class Spigot : MinecraftPlugin {
						public:
							std::string ToString() const { return "MCPl_Spigot"; }
						};

						class Paper : MinecraftPlugin {
						public:
							std::string ToString() const { return "MCPl_Paper"; }
						};
					}
				}

				namespace JavaScriptNS
				{
					// JavaScript
					class NodeJS : JavaScript {
					public:
						std::string ToString() const { return "JS_NodeJS"; }
					};
					
					class ReactJS : JavaScript {
					public:
						std::string ToString() const { return "JS_ReactJS"; }
					};
					
					class VueJS : JavaScript {
					public:
						std::string ToString() const { return "JS_VueJS"; }
					};
					
					class AngularJS : JavaScript {
					public:
						std::string ToString() const { return "JS_AngularJS"; }
					};
					
					class ReactNative : JavaScript {
					public:
						std::string ToString() const { return "JS_ReactNative"; }
					};
					
					class JustWebApp : JavaScript {
					public:
						std::string ToString() const { return "JS_JustWebApp"; }
					};
				}

				namespace CSharpNS
				{
					// CSharp
					class ConsoleApp : CSharp {
					public:
						std::string ToString() const { return "CS_ConsoleApp"; }
					};
					
					class WPFApp : CSharp {
					public:
						std::string ToString() const { return "CS_WPFApp"; }
					};
					
					class WinFormsApp : CSharp {
					public:
						std::string ToString() const { return "CS_WinFormsApp"; }
					};
				}

				namespace CppNS
				{
					// CPP
					class ConsoleApp : CPP {
					public:
						std::string ToString() const { return "Cpp_ConsoleApp"; }
					};
					
					class StaticLibrary : CPP {
					public:
						std::string ToString() const { return "Cpp_StaticLibrary"; }
					};
					
					class DynamicLibrary : CPP {
					public:
						std::string ToString() const { return "Cpp_DynamicLibrary"; }
					};
					
					class Walnut : CPP {
					public:
						std::string ToString() const { return "Cpp_Walnut"; }
					};
					
					class ImGui : CPP {
					public:
						std::string ToString() const { return "Cpp_ImGui"; }
					};
				}

				namespace CNS
				{
					// C
					class ConsoleApp : C {
					public:
						std::string ToString() const { return "C_ConsoleApp"; }
					};
					
					class ImGui : C {
					public:
						std::string ToString() const { return "C_ImGui"; }
					};
					
					class StaticLibrary : C {
					public:
						std::string ToString() const { return "C_StaticLibrary"; }
					};
					
					class DynamicLibrary : C {
					public:
						std::string ToString() const { return "C_DynamicLibrary"; }
					};
				}

				namespace Combinations
				{
					// Combinations
					class WPFwithCPP : CSharpNS::WPFApp, CppNS::DynamicLibrary {
					public:
						std::string ToString() const { return "CS_Cpp_WPFwithCPP"; }
					};
					
					class PythonWithC : PythonNS::ConsoleApp, CNS::StaticLibrary {
					public:
						std::string ToString() const { return "Py_C_PythonWithC"; }
					};
					
					class PythonWithCPP : PythonNS::ConsoleApp, CppNS::StaticLibrary {
					public:
						std::string ToString() const { return "Py_Cpp_PythonWithCPP"; }
					};
					
					class PyGameWithC : PythonNS::PyGame, CNS::StaticLibrary {
					public:
						std::string ToString() const { return "Py_C_PyGameWithC"; }
					};
					
					class PyGameWithCPP : PythonNS::PyGame, CppNS::StaticLibrary {
					public:
						std::string ToString() const { return "Py_Cpp_PyGameWithCPP"; }
					};
				}
			}

			namespace GameNS
			{
				// Game
				class Godot : Game {
				public:
					std::string ToString() const { return "Game_Godot"; }
				};
				
				class Unreal : Game {
				public:
					std::string ToString() const { return "Game_Unreal"; }
				};
				
				class Unity3D : Game {
				public:
					std::string ToString() const { return "Game_Unity3D"; }
				};
				
				class Unity2D : Game {
				public:
					std::string ToString() const { return "Game_Unity2D"; }
				};
				
				class Minecraft : Game {
				public:
					std::string ToString() const { return "Game_Minecraft"; }
				};

				namespace MinecraftNS
				{
					// Minecraft
					class ResourcePack : Minecraft {
					public:
						std::string ToString() const { return "MC_ResourcePack"; }
					};

					class DataPack : Minecraft {
					public:
						std::string ToString() const { return "MC_DataPack"; }
					};
				}
			}

			namespace EditingNS
			{
				// Editing
				class Inkscape : Editing {
				public:
					std::string ToString() const { return "Editing_Inkscape"; }
				};
				
				class Blender : Editing {
				public:
					std::string ToString() const { return "Editing_Blender"; }
				};
				
				class Edius : Editing {
				public:
					std::string ToString() const { return "Editing_Edius"; }
				};
				
				class Resolve : Editing {
				public:
					std::string ToString() const { return "Editing_Resolve"; }
				};
			}

			namespace MusicNS
			{
				// Music
				class Audacity : Music {
				public:
					std::string ToString() const { return "Music_Audacity"; }
				};
				
				class FLStudio : Music {
				public:
					std::string ToString() const { return "Music_FLStudio"; }
				};
				
				class Waveform : Music {
				public:
					std::string ToString() const { return "Music_Waveform"; }
				};
			}

			namespace ThreeDNS
			{
				// ThreeD
				class Blender : ThreeD {
				public:
					std::string ToString() const { return "ThreeD_Blender"; }
				};

				class Maya : ThreeD {
				public:
					std::string ToString() const { return "ThreeD_Maya"; }
				};

				class ZBrush : ThreeD {
				public:
					std::string ToString() const { return "ThreeD_ZBrush"; }
				};

				class SubstancePainter : ThreeD {
				public:
					std::string ToString() const { return "ThreeD_SubstancePainter"; }
				};
			}

			namespace TwoDNS
			{
				// TwoD
				class Blender : TwoD {
				public:
					std::string ToString() const { return "TwoD_Blender"; }
				};
				
				class Inkscape : TwoD {
				public:
					std::string ToString() const { return "TwoD_Inkscape"; }
				};
				
				class Gimp : TwoD {
				public:
					std::string ToString() const { return "TwoD_Gimp"; }
				};

				class Krita : TwoD {
				public:
					std::string ToString() const { return "TwoD_Krita"; }
				};
			}

			namespace CompositingNS
			{
				// Compositing
				class Blender : Compositing {
				public:
					std::string ToString() const { return "Compositing_Blender"; }
				};

				class Resolve : Compositing {
				public:
					std::string ToString() const { return "Compositing_Resolve"; }
				};

				class Fusion : Compositing {
				public:
					std::string ToString() const { return "Compositing_Fusion"; }
				};

				class Nuke : Compositing {
				public:
					std::string ToString() const { return "Compositing_Nuke"; }
				};
			}
		}
	}
}