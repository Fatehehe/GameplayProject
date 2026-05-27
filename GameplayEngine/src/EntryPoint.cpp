#include <EntryPoint.h>
#include "framework/Application.h"

int main(){
    gp::Application* app = gp::GetApplication();
    app->Run();
    delete app;
    return 0;
}