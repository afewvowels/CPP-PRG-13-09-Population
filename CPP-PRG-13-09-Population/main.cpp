//
//  main.cpp
//  CPP-PRG-13-09-Population
//
//  Created by Keith Smith on 11/21/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  In a population, the birth rate and death rate are calculated as follows:
//
//  Birth Rate = Number of Births / Population
//  Death Rate = Number of Deaths / Population
//
//  For example, in a population of 100,000 that has 8,000 births and 6,000 deaths per
//  year, the birth rate and death rate are:
//
//  Birth Rate = 8,000 / 100,000 = 0.08
//  Death Rate = 6,000 / 100,000 = 0.06
//
//  Design a Population class that stores a population, number of births, and number of
//  deaths for a period of time. Member functions should return the birth rate and death
//  rate. Implement the class in a program.
//
//  Input Validation: Do not accept population figures less than 1, or birth or death numbers
//  less than 0.

#include <iostream>
#include "Population.hpp"

int displayMenu();
int displaySubMenu(int);
Population displayResult(Population, int, int);

int main()
{
    int intSelection;
    int intSubSelection;
    
    Population popPopulation;
    
    intSelection = displayMenu();
    
    while (intSelection != 6)
    {
        if (intSelection == 1 || intSelection == 2 || intSelection == 3)
        {
            intSubSelection = displaySubMenu(intSelection);
        }
        else
        {
            intSubSelection = -1;
        }
        
        popPopulation = displayResult(popPopulation, intSelection, intSubSelection);
        
        intSelection = displayMenu();
    }
    
    std::cout << "\nYou have exited the program.\n\n";
    
    return 0;
}

int displayMenu()
{
    int selection;
    
    std::cout << "Please select from the following menu options:\n";
    std::cout << "\t1.Population Size\n";
    std::cout << "\t2.Births\n";
    std::cout << "\t3.Deaths\n";
    std::cout << "\t4.Birth Rate\n";
    std::cout << "\t5.Death Rate\n";
    std::cout << "\t6.Quit\n";
    std::cout << "Make your selection: ";
    std::cin >> selection;
    while (!std::cin || selection < 1 || selection > 6)
    {
        std::cout << "Please select from the visible menu options: ";
        std::cin.clear();
        std::cin.ignore();
        std::cin >> selection;
    }
    
    return selection;
}

int displaySubMenu(int selection)
{
    int subselection;
    
    if (selection == 1)
    {
        std::cout << "Please select from the following menu options:\n";
        std::cout << "\t1.Set Population Size\n";
        std::cout << "\t2.Get Population Size\n";
    }
    else if (selection == 2)
    {
        std::cout << "Please select from the following menu options:\n";
        std::cout << "\t1.Set Briths\n";
        std::cout << "\t2.Get Births\n";
    }
    else if (selection == 3)
    {
        std::cout << "Please select from the following menu options:\n";
        std::cout << "\t1.Set Deaths\n";
        std::cout << "\t2.Get Deaths\n";
    }
    
    std::cin >> subselection;
    while (!std::cin || subselection < 1 || subselection > 2)
    {
        std::cout << "Please select from the visible menu options: ";
        std::cin.clear();
        std::cin.ignore();
        std::cin >> subselection;
    }
    
    return subselection;
}

Population displayResult(Population population, int selection, int subselection)
{
    int intTemp;
    double dblTemp;
    
    switch (selection) {
        case 1:
            if (subselection == 1)
            {
                std::cout << "Set population size: ";
                std::cin >> intTemp;
                while (!std::cin || intTemp <= 0 || intTemp > 1000000)
                {
                    std::cout << "Please enter a population size\n";
                    std::cout << "greater than 0 and less than 1,000,000: ";
                    std::cin.clear();
                    std::cin.ignore();
                    std::cin >> intTemp;
                }
                population.setPopulationSize(intTemp);
            }
            else if (subselection == 2)
            {
                std::cout << "Population size is currently: ";
                std::cout << population.getPopulationSize() << std::endl;
            }
            break;
        case 2:
            if (subselection == 1)
            {
                std::cout << "Set births: ";
                std::cin >> intTemp;
                while (!std::cin || intTemp < 0 || intTemp > population.getPopulationSize())
                {
                    std::cout << "Please enter a number of births\n";
                    std::cout << "greater than 0 and less than ";
                    std::cout << population.getPopulationSize() << ": ";
                    std::cin.clear();
                    std::cin.ignore();
                    std::cin >> intTemp;
                }
                population.setBirths(intTemp);
            }
            else if (subselection == 2)
            {
                std::cout << "Births are currently: ";
                std::cout << population.getBirths() << std::endl;
            }
            break;
        case 3:
            if (subselection == 1)
            {
                std::cout << "Set deaths: ";
                std::cin >> intTemp;
                while (!std::cin || intTemp < 0 || intTemp > population.getPopulationSize())
                {
                    std::cout << "Please enter a number of deaths\n";
                    std::cout << "greater than 0 and less than ";
                    std::cout << population.getPopulationSize() << ": ";
                    std::cin.clear();
                    std::cin.ignore();
                    std::cin >> intTemp;
                }
                population.setDeaths(intTemp);
            }
            else if (subselection == 2)
            {
                std::cout << "Deaths are currently: ";
                std::cout << population.getDeaths() << std::endl;
            }
            break;
        case 4:
            std::cout << "The birth rate is: ";
            std::cout << population.getRateBirth() << std::endl;
            break;
        case 5:
            std::cout << "The death rate is: ";
            std::cout << population.getRateDeath() << std::endl;
            break;
        default:
            break;
    }
    
    return population;
}
