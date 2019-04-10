#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "Render.h"
#include "Textures.h"
#include "Input.h"
#include "SceneManager.h"
#include "Textures.h"
#include "Audio.h"
#include "Fonts.h"
#include "UIElement.h"
#include "UIImage.h"
#include "UILabel.h"
#include "GUI.h"

Gui::Gui() : Module()
{
	name = "gui";
}

// Destructor
Gui::~Gui()
{}

// Called before render is available
bool Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool Gui::Start()
{
	atlas = App->tex->Load("ui/atlas.png");

	return true;
}

// Update all guis
bool Gui::PreUpdate()
{
	//BROFILER_CATEGORY("UIPreUpdate", Profiler::Color::Magenta);
	if (App->input->GetKey(SDL_SCANCODE_F8) == KEY_DOWN)
		debug_draw = !debug_draw;


	return true;
}

bool Gui::Update(float dt)
{
	//scale stuff
	
	//BROFILER_CATEGORY("UIUpdate", Profiler::Color::Magenta);
	for (std::list<UIElement*>::iterator element = elements.begin(); element != elements.end(); ++element)
	{
		if ((*element)->enabled)
		{
			(*element)->Update(dt);
		}

	}
	return true;
}

// Called after all Updates
bool Gui::PostUpdate()
{
	//BROFILER_CATEGORY("UIPostUpdate", Profiler::Color::Magenta);
	for (std::list<UIElement*>::iterator element = elements.begin(); element != elements.end(); ++element)
	{
		if ((*element)->enabled)
		{
			(*element)->UIBlit();
			if (debug_draw)
				App->render->DrawQuad((*element)->GetScreenRect(), 255, 0, 0, 255, false, false);
		}

	}
	return true;
}

// Called before quitting
bool Gui::CleanUp()
{
	LOG("Freeing GUI");
	for (std::list<UIElement*>::iterator element = elements.begin(); element != elements.end(); ++element)
	{
		(*element)->CleanUp();
	}
	elements.clear();
	App->tex->UnLoad(atlas);
	atlas = nullptr;

	return true;
}

UIImage* Gui::CreateImage(iPoint pos, SDL_Rect rect, bool image_, UIElement* parent)
{
	UIImage* image = new UIImage(pos, rect, image_);
	image->parent = parent;
	elements.push_back(image);

	return image;
}

UILabel* Gui::CreateLabel(iPoint pos, std::string path, int size, std::string text, SDL_Color color, int max_width, bool image, UIElement* parent)
{
	_TTF_Font* font = App->fonts->Load(path.c_str(), size);
	UILabel* label = new UILabel(pos, font, text, color, max_width, image);
	label->parent = parent;
	elements.push_back(label);

	return label;
}


void Gui::DeleteElement(UIElement* ele)
{
	for (std::list<UIElement*>::iterator element = elements.begin(); element != elements.end(); ++element)
	{
		if ((*element)->parent && (*element)->parent == ele)
			DeleteElement(*element);
	}
	ele->CleanUp();
	elements.remove(ele);
	delete ele;
}

void Gui::EnableElement(UIElement* ele)
{
	ele->SetEnabled(true);
	for (std::list<UIElement*>::iterator element = elements.begin(); element != elements.end(); ++element)
	{
		if ((*element)->parent && (*element)->parent == ele)
			EnableElement(*element);
	}
}
void Gui::DisableElement(UIElement* ele)
{
	ele->SetEnabled(false);
	for (std::list<UIElement*>::iterator element = elements.begin(); element != elements.end(); ++element)
	{
		if ((*element)->parent && (*element)->parent == ele)
			DisableElement(*element);
	}
}
UIElement* Gui::GetElementUnderMouse()
{
	int x, y;
	App->input->GetMousePosition(x, y);

	for (std::list<UIElement*>::iterator element = elements.begin(); element != elements.end(); ++element)
	{
		if ((*element)->IsInside(x, y) && (*element)->interactable && (*element)->enabled)
		{
			bool inside_child = false;
			for (std::list<UIElement*>::iterator child_item = elements.begin(); child_item != elements.end(); child_item = ++child_item)
			{
				if ((*child_item)->parent && (*child_item)->parent == (*element) && (*child_item)->IsInside(x, y) && (*child_item)->interactable && (*element)->enabled)
				{
					inside_child = true;
					break;
				}
			}
			if (!inside_child)
				return (*element);
		}
	}

	return nullptr;
}



// const getter for atlas
SDL_Texture* Gui::GetAtlas() const
{
	return atlas;
}

// class Gui ---------------------------------------------------