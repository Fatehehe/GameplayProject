#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace gp{
    class Application{
        public:
            Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, std::uint32_t style);
            virtual ~Application();

            void Run();
            virtual void Render(sf::RenderWindow& window);
            virtual void Tick(float deltaTime);


        private:
            void RenderInternal();
            void TickInternal(float deltaTime);

            sf::RenderWindow mWindow;
            float mTargetFrameRate; 
            sf::Clock mClock;
            
    };
}