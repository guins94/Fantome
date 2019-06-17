#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef SURFACE_HEADER
#define SURFACE_HEADER

class Surface : public Component{
	public:
		Surface(GameObject* associated);
	public:
		void Load(std::string file);
	public:
		int* At(int x,int y, int z);
	public:
		void Render();
	public:
		void Start();
	public:
		void RenderLayer(int layer, int cameraX, int CameraY);
	public:
		void Update(float dt);
	public:
		bool Is(std::string type);
};

#endif
