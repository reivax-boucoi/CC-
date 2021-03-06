#ifndef MESH_H
#define MESH_H

#include <GL/glut.h>
#include <iostream>
#include "NoiseMap.h"

using namespace std;

class Mesh{
public:
    Mesh(int s);
    ~Mesh();
    void build(void);
    void draw(int m);
    NoiseMap *nm;
private :
    int size=0;
};


#endif
