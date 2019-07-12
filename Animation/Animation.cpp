#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML/Audio.hpp>

const int WIDTH = 900, HEIGHT = 900;

sf::Vector2f velocity(0, 0);

int Scoreboard = 0;

void jump()
{
	velocity.y = -1.4f;
}

int main()
{
	//state gameState = title;

	int state = 0;


	sf::RectangleShape menuBox;
	menuBox.setSize(sf::Vector2f(325.f, 100));
	menuBox.setPosition(300, 400);
	menuBox.setFillColor(sf::Color(255, 0, 0));

	sf::RectangleShape menuBoxb;
	menuBoxb.setSize(sf::Vector2f(400, 100));
	menuBoxb.setPosition(250, 400);
	menuBoxb.setFillColor(sf::Color(0, 0, 255));

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
	backSprite.setOrigin(13, 0);
	backSprite.setPosition(10, 750);

	backSprite.setPosition(WIDTH / 12, HEIGHT / 4);
	backSprite.setTexture(backText);

	sf::Sprite backgroundSprite;
	sf::Texture background;
	//backgroundSprite.setScale(6, 6);


	sf::Sprite aspike;
	sf::Sprite bspike;


	sf::Texture spikes;

	spikes.loadFromFile("Textures/obstacles.png");
	bspike.setTexture(spikes);
	bspike.setScale(3, 3);
	bspike.setPosition(1975, 750);
	aspike.setTexture(spikes);
	aspike.setScale(3, 3);
	aspike.setPosition(1900, 750);

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
	sf::IntRect marioJumpA[1];
	marioJumpA[0] = sf::IntRect(0, 0, 34, 28);

	jumpsprite.loadFromFile("textures/mariojump.png");

	sf::Sprite coin1;
	sf::Sprite coin2;
	sf::Sprite coin3;
	sf::Sprite coin4;
	sf::Sprite coin5;
	sf::Sprite coin6;
	sf::Sprite coin7;
	sf::Sprite coin8;
	sf::Texture coin;

	coin.loadFromFile("textures/coin.png");

	coin1.setTexture(coin);
	coin1.setPosition(400, 625);

	coin2.setTexture(coin);
	coin2.setPosition(700, 625);

	coin3.setTexture(coin);
	coin3.setPosition(2500, 625);

	coin4.setTexture(coin);
	coin4.setPosition(2800, 625);

	coin5.setTexture(coin);
	coin5.setPosition(3700, 690);

	coin6.setTexture(coin);
	coin6.setPosition(3935, 590);

	coin7.setTexture(coin);
	coin7.setPosition(4050, 490);

	coin8.setTexture(coin);
	coin8.setPosition(4300, 300);


	MarioJump.setTexture(jumpsprite);
	MarioJump.setTextureRect(marioJumpA[0]);
	MarioJump.setOrigin(0, 0);
	MarioJump.setScale(3, 3);
	MarioJump.setPosition(0, 0);

	bool isMovingUp = false;
	bool isMovingDown = false;
	bool isMovingLeft = false;
	bool isMovingRight = false;
	bool jumping = false;
	bool zoom = false;
	bool facingleft = false;

	sf::Sprite monsterg;
	sf::Sprite monsterf;
	sf::Sprite monstere;
	sf::Sprite monsterd;
	sf::Sprite monsterc;
	sf::Sprite monsterb;
	sf::Sprite monster;
	sf::Texture Goomba;

	Goomba.loadFromFile("textures/goomba.png");

	

	monsterf.setTexture(Goomba);
	monsterf.setScale(1.75, 1.75);
	monsterf.setPosition(3100, 790);

	monstere.setTexture(Goomba);
	monstere.setScale(1.75, 1.75);
	monstere.setPosition(2800, 790);

	monsterd.setTexture(Goomba);
	monsterd.setScale(1.75, 1.75);
	monsterd.setPosition(2550, 790);

	monsterc.setTexture(Goomba);
	monsterc.setScale(1.75, 1.75);
	monsterc.setPosition(2400, 790);

	monsterb.setTexture(Goomba);
	monsterb.setScale(1.75, 1.75);
	monsterb.setPosition(800, 790);

	monster.setTexture(Goomba);
	monster.setScale(1.75, 1.75);
	monster.setPosition(300, 790);

	sf::Sprite aplatform;
	sf::Texture platform;
	platform.loadFromFile("textures/platform.png");

	sf::Sprite bplatform;

	bplatform.setTexture(platform);

	bplatform.setPosition(1400, 600);
	bplatform.setScale(4, 4);


	aplatform.setPosition(1200, 700);
	aplatform.setScale(4, 4);

	aplatform.setTexture(platform);

	sf::Sprite cplatform;
	cplatform.setTexture(platform);
	cplatform.setPosition(1600, 500);
	cplatform.setScale(4, 4);

	sf::Sprite dplatform;
	dplatform.setTexture(platform);
	dplatform.setPosition(1800, 400);
	dplatform.setScale(4, 4);

	sf::Sprite eplatform;
	eplatform.setTexture(platform);
	eplatform.setScale(4, 4);
	eplatform.setPosition(3900, 690);
	
		
		sf::Sprite fplatform;
	fplatform.setTexture(platform);
	fplatform.setScale(4, 4);
	fplatform.setPosition(4000, 590);

	sf::Sprite gplatform;
	gplatform.setTexture(platform);
	gplatform.setScale(4, 4);
	gplatform.setPosition(4200, 489);

	sf::Sprite hplatform;

	hplatform.setTexture(platform);
	hplatform.setScale(4, 4);
	hplatform.setPosition(4400, 350);


	sf::Clock clock;
	int imgCount = 0;
	float timer = 0;

	sf::Text myText;
	sf::Text Score;
	sf::Text Title;

	sf::Font myFont;
	myFont.loadFromFile("font/SuperMario256.ttf");

	Score.setFont(myFont);
	
	Score.setOrigin(WIDTH/ 20, 0);
	Score.setCharacterSize(20);
	Score.setFillColor(sf::Color::Blue);

	sf::Sprite mariopipeone;
	sf::Texture mariopipe;

	mariopipe.loadFromFile("textures/mariopipeb.png");
	mariopipeone.setTexture(mariopipe);

	mariopipeone.setPosition(10, 675);
	mariopipeone.setScale(2, 2);

	sf::Sprite finishflag;
	sf::Texture flag;

	flag.loadFromFile("textures/flag.png");
	
	finishflag.setTexture(flag);
	finishflag.setScale(1.5, 1.5);
	finishflag.setPosition(4450, 225);

	sf::Music music;
	if (!music.openFromFile("textures/ThemeSong.wav"))
		return -1; // error
	music.play();

	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("textures/CoinSound.wav"))
		return -1;

	sf::Sound sound;
	sound.setBuffer(buffer);


	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			;

			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::Up) {
					jumping = true;
					if (velocity.y == 0)
						jump();
				}

				if (event.key.code == sf::Keyboard::Enter) {

					state = 1;
				}


				if (event.key.code == sf::Keyboard::Right) {
					isMovingRight = true;
					//if (facingleft) {
						//backSprite.scale(-1, 0);
						//facingleft = false;
					//}
				}

				if (event.key.code == sf::Keyboard::Left) {

					isMovingLeft = true;
					/*if (!facingleft){
						backSprite.scale(-1, 0);
						facingleft = true;*/
				}

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

			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Up) {
					isMovingDown = false;
				}
				if (event.key.code == sf::Keyboard::S) {
					isMovingUp = false;
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

				}
			}
		}

		Score.setString("Coins: " + std::to_string(Scoreboard) );
		


		switch (state) {
		case 0:


			

			Title.setFont(myFont);
			Title.setPosition(470, 200);
			Title.setOrigin(150, 0);
			Title.setString("Mario!");
			Title.setCharacterSize(75);
			Title.setFillColor(sf::Color::Blue);

			myText.setFont(myFont);
			myText.setPosition(450, 450);
			myText.setOrigin(150, 0);
			myText.setString("Press enter to start");
			myText.setCharacterSize(24);
			myText.setFillColor(sf::Color::Black);



			window.clear();
			window.draw(menuBox);
			window.draw(myText);
			window.draw(Title);
			window.display();

			break;


		case 1:

Score.setPosition(camera.getCenter().x, 100);



			velocity.y += 0.005;
			if (backSprite.getPosition().y > HEIGHT / 1.2 && velocity.y > 0)
				velocity.y = 0;

			if (backSprite.getGlobalBounds().intersects(aspike.getGlobalBounds())) {
				state = 2;
				backSprite.setPosition(WIDTH / 12, HEIGHT / 4);
			}
			if (backSprite.getGlobalBounds().intersects(bspike.getGlobalBounds())) {
				state = 2;
				backSprite.setPosition(WIDTH / 12, HEIGHT / 4);
			}

			if (backSprite.getGlobalBounds().intersects(finishflag.getGlobalBounds())) {
				state = 3;
				backSprite.setPosition(WIDTH / 12, HEIGHT / 4);
			}

			if (backSprite.getGlobalBounds().intersects(aplatform.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < aplatform.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 0;
					jump();
				}
			}

			if (backSprite.getGlobalBounds().intersects(coin1.getGlobalBounds())) {

				coin1.setPosition(1000000, 1000000);
				sound.play();
				Scoreboard++;
			}


			if (backSprite.getGlobalBounds().intersects(coin2.getGlobalBounds())) {
				coin2.setPosition(1000000, 1000000);
				sound.play();
				Scoreboard++;
			}

			if (backSprite.getGlobalBounds().intersects(coin3.getGlobalBounds())) {
				coin3.setPosition(1000000, 1000000);
				sound.play();
				Scoreboard++;
			}
			
			if (backSprite.getGlobalBounds().intersects(coin4.getGlobalBounds())) {
				coin4.setPosition(1000000, 1000000);
				sound.play();
				Scoreboard++;
			}
			
			if (backSprite.getGlobalBounds().intersects(coin5.getGlobalBounds())) {
				coin5.setPosition(1000000, 1000000);
				sound.play();
				Scoreboard++;
			}

			if (backSprite.getGlobalBounds().intersects(coin6.getGlobalBounds())) {
				coin6.setPosition(1000000, 1000000);
				sound.play();
				Scoreboard++;
			}

			if (backSprite.getGlobalBounds().intersects(coin7.getGlobalBounds())) {
				coin7.setPosition(1000000, 1000000);
				sound.play();
				Scoreboard++;
			}
			if (backSprite.getGlobalBounds().intersects(coin8.getGlobalBounds())) {
				coin8.setPosition(1000000, 1000000);
				sound.play();
				Scoreboard++;
			}


			if (backSprite.getGlobalBounds().intersects(monster.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < monster.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 2;
					monster.setPosition(-10000, -1000);
					jump();
				}
				else {
					state = 2;
					backSprite.setPosition(WIDTH / 12, HEIGHT / 4);
				}
			}



			if (backSprite.getGlobalBounds().intersects(monsterb.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < monsterb.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 2;
					monsterb.setPosition(-10000, -1000);
					jump();
				}
				else {
					backSprite.setPosition(WIDTH / 12, HEIGHT / 4);

					state = 2;
				}
			}

			if (backSprite.getGlobalBounds().intersects(monsterc.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < monsterc.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 2;
					monsterc.setPosition(-10000, -1000);
					jump();
				}
				else {
					backSprite.setPosition(WIDTH / 12, HEIGHT / 4);

					state = 2;
				}
			}

			if (backSprite.getGlobalBounds().intersects(monsterd.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < monsterd.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 2;
					monsterd.setPosition(-10000, -1000);
					jump();
				}
				else {
					backSprite.setPosition(WIDTH / 12, HEIGHT / 4);

					state = 2;
				}
			}

			if (backSprite.getGlobalBounds().intersects(monsterf.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < monsterf.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 2;
					monsterf.setPosition(-10000, -1000);
					jump();
				}
				else {
					backSprite.setPosition(WIDTH / 12, HEIGHT / 4);

					state = 2;
				}
			}

			if (backSprite.getGlobalBounds().intersects(monsterd.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < monsterd.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 2;
					monsterd.setPosition(-10000, -1000);
					jump();
				}
				else {
					backSprite.setPosition(WIDTH / 12, HEIGHT / 4);

					state = 2;
				}
			}

			if (backSprite.getGlobalBounds().intersects(monstere.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < monstere.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 2;
					monstere.setPosition(-10000, -1000);
					jump();
				}
				else {
					backSprite.setPosition(WIDTH / 12, HEIGHT / 4);

					state = 2;
				}
			}


			if (monstere.getGlobalBounds().intersects(bspike.getGlobalBounds())) {
				monstere.setPosition(2600, 750);


			

			}

			if (monsterf.getGlobalBounds().intersects(bspike.getGlobalBounds())) {
				monsterf.setPosition(2700, 750);




			}

			if (backSprite.getGlobalBounds().intersects(mariopipeone.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < mariopipeone.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 0;


				}

			}
			velocity.x = 0;
			if (isMovingLeft)
				velocity.x -= 0.7;
			if (isMovingRight)
				velocity.x += 0.7;


			if (backSprite.getPosition().x < monster.getPosition().x) {
				monster.move(-0.05, 0);
			}
			else
			{

				monster.move(0.05, 0);

			}
			if (backSprite.getPosition().x < monsterb.getPosition().x) {
				monsterb.move(-0.02, 0);
			}
			else
			{

				monsterb.move(0.05, 0);

			}

			if (backSprite.getPosition().x < monster.getPosition().x) {
				monster.move(-0.05, 0);
			}
			else
			{

				monster.move(0.05, 0);

			}
			if (backSprite.getPosition().x > monsterc.getPosition().x) {
				monsterc.move(-0.02, 0);
			}
			else
			{

				monsterc.move(0.02, 0);

			}

			if (backSprite.getPosition().x > monsterd.getPosition().x) {
				monsterd.move(-0.02, 0);
			}
			else
			{

				monsterd.move(0.02, 0);

			}

			if (backSprite.getPosition().x < monstere.getPosition().x) {
				monstere.move(-0.02, 0);
			}
			else
			{

				monstere.move(0.02, 0);

			}

			if (backSprite.getPosition().x < monsterf.getPosition().x) {
				monsterf.move(-0.02, 0);
			}
			else
			{

				monsterf.move(0.02, 0);

			}



			//if (backSprite.getPosition().y < coin1.getPosition().y) {
			//coin1.move(0, 0.001);
		//}



			if (backSprite.getGlobalBounds().intersects(bplatform.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < bplatform.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 0;
					jump();
				}
			}

			if (backSprite.getGlobalBounds().intersects(cplatform.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < cplatform.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 0;
					jump();
				}
			}

			if (backSprite.getGlobalBounds().intersects(dplatform.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < dplatform.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 0;
					jump();
				}
			}

			if (backSprite.getGlobalBounds().intersects(eplatform.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < eplatform.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 0;
					
				}
			}

			if (backSprite.getGlobalBounds().intersects(fplatform.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < fplatform.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 0;
					
				}
			}

			if (backSprite.getGlobalBounds().intersects(gplatform.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < gplatform.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 0;
					
				}
			}

			if (backSprite.getGlobalBounds().intersects(hplatform.getGlobalBounds())) {
				if (backSprite.getGlobalBounds().top + 98 < hplatform.getGlobalBounds().top && velocity.y > 0) {
					velocity.y = 0;

				}
			}



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
				timer = clock.getElapsedTime().asSeconds();
				if (timer > 0.25f)
				{
					if (imgCount < 7)
						imgCount++;
					else
						imgCount = 0;
					clock.restart();
				}
			}
			else
				imgCount = 0;


			//	if (velocity.y != 0) {
				//	backSprite.setTexture(jumpsprite);
			//	}
				//else {
			if (isMovingRight || isMovingLeft)
				(backSprite.setTextureRect(rect[imgCount]));
			else
				backSprite.setTextureRect(rect[0]);
			//	}


				/*	if (jumping)
						(backSprite.setTextureRect(marioJumpA[imgCount]));
					else
						backSprite.setTextureRect(marioJumpA[0]); */


			window.clear();
			window.draw(backgroundSprite);
			window.draw(secondbackground);
			window.draw(thirdbackground);
			window.draw(fourthbackground);
			window.draw(fifthbackground);
			window.draw(aplatform);
			window.draw(bplatform);
			window.draw(dplatform);
			window.draw(cplatform);
				window.draw(gplatform);
			window.draw(aspike);
			window.draw(bspike);
			window.draw(mariopipeone);
			window.draw(monster);
			window.draw(monsterb);
			window.draw(monsterc);
			window.draw(monsterd);
			window.draw(monstere);
			window.draw(monsterf);
			window.draw(monsterg);
			window.draw(coin1);
			window.draw(coin2);
			window.draw(coin3);
			window.draw(coin4);
			window.draw(coin5);
			window.draw(coin6);
			window.draw(coin7);
			window.draw(coin8);
			window.draw(Score);
			window.draw(eplatform);
			window.draw(fplatform);
			window.draw(finishflag);
			window.draw(hplatform);
			
			window.draw(backSprite);
			window.display();


			break;
		case 2:
			camera.setCenter(450, 450);
			window.setView(camera);

			myFont.loadFromFile("font/SuperMario256.ttf");

			Title.setFont(myFont);
			Title.setPosition(350, 200);
			Title.setOrigin(150, 0);
			Title.setString("Game Over!");
			Title.setCharacterSize(75);
			Title.setFillColor(sf::Color::Red); 
			Title.setStyle(sf::Text::Bold);
			Title.setOutlineThickness(4);
			Title.setOutlineColor(sf::Color::Black);
			

			myText.setFont(myFont);
			myText.setPosition(400, 450);
			myText.setOrigin(150, 0);
			myText.setString("Press enter to play again");
			myText.setCharacterSize(24);
			myText.setFillColor(sf::Color::Black);

			window.clear();
			window.draw(menuBoxb);
			window.draw(myText);
			window.draw(Title);
			window.display();

			break;

		case 3:

			camera.setCenter(450, 450);
			window.setView(camera);

			myFont.loadFromFile("font/SuperMario256.ttf");

			Title.setFont(myFont);
			Title.setPosition(425, 400);
			Title.setOrigin(150, 0);
			Title.setString("Victory!");
			Title.setCharacterSize(75);
			Title.setFillColor(sf::Color::Green);
			Title.setStyle(sf::Text::Bold);
			Title.setOutlineThickness(4);
			Title.setOutlineColor(sf::Color::Black);
			
			window.clear();
			window.draw(myText);
			window.draw(Title);
			window.display();

			

			//	else if (velocity.y != 0) {

					//backSprite.setTexture(jumpsprite);
					//backSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
			//	}
			/*else
				backSprite.setTexture(backText);
			backSprite.setTextureRect(rect[0]);*/


		}
	}
}