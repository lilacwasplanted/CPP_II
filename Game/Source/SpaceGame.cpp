#include "SpaceGame.h"
#include "Scene.h"
#include "Engine.h"
#include "GameData.h"
//#include "Font.h"
//#include "Text.h"
#include "Player.h"

bool SpaceGame::Initialize()
{
    m_scene = new Scene(this);
    //m_font = new Font();
    //m_font->Load("arcadeclassic.ttf", 20);

    return true;
}

void SpaceGame::ShutDown()
{

}

void SpaceGame::Update(float dt)
{
    switch (m_state)
    {
    case eState::TitleScreen:
        if (m_engine->GetInput()->GetKeyDown(SDL_SCANCODE_SPACE)) {
            m_state = eState::StartGame;
        }
        break;
    case eState::StartGame:
  
        m_state = eState::StartLevel;
        break;

    case eState::StartLevel:
    {
        Model* model = new Model{GameData::shipPoints, Color{1, 0, 0} };
        Transform transform{ Vector2{400,300}, 0, 3 };
        Player* player = new Player(800, transform, model);
        player->SetDamping(2.0f);
        player->SetTag("Player");
        m_scene->AddActor(player);

      
        m_spawnTime = 3;
        m_spawnTimer = m_spawnTime;
    }
      m_state = eState::Game;
        break;
    case eState::Game:
        m_score = 0;
        
            break;
    case eState::PlayerDead:
        m_stateTimer -= dt;
        if (m_stateTimer <= 0) {
            m_state = eState::StartLevel;
        }
        break;
    case eState::GameOver:
        break;
    default:
        break;
    }
    m_scene->Update(dt);
}

void SpaceGame::Draw(Renderer& renderer)
{
    switch (m_state)
    {
    case SpaceGame::eState::TitleScreen:
        //draw text "Game Title"
       /* m_textTitle->Create(renderer, "Pew!, Pew!", Color{ 1, 0, 0, 1 });
        m_textTitle->Draw(renderer, 250, 300);*/
        break;
    case SpaceGame::eState::GameOver:
        //draw text "Game Over"
       /* m_textTitle->Create(renderer, "Game Over!" , Color{ 1, 0, 0, 1 });
        m_textTitle->Draw(renderer, 250, 300);*/
        break;
    default:
        break;
    }
    //Draw score
  /*  std::string text = "Score: " + std::to_string(m_score);
    m_textScore->Create(renderer, text, { 0, 1, 0, 1 });
    m_textScore->Draw(renderer, 20, 20);*/
    
  /*  std::string text = "Lives: " + std::to_string(m_lives);
    m_textScore->Create(renderer, text, { 0, 1, 0, 1 });
    m_textScore->Draw(renderer.GetWidth() - 100, 20);*/
         
    m_scene->Draw(renderer);

  //  void SpaceGame::OnPlayerDeath() {
  //      m_lives--;
  //      m_state = (m_lives == 0) ? eState::GameOver : eState::PlayerDead;
  //      m_stateTimer = 3;
  //  }
}
