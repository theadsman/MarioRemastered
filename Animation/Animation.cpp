#include <SFML/Graphics.hpp>

const int WIDTH = 1000, HEIGHT = 800;

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
	rect[1] = sf::IntRect(26, 0, 52, 68);
	rect[2] = sf::IntRect(0, 34, 26, 34);
	rect[3] = sf::IntRect(26, 34, 26, 34);

	backText.loadFromFile("textures/mariomoving.png");

	sf::Sprite backSprite;

	backSprite.setPosition(WIDTH / 2, HEIGHT / 2);
	backSprite.setTexture(backText);

	sf::View camera(sf::Vector2f(50, 50), sf::Vector2f(150, 150));
	camera.setSize(200, 200);
	camera.setCenter(0, 0);
	


	bool isMovingUp = false;
	bool isMovingDown = false;
	bool isMovingLeft = false;
	bool isMovingRight = false;
//	bool jump = false;
	bool zoom = false;

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
		if (backSprite.getPosition().y > HEIGHT / 2 && velocity.y > 0)
			velocity.y = 0;


		if (zoom)
			camera.setSize(400, 400);
		else
			camera.setSize(200, 200);

		//camera.move(viewMove);
		//window.setView(camera);
		backSprite.move(velocity);


		window.clear();
		window.draw(backSprite);
		window.display();
	}
}