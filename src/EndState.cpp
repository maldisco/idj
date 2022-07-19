#include "EndState.h"
#include "GameData.h"
#include "Sprite.h"
#include "Camera.h"
#include "InputManager.h"
#include "TitleState.h"
#include "Text.h"
#include "Game.h"

EndState::EndState(){
    GameObject* bg = new GameObject();
    Sprite* result;
    if(GameData::playerVictory){
        result = new Sprite("assets/img/win.jpg", *bg);
        backgroundMusic = Music("assets/audio/endStateWin.ogg");
    } else {
        result = new Sprite("assets/img/lose.jpg", *bg);
        backgroundMusic = Music("assets/audio/endStateLose.ogg");
    }
    bg->AddComponent(result);
    bg->box.x = Camera::pos.x;
    bg->box.y = Camera::pos.y;
    AddObject(bg);

    GameObject* text = new GameObject();
    text->box.x = Camera::pos.x + CAMERA_WIDTH/2;
    text->box.y = Camera::pos.y + 500;
    text->AddComponent(new Text(*text, "assets/font/callMeMaybe.ttf", 50, Text::BLENDED, "ESC to quit  SPACE to play again", {255, 0, 0, SDL_ALPHA_OPAQUE}));
    AddObject(text);

    backgroundMusic.Play();
}

void EndState::Update(float dt){
    UpdateArray(dt);
    // check if quit was requested
	if(InputManager::GetInstance().KeyPress(ESCAPE_KEY) || InputManager::GetInstance().QuitRequested()){
		quitRequested = true;
	}

    if(InputManager::GetInstance().KeyPress(SPACE_KEY)){
        popRequested = true;
        State* stage = new TitleState();
        Game::GetInstance().Push(stage);
    }
}

EndState::~EndState(){
    objectArray.clear();
}

void EndState::LoadAssets(){}
void EndState::Pause(){}
void EndState::Resume(){}

void EndState::Start(){
	LoadAssets();
	StartArray();
	started = true;
}

void EndState::Render(){
	// Render every object
    RenderArray();
}