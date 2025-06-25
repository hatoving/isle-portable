#include "d3drmrenderer_vitagl.h"
#include "miniwin.h"
#include "meshutils.h"
#include <algorithm>
#include <string>

#include <SDL3/SDL.h>
#include <vitaGL.h>

Direct3DRMRenderer* VitaGLRenderer::Create(DWORD width, DWORD height)
{
	SDL_Log("~ using VitaGL renderer ~");
	return new VitaGLRenderer(width, height);
}

VitaGLRenderer::VitaGLRenderer(
	DWORD width,
	DWORD height
)
	: m_width(width), m_height(height)
{
}

VitaGLRenderer::~VitaGLRenderer()
{
}

void VitaGLRenderer::PushLights(const SceneLight* lightsArray, size_t count)
{
	MINIWIN_NOT_IMPLEMENTED();
}

void VitaGLRenderer::SetFrustumPlanes(const Plane* frustumPlanes)
{
	MINIWIN_NOT_IMPLEMENTED();
}

void VitaGLRenderer::SetProjection(const D3DRMMATRIX4D& projection, D3DVALUE front, D3DVALUE back)
{
	MINIWIN_NOT_IMPLEMENTED();
}

Uint32 VitaGLRenderer::GetTextureId(IDirect3DRMTexture* iTexture)
{
	MINIWIN_NOT_IMPLEMENTED();
	return NO_TEXTURE_ID;
}

Uint32 VitaGLRenderer::GetMeshId(IDirect3DRMMesh* mesh, const MeshGroup* meshGroup)
{
	MINIWIN_NOT_IMPLEMENTED();
	return 0;
}

DWORD VitaGLRenderer::GetWidth()
{
	return m_width;
}

DWORD VitaGLRenderer::GetHeight()
{
	return m_height;
}

void VitaGLRenderer::GetDesc(D3DDEVICEDESC* halDesc, D3DDEVICEDESC* helDesc)
{
	memset(halDesc, 0, sizeof(D3DDEVICEDESC));

	helDesc->dcmColorModel = D3DCOLORMODEL::RGB;
	helDesc->dwFlags = D3DDD_DEVICEZBUFFERBITDEPTH;
	helDesc->dwDeviceZBufferBitDepth = DDBD_32;
	helDesc->dwDeviceRenderBitDepth = DDBD_32;
	helDesc->dpcTriCaps.dwTextureCaps = D3DPTEXTURECAPS_PERSPECTIVE;
	helDesc->dpcTriCaps.dwShadeCaps = D3DPSHADECAPS_ALPHAFLATBLEND;
	helDesc->dpcTriCaps.dwTextureFilterCaps = D3DPTFILTERCAPS_LINEAR;
}

const char* VitaGLRenderer::GetName()
{
	return "vitaGL (Rinnegatamante)";
}

HRESULT VitaGLRenderer::BeginFrame()
{
	MINIWIN_NOT_IMPLEMENTED();
	return S_OK;
}

void VitaGLRenderer::EnableTransparency()
{
	MINIWIN_NOT_IMPLEMENTED();
}

void VitaGLRenderer::SubmitDraw(
	DWORD meshId,
	const D3DRMMATRIX4D& modelViewMatrix,
	const Matrix3x3& normalMatrix,
	const Appearance& appearance
)
{
	MINIWIN_NOT_IMPLEMENTED();
}

HRESULT VitaGLRenderer::FinalizeFrame()
{
	MINIWIN_NOT_IMPLEMENTED();
	return S_OK;
}
