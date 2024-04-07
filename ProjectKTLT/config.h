#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
struct schoolYear;
struct Class;
struct semester;
struct Course;

enum programState { Welcome, SignIn, SignInAsStudent, SignInAsStaff, MenuStaff, MenuStudent, ChangePassStu, ChangePassSta, ViewStudentProfile, ChooseSchoolYear, MenuSchoolYear
, ChooseClass, MenuClass, ChooseSemester, MenuSemester, ChooseSchoolYearStudent, ChooseSemesterStudent, MenuSemesterStudent, AddStudentCLass, CreateSemester
};
struct Static
{
    programState currentState = programState::Welcome;

    std::string username = "";
    std::string password = "";

    //std::string schoolYear = "";

    schoolYear* curSchoolYear = nullptr;

    Course* curCourse = nullptr;

    Class* curClass = nullptr;

    semester* curSemester = nullptr;

    float width = 2000;
    float height = 1200;
    sf::Font fontB;
    sf::Font fontN;
    sf::Font fontI;
    sf::Color lightCyan = sf::Color(208, 227, 255);
    sf::Color backGroundWhite = sf::Color(255, 249, 240);
    sf::Color backGroundWhiteDarker = sf::Color(235, 229, 220); // Darker
    sf::Color backGroundWhiteLighter = sf::Color(255, 252, 240); // Creamier
    sf::Color backGroundWhiteDarkerStill = sf::Color(215, 209, 200); // Even darker
    sf::Color backGroundWhiteMuchDarker = sf::Color(175, 169, 160); // Much darker
    sf::Color textColorBlue = sf::Color(8, 31, 92);
    sf::Color highlightCyan = sf::Color(93, 117, 153);
    
    sf::Color pastelGrey = sf::Color(192, 192, 192);
    sf::Color pastelCyan = sf::Color(156, 217, 207);
    sf::Color pastelPink1 = sf::Color(255, 230, 230);
    sf::Color pastelYellow1 = sf::Color(255, 247, 212);
    sf::Color pastelTitleCyan = sf::Color(185, 204, 218);
    sf::Color pastelSoftBlue = sf::Color(155, 184, 205);
    sf::Color titleGreyColor = sf::Color(64, 64, 64);
    sf::Color lightGrey = sf::Color(200, 200, 200);
    sf::Color fcc689 = sf::Color(48, 58,  60);
    sf::Color blurGrey = sf::Color(64, 64, 64, 150);
    sf::Texture texture;
    
    sf::Sprite sprite;
    
    Static()
    {
        if (!texture.loadFromFile("Background.jpg")) // Replace with your image file
        {
            // Handle error
        }
        sprite.setTexture(texture);
        sprite.setScale(
            static_cast<float>(width) / sprite.getLocalBounds().width, // Scale X
            static_cast<float>(height) / sprite.getLocalBounds().height // Scale Y
        );
        try {

            if (!fontB.loadFromFile("Palatino Linotype Bold.ttf")) {
                // Handle font loading error
                throw std::runtime_error("Failed to load fontB");
            }
            if (!fontN.loadFromFile("Palatino LinoType.ttf")) {
                // Handle font loading error
                throw std::runtime_error("Failed to load fontN");
            }
            if (!fontI.loadFromFile("Palatino Linotype Italic.ttf")) {
                // Handle font loading error
                throw std::runtime_error("Failed to load fontI");
            }
        }
        catch (const std::exception& e) {
            // Log or display the error message
            std::cout << "Font loading error: " << e.what() << std::endl;
            // Optionally, you can terminate the program or handle the error in another way
        }
    }
    
};