/*
 * point3.h
 *	Abstraction of a 3D point, very simple
 *  Created on: Sep 8, 2010
 *      Author: Cleóbulo
 */
#ifndef POINT3_H
#define POINT3_H

class Vector3;

class Point3
{
    private:
        long double x,y,z;

    public:
        Point3();
        Point3( long double x , long double y , long double z );

        // Operações Ponto-Escalar
        Point3 operator+ ( long double  ); // Soma por escalar
        Point3 operator* ( long double  ); // Produto por escalar
        Point3 operator*=( long double  ); // O Mesmo

        // Operações Ponto-Ponto
        Point3  operator+ ( Point3 ); // Soma com outro ponto
        Vector3 operator- ( Point3 ); // Subtração de Dois Pontos

        // Operações Ponto-Vetor
        Point3 operator+ ( Vector3 ); // Soma ponto com vetor
        Point3 operator- ( Vector3 ); // Diminuição com vetor

        // Operação de Comparação
        bool operator==   ( Point3 );

        long double getX();
        long double getY();
        long double getZ();

        // Entrada de dados
        void setX( long double x );
        void setY( long double y );
        void setZ( long double z );
        void setPosition( long double x , long double y , long double z );
        void setPosition( Point3 );
};

#endif // POINT3_H
