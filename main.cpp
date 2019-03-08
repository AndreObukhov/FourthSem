#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

const double Speed = 500;

bool IsInsideWindow(sf::Vector2u WSize, sf::Vector2f Position) {
	if (Position.x >=0 && Position.y >= 0 &&
		Position.x <= WSize.x && Position.y <= WSize.y) {
		return true;
	}
	else {
		return false;
	}
}

struct Bullet {
	Bullet(const sf::Vector2f& pos, double ang, sf::Time t) {
		StartPosition = pos;
		TimeFired = t;
		angle = ang;
	}

	sf::Vector2f StartPosition;
	sf::Time TimeFired;
	double angle;
};

/*Bullet getBullet(const sf::Vector2f& pos, double ang, sf::Time t) {
	return Bullet(pos, ang, t);
}*/

/*sf::CircleShape Bullet() {
	sf::CircleShape bullet(5.f);
	bullet.setFillColor(sf::Color::White);
	return bullet;
}*/

/*void DrawBullets(sf::RenderWindow window, const std::vector<sf::CircleShape>& bullets) {
	for (const auto& b : bullets) {
		window.draw(b);
	}
}*/

int main()
{
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(1500, 900), "SFML works!");
	
	sf::CircleShape shape(200.f);
	//sf::CircleShape circle(50.f);

	shape.setFillColor(sf::Color::Blue);


	sf::Texture texture;
	texture.loadFromFile("C:/Users/User/MIPT/TestSFML/currency_blue_dollar-128.png");
	sf::Sprite circle(texture);
	circle.setScale(1.5f, 1.5f);

	circle.setPosition(100, 100);

	std::vector<Bullet> bullets;

	/*sf::Texture textureCoin;
	textureCoin.loadFromFile("C:/Users/User/MIPT/TestSFML/Coin-Us-Dollar-256.png");*/

	while (window.isOpen())
	{
		sf::Time time = clock.getElapsedTime();
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		//drawing bullets
		for (int i = 0; i < bullets.size(); i ++) {


			sf::CircleShape bullet(5.f);
			bullet.setFillColor(sf::Color::Yellow);
			bullet.setPosition(bullets[i].StartPosition.x + 
									Speed * cos(bullets[i].angle) * (time.asSeconds() - bullets[i].TimeFired.asSeconds()),
							   bullets[i].StartPosition.y + 
									Speed * sin(bullets[i].angle) * (time.asSeconds() - bullets[i].TimeFired.asSeconds()));

			window.draw(bullet);

			//deleting bullets outside of the window
			if (!IsInsideWindow(window.getSize(), bullet.getPosition())) {
				bullets.erase(bullets.begin() + i);
			}
		}
		/*if (bullets.empty()) {		//omg it works
			std::cout << "Empty" << std::endl;
		}*/

		sf::Vector2u CircleSize = circle.getTexture()->getSize();
		circle.setOrigin(CircleSize.x / 2, CircleSize.y / 2);

		sf::Vector2i MousePos = sf::Mouse::getPosition(window);

		sf::Vector2f center = circle.getPosition();

		sf::Vector2f d = sf::Vector2f(MousePos.x, MousePos.y) - center;

		const double Pi = 3.14159f;
		double angle = 90.0 + atan2f(d.y, d.x) * 180.0 / Pi;
		circle.setRotation(angle);

		window.draw(circle);

		//window.draw(shape);
		//window.draw(circle);

		//circle.setPosition(50 + 15 * time.asSeconds(), 100 - 5 * time.asSeconds());
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			circle.move(0, -0.2);
			if (!IsInsideWindow(window.getSize(), circle.getPosition())) {
				circle.move(0, 0.2);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			circle.move(0, 0.2);
			if (!IsInsideWindow(window.getSize(), circle.getPosition())) {
				circle.move(0, -0.2);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			circle.move(0.2, 0);
			if (!IsInsideWindow(window.getSize(), circle.getPosition())) {
				circle.move(-0.2, 0);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			circle.move(-0.2, 0);
			if (!IsInsideWindow(window.getSize(), circle.getPosition())) {
				circle.move(0.2, 0);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			bullets.push_back(Bullet(center, atan2f(d.y, d.x), time));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {		//laser
			sf::Vertex line[] =
			{
				sf::Vertex(center),
				sf::Vertex(sf::Vector2f(MousePos.x, MousePos.y))
			};

			line->color = (sf::Color::Red);
			window.draw(line, 2, sf::Lines);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			circle.scale(1.002, 1.002);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			circle.scale(0.995, 0.995);
		}

		//window.draw(circle);

		window.display();
	}

	return 0;
}
