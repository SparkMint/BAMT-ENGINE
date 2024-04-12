#ifndef BAMT_ENTITY
#define BAMT_ENTITY

#include <vector>

#include "SDL.h"
#include "Transform.h"
#include "Component.h"
#include "Debug.h"

class EngineManager;
class Scene;
class Transform;
class Component;

class Entity 
{
	/// <summary>
	/// The list of Components attached to this entity.
	/// </summary>
	std::vector<Component*> _components;

	public:
		Entity();
		~Entity();

		/// <summary>
		/// Pointer to the scene this entity is attached to.
		/// </summary>
		Scene* scene = nullptr;

		/// <summary>
		/// Defines where this entity is in the game world.
		/// </summary>
		Transform* transform = nullptr;

		/// <summary>
		/// Should this Entity run any logic?
		/// </summary>
		bool active = true;

		/// <summary>
		/// What layer should this Entity Draw on?
		/// </summary>
		int renderLayer = 0;

		/// <summary>
		/// What tag does this entity have? Used mainly for collisions.
		/// </summary>
		std::string tag = "Default";

		/// <summary>
		/// Used to let the entity perform initialization when created.
		/// </summary>
		virtual void Start();

		/// <summary>
		/// Runs Update on all Components attached to this Entity.
		/// </summary>
		virtual void Update(float* timeStep);

		/// <summary>
		/// Runs Render on all Components attached to this Entity.
		/// </summary>
		virtual void Render(SDL_Renderer* renderer) const;

		/// <summary>
		/// Adds a specified Component to this Entity.
		/// </summary>	
		/// <typeparam name="T">- The Component to add.</typeparam>
		template<class T, typename... TArgs>
		T* AddComponent(TArgs&&... mArgs);

		/// <summary>
		/// Tries to get a Component from this Entity.
		/// </summary>
		template<class T>
		T* GetComponent();	  
};

// Implementation for Templates is easiest within the header file.
// Its annoying, but its the only way I can get this to work.

template<class T, typename... TArgs>
T* Entity::AddComponent(TArgs&&... mArgs)
{
	// Create a new instance of this type and pass its arguments.
	T* component = new T(std::forward<TArgs>(mArgs)...);
	const std::string className = typeid(*component).name();
	const size_t startPos = className.find_last_of(" ") + 1;

	// Try use Dynamic Casting to get the base component.
	Component* componentBase = dynamic_cast<Component*>(component);
	if (componentBase != nullptr)
	{
		componentBase->entity = this;
		_components.push_back(componentBase);
		componentBase->Start();

		//Debug::Log(className.substr(startPos) + "(Component) was created.", c);
		return component;
	}

	// If it got here, it means the type given wasn't derived from component.
	Debug::LogError(className.substr(startPos) + " (Component) could not be created successfully. Not derived off Component class.", component);
	delete component;
	return nullptr;
}

template<class T>
T* Entity::GetComponent() 
{
	for (Component* c : _components)
	{
		if (dynamic_cast<T*>(c))
		{
			return static_cast<T*>(c);
		}
	}
	return nullptr;
}
#endif