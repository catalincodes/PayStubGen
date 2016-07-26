#include "ViewMainMenu.h"
#include <iostream>

void ViewMainMenu::update()
{
	displayMenu();
}

void ViewMainMenu::displayMenu()
{
	std::cout << "\n\n\n";
	std::cout << " === Main Menu ===" << std::endl;
	std::cout << " 1. Option 1" << std::endl;
	std::cout << " 2. Option 2" << std::endl;
	std::cout << " 3. Option 3" << std::endl;
	std::cout << "\n Make a choice (1-3): ";
}

ViewMainMenu::ViewMainMenu(Model* usedModel) : View(usedModel)
{
	std::cout << "I'm being created" << std::endl;
}


ViewMainMenu::~ViewMainMenu()
{
	std::cout << "I'm getting killed -- ViewMainMenu" << std::endl;
}
