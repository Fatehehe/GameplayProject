#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace gp{
    class Application{
        public:
            Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, std::uint32_t style);
            ~Application();

            void Run();

        private:
            sf::RenderWindow mWindow;
            float mTargetFrameRate; 

    };
}