#include <string>
#include <GLAD/glad.h>

class Texture
{
public:
	Texture(const char *filename);
	void Bind();
	~Texture();
private:
	GLuint texture, shaderProgram;
};
