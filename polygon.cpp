#include <iterator>
#include <iostream>
#include <cmath>
#include "polygon.h"
#include "line.h"
#include "edgeTable.h"
#include "activeEdgeTable.h"

Polygon::Polygon(bool showE, Color edgeC, bool fill, Color fillC):Primitive("Polygon"), showEdges(showE), edgeColor(edgeC), isFilled(fill), fillColor(fillC) {
	
}

void Polygon::draw(Screen &screen) const {
	if (listOfPoints.size() < 3) {
		std::cout << "Nao forma polígono. Menos de 3 vértices.\n";
        return;
	}
            
    // Desenha arestas se desejar
    if (isFilled)
        scanline(screen);
        
    if (showEdges) {
    	list<Point2D *>::const_iterator it;
    	it = listOfPoints.begin();
    	for (int i = 0; i < listOfPoints.size() - 1; i++, ++it) {
    		Point2D *pI = *it;
    		Point2D *pF = *(next(it));
    		
    		Line line = Line(*pI, *pF, edgeColor);
    		line.draw(screen);
		}
    	
    	it = prev(listOfPoints.end());
    	Point2D *pI = *it;
    	std::cout << "I(" << pI->getX() << ", " << pI->getY() << ")\n";
    	it = listOfPoints.begin();
    	Point2D *pF = *it;
    	std::cout << "I(" << pF->getX() << ", " << pF->getY() << ")\n";
    	Line line = Line(*pI, *pF, edgeColor);
        line.draw(screen);
        
        for (it = listOfPoints.begin(); it != listOfPoints.end(); ++it)
        	(*it)->draw(screen);
	}
}

void Polygon::addVertex(Point2D *p) {
	listOfPoints.push_back(p);
}

void Polygon::scanline (Screen & screen) const {
	EdgeTable ET(listOfPoints);
	
	ActiveEdgeTable AET;
	
	int y = ET.getYMin();
	
    int bits[3][3] = {{0,0,0},{0,0,0},{1,1,1}};	//tenho q dar uma olhada em como q o scanline desenha os pontos na tela, pq n consegui desenhar um padrão
    int i, j;
    // Laço principal
	while (y <= ET.getYMax()) {
        //# Move a lista y na ET para AET (ymin = y), mantendo a AET ordenada em x
        AET.extend(ET.getList(y));
        ET.clearList(y);
        AET.sort();
              
        // Desenhe os pixels do bloco na linha de varredura y, 
        // usando os pares de coordenadas x da AET (cada dois nós definem um bloco)
		double xI, xF;
		i = 0;
        j = 0;
        while (AET.getOneBlockLimits(&xI, &xF)) {
        	
			for (int x = round(xI); x <= floor(xF); x++) {
				if (i > 2)
					i = 0;
				if (j > 2){
					j = 0;
					i++;
				}
				
				if(bits[i][j] == 1)
					screen.setPixel(x, y, fillColor);
				
				j++;
			}
        }
        
		std::cout << "Linha y = " << y <<": ";
		sequenciaBit(AET);
    	
        //Atualiza o valor de y para a próxima linha de varredura
        y = y + 1;
        
        // Remova as arestas que possuem ymax = y da AET
        AET.removeEdgesByYMax(y);
            
        // Para cada aresta na AET, atualize x = x + 1/m
        AET.updateXValues();
    }
    
    /*
    while (y <= ET.getYMax()) {
        //# Move a lista y na ET para AET (ymin = y), mantendo a AET ordenada em x
        AET.extend(ET.getList(y));
        ET.clearList(y);
        AET.sort();
              
        // Desenhe os pixels do bloco na linha de varredura y, 
        // usando os pares de coordenadas x da AET (cada dois nós definem um bloco)
		double xI, xF;
        while (AET.getOneBlockLimits(&xI, &xF)) {
        	for (int x = round(xI); x <= floor(xF); x++)	
        		screen.setPixel(x, y, fillColor);
        }
        
		std::cout << "Linha y = " << y <<": ";
		sequenciaBit(AET);
    	
        //Atualiza o valor de y para a próxima linha de varredura
        y = y + 1;
        
        // Remova as arestas que possuem ymax = y da AET
        AET.removeEdgesByYMax(y);
            
        // Para cada aresta na AET, atualize x = x + 1/m
        AET.updateXValues();
    }
    //Esse é o scanline original
    */
}

/*
1. Estenda o código criando um método que recebe uma tabela de arestas ativas (AET) de uma determinada linha de varredura e retornando 
uma lista com as paridades em cada aresta. Por exemplo, para o polígono do exemplo de aula, e a AET correspondente à linha de varredura y = 8, 
nós teremos 4 arestas sendo interceptadas, sendo que o algoritmo de paridade retornaria a sequência 1 0 1 0 para o bit de paridade em cada aresta. 
Faça ao menos 3 exemplos de linha de varredura para mostrar o funcionamento.
*/
//Pra achar a sequência que o enunciado fala, precisa percorrer a AET e adicionar 1 em iteração par e 0 em ímpar
void Polygon::sequenciaBit(ActiveEdgeTable AET) const {
	int size = AET.getSize();
	for (int i = 0; i < size; i++){
		if (i%2 == 0)
			std::cout << "1";
		else 
			std::cout << "0";
	}
	std::cout << "\n";
}

/*
2. Modifique a implementação do algoritmo Scanline para gerar áreas preenchidas com determinado padrão de preenchimento (hachuras). 
A ideia é fazer uma implementação que aceite qualquer padrão passado como parâmetro. 
Uma ideia consiste em usar uma matriz para representar um padrão, composto de valores 0 e 1 que definem a hachura a ser desenhada. 
Faça 3 exemplos usando três padrões diferentes. DICA: Lembre do preenchimento de circunferências.
*/











