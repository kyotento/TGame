#include "stdafx.h"

HWND g_hwnd = NULL;
GraphicsEngine* g_graphicsEngine = NULL;
int notch;
bool mEve[10];

//TODO : �t���X�N���[���\���ł���悤�ɂ���
LRESULT CALLBACK MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static int nWheelFraction = 0;	// ��]�ʂ̒[��
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_ACTIVATE:
		// �E�B���h�E�̃A�N�e�B�u�؂�ւ����ɒ[�������Z�b�g
		nWheelFraction = 0;
		break;

	case WM_MOUSEWHEEL:
	{
		DWORD fwKeys = GET_KEYSTATE_WPARAM(wParam);	// �����ɉ�����Ă���L�[���
		int zDelta = GET_WHEEL_DELTA_WPARAM(wParam);	// ��]��

		// �O��̒[����ǉ�
		zDelta += nWheelFraction;
		// �m�b�`�������߂�
		int nNotch = zDelta / WHEEL_DELTA;
		notch = nNotch;
		// �[����ۑ�����
		nWheelFraction = zDelta % WHEEL_DELTA;
		break;
	}
	case WM_LBUTTONDOWN:
	{
		//���N���b�N���ꂽ
		mEve[0] = true;
		break;
	}
	case WM_LBUTTONUP:
	{
		//���{�^���𗣂���
		mEve[0] = false;
		break;
	}
	case WM_MBUTTONDOWN:
	{
		//�~�h���N���b�N���ꂽ
		mEve[1] = true;
		break;
	}
	case WM_MBUTTONUP:
	{
		//�~�h���{�^���𗣂���
		mEve[1] = false;
		break;
	}
	case WM_RBUTTONDOWN:
	{
		//�E�N���b�N���ꂽ
		mEve[2] = true;
		break;
	}
	case WM_RBUTTONUP:
	{
		//�E�{�^���𗣂���
		mEve[2] = false;
		break;
	}
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

void InitWindow(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR lpCmdLine,
	int nCmdShow,
	const TCHAR* appName){
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		MsgProc,
		0,
		0,
		GetModuleHandle(NULL),
		NULL,
		NULL,
		NULL,
		NULL,
		appName,
		NULL
	};

	RegisterClassEx(&wc);

	g_hwnd = CreateWindow(
		appName,
		appName,
		WS_OVERLAPPEDWINDOW,	
		0,					
		0,					
		1280,					
		720,					
		NULL,	
		NULL,
		hInstance,
		NULL
	);
	ShowWindow(g_hwnd, nCmdShow);

	//DirectX
	g_graphicsEngine = new GraphicsEngine();
	g_graphicsEngine->InitDirectX(g_hwnd);
	//Bullet
	g_physics.Init();
	//Pad
	g_pad[0].Init(0);
	g_pad[1].Init(1);
	g_pad[2].Init(2);
	g_pad[3].Init(3);
}


bool DispatchWindowMessage() {
	MSG msg = { 0 };
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			break;
		}
	}
	return msg.message != WM_QUIT;
}
