#pragma once
#include "Tiles.h"
#include "RadialLight.hpp"

class LightTile : public Tiles {
private:
    candle::RadialLight light;  // Light source for the tile
public:
    LightTile(float range = 1000.0f);

    void setPosition(const sf::Vector2f& position);

    candle::RadialLight& getLight();


    void draw(sf::RenderWindow& window);
};
