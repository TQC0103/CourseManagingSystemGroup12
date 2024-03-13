#pragma once
#include "Welcome.h"

void WelcomePage::drawWelcome()
{
    window.draw(welcomeRect);
    window.draw(welcomeText);
    window.draw(course);
    window.draw(signInRect);
    window.draw(signInText);
    window.draw(exitRect);
    window.draw(exitText);
}