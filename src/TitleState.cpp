#include "TitleState.h"
#include "Sprite.h"
#include "InputManager.h"
#include "StageState.h"
#include "Camera.h"
#include "Game.h"

TitleState::TitleState() : State(){
    GameObject* title = new GameObject();
    title->AddComponent(new Sprite("assets/img/title.jpg", *title, 1 , 1.0f));
    title->box.x = Camera::pos.x;
    title->box.y = Camera::pos.y;
    AddObject(title);
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
