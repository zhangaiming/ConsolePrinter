#pragma once

class Level;

class LevelManager {
	static Level* curLevel;

public:
	static void Load(Level*);
	static void LoadBeginLevel();
};