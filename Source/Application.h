#ifndef __Application_H__
#define __Application_H__

#include<list>
#include "Globals.h"
#include "Module.h"

class ModuleOpenGL;
class ModuleWindow;
class ModuleTextures;
class ModuleEditor; 
class ModuleInput;
class ModuleRenderExercise;

class Application
{
public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

    ModuleOpenGL* GetOpenGL() { return render; }
    ModuleWindow* GetWindow() { return window; }
    ModuleInput*  GetInput() { return input; }

public:

    ModuleOpenGL* render = nullptr;
    ModuleWindow* window = nullptr;
    ModuleEditor* editor = nullptr;
    ModuleInput* input = nullptr;

    std::list<Module*> modules;

};

extern Application* App;

#endif