#include "State.h"
#include "Sound.h"
#include "Face.h"
#include "TileMap.h"
#include "Game.h"
#include "Camera.h"
#include "InputManager.h"
#include "CameraFollower.h"

#include "iostream"

State::State() : music("assets/audio/stageState.ogg"), quitRequested(false), started(false){
    
	// background
	GameObject* bg = new GameObject();
	bg->AddComponent(new Sprite("assets/img/ocean.jpg", *bg));
	bg->AddComponent(new CameraFollower(*bg));
	bg->box.x = 0;
	bg->box.y = 0;
	objectArray.emplace_back(bg);

	// tileset
    GameObject* go = new GameObject();
	TileSet* tileSet = new TileSet(*go, 64, 64, "assets/img/tileset.png");
	go->AddComponent(new TileMap(*go, "assets/map/tileMap.txt", tileSet));
	go->box.x = 0;
	go->box.y = 0;
	objectArray.emplace_back(go);
    
    music.Play();
}

State::~State(){
    objectArray.clear();
}

void State::Start(){
	LoadAssets();

	for(auto go : objectArray){
		go->Start();
	}

	started = true;
}

void State::LoadAssets(){

}

void State::Update(float dt){

	// update camera
	Camera::Update(dt);

	// check if quit was requested
	if(InputManager::GetInstance().KeyPress(ESCAPE_KEY) || InputManager::GetInstance().QuitRequested()){
		quitRequested = true;
	}

	// if space key was pressed, create an enemy
	if(InputManager::GetInstance().KeyPress(SDLK_SPACE)){
		Vec2 objPos = Vec2( 200, 0 ).Rotate( -PI + PI*(rand() % 1001)/500.0 ) + Vec2( InputManager::GetInstance().GetMouseX(), InputManager::GetInstance().GetMouseY() );
		AddObject((int)objPos.x, (int)objPos.y);
	}

	// Update every object
    for(unsigned i=0; i<objectArray.size(); i++){
        objectArray[i]->Update( Game::GetInstance().GetDeltaTime() );
    }

	// Check if object is dead
    for(unsigned i=0; i<objectArray.size(); i++){
        if( objectArray[i]->IsDead() ){
            objectArray.erase(objectArray.begin()+i);
        }
    }
}

void State::Render(){
	// Render every object
    for(unsigned i=0; i<objectArray.size(); i++){
        objectArray[i]->Render();
    }
}

void State::AddObject( int mouseX, int mouseY ){
    GameObject* go = new GameObject();
	Sprite* sprite = new Sprite("assets/img/penguinface.png", *go);

    go->AddComponent(sprite);
    go->box.x = mouseX + Camera::pos.x - sprite->GetWidth()/2;
    go->box.y = mouseY + Camera::pos.y - sprite->GetHeight()/2 ;
	go->box.w = sprite->GetWidth();
	go->box.h = sprite->GetHeight();
    
    go->AddComponent(new Sound("assets/audio/boom.wav", *go));
	go->AddComponent(new Face(*go));

    objectArray.emplace_back(go);
}

std::weak_ptr<GameObject> State::AddObject( GameObject* go ){
	std::shared_ptr<GameObject> sharedGo(go);
	objectArray.push_back( sharedGo );

	if(started){
		go->Start();
	}

	return std::weak_ptr<GameObject>(sharedGo);
}

std::weak_ptr<GameObject> State::GetObjectPtr( GameObject* go ){
	for(auto s : objectArray){
		if(s.get() == go){
			return std::weak_ptr<GameObject>(s);
		}
	}

	return {};
}

bool State::QuitRequested()
{
    return quitRequested;
}

