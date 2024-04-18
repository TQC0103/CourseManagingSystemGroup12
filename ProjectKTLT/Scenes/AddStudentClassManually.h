#pragma once
#include "../UserInterface.h"
#include "../config.h"
#include "../Class.h"

struct Scene;
struct AddStudentClassManuallyScene
{
	sf::RectangleShape addManuallyBackgr;
	sf::Text addManuallyText;
	sf::Text classText;

	schoolYear* year = nullptr;
	std::string semesterData = "";

	sf::ConvexShape preButt;
	sf::Text preText;

	sf::RectangleShape no;
	sf::Text noText;
	std::string noInput = "";
	sf::Text enterNoHere;

	sf::RectangleShape id;
	sf::Text idText;
	std::string idInput = "";
	sf::Text enterIdHere;

	sf::RectangleShape firstname;
	sf::Text firstnameText;
	std::string firstnameInput = "";
	sf::Text enterFirstnameHere;

	sf::RectangleShape lastname;
	sf::Text lastnameText;
	std::string lastnameInput = "";
	sf::Text enterLastnameHere;

	sf::RectangleShape gender;
	sf::Text genderText;
	std::string genderInput = "";
	sf::Text enterGenderHere;


	sf::RectangleShape birthday;
	sf::Text birthdayText;
	std::string birthdayInput = "";
	sf::Text enterbirthdayHere;


	sf::RectangleShape sID;
	sf::Text sIDText;
	std::string sIDInput = "";
	sf::Text entersIDHere;


	sf::ConvexShape create;
	sf::Text creatingText;

	sf::Clock cursorClock;
	bool isCursorVisible;

	sf::Text successful;
	sf::Text fail;
	
	int isWrong = 0;
	
	int inputEnable = -1;
	int maxInputLength = 15;
	

	// Constructors
	AddStudentClassManuallyScene(Static* a);

	// Functions
	void drawAddMunually(sf::RenderWindow& win, Static* a);
	void renderAddManually(sf::Event event, Scene* scene, sf::RenderWindow& win);

};
