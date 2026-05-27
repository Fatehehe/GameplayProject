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
        mClock.restart();

        float accumulatedTime = 0.f;
        float targetDeltaTime = 1.f/ mTargetFrameRate;

        while (mWindow.isOpen())
        {
            while (const std::optional event = mWindow.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    mWindow.close();
            }

            float frameRateDeltaTime = mClock.restart().asSeconds();
            accumulatedTime += frameRateDeltaTime;

            while(accumulatedTime >= targetDeltaTime){
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
            }
        }
    }

    void Application::RenderInternal(){
        mWindow.clear();
        Render(mWindow);
        mWindow.display();
    }

    void Application::Render(sf::RenderWindow& window){

    }

    void Application::TickInternal(float deltaTime){
        Tick(deltaTime);
        LOG("Delta Time: %f", deltaTime);
    }

    void Application::Tick(float deltaTime){

    }
}