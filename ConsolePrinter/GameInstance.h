#pragma once
#include <string>
class Player;

class GameInstance {
private:
	static GameInstance* instance;
	bool isGoing;
	Player* player;

private:
	GameInstance();

public:
	static GameInstance* GetInstance();
	void Begin();
	void GameMainLoop();
	void Shutdown();
	Player* GetPlayer();
	void CreatePlayer(const std::string& name);

	void SetGameState(bool);
};