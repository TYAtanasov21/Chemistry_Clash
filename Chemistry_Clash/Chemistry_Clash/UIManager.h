#pragma once

#include "Button.h"
#include "Text.h"
#include "CheckButton.h"

struct  RectangleV2
{
    Rectangle rec;
    Color recColor;
};

struct TextureV {
    Texture2D texture;
    Rectangle frameRec;
    Vector2 pos;
};

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

    void AddCheckButton(CheckButton* checkButton);

    void AddText(Text text);

    void AddRec(RectangleV2 rec);

    void AddTexture(TextureV texture);

    void UpdateLists();

private:
    static std::shared_ptr<UIManager> instance;

    std::vector<Button> buttonList;

    std::vector<CheckButton*> checkButtonList;

    std::vector<Text> textList;

    std::vector<RectangleV2> rectangleList;

    std::vector<TextureV> textureList;
};