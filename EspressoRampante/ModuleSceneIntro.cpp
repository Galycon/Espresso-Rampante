#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	// Create sensor cube (will trigger with car)
	sensor_cube = App->physics->AddBody(Cube(5, 5, 5), 0.0);
	sensor_cube->SetAsSensor(true);
	sensor_cube->SetPos(0, 3, 0);


	
	this->CreateElements();

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;

	
	this->RenderElements();

	
	

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

void ModuleSceneIntro::CreateElements()
{

	PhysBody3D* pb_rampaInicial;
	Cube* p_rampaInicial;
	p_rampaInicial = new Cube(5, 2, 15);
	p_rampaInicial->SetPos(0, 0, 5);
	pb_rampaInicial = App->physics->AddBody(*p_rampaInicial, 0.0);
	p_rampaInicial->SetRotation(25, vec3(1, 0, 0));
	pb_rampaInicial->SetTransform(p_rampaInicial->transform.M);
	primitives.PushBack(p_rampaInicial);
	physBodies.PushBack(pb_rampaInicial);


}

void ModuleSceneIntro::RenderElements()
{

	for (int i = 0; i < primitives.Count(); i++) {
		(**primitives.At(i)).Render();
	}

}

