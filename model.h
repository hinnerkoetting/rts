/////////////////////////////////////////////////////////////////
//
//					model.h
//					load 3ds file
//
//					
//
/////////////////////////////////////////////////////////////////

#ifndef MODEL_H_DEF
#define MODEL_H_DEF
																						//					uv2 :  texture coordinates 2

class Model : public PCBReader {
	public:
		Model(char* filename);
		virtual		~Model() {ReleaseAll(); };	
		
		void draw();				
private:
	// Global variables
	CWindow*		window;									// The window
	CVertexArray*	vertexArray; 							// The vertex array
	CIndexBuffer*	faceIndices;							// The face indices
	CTextureBasic*	texture;							// Texture
	CLightBasic*	light;							// Light
	CMaterialBasic*	material;							// Material		
		// Overriden methods
		virtual					bool				NewScene	(PCBSceneInfo*	scene)		{return true;}		// Creation Method
		virtual					bool				NewCamera	(PCBCamera*		camera)		{return true;}		// Creation Method
		virtual					bool				NewLight	(PCBLight*		light)		{return true;}		// Creation Method
		virtual					bool				NewMaterial	(PCBMaterial*	material)	{return true;}		// Creation Method
		virtual					bool				NewTexture	(PCBTexture*	texture);						// Creation Method
		virtual					bool				NewTopology	(PCBTopo*		topo);							// Creation Method
		virtual					bool				NewShape	(PCBShape*		shape)		{return true;}		// Creation Method
		virtual					bool				NewMesh		(PCBMesh*		mesh)		{return true;}		// Creation Method
		virtual					bool				NewShell	(PCBShell*		shell)		{return true;}		// Creation Method
		virtual					bool				NewAnimPRS	(PCBAnimPRS*	anim)		{return true;}		// Creation Method
		virtual					bool				NewAnimCAM	(PCBAnimCAM*	anim)		{return true;}		// Creation Method
		virtual					bool				NewAnimLGH	(PCBAnimLGH*	anim)		{return true;}		// Creation Method
		
};

#endif