#include "Taman.h"
#include "Mesh.h"
#include "Texture.h"

Mesh* prosotan1Mesh;
Mesh* prosotan2Mesh;
Mesh* prosotan3Mesh;
Mesh* prosotan4Mesh;
Mesh* prosotan5Mesh;
Mesh* prosotan6Mesh;
Mesh* prosotan7Mesh;
Mesh* prosotan8Mesh;
Mesh* prosotan9Mesh;
Mesh* prosotan10Mesh;
Mesh* prosotan11Mesh;
Mesh* prosotan12Mesh;
Mesh* prosotan13Mesh;
Mesh* prosotan14Mesh;
Mesh* prosotan15Mesh;
Mesh* prosotan16Mesh;
Mesh* prosotan17Mesh;
Mesh* prosotan18Mesh;
Mesh* kotakpasir1Mesh;
Mesh* kotakpasir2Mesh;
Mesh* kotakpasir3Mesh;
Mesh* langitMesh;
Mesh* jungkatjungkit1Mesh;
Mesh* jungkatjungkit2Mesh;
Mesh* jungkatjungkit3Mesh;
Mesh* jungkatjungkit4Mesh;
Mesh* jungkatjungkit5Mesh;
Mesh* jungkatjungkit6Mesh;
Mesh* jungkatjungkit7Mesh;
Mesh* ayunan1Mesh;
Mesh* ayunan2Mesh;
Mesh* ayunan3Mesh;
Mesh* ayunan4Mesh;
Mesh* ayunan5Mesh;
Mesh* ayunan6Mesh;
Mesh* ayunan7Mesh;
Mesh* ayunan8Mesh;
Mesh* ayunan9Mesh;
Mesh* ayunan10Mesh;
Texture* prosotan1Texture;
Texture* prosotan2Texture;
Texture* prosotan3Texture;
Texture* prosotan4Texture;
Texture* prosotan5Texture;
Texture* prosotan6Texture;
Texture* prosotan7Texture;
Texture* prosotan8Texture;
Texture* prosotan9Texture;
Texture* prosotan10Texture;
Texture* prosotan11Texture;
Texture* prosotan12Texture;
Texture* prosotan13Texture;
Texture* prosotan14Texture;
Texture* prosotan15Texture;
Texture* prosotan16Texture;
Texture* prosotan17Texture;
Texture* prosotan18Texture;
Texture* kotakpasir1Texture;
Texture* kotakpasir2Texture;
Texture* kotakpasir3Texture;
Texture* jungkatjungkit1Texture;
Texture* jungkatjungkit2Texture;
Texture* jungkatjungkit3Texture;
Texture* jungkatjungkit4Texture;
Texture* jungkatjungkit5Texture;
Texture* jungkatjungkit6Texture;
Texture* jungkatjungkit7Texture;
Texture* ayunan1Texture;
Texture* ayunan2Texture;
Texture* ayunan3Texture;
Texture* ayunan4Texture;
Texture* ayunan5Texture;
Texture* ayunan6Texture;
Texture* ayunan7Texture;
Texture* ayunan8Texture;
Texture* ayunan9Texture;
Texture* ayunan10Texture;
Texture* langitTexture;

Taman::Taman() {

}

Taman::~Taman() {
}

void Taman::Init() {
	shaderProgram = BuildShader("vertexShader.vert", "fragmentShader.frag", nullptr);

	BuildProsotan1();
	BuildProsotan2();
	BuildProsotan3();
	BuildProsotan4();
	BuildProsotan5();
	BuildProsotan6();
	BuildProsotan7();
	BuildProsotan8();
	BuildProsotan9();
	BuildProsotan10();
	BuildProsotan11();
	BuildProsotan12();
	BuildProsotan13();
	BuildProsotan14();
	BuildProsotan15();
	BuildProsotan16();
	BuildProsotan17();
	BuildProsotan18();
	BuildKotakPasir1();
	BuildKotakPasir2();
	BuildKotakPasir3();
	BuildJungkatJungkit1();
	BuildJungkatJungkit2();
	BuildJungkatJungkit3();
	BuildJungkatJungkit4();
	BuildJungkatJungkit5();
	BuildJungkatJungkit6();
	BuildJungkatJungkit7();
	BuildAyunan1();
	BuildAyunan2();
	BuildAyunan3();
	BuildAyunan4();
	BuildAyunan5();
	BuildAyunan6();
	BuildAyunan7();
	BuildAyunan8();
	BuildAyunan9();
	BuildAyunan10();
	BuildPlane();
	BuildLangit();
	InitCamera();
}

void Taman::DeInit() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Taman::ProcessInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
		if (fovy < 90) {
			fovy += 0.0005f;
		}
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		if (fovy > 0) {
			fovy -= 0.0005f;
		}
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		MoveCamera(CAMERA_SPEED);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		MoveCamera(-CAMERA_SPEED);
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		StrafeCamera(-CAMERA_SPEED);
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		StrafeCamera(CAMERA_SPEED);
	}

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		UpDownCamera(-0.001f);
	}

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		UpDownCamera(0.001f);
	}

	double mouseX, mouseY;
	double midX = screenWidth / 2;
	double midY = screenHeight / 2;
	float angleY = 0.0f;
	float angleZ = 0.0f;

	glfwGetCursorPos(window, &mouseX, &mouseY);
	if ((mouseX == midX) && (mouseY == midY)) {
		return;
	}

	glfwSetCursorPos(window, midX, midY);

	angleY = (float)((midX - mouseX)) / 1000;
	angleZ = (float)((midY - mouseY)) / 1000;

	viewCamY += angleZ * 2;

	if ((viewCamY - posCamY) > 8) {
		viewCamY = posCamY + 8;
	}
	if ((viewCamY - posCamY) < -8) {
		viewCamY = posCamY - 8;
	}
	RotateCamera(-angleY);
}

void Taman::Update(double deltaTime) {
	if (temp == 0) {
		angle += (float)((deltaTime * 1.5f) / 5000);
		if (angle > 0.35) {
			temp = 1;
		}
	}

	if (temp == 1) {
		angle -= (float)((deltaTime * 1.5f) / 5000);
		if (angle < -0.35) {
			temp = 0;
		}
	}
}

void Taman::Render() {
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);

	glm::mat4 projection = glm::perspective(fovy, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
	GLint projLoc = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glm::mat4 view = glm::lookAt(glm::vec3(posCamX, posCamY, posCamZ), glm::vec3(viewCamX, viewCamY, viewCamZ), glm::vec3(upCamX, upCamY, upCamZ));
	GLint viewLoc = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	DrawProsotan1();
	DrawProsotan2();
	DrawProsotan3();
	DrawProsotan4();
	DrawProsotan5();
	DrawProsotan6();
	DrawProsotan7();
	DrawProsotan8();
	DrawProsotan9();
	DrawProsotan10();
	DrawProsotan11();
	DrawProsotan12();
	DrawProsotan13();
	DrawProsotan14();
	DrawProsotan15();
	DrawProsotan16();
	DrawProsotan17();
	DrawProsotan18();
	DrawKotakPasir1();
	DrawKotakPasir2();
	DrawKotakPasir3();
	DrawJungkatJungkit1();
	DrawJungkatJungkit2();
	DrawJungkatJungkit3();
	DrawJungkatJungkit4();
	DrawJungkatJungkit5();
	DrawJungkatJungkit6();
	DrawJungkatJungkit7();
	DrawAyunan1();
	DrawAyunan2();
	DrawAyunan3();
	DrawAyunan4();
	DrawAyunan5();
	DrawAyunan6();
	DrawAyunan7();
	DrawAyunan8();
	DrawAyunan9();
	DrawAyunan10();
	DrawPlane();
	DrawLangit();

	glDisable(GL_DEPTH_TEST);
}

void Taman::BuildProsotan1() {

	prosotan1Texture = new Texture("prosotan.png");
	
	GLfloat vertices[] = {
		// front
		-2.0, -2.0, 0.5, 0, 0,  // 0
		-1.6, -2.0, 0.5, 1, 0,   // 1
		-1.6,  -1.9, 0.5, 1, 1,   // 2
		-2.0,  -1.9, 0.5, 0, 1,  // 3

		// back
		-2.0, -2.0, -0.5, 0, 0,  // 4
		-1.6, -2.0, -0.5, 1, 0,   // 5
		-1.6,  -1.9, -0.5, 1, 1,   // 6
		-2.0,  -1.9, -0.5, 0, 1,  // 7

		// bottom
		-2.0, -2.0, -0.5, 0, 0,  // 8
		-1.6, -2.0, -0.5, 1, 0,   // 9
		-1.6, -2.0, 0.5, 1, 1,   // 10
		-2.0, -2.0, 0.5, 0, 1,  // 11
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6, 4,  6, 7,  // back
		8, 10, 9, 8, 11, 10   // bottom
	};

	prosotan1Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan1()
{
	glUseProgram(shaderProgram);
	prosotan1Texture->Bind();
	
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(7, 0, 0)); 
	GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	prosotan1Mesh->Draw();
}

