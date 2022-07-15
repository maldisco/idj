#ifndef ALIEN_H
#define ALIEN_H

#include "Component.h"
#include <queue>


/**
 * @brief Entity that responds to mouse inputs
 * 
 */
class Alien : public Component{
    public:
        Alien(GameObject& associated);
        ~Alien();

        void Start();
        void Update(float dt);
        void Render();
        void NotifyCollision(GameObject& other);

        bool Is(std::string type);
    
    private:
        /**
         * @brief Represent an action (move/shoot and direction)
         */
        class Action{
            public:
                enum ActionType{ MOVE, SHOOT };
                Action(ActionType type , float x, float y) : type(type), pos({x, y}){};

                ActionType type;
                Vec2 pos;
        };

        Vec2 speed;
        int hp;

        std::queue<Action> taskQueue;
        std::vector<std::weak_ptr<GameObject>> minionArray;
};
#endif