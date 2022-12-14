#include <SFML/Graphics.hpp>

#include "Actor.h"
#include "Map.h"
#include "Character.h"
#include "Enemy.h"
#include "Projectile.h"
#include <iostream>

using namespace sf;


int main()
{
	RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Yellow);

	GameMap map = GameMap(window, 20, 20);

	std::vector< Projectile* > projectiles;

	// Controls
	Keyboard::Key move_left = Keyboard::Key::A;
	Keyboard::Key move_right = Keyboard::Key::D;
	Keyboard::Key move_up = Keyboard::Key::W;
	Keyboard::Key move_down = Keyboard::Key::S;

	Mouse::Button fire = Mouse::Button::Left;

	bool move_left_pressed = false;
	bool move_right_pressed = false;
	bool move_up_pressed = false;
	bool move_down_pressed = false;

	bool firing = false;

	sf::Vector2f input(0, 0);

	Character player(map.getPixelPos(1, 1), sf::Vector2f(map.tileSize, map.tileSize));
	player.mapref = &map;

	Enemy enemy(map.getPixelPos(5, 5), sf::Vector2f(map.tileSize, map.tileSize));
	enemy.mapref = &map;
	enemy.followTarget = &player;
	Enemy enemy2(map.getPixelPos(10, 10), sf::Vector2f(map.tileSize, map.tileSize));
	enemy2.mapref = &map;
	enemy2.followTarget = &enemy;
	sf::Clock dtClock;

	float firingDelay = 0.5;
	float firingCounter = 0;

	while (window.isOpen())
	{
		sf::Time dt = dtClock.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == move_left) {
					move_left_pressed = true;
				}
				if (event.key.code == move_right) {
					move_right_pressed = true;
				}
				if (event.key.code == move_up) {
					move_up_pressed = true;
				}
				if (event.key.code == move_down) {
					move_down_pressed = true;
				}

				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}

			}
			if (event.type == sf::Event::KeyReleased) {

				if (event.key.code == move_left) {
					move_left_pressed = false;
				}
				if (event.key.code == move_right) {
					move_right_pressed = false;
				}
				if (event.key.code == move_up) {
					move_up_pressed = false;
				}
				if (event.key.code == move_down) {
					move_down_pressed = false;
				}

			}

			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == fire) {
					firing = true;
				}
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.mouseButton.button == fire) {
					firing = false;
				}
			}
		}

		// Process input
		player.movementInput.x = 0;
		player.movementInput.y = 0;

		if (move_left_pressed) {
			player.movementInput.x -= 1;
		}
		if (move_right_pressed) {
			player.movementInput.x += 1;
		}
		if (move_up_pressed) {
			player.movementInput.y -= 1;
		}
		if (move_down_pressed) {
			player.movementInput.y += 1;
		}


		// Normalize vector
		float mag = std::sqrt(std::pow(player.movementInput.x, 2) + std::pow(player.movementInput.y, 2));
		player.movementInput /= mag;

		// Fire projectile
		if (firingCounter > 0) {
			firingCounter -= dt.asSeconds();
		}

		if (firing && firingCounter <= 0) {
			std::cout << projectiles.size() << std::endl;
			firingCounter = firingDelay;

			// Spawn projectile
			// Get target direction
			sf::Vector2f mouse_float = sf::Vector2f(sf::Mouse::getPosition(window));
			sf::Vector2f fire_dir = mouse_float - player.position;

			Projectile* new_bullet = new Projectile(player.position, player.size * 0.25f, fire_dir);
			new_bullet->mapref = &map;
			projectiles.push_back(new_bullet);

			//enemy firing
			sf::Vector2f enemy_fire_dir = player.position - enemy.position;

			Projectile* enemy_new_bullet = new Projectile(enemy.position, enemy.size * 0.25f, enemy_fire_dir);
			enemy_new_bullet->mapref = &map;
			projectiles.push_back(enemy_new_bullet);
		}

		// Run updates
		player.update(dt.asSeconds());
		enemy.update(dt.asSeconds());
		enemy2.update(dt.asSeconds());

		for (int i = 0; i < projectiles.size(); i++) {
			projectiles[i]->update(dt.asSeconds());
			if (projectiles[i]->destroy) {
				projectiles.erase(projectiles.begin() + i);
			}
		}

		// TODO: Test collisions, destroy enemies on hit

		window.clear();

		map.drawMap(window);

		player.draw(window);
		enemy.draw(window);
		enemy2.draw(window);

		for (auto projectile : projectiles) {
			projectile->draw(window);
		}


		window.display();
	}

	return 0;
}