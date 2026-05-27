#include "framework/Application.h"

namespace gp{
    Application::Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, std::uint32_t style)
    : mWindow{sf::VideoMode({windowWidth, windowHeight}), title, style},
    mTargetFrameRate{60.f}
    {
    }

    Application::~Application(){}

    void Application::Run()
    {
        float accumulatedTime = 0.f;
        float targetDeltaTime = 1.f/ mTargetFrameRate;

        while (mWindow.isOpen())
        {
            while (const std::optional event = mWindow.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    mWindow.close();
            }
        }
    }
}