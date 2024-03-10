#include <iostream>
#include <SFML/Graphics.hpp>

// Functions
void createAButton(sf::RectangleShape& button, sf::Text& buttonText, const sf::Vector2f& size, const sf::Color& fillColor, const sf::Font& font, const sf::Color& textColor, const std::string& text, const sf::Vector2f& position) {
    // Set button properties
    button.setSize(size);
    button.setFillColor(fillColor);
    button.setPosition(position);

    // Set button text properties
    buttonText.setFont(font);
    buttonText.setFillColor(textColor);
    buttonText.setString(text);
    buttonText.setCharacterSize(80);

    // Set text origin to center
    sf::FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    buttonText.setPosition(position.x + size.x / 2.0f, position.y + size.y / 2.0f);
}

int main() {
    // Create the window
    int width = 2000;
    int height = 1200;
    sf::RenderWindow window(sf::VideoMode(width, height), "CourseManagingSystem");

    // Set font
    sf::Font fontB;
    if (!fontB.loadFromFile("Palatino Linotype Bold.ttf"))
        return -1;
    sf::Font fontN;
    if (!fontN.loadFromFile("Palatino LinoType.ttf"))
        return -1;
    sf::Font fontI;
    if (!fontI.loadFromFile("Palatino Linotype Italic.ttf"))
        return -1;
    // Set color
    sf::Color backGroundWhite(255, 249, 240);
    sf::Color textColorBlue(8, 31, 92);
    sf::Color highlightCyan(93, 117, 153);
    sf::Color pastelGrey(192, 192, 192);
    sf::Color pastelCyan(156, 217, 207);
    sf::Color pastelPink1(255, 230, 230);
    sf::Color pastelYellow1(255, 247, 212);
    sf::Color pastelTitleCyan(185, 204, 218);
    sf::Color pastelSoftBlue(155, 184, 205);
    sf::Color titleGreyColor(64, 64, 64);
    // Create welcome
    sf::Text welcomeText;
    welcomeText.setFont(fontB);
    // Set the color and edit
    welcomeText.setFillColor(textColorBlue);
    welcomeText.setString("WELCOME TO");
    welcomeText.setCharacterSize(80);
    welcomeText.setPosition((float)(width / 2), 0.f);

    // Centralize 
    sf::FloatRect textRect = welcomeText.getLocalBounds();
    welcomeText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    welcomeText.setPosition(sf::Vector2f(width / 2.0f, 150));
     
    // Create program name
    sf::Text course;
    course.setFont(fontB);
    // Set the color and edit
    course.setFillColor(highlightCyan);
    course.setString("COURSE MANAGING SYSTEM");
    course.setCharacterSize(120);
    course.setPosition((float)(width / 2), 0.f);
    // Centralize 
    textRect = course.getLocalBounds();
    course.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    course.setPosition(sf::Vector2f(width / 2.0f, 300));



    // Define two rectangles to represent different pages
    sf::RectangleShape welcomePage(sf::Vector2f((float)width, (float)height));
    welcomePage.setFillColor(backGroundWhite);
    sf::RectangleShape signInPage(sf::Vector2f((float)width, (float)height));
    signInPage.setFillColor(highlightCyan);


    // Create buttons to sign in page
    
    sf::RectangleShape SignInRec(sf::Vector2f(600.0f, 200.0f));
    sf::Text SignInText;
    createAButton(SignInRec, SignInText, sf::Vector2f(600.0f, 200.0f), pastelGrey, fontB, textColorBlue, "SIGN IN", sf::Vector2f(400.0f, 600.0f));

    // Flag
    bool isWelcomeVisible = true;
    bool isSignInVisible = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if the left mouse button is clicked
                    if (SignInRec.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        isWelcomeVisible = false;
                        isSignInVisible = true;
                    }
                }
            }
        }

        // Clear the window
        window.clear();

        // Draw the appropriate page based on the flag
        if (isWelcomeVisible == true)
        {
            window.draw(welcomePage);
            window.draw(welcomeText);
            window.draw(course);
            window.draw(SignInRec);
            window.draw(SignInText);
        }
        if (isSignInVisible == true)
        {
            window.draw(signInPage);
        }
        // Display the content
        window.display();
    }

    return 0;
}



