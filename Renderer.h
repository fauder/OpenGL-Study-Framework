#pragma once

// GLAD Includes.
#include <glad/glad.h>

// GLFW Includes.
#include <GLFW/glfw3.h>

// Project Includes.
#include "Drawable.h"
#include "Graphics.h"

// std Includes.
#include <iostream>
#include <vector>

namespace Framework
{
	enum class PolygonMode
	{
		POINT = 0, LINE = 1, FILL = 2
	};

	class Renderer
	{
	public:
		Renderer( GLFWwindow*& window, const int width = 800, const int height = 600, const int pos_x = 0, const int pos_y = 0 );

		void Update( GLFWwindow* window ) const;
		void CleanUp() const;
		void AddDrawable( const Drawable& drawable );
		void SetPolygonMode( const PolygonMode mode ) const;
		void EnableDepthTest() const;
		void DisableDepthTest() const;

	private:
		/* GLAD needs the created window's context made current BEFORE it is initialized. */
		void InitializeGLAD() const;

	private:
		std::vector< Drawable > drawable_list;
	};
}
