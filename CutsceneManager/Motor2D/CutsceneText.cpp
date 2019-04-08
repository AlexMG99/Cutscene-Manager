#include "j1App.h"
#include "CutsceneText.h"
#include "GUI.h"
#include "UILabel.h"
#include "Fonts.h"

CutsceneText::CutsceneText(int pos_x, int pos_y, std::string text, bool image)
{
	this->text = App->gui->CreateLabel({ pos_x, pos_y }, "pkmn_font.ttf", 14, text, { 255,255,255,255 }, 5, image);
}
