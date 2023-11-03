#ifndef __ModuleRenderExercise_H__
#define __ModuleRenderExercise__H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;

class ModuleRenderExercise : public Module
{
public:
	ModuleRenderExercise();
	~ModuleRenderExercise();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

private:
	unsigned CreateTriangleVBO();
	void RenderTriangle(unsigned vbo);

	unsigned vbo = 0;
};

#endif

