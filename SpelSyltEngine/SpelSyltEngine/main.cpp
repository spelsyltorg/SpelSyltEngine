#include <SpelSyltGfx/Window/Window.h>
#include <SpelSyltGfx/Rendering/GfxInclude.h>
#include <SpelSyltEngine/Rendering/Sprite/Sprite.h>

int main()
{
	SSGFX::CWindow Window(800, 800, "Hejsan Hoppsan");
	Window.SetClearColor({ 0.f, 1.f, 0.f, 1.f });

	SS::CSprite Sprite;
	Sprite.SetTexture("Hola!");
	Sprite.SetOrigin(0.f, 0.f);
	Sprite.SetPosition(0, 0);
	Sprite.SetScale(0.25f);

	while (Window.IsOpen())
	{
		Window.Clear();
		Sprite.Rotate(2, false);
		Sprite.Draw();

		auto events = Window.FlushEvents();
		for (auto&& e : events)
		{
			switch (e.type)
			{
			case SSGFX::EEventType::RESIZE:
				glViewport(0, 0, e.x, e.y);
				break;
			default:
				break;
			}
		}

		Window.UpdateContent();
	}

	return 0;
}