#include <iostream>
#include <vector>

#include "subdivisor.h"
#include "edge.h"
#include "face.h"
#include "point.h"

using namespace std;

int main()
{
    Subdivisor *subdivisor = new Subdivisor(1, 1.0f);
    
    subdivisor->saveToText();
    subdivisor->readTextFiles();

    /*for(int k = 0; k < subdivisor->connectivity_subdivided.size(); k++)
    {
        std::vector<int> indices = subdivisor->connectivity_subdivided[k];
        std::cout << "[ ";
        for(int i = 0; i < subdivisor->num_edges_subdivided[k]; i++)
        {
            
            std::cout << indices[i];
            if(i != (subdivisor->num_edges_subdivided[k]-1))
            {
                std::cout << ", ";
            }
        }
        std::cout << " ]" << std::endl;
    }*/

    /*step 0:
    30 edges
    20 faces
    12 points

    step 1:
    120 edges
    80 faces
    42 points

    step 2:
    480 edges
    320 faces
    162 points*/

    return 0;
}


