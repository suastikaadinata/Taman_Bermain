#pragma once
#include "RenderEngine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <SOIL/SOIL.h>

class Taman :
	public RenderEngine
{
public:
	Taman();
	~Taman();
private:
	GLuint shaderProgram, VBO, VAO, EBO, texture, VBO2, VAO2, EBO2, texture2, lightShaderProgram;
	float viewCamX, viewCamY, viewCamZ, upCamX, upCamY, upCamZ, posCamX, posCamY, posCamZ, CAMERA_SPEED, fovy;
	float angle = 0, temp = 0;
	virtual void Init();
	virtual void DeInit();
	virtual void Update(double deltaTime);
	virtual void Render();
	virtual void ProcessInput(GLFWwindow *window);
	void BuildPlane();
	void BuildProsotan1();
	void BuildProsotan2();
	void BuildProsotan3();
	void BuildProsotan4();
	void BuildProsotan5();
	void BuildProsotan6();
	void BuildProsotan7();
	void BuildProsotan8();
	void BuildProsotan9();
	void BuildProsotan10();
	void BuildProsotan11();
	void BuildProsotan12();
	void BuildProsotan13();
	void BuildProsotan14();
	void BuildProsotan15();
	void BuildProsotan16();
	void BuildProsotan17();
	void BuildProsotan18();
	void BuildKotakPasir1();
	void BuildKotakPasir2();
	void BuildKotakPasir3();
	void BuildJungkatJungkit1();
	void BuildJungkatJungkit2();
	void BuildJungkatJungkit3();
	void BuildJungkatJungkit4();
	void BuildJungkatJungkit5();
	void BuildJungkatJungkit6();
	void BuildJungkatJungkit7();
	void BuildAyunan1();
	void BuildAyunan2();
	void BuildAyunan3();
	void BuildAyunan4();
	void BuildAyunan5();
	void BuildAyunan6();
	void BuildAyunan7();
	void BuildAyunan8();
	void BuildAyunan9();
	void BuildAyunan10();
	void DrawPlane();
	void DrawProsotan1();
	void DrawProsotan2();
	void DrawProsotan3();
	void DrawProsotan4();
	void DrawProsotan5();
	void DrawProsotan6();
	void DrawProsotan7();
	void DrawProsotan8();
	void DrawProsotan9();
	void DrawProsotan10();
	void DrawProsotan11();
	void DrawProsotan12();
	void DrawProsotan13();
	void DrawProsotan14();
	void DrawProsotan15();
	void DrawProsotan16();
	void DrawProsotan17();
	void DrawProsotan18();
	void DrawKotakPasir1();
	void DrawKotakPasir2();
	void DrawKotakPasir3();
	void DrawJungkatJungkit1();
	void DrawJungkatJungkit2();
	void DrawJungkatJungkit3();
	void DrawJungkatJungkit4();
	void DrawJungkatJungkit5();
	void DrawJungkatJungkit6();
	void DrawJungkatJungkit7();
	void BuildLangit();
	void DrawAyunan1();
	void DrawAyunan2();
	void DrawAyunan3();
	void DrawAyunan4();
	void DrawAyunan5();
	void DrawAyunan6();
	void DrawAyunan7();
	void DrawAyunan8();
	void DrawAyunan9();
	void DrawAyunan10();
	void DrawLangit();
	void UpDownCamera(float speed);
	void MoveCamera(float speed);
	void StrafeCamera(float speed);
	void RotateCamera(float speed);
	void InitCamera();
};
