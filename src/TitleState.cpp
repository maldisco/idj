#include "TitleState.h"
#include "Sprite.h"
#include "Text.h"
#include "InputManager.h"
#include "StageState.h"
#include "Camera.h"
#include "Game.h"

TitleState::TitleState() : State(){
    GameObject* bg = new GameObject();
    bg->AddComponent(new Sprite("assets/img/title.jpg", *bg, 1 , 1.0f));
    bg->box.x = Camera::pos.x;
    bg->box.y = Camera::pos.y;
    AddObject(bg);

    GameObject* text = new GameObject();
    text->box.x = Camera::pos.x + CAMERA_WIDTH/2;
    text->box.y = Camera::pos.y + 500;
    text->AddComponent(new Text(*text, "assets/font/callMeMaybe.ttf", 50, Text::BLENDED, "Press space to play", {255, 0, 0, SDL_ALPHA_OPAQUE}));
    AddObject(text);
}

TitleState::~TitleState(){
    objectArray.clear();
}

void TitleState::LoadAssets(){}
void TitleState::Pause(){}
void TitleState::Resume(){}

void TitleState::Start(){
	LoadAssets();
	StartArray();
	started = true;
}

void TitleState::Update(float dt){
    // check if quit was requested
	if(InputManager::GetInstance().KeyPress(ESCAPE_KEY) || InputManager::GetInstance().QuitRequested()){
		quitRequested = true;
	}

    if(InputManager::GetInstance().KeyPress(SPACE_KEY)){
        State* stage = new StageState();
        Game::GetInstance().Push(stage);
    }
}

void TitleState::Render(){
	// Render every object
    RenderArray();
}
