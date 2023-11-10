#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "UIManager.h"

class Scene {
public:
	virtual void LoadScene() = 0;

	void ClearSceneBackground() {
		ClearBackground(backgroundColor);
	}

protected:
	Color backgroundColor;
};

