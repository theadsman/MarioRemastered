#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>

const int WIDTH = 900, HEIGHT = 900;

sf::Vector2f velocity(0, 0);

	void jump()
	{
		velocity.y = -1.35f;
	}
	
int main()
{
	//state gameState = title;

	int state = 0;

	
	sf::RectangleShape menuBox;
	menuBox.setSize(sf::Vector2f(300.f, 100));
	menuBox.setPosition(300, 400);
	menuBox.setFillColor(sf::Color(255, 0, 0));


	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Camera");
	sf::Texture backText;
	sf::IntRect rect[4];
	rect[0] = sf::IntRect(0, 0, 26, 34);
	rect[1] = sf::IntRect(26, 0, 26, 34);
	rect[2] = sf::IntRect(0, 34, 26, 34);
	rect[3] = sf::IntRect(26, 34, 26, 34);

	backText.loadFromFile("textures/mariomoving.png");

	

	

	sf::Sprite backSprite;
	backSprite.setScale(3, 3);

	backSprite.setPosition(100, 750);

	backSprite.setPosition(WIDTH / 2, HEIGHT / 2);
	backSprite.setTexture(backText);

	sf::Sprite backgroundSprite;
	sf::Texture background;
	//backgroundSprite.setScale(6, 6);


	background.loadFromFile("textures/background.png");
	backgroundSprite.setTexture(background);

	sf::Sprite secondbackground;

		secondbackground.setTexture(background);
		secondbackground.setPosition(900, 0);

		sf::Sprite thirdbackground;

		thirdbackground.setTexture(background);
		thirdbackground.setPosition(1800, 0);

		sf::Sprite fourthbackground;

		fourthbackground.setTexture(background);
		fourthbackground.setPosition(2700, 0);

		sf::Sprite fifthbackground;

		fifthbackground.setTexture(background);
		fifthbackground.setPosition(3600, 0);


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

	Goomba.loadFromFile("textures/goomba.png");

	monster.setTexture(Goomba);
	monster.setScale(1.5, 1.5);
	monster.setPosition(700, 790);

	sf::Sprite aplatform;
	sf::Texture platform;

	aplatform.setPosition(500, 650);
	aplatform.setScale(4, 4);

	platform.loadFromFile("textures/platform.png");
	aplatform.setTexture(platform);

	sf::Clock clock;
	int imgCount = 0;
	float timer = 0;

	sf::Text myText;

	sf::Font myFont;

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
					isMovingLeft = true;
				}
				if (event.key.code == sf::Keyboard::Left) {
					
					isMovingRight = true;
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
					isMovingDown = false;
				}
				if (event.key.code == sf::Keyboard::S) {
					isMovingUp = false;
				}
				if (event.key.code == sf::Keyboard::Right) {
					isMovingLeft = false;
				}
				if (event.key.code == sf::Keyboard::Left) {
						isMovingRight = false;
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
		switch (state) {
		case 0:
			
			
			myFont.loadFromFile("font/SuperMario256.ttf");

			myText.setFont(myFont);
			myText.setPosition(450, 450);
			myText.setString("Press enter to start");
			myText.setCharacterSize(24);
			myText.setFillColor(sf::Color::White);


			
			window.clear();
			window.draw(menuBox);
			window.draw(myText);
			window.display();

			break;
		case 1:



			velocity.y += 0.004;
			if (backSprite.getPosition().y > HEIGHT / 1.2 && velocity.y > 0)
				velocity.y = 0;

			if (backSprite.getGlobalBounds().intersects(monster.getGlobalBounds()))
				backSprite.setPosition(100, 750);

			if (backSprite.getGlobalBounds().intersects(aplatform.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < aplatform.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 0;
				}
			}



			velocity.x = 0;
			if (isMovingLeft)
				velocity.x -= 0.7;
			if (isMovingRight)
				velocity.x += 0.7;



			camera.setSize(900, 900);

			camera.setCenter(backSprite.getPosition().x, 450);
			if (camera.getCenter().x < 450)
				camera.setCenter(450, 450);
			else if (camera.getCenter().x > 3600 + 450)
				camera.setCenter(3600 + 450, 450);

			window.setView(camera);
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

			//if (backSprite.getPosition().x >= WIDTH) {
				//backSprite.setPosition(0, 750);
			//}

			if (isMovingLeft || isMovingRight) {
				backSprite.setTexture(backText);
				backSprite.setTextureRect(rect[imgCount]);
			}
			//	else if (velocity.y != 0) {

					//backSprite.setTexture(jumpsprite);
					//backSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
			//	}
			else
				backSprite.setTexture(backText);
			backSprite.setTextureRect(rect[0]);

			window.clear();
			window.draw(backgroundSprite);
			window.draw(secondbackground);
			window.draw(thirdbackground);
			window.draw(fourthbackground);
			window.draw(fifthbackground);
			window.draw(aplatform);
			window.draw(monster);
			window.draw(backSprite);
			window.draw(menuBox);
			window.display();
		}
	}
}