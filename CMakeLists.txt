# cmake_minimum_required(VERSION <specify CMake version here>)
project(VirtualQuest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Settings.cpp Settings.h VirtualQuest.cpp VirtualQuest.h DungeonMaster.cpp DungeonMaster.h characters/MainPlayer.cpp characters/MainPlayer.h characters/races/Stats.cpp characters/races/Stats.h characters/races/FullCharacter.cpp characters/races/FullCharacter.h characters/races/Languages.h characters/races/Elf.cpp characters/races/Elf.h dice.cpp dice.h)
add_executable(untitled ${SOURCE_FILES})