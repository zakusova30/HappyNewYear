
#include <SFML/Graphics.hpp> /// ���������� ������������ ����, ������� �������� �� ������ � ��������
#include "globals.h"
#include "Map.h"
#include <fstream>
#include <string>

RenderWindow window(sf::VideoMode(1380, 770), "Happy New Year"); // ������� �������� �� ��������� ������ ���� ����
/////// ������ �����
Map::Map() { //����������� 

	image1.loadFromFile("images/map2.png"); // ���������� ����������� ��� �����


	map.loadFromImage(image1); // � ������������ ����� Map.h � ��� ������ ������ map �������� � ���� ������ image 1

	s_map.setTexture(map); // � ������ s_map �������� �������� 

	Clock clock; // ������� ���������� ������� 



}

Map::~Map() { // ����������

}
String TileMap[HEIGHT_MAP] = { // ���� ������� �����

	"0000000000000000000000000000000000000000000",
	"0(  111%%22222n22e          y2n222%2222Y220",
	"0   1112Z22222m22e          y2m22222S222220",
	"0   1112222222222e          9$22222222222Z0",
	"0   ajxq222222222e          y222L2222222220",
	"0   1112222222L22e          y22222222222220",
	"0   11122S2222222e          y2&22q2222S2220",
	"0   111222222222Ye        P 11111^111111110",
	"01111112&22!22222e          111114111111110",
	"0111111wwwwkwwwwwr          111116111111110",
	"0               11                     1110",
	"0              P 11                P   .|-0",
	"0                 11                   1110",
	"0111111711111111111111111   111111111711110",
	"0111111311111111111111111   111111111511110",
	"0111111>11111111111111111   111111111>11110",
	"0y22222q22e2n222222222Z2e   y22222222q222&0",
	"0y22S22222e2m22222222222e   y2S222222222220",
	"0y222e2wwwr222222e22222#8   9$222222L222220",
	"0y222e2S222222222e22L222e   y2222222222S220",
	"0y222e222222L2222e222222e   y2222n222222220",
	"0y2n2e22222222222e222n22e   y2222m222222220",
	"0y2m2e&22Y2222222eZ22m22e   y22Y2S222222220",
	"0000000000000000000000000000000000000000000",

};