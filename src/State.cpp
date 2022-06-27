#include "State.h"
#include "Sound.h"
#include "Face.h"
#include "TileMap.h"

#include "iostream"

State::State() : quitRequested(false), music("assets/audio/stageState.ogg"){
    
	// background
	GameObject* bg = new GameObject();
	bg->AddComponent(new Sprite("assets/img/ocean.jpg", *bg));
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

void State::LoadAssets(){}

void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		}
		
		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {
			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(go->box.Contains( {(float)mouseX, (float)mouseY} ) ) {
					Face* face = (Face*)go->GetComponent( "Face" );
					if ( nullptr != face ) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}
		if( event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vec2 objPos = Vec2( 200, 0 ).Rotate( -PI + PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}

void State::Update(float dt){
    Input();
    for(int i=0; i<objectArray.size(); i++){
        objectArray[i]->Update(0);
    }

    for(int i=0; i<objectArray.size(); i++){
        if( objectArray[i]->IsDead() ){
            objectArray.erase(objectArray.begin()+i);
        }
    }
}

void State::Render(){
    for(int i=0; i<objectArray.size(); i++){
        objectArray[i]->Render();
    }
}

void State::AddObject( int mouseX, int mouseY ){
    GameObject* go = new GameObject();
	Sprite* temp = new Sprite("assets/img/penguinface.png", *go);

    go->AddComponent(temp);
    go->box.x = mouseX - temp->GetWidth()/2;
    go->box.y = mouseY - temp->GetHeight()/2;
	go->box.w = temp->GetWidth();
	go->box.h = temp->GetHeight();
    
    go->AddComponent(new Sound("assets/audio/boom.wav", *go));
	go->AddComponent(new Face(*go));

    objectArray.emplace_back(go);
}

bool State::QuitRequested()
{
    return quitRequested;
}

