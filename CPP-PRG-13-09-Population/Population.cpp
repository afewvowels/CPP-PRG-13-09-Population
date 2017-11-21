//
//  Population.cpp
//  CPP-PRG-13-09-Population
//
//  Created by Keith Smith on 11/21/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//

#include "Population.hpp"

Population::Population()
{
    intPopulationSize = 0;
    intBirths = 0;
    intDeaths = 0;
}
Population::Population(int size, int births, int deaths)
{
    intPopulationSize = size;
    intBirths = births;
    intDeaths = deaths;
}

void Population::setPopulationSize(int size)
{
    intPopulationSize = size;
}

void Population::setBirths(int births)
{
    intBirths = births;
}

void Population::setDeaths(int deaths)
{
    intDeaths = deaths;
}

int Population::getPopulationSize() const
{
    return intPopulationSize;
}

int Population::getBirths() const
{
    return intBirths;
}

int Population::getDeaths() const
{
    return intDeaths;
}

double Population::getRateBirth() const
{
    return static_cast<double>(intBirths) / static_cast<double>(intPopulationSize);
}

double Population::getRateDeath() const
{
    return static_cast<double>(intDeaths) / static_cast<double>(intPopulationSize);
}
