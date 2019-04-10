#include "j1App.h"
#include "CutsceneText.h"
#include "GUI.h"
#include "UILabel.h"
#include "Fonts.h"

CutsceneText::CutsceneText(int pos_x, int pos_y, std::string text, bool image)
{
	this->text = App->gui->CreateLabel({ pos_x, pos_y }, "ui/pkmn_font.ttf", 27, text, { 0,0,0,255 }, 5, image);
}

CutsceneText::~CutsceneText()
{
	App->gui->DeleteElement(text);
}

void CutsceneText::ChangeState(bool active)
{
	text->image = active;
}
