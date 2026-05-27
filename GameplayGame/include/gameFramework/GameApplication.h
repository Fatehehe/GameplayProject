#pragma once
#include "framework/Application.h"

namespace gp{
    class Actor;
    class GameApplication : public Application{
        public:
            GameApplication();
            virtual ~GameApplication();

            // virtual void Render(sf::RenderWindow& window) override;
            virtual void Tick(float deltaTime) override;

        
        private:
            float timer;
            weak<Actor> testActor;
    };
}