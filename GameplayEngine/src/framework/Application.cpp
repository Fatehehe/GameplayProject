#include "framework/Application.h"
#include "framework/World.h"

namespace gp{
    Application::Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, std::uint32_t style)
    : mWindow{sf::VideoMode({windowWidth, windowHeight}), title, style},
    mTargetFrameRate{60.f},
    mTickClock{},
    mCleanCycleClock{},
    mCleanCycleInterval{2.f},
    mCurrentWorld{nullptr}
    {
    }

    Application::~Application(){}

    void Application::Run()
    {
        mTickClock.restart();

        float accumulatedTime = 0.f;
        float targetDeltaTime = 1.f/ mTargetFrameRate;

        while (mWindow.isOpen())
        {
            while (const std::optional event = mWindow.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    mWindow.close();
            }

            float frameRateDeltaTime = mTickClock.restart().asSeconds();
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
        if(mCurrentWorld){
            mCurrentWorld->BeginPlayInternal();
            mCurrentWorld->TickInternal(deltaTime);
        }
    }

    void Application::Tick(float deltaTime){

    }
}