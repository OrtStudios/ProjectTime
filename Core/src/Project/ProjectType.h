#pragma once

namespace Core
{
	namespace ProjectNS
	{
		class ProjectType { virtual std::string ToString() const { return "Unknown"; } };
		
		namespace ProjectTypeNS
		{
			class Unknown : ProjectType {
				std::string ToString() const override { return "Unknown"; }
			};

			class Programing : ProjectType {
				std::string ToString() const override { return "Programing"; }
			};

			class Game : ProjectType {
				std::string ToString() const override { return "Game"; }
			};

			class Editing : ProjectType {
				std::string ToString() const override { return "Editing"; }
			};

			class Music : ProjectType {
				std::string ToString() const override { return "Music"; }
			};

			class Movie : ProjectType {
				std::string ToString() const override { return "Movie"; }
			};

			class ShortFilm : ProjectType {
				std::string ToString() const override { return "ShortFilm"; }
			};

			class ThreeD : ProjectType {
				std::string ToString() const override { return "ThreeD"; }
			};

			class TwoD : ProjectType {
				std::string ToString() const override { return "TwoD"; }
			};

			class Compositing : ProjectType {
				std::string ToString() const override { return "Compositing"; }
			};

			namespace ProgramingNS
			{
				// Programing types
				class Python : Programing {
					std::string ToString() const override { return "Python"; }
				};

				class Dart : Programing {
					std::string ToString() const override { return "Dart"; }
				};

				class Java : Programing {
					std::string ToString() const override { return "Java"; }
				};

				class JavaScript : Programing {
					std::string ToString() const override { return "JavaScript"; }
				};

				class CSharp : Programing {
					std::string ToString() const override { return "CSharp"; }
				};

				class CPP : Programing {
					std::string ToString() const override { return "CPP"; }
				};

				class C : Programing {
					std::string ToString() const override { return "C"; }
				};

				namespace PythonNS
				{
					// Python
					class ConsoleApp : Python {
						std::string ToString() const override { return "Py_ConsoleApp"; }
					};
					
					class PyGame : Python {
						std::string ToString() const override { return "Py_PyGame"; }
					};
					
					class PySimpleGUI : Python {
						std::string ToString() const override { return "Py_PySimpleGUI"; }
					};
					
					class Kivy : Python {
						std::string ToString() const override { return "Py_Kivy"; }
					};
				}

				namespace DartNS
				{
					// Dart
					class ConsoleApp : Dart {
						std::string ToString() const override { return "Dart_ConsoleApp"; }
					};

					class Flutter : Dart {
						std::string ToString() const override { return "Dart_Flutter"; }
					};

					namespace FlutterNS
					{
						// Dart -> Flutter
						class FullMobileApp : Flutter {
							std::string ToString() const override { return "Flutter_FullMobileApp"; }
						};
						
						class AndroidApp : FullMobileApp {
							std::string ToString() const override { return "Flutter_AndroidApp"; }
						};
						
						class IOSApp : FullMobileApp {
							std::string ToString() const override { return "Flutter_IOSApp"; }
						};
						
						class WebApp : Flutter {
							std::string ToString() const override { return "Flutter_WebApp"; }
						};
						
						class FullDesktopApp : Flutter {
							std::string ToString() const override { return "Flutter_FullDesktopApp"; }
						};
						
						class WindowsApp : FullDesktopApp {
							std::string ToString() const override { return "Flutter_WindowsApp"; }
						};
						
						class MacOSApp : FullDesktopApp {
							std::string ToString() const override { return "Flutter_MacOSApp"; }
						};
						
						class LinuxApp : FullDesktopApp {
							std::string ToString() const override { return "Flutter_LinuxApp"; }
						};
					}
				}

				namespace JavaNS
				{
					// Java
					class ConsoleApp : Java {
						std::string ToString() const override { return "Java_ConsoleApp"; }
					};
					
					class MinecraftMod : Java {
						std::string ToString() const override { return "Java_MinecraftMod"; }
					};
					
					class MinecraftPlugin : Java {
						std::string ToString() const override { return "Java_MinecraftPlugin"; }
					};

					namespace MinecraftModNS
					{
						// Java -> MinecraftMod
						class Fabric : MinecraftMod {
							std::string ToString() const override { return "MCM_Fabric"; }
						};

						class Forge : MinecraftMod {
							std::string ToString() const override { return "MCM_Forge"; }
						};
					}

					namespace MinecraftPluginNS
					{
						// Java -> MinecraftPlugin
						class Spigot : MinecraftPlugin {
							std::string ToString() const override { return "MCPl_Spigot"; }
						};

						class Paper : MinecraftPlugin {
							std::string ToString() const override { return "MCPl_Paper"; }
						};
					}
				}

				namespace JavaScriptNS
				{
					// JavaScript
					class NodeJS : JavaScript {
						std::string ToString() const override { return "JS_NodeJS"; }
					};
					
					class ReactJS : JavaScript {
						std::string ToString() const override { return "JS_ReactJS"; }
					};
					
					class VueJS : JavaScript {
						std::string ToString() const override { return "JS_VueJS"; }
					};
					
					class AngularJS : JavaScript {
						std::string ToString() const override { return "JS_AngularJS"; }
					};
					
					class ReactNative : JavaScript {
						std::string ToString() const override { return "JS_ReactNative"; }
					};
					
					class JustWebApp : JavaScript {
						std::string ToString() const override { return "JS_JustWebApp"; }
					};
				}

				namespace CSharpNS
				{
					// CSharp
					class ConsoleApp : CSharp {
						std::string ToString() const override { return "CS_ConsoleApp"; }
					};
					
