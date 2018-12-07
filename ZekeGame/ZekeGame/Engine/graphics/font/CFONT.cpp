#include "stdafx.h"
#include "CFONT.h"
CFont::CFont()
{
	m_spriteBatch = g_graphicsEngine->GetSpriteBatch();
	m_spriteFont = g_graphicsEngine->GetSpriteFont();
	m_scaleMat.MakeScaling(
		{
			g_graphicsEngine->GetFrameBufferWidth() / static_cast<float>(g_graphicsEngine->Get2DSpaceScreenWidth()),
			g_graphicsEngine->GetFrameBufferHeight() / static_cast<float>(g_graphicsEngine->Get2DSpaceScreenHeight()),
			1.0f
		}
	);
}
CFont::~CFont()
{
}

void CFont::Begin()
{
	m_spriteBatch->Begin();
}
void CFont::End()
{
	m_spriteBatch->End();
	g_graphicsEngine->Clear();
}
void CFont::Draw(
	wchar_t const* text,
	const CVector2& position,
	const CVector4& color,
	float rotation,
	float scale,
	CVector2 pivot)
{
	CVector2 pos = position;
	float frameBufferHalfWidth = g_graphicsEngine->Get2DSpaceScreenWidth() * 0.5f;
	float frameBufferHalfHeight = g_graphicsEngine->Get2DSpaceScreenHeight() * 0.5f;
	pos.x += frameBufferHalfWidth;
	pos.y = -pos.y + frameBufferHalfHeight;

	m_spriteFont->DrawString(
		m_spriteBatch,
		text,
		pos.vec,
		color,
		rotation,
		DirectX::XMFLOAT2(pivot.x, pivot.y),
		scale
	);
}