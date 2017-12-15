/**
 * @file RoundObj.h
 * @brief Файл с классом круглого объекта
 */

#ifndef FOOTBALLMANAGER_FOOTBALLER_H
#define FOOTBALLMANAGER_FOOTBALLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/**
 * @brief Класс круглого объекта
 *
 * Используется футболистами и мячём
 */
class RoundObj : public sf::Drawable {
private:
    sf::CircleShape obj;
    sf::Texture texture;
    bool havePic;
public:
    unsigned int radius = 0;
    sf::Vector2f pos;
    sf::Vector2f posv;
    std::string name;

    /**
     * @todo Избавиться в пользу структуры `skills`
     */
    unsigned int skill_goalkeeper = 0;
    unsigned int skill_defender = 0;
    unsigned int skill_midfielder = 0;
    unsigned int skill_striker = 0;

    /**
     * @brief Конструктор класса
     * @param radius Радиус футболиста
     * @param footballerName Имя футболиста. png должен быть в assets
     * @param fillColor Цвет заливки
     * @param outlineColor Цвет края
     * @throws std::runtime_error Если картинка не найдена
     */
    RoundObj(const unsigned int &radius, const std::string &footballerName, const std::uint8_t skill,
               const sf::Color &fillColor,
               const sf::Color &outlineColor = sf::Color::White) {
        this->radius = radius;
        this->pos = pos;
        this->name = footballerName;
        this->posv = {10 + skill, 10 + skill};

        if (footballerName != "-") {
            sf::Image heroimage; //создаем объект Image (изображение)
            if (!heroimage.loadFromFile("../assets/" + footballerName + ".png")) {
                throw std::runtime_error("Image not found.");
            } //загружаем в него файл
            if (!this->texture.loadFromImage(heroimage)) {
                throw std::runtime_error("Image not found.");
            }
            this->havePic = true;
        } else {
            this->havePic = false;
        }

        this->texture.setSmooth(true);
        this->obj.setOutlineColor(outlineColor);
        this->obj.setOutlineThickness(5);
        this->obj.setPosition({0, 0});
        this->obj.setRadius(this->radius);
    }

    /**
     * @brief Конструктор копирования
     * @param f Объект из которого копируем
     */
    RoundObj(const RoundObj &f) {
        this->radius = f.radius;
        this->obj = f.obj;
        this->texture = f.texture;
        this->obj.setTexture(&this->texture);
        this->pos = f.pos;
        this->name = f.name;

        this->skill_goalkeeper = f.skill_goalkeeper;
        this->skill_defender = f.skill_defender;
        this->skill_midfielder = f.skill_midfielder;
        this->skill_striker = f.skill_striker;

        this->posv = f.posv;
        this->havePic = f.havePic;
    }

    /**
     * @brief Изменить текстуру на другую
     * @param texture Новая текстура
     */
    void setTexture(const sf::Texture &texture) {
        this->texture = texture;
    }

    /**
     * @brief Установить скилл игрока
     * @todo Убрать в пользу `RoundObj->skill_xxx = yyy`
     */
    void setSkills(unsigned int skill_goalkeeper, unsigned int skill_defender, unsigned int skill_midfielder,
                   unsigned int skill_striker) {
        this->skill_goalkeeper = skill_goalkeeper;
        this->skill_defender = skill_defender;
        this->skill_midfielder = skill_midfielder;
        this->skill_striker = skill_striker;
    }

    /**
     * @brief Передвинуть объект
     * @param pos Новая позиция
     */
    void move(const sf::Vector2f &pos) {
        //this->pos = this->obj.getPosition();
        this->obj.setPosition(pos.x, pos.y);
        this->pos = this->obj.getPosition();
    }

    /**
     * @brief Изменить радиус
     * @param radius Новый радиус
     */
    void setRadius(unsigned int radius) {
        this->radius = radius;
        this->obj.setRadius(radius);
    }


    bool isNear(const sf::Vector2f &pos) {
        return abs(static_cast<int>(pos.x - this->pos.x)) <= 2 * this->radius and
               abs(static_cast<int>(pos.y - this->pos.y)) <= 2 * this->radius;
    }

    /**
     * @todo Убрать эту функцию в пользу `isNear(player.pos)`
     * @param player Круглый объект с которым надо сравивать
     * @see isNear(pos)
     */
    bool isNear(const RoundObj &player) {
        return isNear(player.pos);
    }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(this->obj, states);
    }

    /**
     * @brief Есть ли у объекта картинка
     */
    bool pic() {
        return this->havePic;
    }

    /**
     * @brief Проверить, находится ли объект за пределами `bounds`
     * @param bounds Границы поля
     */
    bool isOutOf(sf::Vector2u bounds) {
        return this->pos.x <= 0 or this->pos.y <= 0 or this->pos.x >= bounds.x or this->pos.y >= bounds.y;
    }
};


#endif //FOOTBALLMANAGER_FOOTBALLER_H