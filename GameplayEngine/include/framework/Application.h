#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace gp{
    class World;
    class Application{
        public:
            Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, std::uint32_t style);
            virtual ~Application();

            void Run();
            
            template<typename WorldType>
            weak<WorldType> LoadWorld();

        private:
            virtual void Render(sf::RenderWindow& window);
            virtual void Tick(float deltaTime);
            void RenderInternal();
            void TickInternal(float deltaTime);

            sf::RenderWindow mWindow;
            float mTargetFrameRate; 
            sf::Clock mTickClock;
            sf::Clock mCleanCycleClock;
            float mCleanCycleInterval;
            
            shared<World> mCurrentWorld;
    };

    template<typename WorldType>
    weak<WorldType> Application::LoadWorld(){
        shared<WorldType> newWorld{new WorldType(this)};
        mCurrentWorld = newWorld;
        return newWorld;
    }
}