/*
 * frame.h
 *	The abstraction of a coordinate indepent frame
 *  Created on: 08/09/2010
 *      Author: Cle�bulo
 */
#ifndef FRAME_H
#define FRAME_H

#include <SDL/SDL_opengl.h>
#include "Point3.h"
#include "Vector3.h"

class Frame
{

protected:
    Vector3 i,j,k;				// The vectors
    float angleX,angleY,angleZ;	// The rotation angles

    Point3 origin;				// The origin point
    GLfloat matrix[16];			// The final matrix

    void normalizeAngle( float* );	// In this case the angles are 16*angle(X/Y/Z)
    								// so the normalization reduces them to the real form
public:
    // Initializers
    Frame();
    Frame( Point3 , Vector3 , Vector3 , Vector3 );

    // Apply the frame operations to a vector or a point
    static Vector3 convertV( Vector3 , GLfloat* );
    static Point3 convertP( Point3 , GLfloat* );

    // Setters
    void setI( Vector3 );
    void setJ( Vector3 );
    void setK( Vector3 );

    // Getters
    Vector3* getI();
    Vector3* getJ();
    Vector3* getK();
    Point3* getOrigin();

    // Set rotation but don't modify the matrix
    void setRotationX( float );
    void rotateX( float );
    void setRotationY( float );
    void rotateY( float );
    void setRotationZ( float );
    void rotateZ( float );

    // Getters of rotations
    int getRotationX();
    int getRotationY();
    int getRotationZ();

    // It's here when the matrix is actually calculated
    void calculateRotation();		// Actually calculates the rotation
    void resetRotation();			// Reset the rotation to the original position

    GLfloat* getMatrixToWorld();    // Converts This-Frame to the World-Frame
    GLfloat* getMatrixToThis();     // Converts World-Frame to This-Frame

    void moveOriginW( Vector3 );                // Move origin through world coordinates
    void moveOriginW( float , float , float );  //

    void moveOriginT( Vector3 );                // Move origin through this frame coordinates
    void moveOriginT( float , float , float );  //

    //lol
    Frame operator=(Frame f);
    Frame operator^(Frame f);
};

#endif // FRAME_H
