#include "Sprite.h"
#include <SpelSyltGfx\Rendering\GfxInclude.h>

SSGFX::CVertexBuffer SS::CSprite::Quad;
SSGFX::CShader SS::CSprite::DefaultShader;

SS::CSprite::CSprite()
{
	RenderObject.Bind();
	RenderObject.SetPrimitiveType(SSGFX::Triangles);
	RenderObject.SetVertexCount(6);

	static bool initializedDefaults = false;
	if (!initializedDefaults)
	{
		initializedDefaults = true;
		float vertices[] = {
			-1.f, 1.f, 0.f, 1.f,
			1.f, 1.f, 1.f, 1.f,
			1.f, -1.f, 1.f, 0.f,
			-1.f, 1.f, 0.f, 1.f,
			1.f, -1.f, 1.f, 0.f,
			-1.f, -1.f, 0.f, 0.f,
		};
		Quad.Create(vertices, sizeof(vertices), 4);

		const char vertexShader[] = "\
#version 460 core \n\
layout(location = 0) in vec4 vertexPosXYandUV; \
out vec2 uv; \
uniform mat3 model; \
void main() \
{ \
gl_Position = vec4(model * vec3(vertexPosXYandUV.xy,1.0),1.0); \
uv = vertexPosXYandUV.zw; \
} \
";
		DefaultShader.Load(SSGFX::CShader::EShaderType::Vertex, (void*)vertexShader, sizeof(vertexShader));
		const char pixelShader[] = "\
#version 460 core \n\
out vec4 fragColor; \
in vec2 uv; \
uniform sampler2D tex; \
void main() \
{ \
fragColor = texture2D(tex, uv); \
} \
";
		DefaultShader.Load(SSGFX::CShader::EShaderType::Fragment, (void*)pixelShader, sizeof(pixelShader));
		DefaultShader.Link();
	}
}

void SS::CSprite::SetTexture(const std::string & FileName)
{
	Texture = new SSGFX::CTexture();
	Texture->Load("japaneseGoblin.PNG");
}

void SS::CSprite::Draw()
{
	RenderObject.Bind();
	DefaultShader.Bind();
	Quad.Bind(0);
	DefaultShader.SetUniform("model", *this);
	DefaultShader.SetUniform("tex", *Texture);
	RenderObject.Render();
}
