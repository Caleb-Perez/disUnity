#include "pch.h"
#include "disUnityApplication.h"
#include "disUnityWindow.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"
#include "codeOpenGL/ImageOpenGL.h"
#include "Image.h"
#include "Shader.h"

namespace disUnity {

}

void disUnity::disUnityApplication::Initialize()
{
}

void disUnity::disUnityApplication::OnUpdate()
{
}

void disUnity::disUnityApplication::Shutdown()
{
}

void disUnity::disUnityApplication::Run() {
	disUnityWindow::Init();
	disUnityWindow::GetWindow()->Create(1000, 800);



	Shader sProg{"C:/Users/Caleb/source/repos/S24_Caleb_Perez/disUnity/Assets/Shaders/DefaultVertexShader", "C:/Users/Caleb/source/repos/S24_Caleb_Perez/disUnity/Assets/Shaders/DefaultFragmentShader"};



	disUnity::Image pic("C:/Users/Caleb/source/repos/S24_Caleb_Perez/disUnity/Assets/test.png");

	Initialize();

	while (true) {

		OnUpdate();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		sProg.Bind();
		glBindVertexArray(VAO);
		pic.Bind();

		disUnityWindow::GetWindow()->SwapBuffers();
		disUnityWindow::GetWindow()->PollEvents();
	}
	
	Shutdown();

	disUnityWindow::ShutDown();
}