#include "SideTools.h"
#include <iostream>
#include <fstream>

SideTools::SideTools()
{
	for (size_t i = 0; i < NUM_OF_ICONS; i++)
		m_positions[i] = sf::Vector2f(0, i * (float)P_SIZE);
}

void SideTools::setToolbar()
{
	std::ifstream inputFile("Names.txt");

	// Check if the file is successfully opened
	if (!inputFile.is_open()) {
		std::cerr << "Unable to open file 'Names.txt'" << std::endl;
		exit(EXIT_FAILURE); 
	}

	std::string line;
	int i = 0;

	// Read and print each line until the end of the file
	while (std::getline(inputFile, line)) {
		m_pTexture[IconsBar(i)].loadFromFile(line);
		m_sprite[i].setTexture(m_pTexture[i]);
		
		m_sprite[i].setScale(sf::Vector2f(((float)P_SIZE / m_sprite[i].getGlobalBounds().height), ((float)P_SIZE / m_sprite[i].getGlobalBounds().height)));
		m_sprite[i].setPosition(m_positions[i]);
		i++;
	}

	// Close the file
	inputFile.close();
}

void SideTools::drawToolbar(sf::RenderWindow& window)
{
	for (size_t i = 0; i < NUM_OF_ICONS; i++)
		window.draw(m_sprite[i]);
}
