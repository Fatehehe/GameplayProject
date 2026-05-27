#pragma once
#include "framework/Application.h"

namespace gp{
    class GameApplication : public Application{
        public:
            GameApplication();
            virtual ~GameApplication();

            virtual void Render(sf::RenderWindow& window) override;
            virtual void Tick(float deltaTime) override;
    };
}