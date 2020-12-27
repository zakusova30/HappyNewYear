
#include <SFML/Graphics.hpp> /// подключаем заголовочный файл, который отвечает за работу с графикой
#include "globals.h"
#include "Map.h"
#include <fstream>
#include <string>

RenderWindow window(sf::VideoMode(1380, 770), "Happy New Year"); // создаём функцию, которая будет отвечать за появление окна игры

/////// рисуем карту
Map::Map()//конструктор 
{  

	image1.loadFromFile("images/map2.png"); // подгружаем изображение для нашей карты


	map.loadFromImage(image1); // в заголовочном файле Map.h у был создан объект map. Передаем в него объект image 1

	s_map.setTexture(map); // в объект s_map передаем текстуру 

	Clock clock; // создаем переменную времени 



}

Map::~Map() // создаём деструктор
{ 

}
void Map::drawing() {
	for (int i = 0; i < HEIGHT_MAP; i++) // рисуем карту по высоте и по ширине 
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			// ниже рисуется карта по символам, поэтому когда тот символ равен тому-то, то рисуется определённый элемент 
			if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 32, 32, 32));//дорога
			if (TileMap[i][j] == '2')  s_map.setTextureRect(IntRect(32, 32, 32, 32)); //деревянный пол
			if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(0, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик

			if ((TileMap[i][j] == 'q')) s_map.setTextureRect(IntRect(0, 96, 32, 32));//ковер
			if ((TileMap[i][j] == 'r')) s_map.setTextureRect(IntRect(0, 128, 32, 32));//ковер

			//дверь
			if ((TileMap[i][j] == '!')) s_map.setTextureRect(IntRect(32, 32, 32, 32)); //дверь
			if ((TileMap[i][j] == '@')) s_map.setTextureRect(IntRect(32, 32, 32, 32)); //дверь
			if ((TileMap[i][j] == '$')) s_map.setTextureRect(IntRect(32, 32, 32, 32)); //дверь
			if ((TileMap[i][j] == 'k')) s_map.setTextureRect(IntRect(128, 64, 32, 32)); //дверь
			if ((TileMap[i][j] == '8')) s_map.setTextureRect(IntRect(128, 0, 32, 32)); //дверь
			if ((TileMap[i][j] == '9')) s_map.setTextureRect(IntRect(128, 32, 32, 32)); //дверь


			if ((TileMap[i][j] == '1')) s_map.setTextureRect(IntRect(128, 96, 32, 32)); //крыша

			if ((TileMap[i][j] == 'w')) s_map.setTextureRect(IntRect(96, 32, 32, 32)); //стена ->
			if ((TileMap[i][j] == 'e')) s_map.setTextureRect(IntRect(0, 64, 32, 32)); //стена |
			if ((TileMap[i][j] == 'y')) s_map.setTextureRect(IntRect(32, 64, 32, 32)); //стена |
			if ((TileMap[i][j] == 't')) s_map.setTextureRect(IntRect(96, 96, 32, 32)); //стена |
			if ((TileMap[i][j] == 'r')) s_map.setTextureRect(IntRect(0, 128, 32, 32)); //стена L

			//камин
			if ((TileMap[i][j] == '^')) s_map.setTextureRect(IntRect(128, 128, 32, 32));//вверх
			if ((TileMap[i][j] == '>')) s_map.setTextureRect(IntRect(128, 160, 32, 32));//вниз
			if ((TileMap[i][j] == 'x')) s_map.setTextureRect(IntRect(96, 160, 32, 32));//вправо

			//ель
			if ((TileMap[i][j] == 'n')) s_map.setTextureRect(IntRect(32, 96, 32, 32));//вверх
			if ((TileMap[i][j] == 'm')) s_map.setTextureRect(IntRect(32, 128, 32, 32));//вниз
			if ((TileMap[i][j] == '/')) s_map.setTextureRect(IntRect(64, 128, 32, 32)); //стена ->

			if ((TileMap[i][j] == 'Z')) s_map.setTextureRect(IntRect(64, 192, 32, 32));
			if ((TileMap[i][j] == 'Y')) s_map.setTextureRect(IntRect(96, 192, 32, 32));
			if ((TileMap[i][j] == '&')) s_map.setTextureRect(IntRect(128, 192, 32, 32));
			if ((TileMap[i][j] == '%')) s_map.setTextureRect(IntRect(128, 224, 32, 32));


			if ((TileMap[i][j] == '(')) s_map.setTextureRect(IntRect(0, 229, 32, 32));
			//труба
			if ((TileMap[i][j] == 'j')) s_map.setTextureRect(IntRect(64, 160, 32, 32));//вверх
			if ((TileMap[i][j] == '3')) s_map.setTextureRect(IntRect(64, 160, 32, 32));//вверх
			if ((TileMap[i][j] == '4')) s_map.setTextureRect(IntRect(64, 160, 32, 32));//вверх
			if ((TileMap[i][j] == '5')) s_map.setTextureRect(IntRect(64, 160, 32, 32));//вверх


			//лестница
			if ((TileMap[i][j] == 'a')) s_map.setTextureRect(IntRect(32, 160, 32, 32));//вверх
			if ((TileMap[i][j] == '6')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//вверх
			if ((TileMap[i][j] == '7')) s_map.setTextureRect(IntRect(32, 0, 32, 32));//вверх

			//выход
			if ((TileMap[i][j] == '.')) s_map.setTextureRect(IntRect(0, 32, 32, 32));//вверх
			if ((TileMap[i][j] == '|')) s_map.setTextureRect(IntRect(32, 196, 32, 32));//вверх
			if ((TileMap[i][j] == '-')) s_map.setTextureRect(IntRect(0, 260, 32, 32));//вверх
			if ((TileMap[i][j] == ',')) s_map.setTextureRect(IntRect(0, 196, 32, 32));//вверх
			
			//большая ель
			if ((TileMap[i][j] == 'A')) s_map.setTextureRect(IntRect(160, 0, 32, 32));
			if ((TileMap[i][j] == 'B')) s_map.setTextureRect(IntRect(192, 0, 32, 32));
			if ((TileMap[i][j] == 'C')) s_map.setTextureRect(IntRect(224, 0, 32, 32));
			if ((TileMap[i][j] == 'D')) s_map.setTextureRect(IntRect(256, 0, 32, 32));
			if ((TileMap[i][j] == 'E')) s_map.setTextureRect(IntRect(298, 0, 32, 32));

			if ((TileMap[i][j] == 'F')) s_map.setTextureRect(IntRect(160, 32, 32, 32));
			if ((TileMap[i][j] == 'G')) s_map.setTextureRect(IntRect(192, 32, 32, 32));
			if ((TileMap[i][j] == 'H')) s_map.setTextureRect(IntRect(224, 32, 32, 32));
			if ((TileMap[i][j] == 'I')) s_map.setTextureRect(IntRect(256, 32, 32, 32));
			if ((TileMap[i][j] == 'J')) s_map.setTextureRect(IntRect(298, 32, 32, 32));

			if ((TileMap[i][j] == 'K')) s_map.setTextureRect(IntRect(160, 64, 32, 32));
			if ((TileMap[i][j] == 'M')) s_map.setTextureRect(IntRect(192, 64, 32, 32));
			if ((TileMap[i][j] == 'N')) s_map.setTextureRect(IntRect(224, 64, 32, 32));
			if ((TileMap[i][j] == 'O')) s_map.setTextureRect(IntRect(256, 64, 32, 32));
			if ((TileMap[i][j] == 'R')) s_map.setTextureRect(IntRect(298, 64, 32, 32));

			if ((TileMap[i][j] == 'T')) s_map.setTextureRect(IntRect(160, 96, 32, 32));
			if ((TileMap[i][j] == 'U')) s_map.setTextureRect(IntRect(192, 96, 32, 32));
			if ((TileMap[i][j] == 'V')) s_map.setTextureRect(IntRect(224, 96, 32, 32));
			if ((TileMap[i][j] == 'W')) s_map.setTextureRect(IntRect(256, 96, 32, 32));
			if ((TileMap[i][j] == 'X')) s_map.setTextureRect(IntRect(298, 96, 32, 32));
			s_map.setPosition(j * 32, i * 32);

			window.draw(s_map);


		}


}
// рисовка карты символами
String TileMap[HEIGHT_MAP] = { 

	"0000000000000000000000000000000000000000000",
	"0(  111%%22222n22e  ABCDE   y2n222%2222Y220",
	"0   1112Z22222m22e  FGHIJ   y2m22222S222220",
	"0   1112222222222e  KMNOR   9$22222222222Z0",
	"0   ajxq222222222e  TUVWX   y222L2222222220",
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