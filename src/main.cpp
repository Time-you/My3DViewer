#include "ViewerWindow.h"
#include "OpenglRenderSystem.h"
#include "GeometryPrimitives.h"

#include <glm/gtc/matrix_transform.hpp>

// Яку фігуру показує в'ювер: перемикається клавішею Space
enum class Shape
{
    Cube,
    Pyramid
};

void renderScene(OpenglRenderSystem& rs, Shape shape)
{
    static const auto& cubeData = GeometryPrimitives::createCubeVertices();
    static const auto& pyramidData = GeometryPrimitives::createPyramidVertices();

    if (shape == Shape::Cube)
        rs.renderTriangleSoup(cubeData);
    else
        rs.renderTriangleSoup(pyramidData);
}

void moveCube(OpenglRenderSystem& rs, glm::vec3 offset)
{
	rs.setViewMatrix(glm::translate(rs.getViewMatrix(), offset));
}

int main()
{
	constexpr int width = 640;
	constexpr int height = 480;

	OpenglRenderSystem rs;
	ViewerWindow window("My3DViewer", width, height);

	Shape currentShape = Shape::Pyramid;

	window.setKeyCallback([&rs, &currentShape](KeyCode key, Action action, Modifier mods)
	{
		// Реагуємо на натискання та утримання клавіші, але не на її відпускання
		if (action == Action::Release)
			return;

		if (key == KeyCode::UP)
			moveCube(rs, { 0, 0.1, 0 });

		if (key == KeyCode::DOWN)
			moveCube(rs, { 0, -0.1, 0 });

		if (key == KeyCode::LEFT)
			moveCube(rs, { 0.1, 0, 0 });

		if (key == KeyCode::RIGHT)
			moveCube(rs, { -0.1, 0, 0 });

		if (key == KeyCode::Space)
			currentShape = (currentShape == Shape::Cube) ? Shape::Pyramid : Shape::Cube;
	});

	rs.init();
	rs.setupLight(0, glm::vec3( 0,5,0 ), glm::vec3( 1,0,0 ), glm::vec3( 0,1,0 ), glm::vec3( 0,0,1 ));
	rs.turnLight(0, true);

	// Камера трохи збоку та згори, щоб було видно кілька граней фігури
	glm::vec3 cameraPosition(2.0f, 2.0f, -3.0f);
	glm::vec3 lookAtCenter(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraUpVector(0.0f, 1.0f, 0.0f);

	glm::mat4 viewMatrix = glm::lookAt(cameraPosition, lookAtCenter, cameraUpVector);
	rs.setViewMatrix(viewMatrix);

	glm::mat4 projMatrix = glm::perspective(glm::radians(60.0f), float(width) / float(height), 0.1f, 500.f);
	rs.setProjectionMatrix(projMatrix);

	while (!glfwWindowShouldClose(window.getGLFWHandle()))
	{
		rs.setViewport(0, 0, window.getWidth(), window.getHeight());
		rs.clearDisplay(0.5f, 0.5f, 0.5f);
		renderScene(rs, currentShape);
		glfwSwapBuffers(window.getGLFWHandle());
		glfwWaitEvents();
	}

    return 0;
}
