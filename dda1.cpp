#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
float  X1,X2,Y1,Y2;
void simpleline();
void Dashedline();
void Dottedline();
float dy,dx,length,x,y,k,Yin,Xin;

void display(){
cout<<"\nSimple Line\n";
simpleline();
cout<<"\nDashed Line\n";
Dashedline();
cout<<"\nDotted Line\n";
Dottedline(); 
}
void simpleline(){  
cout<<"Enter the value of x:";
cin>>X1;
cout<<"Enter the value of y1";
cin>>Y1;
cout<<"Enter the value of x2";
cin>>X2;
cout<<"Enter the value of y2:";
cin>>Y2;
        dx=X2-X1;
        dy=Y2-Y2;
        if(abs(dx)>abs(dy)){
                length=abs(dx);
        }
        else{
                length=abs(dy);
        }
        Xin=dx/length;
        Yin=dy/length;
        
        x=X1;
        y=Y1;
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
        
        for( k=1;k<=length;k++){
                x=x+Xin;
                y=y+Yin;
                  glColor3f(0.0,1.0,0.0);
                glBegin(GL_POINTS);
                glVertex2i(x,y);
                glEnd();
        }
        glFlush();
  }
  void Dashedline(){
  cout<<"Enter the value of x:";
cin>>X1;
cout<<"Enter the value of y1";
cin>>Y1;
cout<<"Enter the value of x2";
cin>>X2;
cout<<"Enter the value of y2:";
cin>>Y2;
        dx=X2-X1;
        dy=Y2-Y2;
        if(abs(dx)>abs(dy)){
                length=abs(dx);
        }
        else{
                length=abs(dy);
        }
        Xin=dx/length;
        Yin=dy/length;
        
        x=X1;
        y=Y1;
          glColor3f(0.0,1.0,0.0);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        
        
        for( k=1;k<=length;k++){
                x=x+Xin;
                y=y+Yin;
                if(k % 5==0){
                glVertex2i(x,y);
        }
     }
     glEnd();
        glFlush();
  }
  void Dottedline(){
  cout<<"Enter the value of x:";
cin>>X1;
cout<<"Enter the value of y1";
cin>>Y1;
cout<<"Enter the value of x2";
cin>>X2;
cout<<"Enter the value of y2:";
cin>>Y2;
        dx=X2-X1;
        dy=Y2-Y2;
        if(abs(dx)>abs(dy)){
                length=abs(dx);
        }
        else{
                length=abs(dy);
        }
        Xin=dx/length;
        Yin=dy/length;
        
        x=X1;
        y=Y1;
          glColor3f(0.0,1.0,0.0);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        
        for(k=1;k<=length;k++){
                x=x+Xin;
                y=y+Yin;
                if(k % 2==0){
                glVertex2i(x,y);
             }
        }
        glEnd();
        glFlush();
  }
  


void init(void){
        glClearColor(1.0,0.0,0.0,0.0);
        glColor3f(0.0,1.0,0.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char**argv){
       
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500,500);
        glutInitWindowPosition(100,100);
        glutCreateWindow("DDA Line Algorithm");
        init();
        glutDisplayFunc(display);
        glutMainLoop();
        
        return 0;
}
