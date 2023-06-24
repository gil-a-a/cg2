#include <iostream>
#include <SDL2/SDL.h>
#include "screen.h"
#include "point2D.h"
#include "color.h"
#include "line.h"
#include "picture.h"
#include "circle.h"
#include "polygon.h"

int main(int argc, char *argv[])
{
    /*Screen screen("Aula 3", BLACK, 700, 700);

    Point2D p3(350, 450);

    Picture p;
    
    // Telhado
    Line l1(Point2D(350, 50), Point2D(50, 250), RED);
    Line l2(Point2D(50, 250), Point2D(650, 250), RED);
    Line l3(Point2D(650, 250), Point2D(350, 50), RED);
        
    // Parede
    Line l4(Point2D(50, 250), Point2D(50, 650), GREEN);
    Line l5(Point2D(50, 650), Point2D(650, 650), GREEN);
    Line l6(Point2D(650, 650), Point2D(650, 250), GREEN);
        
    Circle circ(p3, 150, BLUE);
        
    // Insere primitivas na lista
    p.add(&l1);
    p.add(&l2);
    p.add(&l3);
    p.add(&l4);
    p.add(&l5);
    p.add(&l6);
    p.add(&circ);
        
    screen.run(p);*/
    
    // Aula - Preenchimento de Polígonos
    Screen screen2("Aula 4", BLACK, 700, 700);

	//Exemplo 1 - Polígono da aula
//	/*
	Polygon pol(true, RED, true, WHITE);
	Point2D v1(20,30,GREEN);
	Point2D v2(70,10,GREEN);
	Point2D v3(130,50,GREEN);
	Point2D v4(130,110,GREEN);
	Point2D v5(70,70,GREEN);
	Point2D v6(20,90,GREEN);
	
	pol.addVertex(&v1);
	pol.addVertex(&v2);
	pol.addVertex(&v3);
	pol.addVertex(&v4);
	pol.addVertex(&v5);
	pol.addVertex(&v6);
//	*/
	
	//Exemplo 2 - Fábrica
	/*
	Polygon pol2(true, RED, true, WHITE);
	Point2D v1pol2(20,30,GREEN);
	Point2D v2pol2(35, 30,GREEN);
	Point2D v3pol2(35, 60,GREEN);	
	Point2D v4pol2(70, 30,GREEN);
	Point2D v5pol2(70, 60,GREEN);
	Point2D v6pol2(130, 30, GREEN);
	Point2D v7pol2(130,90,GREEN);
	Point2D v8pol2(20,90,GREEN);
	
	pol2.addVertex(&v1pol2);
	pol2.addVertex(&v2pol2);
	pol2.addVertex(&v3pol2);
	pol2.addVertex(&v4pol2);
	pol2.addVertex(&v5pol2);
	pol2.addVertex(&v6pol2);
	pol2.addVertex(&v7pol2);
	pol2.addVertex(&v8pol2);
//	*/
	
	//Exemplo 3 - Estrela torta
	/*
	Polygon pol3(true, RED, true, WHITE);
	Point2D v1pol3(20, 50, GREEN);
	Point2D v2pol3(45, 50, GREEN);
	Point2D v3pol3(70, 20, GREEN);
	Point2D v4pol3(95, 50, GREEN);
	Point2D v5pol3(120, 50, GREEN);
	Point2D v6pol3(95, 70, GREEN);
	Point2D v7pol3(105, 120, GREEN);
	Point2D v8pol3(70, 90, GREEN);
	Point2D v9pol3(45, 120, GREEN);
	Point2D v10pol3(55, 70, GREEN);
	
	pol3.addVertex(&v1pol3);
	pol3.addVertex(&v2pol3);
	pol3.addVertex(&v3pol3);
	pol3.addVertex(&v4pol3);
	pol3.addVertex(&v5pol3);
	pol3.addVertex(&v6pol3);
	pol3.addVertex(&v7pol3);
	pol3.addVertex(&v8pol3);
	pol3.addVertex(&v9pol3);
	pol3.addVertex(&v10pol3);
//	*/
	
	Picture p2;
	p2.add(&pol);
//	p2.add(&pol2);
//	p2.add(&pol3);
	
	screen2.run(p2);

    return 0;
}