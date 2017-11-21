//
//  Population.hpp
//  CPP-PRG-13-09-Population
//
//  Created by Keith Smith on 11/21/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//

#ifndef Population_hpp
#define Population_hpp

#include <stdio.h>

class Population
{
private:
    int intPopulationSize;
    int intBirths;
    int intDeaths;
public:
    Population();
    Population(int, int, int);
    
    void setPopulationSize(int);
    void setBirths(int);
    void setDeaths(int);
    
    int getPopulationSize() const;
    int getBirths() const;
    int getDeaths() const;
    
    double getRateBirth() const;
    double getRateDeath() const;
};

#endif /* Population_hpp */
