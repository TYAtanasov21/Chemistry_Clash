#pragma once

#include "Button.h"
#include "Text.h"

class UIManager {
public:

    static std::shared_ptr<UIManager> GetInstance()
    {
        if (instance == nullptr)
            instance = std::make_shared<UIManager>();

        return instance;
    }

    void DrawAll();

    void UpdateAll();

    void AddButton(Button button);

    void AddText(Text text);

    void UpdateLists();

private:
    static std::shared_ptr<UIManager> instance;

    std::vector<Button> buttonList;

    std::vector<Text> textList;
};