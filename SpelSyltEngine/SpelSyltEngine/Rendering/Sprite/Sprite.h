#pragma once
#include <SpelSyltGfx\Rendering\RenderObject.h>
#include <SpelSyltGfx\Rendering\VertexBuffer.h>
#include <SpelSyltGfx\Rendering\Shader.h>
#include <SpelSyltCommonLibrary\Graphics\Public\Transformable2D.h>

#include <SpelSyltGfx/Rendering/Texture.h>

namespace SS
{
	class CSprite : public CL::CTransformable2D
	{
	public:
		CSprite();

		void SetTexture(const std::string& FileName);

		void Draw();

	private:
		SSGFX::CRenderObject RenderObject;

		SSGFX::CTexture* Texture = nullptr;

		static SSGFX::CVertexBuffer Quad;
		static SSGFX::CShader DefaultShader;
	};
}