#pragma once
#include "Game.h"
class SpaceGame : public Game
{
public:
	enum class eState {
		TitleScreen,
		StartGame,
		StartLevel,
		Game,
		PlayerDead,
		GameOver

	};

public: 
	SpaceGame(Engine* engine) : Game{ engine } {}
	bool Initialize() override;
	void ShutDown() override;
	void Update(float dt) override;
	void Draw(Renderer& renderer) override;


private:
	eState m_state{ eState::TitleScreen };
	float m_spawnTimer{ 0 };
	float m_spawnTime{ 0 };
	float m_stateTimer{ 0 };
	
	/*Font* m_font{ nullptr };
	Text* m_textScore{ nullptr };
	Text* m_fontLarge{ nullptr };
	Text* m_textScore{ nullptr };*/
};

