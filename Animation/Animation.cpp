#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>

const int WIDTH = 900, HEIGHT = 900;

sf::Vector2f velocity(0, 0);

	void jump()
	{
		velocity.y = -1;
	}
int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Camera");
	sf::Texture backText;
	sf::IntRect rect[4];
	rect[0] = sf::IntRect(0, 0, 26, 34);
	rect[1] = sf::IntRect(26, 0, 26, 34);
	rect[2] = sf::IntRect(0, 34, 26, 34);
	rect[3] = sf::IntRect(26, 34, 26, 34);

	backText.loadFromFile("textures/mariomoving.png");

	

	sf::Sprite backSprite;
	backSprite.setScale(2, 2);

	backSprite.setPosition(WIDTH / 2, HEIGHT / 2);
	backSprite.setTexture(backText);

	sf::Sprite backgroundSprite;
	sf::Texture background;
	//backgroundSprite.setScale(6, 6);

	background.loadFromFile("textures/background.png");
	backgroundSprite.setTexture(background);


	sf::View camera(sf::Vector2f(50, 50), sf::Vector2f(150, 150));
	camera.setSize(200, 200);
	camera.setCenter(0, 0);
	
	sf::Sprite MarioJump;
	sf::Texture jumpsprite;

	jumpsprite.loadFromFile("textures/mariojump.png");
	MarioJump.setTexture(jumpsprite);

	bool isMovingUp = false;
	bool isMovingDown = false;
	bool isMovingLeft = false;
	bool isMovingRight = false;
	bool jumping = false;
	bool zoom = false;

	sf::Sprite monster;
	sf::Texture Goomba;

	Goomba.loadFromFile("textures/mariojump.png");

	sf::Clock clock;
	int imgCount = 0;
	float timer = 0;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				/*  
				if (event.key.code == sf::Keyboard::W) {
					isMovingUp = true;
				}
				if (event.key.code == sf::Keyboard::S) {
					isMovingDown = true;
				}
				*/
				if (event.key.code == sf::Keyboard::Right) {
					isMovingRight = true;
				}
				if (event.key.code == sf::Keyboard::Left) {
					isMovingLeft = true;
				}
				if (event.key.code == sf::Keyboard::Tab)
				{
					zoom = true;
				}
				if (event.key.code == sf::Keyboard::Space) {
					jumping = true;
					window.draw(MarioJump);

					if (velocity.y == 0)
						jump();

				}
			}
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::W) {
					isMovingUp = false;
				}
				if (event.key.code == sf::Keyboard::S) {
					isMovingDown = false;
				}
				if (event.key.code == sf::Keyboard::Right) {
					isMovingRight = false;
				}
				if (event.key.code == sf::Keyboard::Left) {
					isMovingLeft = false;
				}
				if (event.key.code == sf::Keyboard::Tab)
				{
					zoom = false;
				}
				if (event.key.code == sf::Keyboard::Space) {
					;
				}
			}
		}
	
		

		velocity.x = 0;
		if (isMovingLeft)
			velocity.x -= 0.7;
		if (isMovingRight)
			velocity.x += 0.7;
		
		velocity.y += 0.005;
		if (backSprite.getPosition().y > HEIGHT / 1.2 && velocity.y > 0)
			velocity.y = 0;


		if (zoom)
			camera.setSize(400, 400);
		else
			camera.setSize(200, 200);

		//camera.move(viewMove);
		//window.setView(camera);
		backSprite.move(velocity);

		if (isMovingLeft || isMovingRight) {
			timer = clock.getElapsedTime().asSeconds();
			if (timer > 0.25f)
			{
				if (imgCount < 3)
					imgCount++;
				else
					imgCount = 0;
				clock.restart();
			}
		}
		else
			imgCount = 0;

		

		if (isMovingLeft || isMovingRight) {
			backSprite.setTexture(backText);
			backSprite.setTextureRect(rect[imgCount]);
		}
		else if (velocity.y != 0) {

			backSprite.setTexture(jumpsprite);
			backSprite.setTextureRect(sf::IntRect(0, 0, 28, 34));
		}
		else
			backSprite.setTexture(backText);
			backSprite.setTextureRect(rect[0]);

		window.clear();
		window.draw(backgroundSprite);
		window.draw(backSprite);
		window.display();
	}
}