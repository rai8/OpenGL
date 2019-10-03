#include <cstdlib>
#include <GL/glut.h>
#include <GL/glut.h>

void displayFunc(void)
{
    // Clear the current buffer before drawing .
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    // Draw polygon
    glBegin(GL_POLYGON);
    {
        // change color
        glColor3f(0.0, 1.0, 0.0);
        // set point
        glVertex3f(-0.4, -0.5, -3.0);
        // change color
        glColor3f(1.0, 0.0, 0.0);
        // set point
        glVertex3f(0.6, -0.5, -3.0);
        // change color
        glColor3f(0.0, 0.0, 1.0);
        // set point
        glVertex3f(0.7, 0.5, -3.0);
    }
    glEnd();
    // Flush the buffer
    glFlush();
}

void reshapeFunc(int x, int y)
{

    if (y == 0 || x == 0)
        return;

    //New projection matrix.
    glMatrixMode(GL_PROJECTION);
    //Load Identity matrix.
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
    //Use all window size for rendering
    glViewport(0, 0, x, y);
}

int main(int argc, char *argv[])
{
    //Initialization to GLUT
    glutInit(&argc, argv);
    // Single Buffer
    // Use RGB Colors
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set the width and height of windows
    glutInitWindowSize(400, 400);
    // Create the window / with title = codemiles openGL
    glutCreateWindow("codemiles openGL");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //Set the function used for display call back .
    glutDisplayFunc(displayFunc);
    //Set the function used for reshape call back .
    glutReshapeFunc(reshapeFunc);

    //start glut map
    glutMainLoop();
    return 0;
}