void Taman::BuildProsotan2() {
	
	prosotan2Texture = new Texture("prosotan.png");

	GLfloat vertices[] = {
		// front
		-1.6, -2.0, 0.5, 0, 0,  // 0
		-1.45, -1.95, 0.5, 1, 0,   // 1
		-1.45,  -1.85, 0.5, 1, 1,   // 2
		-1.6,  -1.9, 0.5, 0, 1,  // 3

		// back
		-1.6, -2.0, -0.5, 0, 0,  // 4
		-1.45, -1.95, -0.5, 1, 0,   // 5
		-1.45,  -1.85, -0.5, 1, 1,   // 6
		-1.6,  -1.9, -0.5, 0, 1,  // 7

		// bottom
		-1.6,  -2.0, -0.5, 0, 0,  // 8
		-1.45,  -1.95, -0.5, 1, 0,   // 9
		-1.45, -1.95, 0.5, 1, 1,   // 10
		-1.6, -2.0, 0.5, 0, 1,  // 11
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6, 4,  6, 7,  // back
		8, 10, 9, 8, 11, 10   // bottom
	};

	prosotan2Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan2()
{
	glUseProgram(shaderProgram);
	prosotan2Texture->Bind();
	prosotan2Mesh->Draw();
}

void Taman::BuildProsotan3() {
	
	prosotan3Texture = new Texture("prosotan-big.png");
	
	GLfloat vertices[] = {
		// front
		-1.45, -1.95, 0.5, 0, 0,   // 0
		 0.0,  0.0, 0.5, 3, 0,   // 1
		 0.0,  0.1, 0.5, 3, 3,   // 2
		-1.45, -1.85, 0.5, 0, 3,   // 3

		// back
		-1.45, -1.95, -0.5, 0, 0,   // 4
		0.0,  0.0, -0.5, 3, 0,   // 5
		0.0,  0.1, -0.5, 3, 3,   // 6
		-1.45, -1.85, -0.5, 0, 3,   // 7

		// bottom
		-1.45,  -1.95, -0.5, 0, 0,   // 8
		0.0,  0.0, -0.5, 3, 0,   // 9
		0.0, 0.0, 0.5, 3, 3,   // 10
		-1.45, -1.95, 0.5, 0, 3,   // 11
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6, 4,  6, 7,  // back
		8, 10, 9, 8, 11, 10   // bottom
	};

	prosotan3Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan3()
{
	glUseProgram(shaderProgram);
	prosotan3Texture->Bind();
	prosotan3Mesh->Draw();
}

void Taman::BuildProsotan4() {
	
	prosotan4Texture = new Texture("prosotan.png");
	
	GLfloat vertices[] = {
		// front
		0.1, 0.0, 0.5, 0, 0,   // 0
		0.6,  0.0, 0.5, 1, 0,   // 1
		0.6,  0.1, 0.5, 1, 1,   // 2
		0.1,  0.1, 0.5, 0, 1,   // 3

		// back
		0.1, 0.0, -0.5, 0, 0,   // 4
		0.6,  0.0, -0.5, 1, 0,   // 5
		0.6,  0.1, -0.5, 1, 1,   // 6
		0.1,  0.1, -0.5, 0, 1,   // 7

		// bottom
		0.0,  0.0, -0.5, 0, 0,   // 8
		0.7,  0.0, -0.5, 1, 0,   // 9
		0.7, 0.0, 0.5, 1, 1,   // 10
		0.0, 0.0, 0.5, 0, 1,   // 11
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6, 4,  6, 7,  // back
		8, 10, 9, 8, 11, 10   // bottom
	};

	prosotan4Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan4()
{
	glUseProgram(shaderProgram);
	prosotan4Texture->Bind();
	prosotan4Mesh->Draw();
}

void Taman::BuildProsotan5() {
	
	prosotan5Texture = new Texture("prosotan-besi-big.png");
	
	GLfloat vertices[] = {
		// front
		0.6, -2.0, 0.6, 0, 0,  // 0
		0.7, -2.0, 0.6, 1, 0,   // 1
		0.7,  0.35, 0.6, 1, 1,   // 2
		0.6,  0.30, 0.6, 0, 1,  // 3

		// right
		0.7, 0.35, 0.6, 0, 0,  // 6
		0.7, 0.35, 0.5, 1, 0,  // 7
		0.7, -2.0, 0.5, 1, 1,  // 4
		0.7, -2.0, 0.6, 0, 1,  // 5

		// back
		0.6, -2.0, 0.5, 0, 0,  // 8
		0.7, -2.0, 0.5, 1, 0,   // 9
		0.7,  0.35, 0.5, 1, 1,   // 10
		0.6,  0.30, 0.5, 0, 1,  // 11

		// left
		0.6, -2.0, 0.5, 0, 0,  // 12
		0.6, -2.0, 0.6, 1, 0,  // 13
		0.6, 0.30, 0.6, 1, 1,  // 14
		0.6, 0.30, 0.5, 0, 1,  // 15

		// bottom
		0.6, -2.0, 0.5, 0, 0, // 16
		0.7, -2.0, 0.5, 1, 0,  // 17
		0.7, -2.0, 0.6, 1, 1,  // 18
		0.6, -2.0, 0.6, 0, 1, // 19
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18   // bottom
	};

	prosotan5Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan5()
{
	glUseProgram(shaderProgram);
	prosotan5Texture->Bind();
	prosotan5Mesh->Draw();
}

void Taman::BuildProsotan6() {
	
	prosotan6Texture = new Texture("prosotan-besi-big.png");
	
	GLfloat vertices[] = {
		
		// front
		0.0, -2.0, 0.6, 0, 0,  // 0
		0.1, -2.0, 0.6, 1, 0,   // 1
		0.1,  0.30, 0.6, 1, 1,   // 2
		0.0,  0.35, 0.6, 0, 1,  // 3

		// right
		0.1, 0.30, 0.6, 0, 0,  // 4
		0.1, 0.30, 0.5, 1, 0,  // 5
		0.1, -2.0, 0.5, 1, 1,  // 6
		0.1, -2.0, 0.6, 0, 1,  // 7
		
		// back
		0.0, -2.0, 0.5, 0, 0,  // 8
		0.1, -2.0, 0.5, 1, 0,   // 9
		0.1,  0.30, 0.5, 1, 1,   // 10
		0.0,  0.35, 0.5, 0, 1,  // 11

		// left
		0.0, -2.0, 0.5, 0, 0,  // 12
		0.0, -2.0, 0.6, 1, 0,  // 13
		0.0, 0.35, 0.6, 1, 1,  // 14
		0.0, 0.35, 0.5, 0, 1,  // 15

		// bottom
		0.0, -2.0, 0.5, 0, 0, // 16
		0.1, -2.0, 0.5, 1, 0,  // 17
		0.1, -2.0, 0.6, 1, 1,  // 18
		0.0, -2.0, 0.6, 0, 1, // 19
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18   // bottom
	};

	prosotan6Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan6()
{
	glUseProgram(shaderProgram);
	prosotan6Texture->Bind();
	prosotan6Mesh->Draw();
}

void Taman::BuildProsotan7() {
	
	prosotan7Texture = new Texture("prosotan-besi-mini.png");
	
	GLfloat vertices[] = {
		// front
		0.6, 0.30, 0.6, 0, 0,  // 0
		0.7, 0.35, 0.6, 1, 0,   // 1
		0.6, 0.45, 0.6, 1, 1,   // 2
		0.55,  0.35, 0.6, 0, 1,  // 3

		// right
		0.6, 0.45, 0.6, 0, 0,   // 4
		0.6, 0.45, 0.5, 1, 0,   // 5
		0.7, 0.35, 0.5, 1, 1,   // 6
		0.7, 0.35, 0.6, 0, 1,   // 7

		// left
		0.6, 0.30, 0.5, 0, 0,  // 8
		0.6, 0.30, 0.6, 1, 0,  // 9
		0.55,  0.35, 0.6, 1, 1,  // 10
		0.55,  0.35, 0.5, 0, 1,  // 11

		// back
		0.6, 0.30, 0.5, 0, 0,  // 12
		0.7, 0.35, 0.5, 1, 0,   // 13
		0.6, 0.45, 0.5, 1, 1,   // 14
		0.55,  0.35, 0.5, 0, 1,  // 15
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8, 10, 9, 8, 11, 10,  // left
		12,  13,  14, 12,  14, 15,  // back
	};

	prosotan7Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan7()
{
	glUseProgram(shaderProgram);
	prosotan7Texture->Bind();
	prosotan7Mesh->Draw();
}

void Taman::BuildProsotan8() {
	
	prosotan8Texture = new Texture("prosotan-besi-mini.png");
	
	GLfloat vertices[] = {
		// front
		0.0, 0.35, 0.6, 0, 0,  // 0
		0.1, 0.30, 0.6, 1, 0,   // 1
		0.15, 0.35, 0.6, 1, 1,   // 2
		0.1, 0.45, 0.6, 0, 1,  // 3

		// right
		0.15, 0.35, 0.6, 0, 0,   // 4
		0.15, 0.35, 0.5, 1, 0,   // 5
		0.1, 0.30, 0.5, 1, 1,   // 6
		0.1, 0.30, 0.6, 0, 1,   // 7

		// left
		0.0, 0.35, 0.5, 0, 0,  // 8
		0.0, 0.35, 0.6, 0, 0,  // 9
		0.1, 0.45, 0.6, 0, 1,  // 10
		0.1, 0.45, 0.5, 0, 1,  // 11

		// back
		0.0, 0.35, 0.5, 0, 0,  // 12
		0.1, 0.30, 0.5, 1, 0,   // 13
		0.15, 0.35, 0.5, 1, 1,   // 14
		0.1, 0.45, 0.5, 0, 1,  // 15
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8, 10, 9, 8, 11, 10,  // left
		12,  13,  14, 12,  14, 15,  // back
	};

	prosotan8Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan8()
{
	glUseProgram(shaderProgram);
	prosotan8Texture->Bind();
	prosotan8Mesh->Draw();
}

void Taman::BuildProsotan9() {

	prosotan9Texture = new Texture("prosotan-besi-mini.png");

	GLfloat vertices[] = {
		// front
		0.15, 0.35, 0.6, 0, 0,  // 0
		0.55, 0.35, 0.6, 1, 0,   // 1
		0.6, 0.45, 0.6, 1, 1,   // 2
		0.1, 0.45, 0.6, 0, 1,  // 3

		// upper
		0.6, 0.45, 0.6, 0, 0,   // 4
		0.1, 0.45, 0.6, 1, 0,   // 5
		0.1, 0.45, 0.5, 1, 1,   // 6
		0.6, 0.45, 0.5, 0, 1,   // 7

		// bottom
		0.15, 0.4, 0.5, 0, 0,  // 8
		0.55, 0.4, 0.5, 0, 0,  // 9
		0.55, 0.4, 0.6, 0, 1,  // 10
		0.15, 0.4, 0.6, 0, 1,  // 11

		// back
		0.15, 0.35, 0.5, 0, 0,  // 12
		0.55, 0.35, 0.5, 1, 0,   // 13
		0.6, 0.45, 0.5, 1, 1,   // 14
		0.1, 0.45, 0.5, 0, 1,  // 15
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  7,  6,  4,  6,  5,   // upper
		8, 10, 9, 8, 11, 10,  // bottom
		12,  14,  13, 12,  15, 14,  // back
	};

	prosotan9Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan9()
{
	glUseProgram(shaderProgram);
	prosotan9Texture->Bind();
	prosotan9Mesh->Draw();
}

void Taman::BuildProsotan10() {
	
	prosotan10Texture = new Texture("prosotan-besi-big.png");
	
	GLfloat vertices[] = {
		// front
		0.6, -2.0, -0.5, 0, 0,  // 0
		0.7, -2.0, -0.5, 1, 0,   // 1
		0.7,  0.35, -0.5, 1, 1,   // 2
		0.6,  0.30, -0.5, 0, 1,  // 3

		// right
		0.7, 0.35, -0.5, 0, 0,  // 6
		0.7, 0.35, -0.6, 1, 0,  // 7
		0.7, -2.0, -0.6, 1, 1,  // 4
		0.7, -2.0, -0.5, 0, 1,  // 5

		// back
		0.6, -2.0, -0.6, 0, 0,  // 8
		0.7, -2.0, -0.6, 1, 0,   // 9
		0.7,  0.35, -0.6, 1, 1,   // 10
		0.6,  0.30, -0.6, 0, 1,  // 11

		// left
		0.6, -2.0, -0.6, 0, 0,  // 12
		0.6, -2.0, -0.5, 1, 0,  // 13
		0.6, 0.30, -0.5, 1, 1,  // 14
		0.6, 0.30, -0.6, 0, 1,  // 15

		// bottom
		0.6, -2.0, -0.6, 0, 0, // 16
		0.7, -2.0, -0.6, 1, 0,  // 17
		0.7, -2.0, -0.5, 1, 1,  // 18
		0.6, -2.0, -0.5, 0, 1, // 19
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18   // bottom
	};

	prosotan10Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan10()
{
	glUseProgram(shaderProgram);
	prosotan10Texture->Bind();
	prosotan10Mesh->Draw();
}

void Taman::BuildProsotan11() {
	
	prosotan11Texture = new Texture("prosotan-besi-big.png");

	GLfloat vertices[] = {
		// front
		0.0, -2.0, -0.5, 0, 0,  // 0
		0.1, -2.0, -0.5, 1, 0,   // 1
		0.1,  0.30, -0.5, 1, 1,   // 2
		0.0,  0.35, -0.5, 0, 1,  // 3

		// right
		0.1, 0.30, -0.5, 0, 0,  // 4
		0.1, 0.30, -0.6, 1, 0,  // 5
		0.1, -2.0, -0.6, 1, 1,  // 6
		0.1, -2.0, -0.5, 0, 1,  // 7

		// back
		0.0, -2.0, -0.6, 0, 0,  // 8
		0.1, -2.0, -0.6, 1, 0,   // 9
		0.1,  0.30, -0.6, 1, 1,   // 10
		0.0,  0.35, -0.6, 0, 1,  // 11

		// left
		0.0, -2.0, -0.6, 0, 0,  // 12
		0.0, -2.0, -0.5, 1, 0,  // 13
		0.0, 0.35, -0.5, 1, 1,  // 14
		0.0, 0.35, -0.6, 0, 1,  // 15

		// bottom
		0.0, -2.0, -0.6, 0, 0, // 16
		0.1, -2.0, -0.6, 1, 0,  // 17
		0.1, -2.0, -0.5, 1, 1,  // 18
		0.0, -2.0, -0.5, 0, 1, // 19
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18   // bottom
	};

	prosotan11Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan11()
{
	glUseProgram(shaderProgram);
	prosotan11Texture->Bind();
	prosotan11Mesh->Draw();
}

void Taman::BuildProsotan12() {
	
	prosotan12Texture = new Texture("prosotan-besi-mini.png");
	
	GLfloat vertices[] = {
		// front
		0.6, 0.30, -0.5, 0, 0,  // 0
		0.7, 0.35, -0.5, 1, 0,   // 1
		0.6, 0.45, -0.5, 1, 1,   // 2
		0.55,  0.35, -0.5, 0, 1,  // 3

		// right
		0.6, 0.45, -0.5, 0, 0,   // 4
		0.6, 0.45, -0.6, 1, 0,   // 5
		0.7, 0.35, -0.6, 1, 1,   // 6
		0.7, 0.35, -0.5, 0, 1,   // 7

		// left
		0.6, 0.30, -0.6, 0, 0,  // 8
		0.6, 0.30, -0.5, 1, 0,  // 9
		0.55, 0.35, -0.5, 1, 1,  // 10
		0.55, 0.35, -0.6, 0, 1,  // 11

		// back
		0.6, 0.30, -0.6, 0, 0,  // 12
		0.7, 0.35, -0.6, 1, 0,   // 13
		0.6, 0.45, -0.6, 1, 1,   // 14
		0.55, 0.35, -0.6, 0, 1,  // 15
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8, 10, 9, 8, 11, 10,  // left
		12,  13,  14, 12,  14, 15,  // back
	};

	prosotan12Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan12()
{
	glUseProgram(shaderProgram);
	prosotan12Texture->Bind();
	prosotan12Mesh->Draw();
}

void Taman::BuildProsotan13() {
	
	prosotan13Texture = new Texture("prosotan-besi-mini.png");
	
	GLfloat vertices[] = {
		// front
		0.0, 0.35, -0.5, 0, 0,  // 0
		0.1, 0.30, -0.5, 1, 0,   // 1
		0.15, 0.35, -0.5, 1, 1,   // 2
		0.1, 0.45, -0.5, 0, 1,  // 3

		// right
		0.15, 0.35, -0.5, 0, 0,   // 4
		0.15, 0.35, -0.6, 1, 0,   // 5
		0.1, 0.30, -0.6, 1, 1,   // 6
		0.1, 0.30, -0.5, 0, 1,   // 7

		// left
		0.0, 0.35, -0.6, 0, 0,  // 8
		0.0, 0.35, -0.5, 0, 0,  // 9
		0.1, 0.45, -0.5, 0, 1,  // 10
		0.1, 0.45, -0.6, 0, 1,  // 11

		// back
		0.0, 0.35, -0.6, 0, 0,  // 12
		0.1, 0.30, -0.6, 1, 0,   // 13
		0.15, 0.35, -0.6, 1, 1,   // 14
		0.1, 0.45, -0.6, 0, 1,  // 15
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8, 10, 9, 8, 11, 10,  // left
		12,  13,  14, 12,  14, 15,  // back
	};

	prosotan13Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan13()
{
	glUseProgram(shaderProgram);
	prosotan13Texture->Bind();
	prosotan13Mesh->Draw();
}

void Taman::BuildProsotan14() {

	prosotan14Texture = new Texture("prosotan-besi-mini.png");

	GLfloat vertices[] = {
		// front
		0.15, 0.35, -0.5, 0, 0,  // 0
		0.55, 0.35, -0.5, 1, 0,   // 1
		0.6, 0.45, -0.5, 1, 1,   // 2
		0.1, 0.45, -0.5, 0, 1,  // 3

		// upper
		0.6, 0.45, -0.5, 0, 0,   // 4
		0.1, 0.45, -0.5, 1, 0,   // 5
		0.1, 0.45, -0.6, 1, 1,   // 6
		0.6, 0.45, -0.6, 0, 1,   // 7

		// bottom
		0.15, 0.4, -0.6, 0, 0,  // 8
		0.55, 0.4, -0.6, 0, 0,  // 9
		0.55, 0.4, -0.5, 0, 1,  // 10
		0.15, 0.4, -0.5, 0, 1,  // 11

		// back
		0.15, 0.35, -0.6, 0, 0,  // 12
		0.55, 0.35, -0.6, 1, 0,   // 13
		0.6, 0.45, -0.6, 1, 1,   // 14
		0.1, 0.45, -0.6, 0, 1,  // 15
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  7,  6,  4,  6,  5,   // upper
		8, 10, 9, 8, 11, 10,  // bottom
		12,  14,  13, 12,  15, 14,  // back
	};

	prosotan14Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan14()
{
	glUseProgram(shaderProgram);
	prosotan14Texture->Bind();
	prosotan14Mesh->Draw();
}

void Taman::BuildProsotan15() {
	
	prosotan15Texture = new Texture("prosotan-besi-mini.png");
	
	GLfloat vertices[] = {
		// upper
		0.7, -0.3, 0.5, 0, 0,   // 0
		0.6, -0.3, 0.5, 1, 0,   // 1
		0.6, -0.3, -0.5, 1, 1,   // 2
		0.7, -0.3, -0.5, 0, 1,   // 3

		// right
		0.7, -0.3, 0.5, 0, 0,   // 4
		0.7, -0.3, -0.5, 1, 0,   // 5
		0.7, -0.4, -0.5, 1, 1,   // 6
		0.7, -0.4, 0.5, 0, 1,   // 7

		// bottom
		0.6, -0.4, -0.5, 0, 0,  // 8
		0.7, -0.4, -0.5, 1, 0,  // 9
		0.7, -0.4, 0.5, 1, 1,  // 10
		0.6, -0.4, 0.5, 0, 1,  // 11

		// left
		0.6, -0.4, -0.5, 0, 0,  // 12
		0.7, -0.4, 0.5, 1, 0,   // 13
		0.7, -0.3, 0.5, 1, 1,   // 14
		0.6, -0.3, -0.5, 0, 1,  // 15
	};

	unsigned int indices[] = {
		0,  3,  2,  0,  2,  1,   // upper
		4, 5, 6, 4, 6, 7,   // right
		8, 10, 9, 8, 11, 10,  // bottom
		12, 14, 13, 12, 15, 14,  // left
	};

	prosotan15Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan15()
{
	glUseProgram(shaderProgram);
	prosotan15Texture->Bind();
	prosotan15Mesh->Draw();
}

void Taman::BuildProsotan16() {

	prosotan16Texture = new Texture("prosotan-besi-mini.png");
	
	GLfloat vertices[] = {
		// upper
		0.7, -0.7, 0.5, 0, 0,   // 0
		0.6, -0.7, 0.5, 1, 0,   // 1
		0.6, -0.7, -0.5, 1, 1,   // 2
		0.7, -0.7, -0.5, 0, 1,   // 3

		// right
		0.7, -0.7, 0.5, 0, 0,   // 4
		0.7, -0.7, -0.5, 1, 0,   // 5
		0.7, -0.8, -0.5, 1, 1,   // 6
		0.7, -0.8, 0.5, 0, 1,   // 7

		// bottom
		0.6, -0.8, -0.5, 0, 0,  // 8
		0.7, -0.8, -0.5, 1, 0,  // 9
		0.7, -0.8, 0.5, 1, 1,  // 10
		0.6, -0.8, 0.5, 0, 1,  // 11

		// left
		0.6, -0.8, -0.5, 0, 0,  // 12
		0.7, -0.8, 0.5, 1, 0,   // 13
		0.7, -0.7, 0.5, 1, 1,   // 14
		0.6, -0.7, -0.5, 0, 1,  // 15
	};

	unsigned int indices[] = {
		0,  3,  2,  0,  2,  1,   // upper
		4, 5, 6, 4, 6, 7,   // right
		8, 10, 9, 8, 11, 10,  // bottom
		12, 14, 13, 12, 15, 14,  // left
	};

	prosotan16Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan16()
{
	glUseProgram(shaderProgram);
	prosotan16Texture->Bind();
	prosotan16Mesh->Draw();
}

void Taman::BuildProsotan17() {
	
	prosotan17Texture = new Texture("prosotan-besi-mini.png");

	GLfloat vertices[] = {
		// upper
		0.7, -1.1, 0.5, 0, 0,   // 0
		0.6, -1.1, 0.5, 1, 0,   // 1
		0.6, -1.1, -0.5, 1, 1,   // 2
		0.7, -1.1, -0.5, 0, 1,   // 3

		// right
		0.7, -1.1, 0.5, 0, 0,   // 4
		0.7, -1.1, -0.5, 1, 0,   // 5
		0.7, -1.2, -0.5, 1, 1,   // 6
		0.7, -1.2, 0.5, 0, 1,   // 7

		// bottom
		0.6, -1.2, -0.5, 0, 0,  // 8
		0.7, -1.2, -0.5, 1, 0,  // 9
		0.7, -1.2, 0.5, 1, 1,  // 10
		0.6, -1.2, 0.5, 0, 1,  // 11

		// left
		0.6, -1.2, -0.5, 0, 0,  // 12
		0.7, -1.2, 0.5, 1, 0,   // 13
		0.7, -1.1, 0.5, 1, 1,   // 14
		0.6, -1.1, -0.5, 0, 1,  // 15
	};

	unsigned int indices[] = {
		0,  3,  2,  0,  2,  1,   // upper
		4, 5, 6, 4, 6, 7,   // right
		8, 10, 9, 8, 11, 10,  // bottom
		12, 14, 13, 12, 15, 14,  // left
	};

	prosotan17Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan17()
{
	glUseProgram(shaderProgram);
	prosotan17Texture->Bind();
	prosotan17Mesh->Draw();
}

void Taman::BuildProsotan18() {

	prosotan18Texture = new Texture("prosotan-besi-mini.png");
	
	GLfloat vertices[] = {
		// upper
		0.7, -1.5, 0.5, 0, 0,   // 0
		0.6, -1.5, 0.5, 1, 0,   // 1
		0.6, -1.5, -0.5, 1, 1,   // 2
		0.7, -1.5, -0.5, 0, 1,   // 3

		// right
		0.7, -1.5, 0.5, 0, 0,   // 4
		0.7, -1.5, -0.5, 1, 0,   // 5
		0.7, -1.6, -0.5, 1, 1,   // 6
		0.7, -1.6, 0.5, 0, 1,   // 7

		// bottom
		0.6, -1.6, -0.5, 0, 0,  // 8
		0.7, -1.6, -0.5, 1, 0,  // 9
		0.7, -1.6, 0.5, 1, 1,  // 10
		0.6, -1.6, 0.5, 0, 1,  // 11

		// left
		0.6, -1.6, -0.5, 0, 0,  // 12
		0.7, -1.6, 0.5, 1, 0,   // 13
		0.7, -1.5, 0.5, 1, 1,   // 14
		0.6, -1.5, -0.5, 0, 1,  // 15
	};

	unsigned int indices[] = {
		0,  3,  2,  0,  2,  1,   // upper
		4, 5, 6, 4, 6, 7,   // right
		8, 10, 9, 8, 11, 10,  // bottom
		12, 14, 13, 12, 15, 14,  // left
	};

	prosotan18Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawProsotan18()
{
	glUseProgram(shaderProgram);
	prosotan18Texture->Bind();
	prosotan18Mesh->Draw();
}

void Taman::BuildKotakPasir1() {

	kotakpasir1Texture = new Texture("prosotan-besi-big.png");

	GLfloat vertices[] = {
		// front
		-1.5, -2.0, 1.5, 0, 0,  // 0
		1.5, -2.0, 1.5, 1, 0,   // 1
		1.5,  -1.5, 1.5, 1, 1,   // 2
		-1.5,  -1.5, 1.5, 0, 1,  // 3

		// right
		1.5,  -1.5, 1.5, 0, 0,   // 2
		1.5,  -1.5, -1.5, 1, 0,   // 2
		1.5,  -2.0, -1.5, 1, 1,  // 4
		1.5,  -2.0, 1.5, 0, 1,  // 5

		// back
		-1.5, -2.0, -1.5, 0, 0,  // 0
		1.5, -2.0, -1.5, 1, 0,   // 1
		1.5,  -1.5, -1.5, 1, 1,   // 2
		-1.5,  -1.5, -1.5, 0, 1,  // 3
	
		// left
		-1.5, -2.0, -1.5, 0, 0,  // 12
		-1.5, -2.0, 1.5, 1, 0,  // 13
		-1.5, -1.5, 1.5, 1, 1,  // 14
		-1.5, -1.5, -1.5, 0, 1,  // 15

		// bottom
		-1.5, -2.0, -1.5, 0, 0, // 16
		1.5, -2.0, -1.5, 1, 0,  // 17
		1.5, -2.0, 1.5, 1, 1,  // 18
		-1.5, -2.0, 1.5, 0, 1, // 19
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18   // bottom
	};

	kotakpasir1Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawKotakPasir1()
{
	glUseProgram(shaderProgram);
	kotakpasir1Texture->Bind();

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(1, 0, 4)); 
	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	kotakpasir1Mesh->Draw();
}

void Taman::BuildKotakPasir2() {
	
	kotakpasir2Texture = new Texture("sand.png");
	
	GLfloat vertices[] = {
		1.5, -1.7, 1.5, 0, 0,  // 0
		-1.5, -1.7, 1.5, 1, 0,   // 1
		-1.5,  -1.7, -1.5, 1, 1,   // 2
		1.5,  -1.7, -1.5, 0, 1,  // 3
	};

	unsigned int indices[] = {
		0,  3,  2,  0,  2,  1,  
	};

	kotakpasir2Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawKotakPasir2()
{
	glUseProgram(shaderProgram);
	kotakpasir2Texture->Bind();
	kotakpasir2Mesh->Draw();
}

void Taman::BuildKotakPasir3() {
	
	kotakpasir3Texture = new Texture("ember.png");

	GLfloat vertices[] = {
		// front
		0.8, -1.7, -0.3, 0, 0,  // 0
		1.0, -1.7, -0.3, 1, 0,   // 1
		1.1,  -1.3, -0.2, 1, 1,   // 2
		0.7,  -1.3, -0.2, 0, 1,  // 3

		// right
		1.1,  -1.3, -0.2, 0, 0,   // 2
		1.1,  -1.3, -0.6, 1, 0,   // 2
		1.0,  -1.7, -0.5, 1, 1,  // 4
		1.0,  -1.7, -0.3, 0, 1,  // 5

		// back
		0.8, -1.7, -0.5, 0, 0,  // 0
		1.0, -1.7, -0.5, 1, 0,   // 1
		1.1,  -1.3, -0.6, 1, 1,   // 2
		0.7,  -1.3, -0.6, 0, 1,  // 3

		// left
		 0.8, -1.7, -0.5, 0, 0,  // 12
		 0.8, -1.7, -0.3, 1, 0,  // 13
		 0.7, -1.3, -0.2, 1, 1,  // 14
		 0.7, -1.3, -0.6, 0, 1,  // 15

		// bottom
		0.8, -1.7, -0.5, 0, 0, // 16
		1.0, -1.7, -0.5, 1, 0,  // 17
		1.0, -1.7, -0.3, 1, 1,  // 18
		0.8, -1.7, -0.3, 0, 1, // 19
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18   // bottom
	};

	kotakpasir3Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawKotakPasir3()
{
	glUseProgram(shaderProgram);
	kotakpasir3Texture->Bind();
	kotakpasir3Mesh->Draw();
}

void Taman::BuildJungkatJungkit1() {
	
	jungkatjungkit1Texture = new Texture("penyangga-jungkat-jungkit.png");

	GLfloat vertices[] = {
		// front
		-1.95, -2.0, 0.8, 0, 0,  // 0
		-1.75, -2.0, 0.8, 1, 0,   // 1
		-1.75,  -0.7, 0.8, 1, 1,   // 2
		-1.95,  -0.7, 0.8, 0, 1,  // 3

		// right
		-1.75,  -0.7, 0.8, 0, 0,   // 4
		-1.75,  -0.7, 0.5, 1, 0,   // 5
		-1.75, -2.0, 0.5, 1, 1,   // 6
		-1.75, -2.0, 0.8, 0, 1,   // 7

		// back
		-1.95, -2.0, 0.5, 0, 0,  // 8
		-1.75, -2.0, 0.5, 1, 0,   // 9
		-1.75,  -0.7, 0.5, 1, 1,   // 10
		-1.95,  -0.7, 0.5, 0, 1,  // 11

		// left
		-1.95, -2.0, 0.5, 0, 0,  // 12
		-1.95, -2.0, 0.8, 1, 0,  // 13
		-1.95,  -0.7, 0.8, 1, 1,  // 14
		-1.95,  -0.7, 0.5, 0, 1,  // 15

		// upper
		-1.75,  -0.7, 0.8, 0, 0,   // 16
		-1.95,  -0.7, 0.8, 1, 0,  // 17
		-1.95,  -0.7, 0.5, 1, 1,  // 18
		-1.75,  -0.7, 0.5, 0, 1,   // 19

		// bottom
		-1.95, -2.0, 0.5, 0, 0,  // 20
		-1.75, -2.0, 0.5, 1, 0,   // 21
		-1.75, -2.0, 0.8, 1, 1,   // 22
		-1.95, -2.0, 0.8, 0, 1,  // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	jungkatjungkit1Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawJungkatJungkit1()
{
	glUseProgram(shaderProgram);
	jungkatjungkit1Texture->Bind();

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(-3, 0, 0)); 
	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	jungkatjungkit1Mesh->Draw();
}

void Taman::BuildJungkatJungkit2() {

	jungkatjungkit2Texture = new Texture("penyangga-jungkat-jungkit.png");

	GLfloat vertices[] = {
		// front
		-1.95, -2.0, -0.8, 0, 0,  // 0
		-1.75, -2.0, -0.8, 1, 0,   // 1
		-1.75,  -0.7, -0.8, 1, 1,   // 2
		-1.95,  -0.7, -0.8, 0, 1,  // 3

		// right
		-1.75,  -0.7, -0.8, 0, 0,   // 4
		-1.75,  -0.7, -0.5, 1, 0,   // 5
		-1.75, -2.0, -0.5, 1, 1,   // 6
		-1.75, -2.0, -0.8, 0, 1,   // 7

		// back
		-1.95, -2.0, -0.5, 0, 0,  // 8
		-1.75, -2.0, -0.5, 1, 0,   // 9
		-1.75,  -0.7, -0.5, 1, 1,   // 10
		-1.95,  -0.7, -0.5, 0, 1,  // 11

		// left
		-1.95, -2.0, -0.5, 0, 0,  // 12
		-1.95, -2.0, -0.8, 1, 0,  // 13
		-1.95,  -0.7, -0.8, 1, 1,  // 14
		-1.95,  -0.7, -0.5, 0, 1,  // 15

		// upper
		-1.75,  -0.7, -0.8, 0, 0,   // 16
		-1.95,  -0.7, -0.8, 1, 0,  // 17
		-1.95,  -0.7, -0.5, 1, 1,  // 18
		-1.75,  -0.7, -0.5, 0, 1,   // 19

		// bottom
		-1.95, -2.0, -0.5, 0, 0,  // 20
		-1.75, -2.0, -0.5, 1, 0,   // 21
		-1.75, -2.0, -0.8, 1, 1,   // 22
		-1.95, -2.0, -0.8, 0, 1,  // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	jungkatjungkit2Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawJungkatJungkit2()
{
	glUseProgram(shaderProgram);
	jungkatjungkit2Texture->Bind();
	jungkatjungkit2Mesh->Draw();
}

void Taman::BuildJungkatJungkit3() {

	jungkatjungkit3Texture = new Texture("prosotan.png");

	GLfloat vertices[] = {
		// front
		-2.6, -0.1, 0.5, 0, 0,  // 0
		2.6, -0.1, 0.5, 4, 0,   // 1
		2.6, 0.1, 0.5, 4, 4,   // 2
		-2.6, 0.1, 0.5, 0, 4,  // 3

		// right
		2.6, 0.1, 0.5, 0, 0,   // 4
		2.6, 0.1, -0.5, 4, 0,   // 5
		2.6, -0.1, -0.5, 4, 4,   // 6
		2.6, -0.1, 0.5, 0, 4,   // 7

		// back
		-2.6, -0.1, -0.5, 0, 0,  // 8
		2.6, -0.1, -0.5, 4, 0,   // 9
		2.6, 0.1, -0.5, 4, 4,   // 10
		-2.6, 0.1, -0.5, 0, 4,  // 11

		// left
		-2.6, -0.1, -0.5, 0, 0,  // 12
		-2.6, -0.1, 0.5, 4, 0,  // 13
		-2.6, 0.1, 0.5, 4, 4,  // 14
		-2.6, 0.1, -0.5, 0, 4,  // 15

		// upper
		2.6, 0.1, 0.5, 0, 0,   // 16
		-2.6, 0.1, 0.5, 4, 0,  // 17
		-2.6, 0.1, -0.5, 4, 4,  // 18
		2.6, 0.1, -0.5, 0, 4,   // 19

		// bottom
		-2.6, -0.1, -0.5, 0, 0,  // 20
		2.6, -0.1, -0.5, 4, 0,   // 21
		2.6, -0.1, 0.5, 4, 4,   // 22
		-2.6, -0.1, 0.5, 0, 4,  // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	jungkatjungkit3Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawJungkatJungkit3()
{
	glUseProgram(shaderProgram);
	jungkatjungkit3Texture->Bind();

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(-4.85, -1, 0));
	model = glm::rotate(model, angle, glm::vec3(0, 0, 1)); 
	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	jungkatjungkit3Mesh->Draw();
}

void Taman::BuildJungkatJungkit4() {

	jungkatjungkit4Texture = new Texture("pegangan-jungkat-jungkit.png");

	GLfloat vertices[] = {
		// front
		1.5, 0.1, 0.05, 0, 0,  // 0
		1.6, 0.1, 0.05, 1, 0,   // 1
		1.6, 0.4, 0.05, 1, 1,   // 2
		1.5, 0.4, 0.05, 0, 1,  // 3

		// right
		1.6, 0.4, 0.05, 0, 0,   // 4
		1.6, 0.4, -0.05, 1, 0,   // 5
		1.6, 0.1, -0.05, 1, 1,   // 6
		1.6, 0.1, 0.05, 0, 1,   // 7

		// back
		1.5, 0.1, -0.05, 0, 0,  // 8
		1.6, 0.1, -0.05, 1, 0,   // 9
		1.6, 0.4, -0.05, 1, 1,   // 10
		1.5, 0.4, -0.05, 0, 1,  // 11

		// left
		1.5, 0.1, -0.05, 0, 0,  // 12
		1.5, 0.1, 0.05, 1, 0,  // 13
		1.5, 0.4, 0.05, 1, 1,  // 14
		1.5, 0.4, -0.05, 0, 1,  // 15

		// upper
		1.6, 0.4, 0.05, 0, 0,   // 16
		1.5, 0.4, 0.05, 1, 0,  // 17
		1.5, 0.4, -0.05, 1, 1,  // 18
		1.6, 0.4, -0.05, 0, 1,   // 19

		// bottom
		1.5, 0.1, -0.05, 0, 0,  // 20
		1.6, 0.1, -0.05, 1, 0,   // 21
		1.6, 0.1, 0.05, 1, 1,   // 22
		1.5, 0.1, 0.05, 0, 1,  // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	jungkatjungkit4Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawJungkatJungkit4()
{
	glUseProgram(shaderProgram);
	jungkatjungkit4Texture->Bind();
	jungkatjungkit4Mesh->Draw();
}

void Taman::BuildJungkatJungkit5() {

	jungkatjungkit5Texture = new Texture("pegangan-jungkat-jungkit.png");

	GLfloat vertices[] = {
		// front
		1.5, 0.4, 0.5, 0, 0,  // 0
		1.6, 0.4, 0.5, 1, 0,   // 1
		1.6, 0.5, 0.5, 1, 1,   // 2
		1.5, 0.5, 0.5, 0, 1,  // 3

		// right
		1.6, 0.5, 0.5, 0, 0,   // 4
		1.6, 0.5, -0.5, 1, 0,   // 5
		1.6, 0.4, -0.5, 1, 1,   // 6
		1.6, 0.4, 0.5, 0, 1,   // 7

		// back
		1.5, 0.4, -0.5, 0, 0,  // 8
		1.6, 0.4, -0.5, 1, 0,   // 9
		1.6, 0.5, -0.5, 1, 1,   // 10
		1.5, 0.5, -0.5, 0, 1,  // 11

		// left
		1.5, 0.4, -0.5, 0, 0,  // 12
		1.5, 0.4, 0.5, 1, 0,  // 13
		1.5, 0.5, 0.5, 1, 1,  // 14
		1.5, 0.5, -0.5, 0, 1,  // 15

		// upper
		1.6, 0.5, 0.5, 0, 0,   // 16
		1.5, 0.5, 0.5, 1, 0,  // 17
		1.5, 0.5, -0.5, 1, 1,  // 18
		1.6, 0.5, -0.5, 0, 1,   // 19

		// bottom
		1.5, 0.4, -0.5, 0, 0,  // 20
		1.6, 0.4, -0.5, 1, 0,   // 21
		1.6, 0.4, 0.5, 1, 1,   // 22
		1.5, 0.4, 0.5, 0, 1,  // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	jungkatjungkit5Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawJungkatJungkit5()
{
	glUseProgram(shaderProgram);
	jungkatjungkit5Texture->Bind();
	jungkatjungkit5Mesh->Draw();
}

void Taman::BuildJungkatJungkit6() {

	jungkatjungkit6Texture = new Texture("pegangan-jungkat-jungkit.png");

	GLfloat vertices[] = {
		// front
		-1.6, 0.1, 0.05, 0, 0,  // 0
		-1.5, 0.1, 0.05, 1, 0,   // 1
		-1.5, 0.4, 0.05, 1, 1,   // 2
		-1.6, 0.4, 0.05, 0, 1,  // 3

		// right
		-1.5, 0.4, 0.05, 0, 0,   // 4
		-1.5, 0.4, -0.05, 1, 0,   // 5
		-1.5, 0.1, -0.05, 1, 1,   // 6
		-1.5, 0.1, 0.05, 0, 1,   // 7

		// back
		-1.6, 0.1, -0.05, 0, 0,  // 8
		-1.5, 0.1, -0.05, 1, 0,   // 9
		-1.5, 0.4, -0.05, 1, 1,   // 10
		-1.6, 0.4, -0.05, 0, 1,  // 11

		// left
		-1.6, 0.1, -0.05, 0, 0,  // 12
		-1.6, 0.1, 0.05, 1, 0,  // 13
		-1.6, 0.4, 0.05, 1, 1,  // 14
		-1.6, 0.4, -0.05, 0, 1,  // 15

		// upper
		-1.5, 0.4, 0.05, 0, 0,   // 16
		-1.6, 0.4, 0.05, 1, 0,  // 17
		-1.6, 0.4, -0.05, 1, 1,  // 18
		-1.5, 0.4, -0.05, 0, 1,   // 19

		// bottom
		-1.6, 0.1, -0.05, 0, 0,  // 20
		-1.5, 0.1, -0.05, 1, 0,   // 21
		-1.5, 0.1, 0.05, 1, 1,   // 22
		-1.6, 0.1, 0.05, 0, 1,  // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	jungkatjungkit6Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawJungkatJungkit6()
{
	glUseProgram(shaderProgram);
	jungkatjungkit6Texture->Bind();
	jungkatjungkit6Mesh->Draw();
}

void Taman::BuildJungkatJungkit7() {

	jungkatjungkit7Texture = new Texture("pegangan-jungkat-jungkit.png");

	GLfloat vertices[] = {
		// front
		-1.6, 0.4, 0.5, 0, 0,  // 0
		-1.5, 0.4, 0.5, 1, 0,   // 1
		-1.5, 0.5, 0.5, 1, 1,   // 2
		-1.6, 0.5, 0.5, 0, 1,  // 3

		// right
		-1.5, 0.5, 0.5, 0, 0,   // 4
		-1.5, 0.5, -0.5, 1, 0,   // 5
		-1.5, 0.4, -0.5, 1, 1,   // 6
		-1.5, 0.4, 0.5, 0, 1,   // 7

		// back
		-1.6, 0.4, -0.5, 0, 0,  // 8
		-1.5, 0.4, -0.5, 1, 0,   // 9
		-1.5, 0.5, -0.5, 1, 1,   // 10
		-1.6, 0.5, -0.5, 0, 1,  // 11

		// left
		-1.5, 0.4, -0.5, 0, 0,  // 12
		-1.5, 0.4, 0.5, 1, 0,  // 13
		-1.5, 0.5, 0.5, 1, 1,  // 14
		-1.5, 0.5, -0.5, 0, 1,  // 15

		// upper
		-1.5, 0.5, 0.5, 0, 0,   // 16
		-1.6, 0.5, 0.5, 1, 0,  // 17
		-1.6, 0.5, -0.5, 1, 1,  // 18
		-1.5, 0.5, -0.5, 0, 1,   // 19

		// bottom
		-1.6, 0.4, -0.5, 0, 0,  // 20
		-1.5, 0.4, -0.5, 1, 0,   // 21
		-1.5, 0.4, 0.5, 1, 1,   // 22
		-1.6, 0.4, 0.5, 0, 1,  // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	jungkatjungkit7Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawJungkatJungkit7()
{
	glUseProgram(shaderProgram);
	jungkatjungkit7Texture->Bind();
	jungkatjungkit7Mesh->Draw();
}

void Taman::BuildAyunan1() {
	
	ayunan1Texture = new Texture("prosotan.png");
	
	GLfloat vertices[] = {
		// front
		-1.5, -2.0, 1, 0, 0,  // 0
		-1.3, -2.0, 1, 1, 0,   // 1
		-1.3,  1, 1, 1, 1,   // 2
		-1.5,  1, 1, 0, 1,  // 3

		// right
		-1.3, 1, 1, 0, 0,  // 4
		-1.3, 1, 0.8, 1, 0,  // 5
		-1.3, -2.0, 0.8, 1, 1,  // 6
		-1.3, -2.0, 1, 0, 1,  // 7

		// back
		-1.5, -2.0, 0.8, 0, 0,  // 8
		-1.3, -2.0, 0.8, 1, 0,   // 9
		-1.3,  1, 0.8, 1, 1,   // 10
		-1.5,  1, 0.8, 0, 1,  // 11

		// left
		-1.3, -2.0, 0.8, 0, 0,  // 12
		-1.5, -2.0, 1, 1, 0,  // 13
		-1.5, 1, 1, 1, 1,  // 14
		-1.3, 1, 0.8, 0, 1,  // 15

		// bottom
		-1.5, -2.0, 0.8, 0, 0, // 16
		-1.3, -2.0, 0.8, 1, 0,  // 17
		-1.3, -2.0, 1, 1, 1,  // 18
		-1.5, -2.0, 1, 0, 1, // 19
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18   // bottom

	};

	ayunan1Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawAyunan1()
{
	glUseProgram(shaderProgram);
	ayunan1Texture->Bind();

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(1, 0, -4)); 
	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	ayunan1Mesh->Draw();
}

void Taman::BuildAyunan2() {

	ayunan2Texture = new Texture("prosotan.png");
	
	GLfloat vertices[] = {
		// front
		-1.5, -2.0, -1, 0, 0,  // 0
		-1.3, -2.0, -1, 1, 0,   // 1
		-1.3,  1, -1, 1, 1,   // 2
		-1.5,  1, -1, 0, 1,  // 3

		// right
		-1.3, 1, -1, 0, 0,  // 4
		-1.3, 1, -0.8, 1, 0,  // 5
		-1.3, -2.0, -0.8, 1, 1,  // 6
		-1.3, -2.0, -1, 0, 1,  // 7

		// back
		-1.5, -2.0, -0.8, 0, 0,  // 8
		-1.3, -2.0, -0.8, 1, 0,   // 9
		-1.3,  1, -0.8, 1, 1,   // 10
		-1.5,  1, -0.8, 0, 1,  // 11

		// left
		-1.5, -2.0, -0.8, 0, 0,  // 12
		-1.5, -2.0, -1, 1, 0,  // 13
		-1.5, 1, -1, 1, 1,  // 14
		-1.5, 1, -0.8, 0, 1,  // 15

		// bottom
		-1.5, -2.0, -0.8, 0, 0, // 16
		-1.3, -2.0, -0.8, 1, 0,  // 17
		-1.3, -2.0, -1, 1, 1,  // 18
		-1.5, -2.0, -1, 0, 1, // 19
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18   // bottom

	};

	ayunan2Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawAyunan2()
{
	glUseProgram(shaderProgram);
	ayunan2Texture->Bind();
	ayunan2Mesh->Draw();
}

void Taman::BuildAyunan3() {

	ayunan3Texture = new Texture("prosotan.png");
	
	GLfloat vertices[] = {
		// front
		1.5, -2.0, 1, 0, 0,  // 0
		1.3, -2.0, 1, 1, 0,   // 1
		1.3,  1, 1, 1, 1,   // 2
		1.5,  1, 1, 0, 1,  // 3

		// right
		1.3, 1, 1, 0, 0,  // 4
		1.3, 1, 0.8, 1, 0,  // 5
		1.3, -2.0, 0.8, 1, 1,  // 6
		1.3, -2.0, 1, 0, 1,  // 7

		// back
		1.5, -2.0, 0.8, 0, 0,  // 8
		1.3, -2.0, 0.8, 1, 0,   // 9
		1.3,  1, 0.8, 1, 1,   // 10
		1.5,  1, 0.8, 0, 1,  // 11

		// left
		1.5, -2.0, 0.8, 0, 0,  // 12
		1.5, -2.0, 1, 1, 0,  // 13
		1.5, 1, 1, 1, 1,  // 14
		1.5, 1, 0.8, 0, 1,  // 15

		// bottom
		1.5, -2.0, 0.8, 0, 0, // 16
		1.3, -2.0, 0.8, 1, 0,  // 17
		1.3, -2.0, 1, 1, 1,  // 18
		1.5, -2.0, 1, 0, 1, // 19
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18   // bottom

	};

	ayunan3Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawAyunan3()
{
	glUseProgram(shaderProgram);
	ayunan3Texture->Bind();
	ayunan3Mesh->Draw();
}

void Taman::BuildAyunan4() {
	
	ayunan4Texture = new Texture("prosotan.png");
	
	GLfloat vertices[] = {
		// front
		1.5, -2.0, -1, 0, 0,  // 0
		1.3, -2.0, -1, 1, 0,   // 1
		1.3,  1, -1, 1, 1,   // 2
		1.5,  1, -1, 0, 1,  // 3

		// right
		1.3, 1, -1, 0, 0,  // 4
		1.3, 1, -0.8, 1, 0,  // 5
		1.3, -2.0, -0.8, 1, 1,  // 6
		1.3, -2.0, -1, 0, 1,  // 7

		// back
		1.5, -2.0, -0.8, 0, 0,  // 8
		1.3, -2.0, -0.8, 1, 0,   // 9
		1.3,  1, -0.8, 1, 1,   // 10
		1.5,  1, -0.8, 0, 1,  // 11

		// left
		1.5, -2.0, -0.8, 0, 0,  // 12
		1.5, -2.0, -1, 1, 0,  // 13
		1.5, 1, -1, 1, 1,  // 14
		1.5, 1, -0.8, 0, 1,  // 15

		// bottom
		1.5, -2.0, -0.8, 0, 0, // 16
		1.3, -2.0, -0.8, 1, 0,  // 17
		1.3, -2.0, -1, 1, 1,  // 18
		1.5, -2.0, -1, 0, 1, // 19
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18   // bottom

	};

	ayunan4Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawAyunan4()
{
	glUseProgram(shaderProgram);
	ayunan4Texture->Bind();
	ayunan4Mesh->Draw();
}

void Taman::BuildAyunan5() {
	
	ayunan5Texture = new Texture("prosotan.png");
	
	GLfloat vertices[] = {
		// front
		-1.5, 1.2, 1, 0, 0,  // 0
		-1.3, 1.2, 1, 1, 0,   // 1
		-1.3,  1, 1, 1, 1,   // 2
		-1.5,  1, 1, 0, 1,  // 3

		// right
		-1.3, 1, 1, 0, 0,  // 4
		-1.3, 1, -1, 1, 0,  // 5
		-1.3, 1.2, -1, 1, 1,  // 6
		-1.3, 1.2, 1, 0, 1,  // 7

		// back
		-1.5, 1.2, -1, 0, 0,  // 8
		-1.3, 1.2, -1, 1, 0,   // 9
		-1.3,  1, -1, 1, 1,   // 10
		-1.5,  1, -1, 0, 1,  // 11

		// left
		-1.5, 1.2, -1, 0, 0,  // 12
		-1.5, 1.2, 1, 1, 0,  // 13
		-1.5, 1, 1, 1, 1,  // 14
		-1.5, 1, -1, 0, 1,  // 15

		// upper
		-1.5, 1.2, 1, 0, 0, // 16
		-1.3, 1.2, 1, 1, 0,  // 17
		-1.3, 1.2, -1, 1, 1,  // 18
		-1.5, 1.2, -1, 0, 1, // 19
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18   // bottom

	};

	ayunan5Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawAyunan5()
{
	glUseProgram(shaderProgram);
	ayunan5Texture->Bind();
	ayunan5Mesh->Draw();
}

void Taman::BuildAyunan6() {
	
	ayunan6Texture = new Texture("prosotan.png");
	
	GLfloat vertices[] = {
		// front
		1.5, 1.2, 1, 0, 0,  // 0
		1.3, 1.2, 1, 1, 0,   // 1
		1.3,  1, 1, 1, 1,   // 2
		1.5,  1, 1, 0, 1,  // 3

		// right
		1.3, 1, 1, 0, 0,  // 4
		1.3, 1, -1, 1, 0,  // 5
		1.3, 1.2, -1, 1, 1,  // 6
		1.3, 1.2, 1, 0, 1,  // 7

		// back
		1.5, 1.2, -1, 0, 0,  // 8
		1.3, 1.2, -1, 1, 0,   // 9
		1.3,  1, -1, 1, 1,   // 10
		1.5,  1, -1, 0, 1,  // 11

		// left
		1.5, 1.2, -1, 0, 0,  // 12
		1.5, 1.2, 1, 1, 0,  // 13
		1.5, 1, 1, 1, 1,  // 14
		1.5, 1, -1, 0, 1,  // 15

		// upper
		1.5, 1.2, 1, 0, 0, // 16
		1.3, 1.2, 1, 1, 0,  // 17
		1.3, 1.2, -1, 1, 1,  // 18
		1.5, 1.2, -1, 0, 1, // 19
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18   // bottom

	};

	ayunan6Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawAyunan6()
{
	glUseProgram(shaderProgram);
	ayunan6Texture->Bind();
	ayunan6Mesh->Draw();
}

void Taman::BuildAyunan7() {
	
	ayunan7Texture = new Texture("prosotan-besi-big.png");
	
	GLfloat vertices[] = {
		// front
		1.3, 1, 0.1, 0, 0,  // 0
		-1.3, 1, 0.1, 1, 0,   // 1
		-1.3,  1.2, 0.1, 1, 1,   // 2
		1.3,  1.2, 0.1, 0, 1,  // 3

		// bottom
		-1.3, 1, 0.1, 0, 0,  // 4
		-1.3, 1, -0.1, 1, 0,  // 5
		1.3, 1, -0.1, 1, 1,  // 6
		1.3, 1, 0.1, 0, 1,  // 7

		// back
		-1.3, 1, -0.1, 0, 0,  // 8
		1.3, 1, -0.1, 1, 0,   // 9
		1.3,  1.2, -0.1, 1, 1,   // 10
		-1.3,  1.2, -0.1, 0, 1,  // 11

		// upper
		-1.3, 1.2, 0.1, 0, 0, // 12
		1.3, 1.2, 0.1, 1, 0,  // 13
		1.3, 1.2, -0.1, 1, 1,  // 14
		-1.3, 1.2, -0.1, 0, 1, // 15
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // bottom
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left

	};

	ayunan7Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawAyunan7()
{
	glUseProgram(shaderProgram);
	ayunan7Texture->Bind();
	ayunan7Mesh->Draw();
}

void Taman::BuildAyunan8() {

	ayunan8Texture = new Texture("pegangan-jungkat-jungkit.png");

	GLfloat vertices[] = {
		// front
		-0.7, -1.3, 0.0125, 0, 0,  // 0
		-0.65, -1.3, 0.0125, 1, 0,   // 1
		-0.65,  1, 0.0125, 1, 1,   // 2
		-0.7,  1, 0.0125, 0, 1,  // 3

		// right
		-0.65, 1, -0.0125, 0, 0,  // 4
		-0.65, 1, 0.0125, 1, 0,  // 5
		-0.65, -1.3, 0.0125, 1, 1,  // 6
		-0.65, -1.3, -0.0125, 0, 1,  // 7

		// back
		-0.7, -1.3, -0.0125, 0, 0,  // 8
		-0.65, -1.3, -0.0125, 1, 0,   // 9
		-0.65,  1, -0.0125, 1, 1,   // 10
		-0.7,  1, -0.0125, 0, 1,  // 11

		// left
		-0.7, -1.3, -0.0125, 0, 0,  // 12
		-0.7, -1.3, -0.0125, 1, 0,  // 13
		-0.7, 1, -0.0125, 1, 1,  // 14
		-0.7, 1, -0.0125, 0, 1,  // 15
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left

	};

	ayunan8Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawAyunan8()
{
	glUseProgram(shaderProgram);
	ayunan8Texture->Bind();
	ayunan8Mesh->Draw();
}

void Taman::BuildAyunan9() {
	
	ayunan9Texture = new Texture("pegangan-jungkat-jungkit.png");
	
	GLfloat vertices[] = {
		// front
		0.7, -1.3, 0.0125, 0, 0,  // 0
		0.65, -1.3, 0.0125, 1, 0,   // 1
		0.65,  1, 0.0125, 1, 1,   // 2
		0.7,  1, 0.0125, 0, 1,  // 3

		// right
		0.65, 1, -0.0125, 0, 0,  // 4
		0.65, 1, 0.0125, 1, 0,  // 5
		0.65, -1.3, 0.0125, 1, 1,  // 6
		0.65, -1.3, -0.0125, 0, 1,  // 7

		// back
		0.7, -1.3, -0.0125, 0, 0,  // 8
		0.65, -1.3, -0.0125, 1, 0,   // 9
		0.65,  1, -0.0125, 1, 1,   // 10
		0.7,  1, -0.0125, 0, 1,  // 11

		// left
		0.7, -1.3, -0.0125, 0, 0,  // 12
		0.7, -1.3, -0.0125, 1, 0,  // 13
		0.7, 1, -0.0125, 1, 1,  // 14
		0.7, 1, -0.0125, 0, 1,  // 15
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left

	};

	ayunan9Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawAyunan9()
{
	glUseProgram(shaderProgram);
	ayunan9Texture->Bind();
	ayunan9Mesh->Draw();
}

void Taman::BuildAyunan10() {
	
	ayunan10Texture = new Texture("prosotan.png");
	
	GLfloat vertices[] = {
		// front
		-0.8, -1.4, 0.5, 0, 0,  // 0
		0.8, -1.4, 0.5, 1, 0,   // 1
		0.8, -1.3, 0.5, 1, 1,   // 2
		-0.8, -1.3, 0.5, 0, 1,  // 3

		// right
		0.8, -1.3, 0.5, 0, 0,  // 4
		0.8, -1.3, -0.5, 1, 0,  // 5
		0.8, -1.4, -0.5, 1, 1,  // 6
		0.8, -1.4, 0.5, 0, 1,  // 7

		// back
		-0.8, -1.4, -0.5, 0, 0,  // 8
		0.8, -1.3, -0.5, 1, 0,   // 9
		0.8,  -1.3, -0.5, 1, 1,   // 10
		-0.8,  -1.4, -0.5, 0, 1,  // 11

		// left
		-0.8, -1.4, -0.5, 0, 0,  // 12
		-0.8, -1.4, 0.5, 1, 0,  // 13
		-0.8, -1.3, 0.5, 1, 1,  // 14
		-0.8, -1.3, -0.5, 0, 1,  // 15

		// upper
		0.8, -1.3, 0.5, 0, 0, // 16
		-0.8, -1.3, 0.5, 1, 0,  // 17
		-0.8, -1.3, -0.5, 1, 1,  // 18
		0.8, -1.3, -0.5, 0, 1, // 19

		// bottom
		0.8, -1.4, 0.5, 0, 0, // 20
		-0.8, -1.4, 0.5, 1, 0,  // 21
		-0.8, -1.4, -0.5, 1, 1,  // 22
		0.8, -1.4, -0.5, 0, 1, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,   // upper
		20, 22, 21, 20, 23, 22	//bottom

	};

	ayunan10Mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawAyunan10()
{
	glUseProgram(shaderProgram);
	ayunan10Texture->Bind();
	ayunan10Mesh->Draw();
}

void Taman::BuildLangit() {

	langitTexture = new Texture("sky-1.jpg");

	GLfloat vertices[] = {
		// front
		-20.0, -2.01, 20.0, 0, 0,  // 0
		 20.0, -2.01, 20.0, 1, 0,   // 1
		 20.0, 30.0, 20.0, 1, 1,   // 2
		-20.0, 30.0, 20.0, 0, 1,  // 3

		// right
		20.0,  30.0, 20.0, 0, 0,   // 4
		20.0,  30.0, -20.0, 1, 0,   // 5
		20.0, -2.01, -20.0, 1, 1,   // 6
		20.0, -2.01, 20.0, 0, 1,   // 7

		// back
		-20.0, -2.01, -20.0, 0, 0,  // 8
		20.0, -2.01, -20.0, 1, 0,   // 9
		20.0,  30.0, -20.0, 1, 1,   // 10
		-20.0,  30.0, -20.0, 0, 1,  // 11

		// left
		-20.0, -2.01, -20.0, 0, 0,  // 12
		-20.0, -2.01, 20.0, 1, 0,  // 13
		-20.0,  30.0, 20.0, 1, 1,  // 14
		-20.0,  30.0, -20.0, 0, 1,  // 15

		// upper
		-20.0,  30.0, -20.0, 0, 0,  // 16
		20.0,  30.0, -20.0, 1, 0,   // 17
		20.0,  30.0, 20.0, 1, 1,   // 18
		-20.0,  30.0, 20.0, 0, 1,  // 19
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
	};

	langitMesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));
}

void Taman::DrawLangit()
{
	glUseProgram(shaderProgram);
	langitTexture->Bind();

	glm::mat4 model;
	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	langitMesh->Draw();
}

void Taman::BuildPlane()
{
	// Load and create a texture 
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height;
	unsigned char* image = SOIL_load_image("rumput.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// Build geometry
	GLfloat vertices[] = {
		// format position, tex coords
		// bottom
		-20.0, -2.01, -20.0,  0,  0,
		20.0, -2.01, -20.0, 20,  0,
		20.0, -2.01,  20.0, 20, 20,
		-20.0, -2.01,  20.0,  0, 20,
	};

	unsigned int indices[] = { 0,  2,  1,  0,  3,  2 };

	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);
	glGenBuffers(1, &EBO2);

	glBindVertexArray(VAO2);

	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	//// TexCoord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0); // Unbind VAO
}

void Taman::DrawPlane()
{
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 1);

	glBindVertexArray(VAO2); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glm::mat4 model;
	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void Taman::InitCamera()
{
	posCamX = 1.0f;
	posCamY = 3.0f;
	posCamZ = 15.0f;
	viewCamX = 3.0f;
	viewCamY = 0.0f;
	viewCamZ = 0.0f;
	upCamX = 0.0f;
	upCamY = 1.0f;
	upCamZ = 0.0f;
	CAMERA_SPEED = 0.0005f;
	fovy = 45.0f;
	glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Taman::MoveCamera(float speed)
{
	float x = viewCamX - posCamX;
	float z = viewCamZ - posCamZ;
	posCamX = posCamX + x * speed;
	posCamZ = posCamZ + z * speed;
	viewCamX = viewCamX + x * speed;
	viewCamZ = viewCamZ + z * speed;
}

void Taman::UpDownCamera(float speed)
{
	float y = viewCamY - posCamY;
	posCamY = posCamY + y * speed;
	viewCamY = viewCamY + y * speed;
}

void Taman::StrafeCamera(float speed)
{
	float x = viewCamX - posCamX;
	float z = viewCamZ - posCamZ;
	float orthoX = -z;
	float orthoZ = x;

	posCamX = posCamX + orthoX * speed;
	posCamZ = posCamZ + orthoZ * speed;
	viewCamX = viewCamX + orthoX * speed;
	viewCamZ = viewCamZ + orthoZ * speed;
}

void Taman::RotateCamera(float speed)
{
	float x = viewCamX - posCamX;
	float z = viewCamZ - posCamZ;
	viewCamZ = (float)(posCamZ + glm::sin(speed) * x + glm::cos(speed) * z);
	viewCamX = (float)(posCamX + glm::cos(speed) * x - glm::sin(speed) * z);
}

int main(int argc, char** argv) {
	RenderEngine &app = Taman();
	app.Start("Taman Bermain Anak", 800, 600, false, false);
}