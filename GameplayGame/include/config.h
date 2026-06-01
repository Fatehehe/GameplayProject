#pragma once
#include <string>

std::string GetResourceDirectory(){
    #ifdef NDEBUG
        return "assets/";
    #else
        return "/Users/fatakhillahkhaqo/Documents/Personal Projects/Game Dev/GameplayProject/GameplayGame/assets/";
    #endif
}
