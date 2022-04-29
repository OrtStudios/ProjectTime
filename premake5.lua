-- premake5.lua
workspace "ProjectTime"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "ProjectTime"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
include "Walnut/WalnutExternal.lua"

include "ProjectTime"