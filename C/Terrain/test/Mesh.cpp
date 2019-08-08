#include "Mesh.h"

Mesh::Mesh(int s){
    size=s;
};

Mesh::~Mesh(){};

void Mesh::build(void){
    nm=new NoiseMap(size);
    cout << "Mesh init"<<endl;  
};

void Mesh::draw(){
    
    float xoff=-0.9f;
    float spacing=1.8f/size;
    glBegin(GL_TRIANGLES);
    for(int i=0;i<size;i++){
        
        float yoff=-0.9f;
        
        for(int j=0;j<size;j++){
            nm->setColor(i,j);
            glVertex3f(xoff,yoff,nm->getNoise(i,j));
            
            nm->setColor(i+1,j+1);
            glVertex3f(xoff+spacing,yoff+spacing,nm->getNoise(i+1,j+1));
            
            nm->setColor(i,j+1);
            glVertex3f( xoff, yoff+spacing, nm->getNoise(i,j+1));
            
            
            nm->setColor(i,j);
            glVertex3f(xoff,yoff, nm->getNoise(i,j));
            
            nm->setColor(i+1,j+1);
            glVertex3f( xoff+spacing,yoff+spacing, nm->getNoise(i+1,j+1));
            
            nm->setColor(i+1,j);
            glVertex3f(xoff+spacing, yoff, nm->getNoise(i+1,j));
            yoff+=spacing;
        }
        xoff+=spacing;
    }
    glEnd();
    
}