					class WPFApp : CSharp {
						std::string ToString() const override { return "CS_WPFApp"; }
					};
					
					class WinFormsApp : CSharp {
						std::string ToString() const override { return "CS_WinFormsApp"; }
					};
				}

				namespace CppNS
				{
					// CPP
					class ConsoleApp : CPP {
						std::string ToString() const override { return "Cpp_ConsoleApp"; }
					};
					
					class StaticLibrary : CPP {
						std::string ToString() const override { return "Cpp_StaticLibrary"; }
					};
					
					class DynamicLibrary : CPP {
						std::string ToString() const override { return "Cpp_DynamicLibrary"; }
					};
					
					class Walnut : CPP {
						std::string ToString() const override { return "Cpp_Walnut"; }
					};
					
					class ImGui : CPP {
						std::string ToString() const override { return "Cpp_ImGui"; }
					};
				}

				namespace CNS
				{
					// C
					class ConsoleApp : C {
						std::string ToString() const override { return "C_ConsoleApp"; }
					};
					
					class ImGui : C {
						std::string ToString() const override { return "C_ImGui"; }
					};
					
					class StaticLibrary : C {
						std::string ToString() const override { return "C_StaticLibrary"; }
					};
					
					class DynamicLibrary : C {
						std::string ToString() const override { return "C_DynamicLibrary"; }
					};
				}

				namespace Combinations
				{
					// Combinations
					class WPFwithCPP : CSharpNS::WPFApp, CppNS::DynamicLibrary {
						std::string ToString() const override { return "CS_Cpp_WPFwithCPP"; }
					};
					
					class PythonWithC : PythonNS::ConsoleApp, CNS::StaticLibrary {
						std::string ToString() const override { return "Py_C_PythonWithC"; }
					};
					
					class PythonWithCPP : PythonNS::ConsoleApp, CppNS::StaticLibrary {
						std::string ToString() const override { return "Py_Cpp_PythonWithCPP"; }
					};
					
					class PyGameWithC : PythonNS::PyGame, CNS::StaticLibrary {
						std::string ToString() const override { return "Py_C_PyGameWithC"; }
					};
					
					class PyGameWithCPP : PythonNS::PyGame, CppNS::StaticLibrary {
						std::string ToString() const override { return "Py_Cpp_PyGameWithCPP"; }
					};
				}
			}

			namespace GameNS
			{
				// Game
				class Godot : Game {
					std::string ToString() const override { return "Game_Godot"; }
				};
				
				class Unreal : Game {
					std::string ToString() const override { return "Game_Unreal"; }
				};
				
				class Unity3D : Game {
					std::string ToString() const override { return "Game_Unity3D"; }
				};
				
				class Unity2D : Game {
					std::string ToString() const override { return "Game_Unity2D"; }
				};
				
				class Minecraft : Game {
					std::string ToString() const override { return "Game_Minecraft"; }
				};

				namespace MinecraftNS
				{
					// Minecraft
					class ResourcePack : Minecraft {
						std::string ToString() const override { return "MC_ResourcePack"; }
					};

					class DataPack : Minecraft {
						std::string ToString() const override { return "MC_DataPack"; }
					};
				}
			}

			namespace EditingNS
			{
				// Editing
				class Inkscape : Editing {
					std::string ToString() const override { return "Editing_Inkscape"; }
				};
				
				class Blender : Editing {
					std::string ToString() const override { return "Editing_Blender"; }
				};
				
				class Edius : Editing {
					std::string ToString() const override { return "Editing_Edius"; }
				};
				
				class Resolve : Editing {
					std::string ToString() const override { return "Editing_Resolve"; }
				};
			}

			namespace MusicNS
			{
				// Music
				class Audacity : Music {
					std::string ToString() const override { return "Music_Audacity"; }
				};
				
				class FLStudio : Music {
					std::string ToString() const override { return "Music_FLStudio"; }
				};
				
				class Waveform : Music {
					std::string ToString() const override { return "Music_Waveform"; }
				};
			}

			namespace ThreeDNS
			{
				// ThreeD
				class Blender : ThreeD {
					std::string ToString() const override { return "ThreeD_Blender"; }
				};

				class Maya : ThreeD {
					std::string ToString() const override { return "ThreeD_Maya"; }
				};

				class ZBrush : ThreeD {
					std::string ToString() const override { return "ThreeD_ZBrush"; }
				};

				class SubstancePainter : ThreeD {
					std::string ToString() const override { return "ThreeD_SubstancePainter"; }
				};
			}

			namespace TwoDNS
			{
				// TwoD
				class Blender : TwoD {
					std::string ToString() const override { return "TwoD_Blender"; }
				};
				
				class Inkscape : TwoD {
					std::string ToString() const override { return "TwoD_Inkscape"; }
				};
				
				class Gimp : TwoD {
					std::string ToString() const override { return "TwoD_Gimp"; }
				};

				class Krita : TwoD {
					std::string ToString() const override { return "TwoD_Krita"; }
				};
			}

			namespace CompositingNS
			{
				// Compositing
				class Blender : Compositing {
					std::string ToString() const override { return "Compositing_Blender"; }
				};

				class Resolve : Compositing {
					std::string ToString() const override { return "Compositing_Resolve"; }
				};

				class Fusion : Compositing {
					std::string ToString() const override { return "Compositing_Fusion"; }
				};

				class Nuke : Compositing {
					std::string ToString() const override { return "Compositing_Nuke"; }
				};
			}
		}
	}
}