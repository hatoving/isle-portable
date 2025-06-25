#pragma once

#include "d3drmrenderer.h"
#include "d3drmtexture_impl.h"
#include "ddraw_impl.h"

#include <vitaGL.h>
#include <vector>

DEFINE_GUID(VitaGL_GUID, 0x682656F3, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07);

class VitaGLRenderer : public Direct3DRMRenderer {
public:
	static Direct3DRMRenderer* Create(DWORD width, DWORD height);
	VitaGLRenderer(
		DWORD width,
		DWORD height
	);
	~VitaGLRenderer() override;

	void PushLights(const SceneLight* lightsArray, size_t count) override;
	void SetProjection(const D3DRMMATRIX4D& projection, D3DVALUE front, D3DVALUE back) override;
	void SetFrustumPlanes(const Plane* frustumPlanes) override;
	Uint32 GetTextureId(IDirect3DRMTexture* texture) override;
	Uint32 GetMeshId(IDirect3DRMMesh* mesh, const MeshGroup* meshGroup) override;
	DWORD GetWidth() override;
	DWORD GetHeight() override;
	void GetDesc(D3DDEVICEDESC* halDesc, D3DDEVICEDESC* helDesc) override;
	const char* GetName() override;
	HRESULT BeginFrame() override;
	void EnableTransparency() override;
	void SubmitDraw(
		DWORD meshId,
		const D3DRMMATRIX4D& modelViewMatrix,
		const Matrix3x3& normalMatrix,
		const Appearance& appearance
	) override;
	HRESULT FinalizeFrame() override;

private:
	D3DRMMATRIX4D m_projection;
//	SDL_Surface* m_renderedImage;
	DWORD m_width, m_height;
	std::vector<SceneLight> m_lights;
	//SDL_GLContext m_context;;
};

inline static void VitaGLRenderer_EnumDevice(LPD3DENUMDEVICESCALLBACK cb, void* ctx)
{
	SDL_Log("Enuming VitaGL device...");
	Direct3DRMRenderer* device = VitaGLRenderer::Create(640, 480);
	if (device) {
		EnumDevice(cb, ctx, device, VitaGL_GUID);
		delete device;
	}
}
